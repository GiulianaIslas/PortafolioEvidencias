/*
string fecha_de_creacion = "19 de octubre de 2022";
string fecha_de_ultima_modificación = "19 de octubre de 2022";

string []Autores = [
    "A01369142 José Alberto Velazquez Trujillo",
    "A01368818 Joel Sanchez Olvera",
    "A01771003 Giuliana Sofia Islas Carbajal",
];

string descripción = 
 " El siguiente programa muestra el uso de vectores y sus métodos para ordenar datos recibidos, 
 tomando como su campo a ordenar la dirección IP recibida, una vez ordenado el archivo, se toma 
 en cuenta el campo de la IP para realizar las búsquedas de una IP inicial a una IP Final, posteriormente
 se guarda el archivo ordenado en "bitacoraOrdenada.txt" ";

*/


//Incluimos Librerías Necesarias 
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>

using namespace std;

// Declaramos la clase Bitacora 
class Bitacora
{
    private:
        ifstream bitacoraReader;
        ofstream bitacoraWriter;
        //Vectores a Utilizar en el programa
        vector<long long> ipLogs, aux, ip1, ip2, ip3, ip4, ip1aux, ip2aux, ip3aux, ip4aux;
        vector<string> logs, logsAux, ipOnly, ipOnlyAux;
        
        // Funcion EXTRA para barra de progreso
        void delay(int secs) {
            for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
        }

        //Funcion para leer la base de datos y almacenar su contenido en los vectores que ya se crearon
        void readBitacora(){
            // Excribimos en el nuevo archivo
            // Leemos el archivo original
            // bitacoraReader.open( "bitacora.txt" );
            string row, row1, row2, row3, row4, helper;

            ifstream bitacoraReader2;
            bitacoraReader2.open("bitacora.txt");
            string file;
            while( getline(bitacoraReader2, row) ){
                bitacoraReader2 >> row1 >> row2 >> row3 >> row4;
                file = row1 + " " + row2 + " " + row3 + " " + row4 + " " + row;
              
                for( int i = 0; i < row4.size(); i++ ){
                    if( row4[i] == '.' || row4[i] == ':' ){
                        row4[i] = ' ';
                        
                    }

                }
                // escribimos en el archivo creado
                ipOnly.push_back(row4);
            }
            bitacoraReader2.close();


            ofstream bitacoraWriter2;
            bitacoraWriter2.open("bitacoraOrdenada.txt");

            for( int i = 0; i < ipOnly.size(); i++ ){
                bitacoraWriter2 << ipOnly[i] << endl;
            }
            bitacoraWriter2.close();

            ifstream bitacoraReader3;
            bitacoraReader3.open("bitacoraOrdenada.txt");
            string s1, s2, s3, s4, s5;
            
            long long res;
            while( getline(bitacoraReader3, row )){
                bitacoraReader3 >> s1 >> s2 >> s3 >> s4 >> s5;

                ip1.push_back(stoll(s1)); 
                ip2.push_back(stoll(s2)); 
                ip3.push_back(stoll(s3)); 
                ip4.push_back(stoll(s4)); 
                ip1aux.push_back(stoll(s1)); 
                ip2aux.push_back(stoll(s2)); 
                ip3aux.push_back(stoll(s3)); 
                ip4aux.push_back(stoll(s4)); 
                file = s1 + " " + s2 + " " + s3 + " " +s4;
                logs.push_back( file );
                logsAux.push_back( file );
                ipLogs.push_back( stoll(s1) );//suicidio o q
                aux.push_back( stoll(s1) );
            }
            bitacoraReader3.close();
            
        }


        void mergeSort( int lo, int hi ){
            if( lo >= hi ) return ;
            int mid = lo + ( hi - lo ) / 2;
            mergeSort( lo , mid );
            mergeSort( mid+1, hi );
            merge( lo, mid, hi );
        }
        
        // Función de mergeSort para ordenar las IP
        void merge(int lo, int mid, int hi){
            for( int i = lo; i <= hi; i++ ){
                aux[i] = ipLogs[i];
                logsAux[i] = logs[i];
            }
            
            // Declaramos i, j y k respectivamente
            int i = lo; 
            int j = mid + 1;
            int k = lo;
            
            while( i <= mid && j <= hi ){
                // Si el el valor del arreglo en el lado izquierdo es menor que el arreglo del lado derecho,
                // se guarda en el arreglo principal, si no lo contrario
              if( aux[i] < aux[j] ){
                ipLogs[k] = aux[i];
                logs[k] = logsAux[i];

                i++; // Aumentamos i si guardamos ese valor
              }  
              else{
                ipLogs[k] = aux[j];
                logs[k] = logsAux[j];
            
                j++; // Aumentamos j si guardamos ese valor
              }
                k++; // Aumentamos k siempre 
            }

            while( i <= mid ){ // Si "i" todavia no llega a la mitad copiamos los valores restantes del lado izquierdo
                ipLogs[k] = aux[i];
                logs[k] = logsAux[i];
         
                i++;
                k++;
            }

            while( j <= hi ){ // Si "j" todavia no llega a la mitad copiamos los valores restantes del lado derecho
                ipLogs[k] = aux[j];
                logs[k] = logsAux[j];
            
                j++;
                k++;
            }
        }

        void writeToFile(){
            bitacoraWriter.open( "bitacoraOrdenada.txt" );
            for( int i = 0; i < logs.size(); i++ ){
                //cout << ipLogs[i] << endl;
                bitacoraWriter << logs[i] << '\n';
                //cout << logs[i] << endl;
            }
            bitacoraWriter.close();
        }


    public:
        //Funcion de busqueda de las IPs
        void getIps(){
            string firstIP, lastIP, help, help2;
            long long firstValueIP, lastValueIP;

            //Input del usuario
            cout << "Ingrese el rango de las IP a buscar: "<<endl;
            cout << "IP Inicial : ";
            cin >> firstIP;
            cout << "IP Final : ";
            cin >> lastIP;
            help = "";
            help2 = "";

            for( int i = 0; i < firstIP.size(); i++ ) 
                if( firstIP[i] != '.' && firstIP[i] != ':' ){
                    help += firstIP[i];
                }

            for( int i = 0; i < lastIP.size(); i++ ) 
                if( lastIP[i] != '.' && lastIP[i] != ':' ){
                    help2 += lastIP[i];
                }
            firstValueIP = stoll(help);
            lastValueIP = stoll(help2);

            cout<< "\nResultados de " << firstIP << " a " << lastIP << " : \n" << endl;
            
            // Busca los datos en el archivo ordenado
            for (int i=0; i<ipLogs.size(); i++){
                if (ipLogs[i]==firstValueIP){
                    for(; ipLogs[i]!=lastValueIP ; i++ ) 
                        cout << logs[i] << endl; 
                        
                    
                    for(; ipLogs[i]==lastValueIP ; i++ )
                        cout << logs[i] << endl;                
                }
            }
        }

        void printBitacora(){
            for( int i = 0; i < ipLogs.size(); i++ ){
                cout << ipLogs[i] << endl;
            }
        }

        void printBitacoraL(){
            for( int i = 0; i < logs.size(); i++ ){
                cout << logs[i] << endl;
            }
        }

        Bitacora(){
            char b = (char)254;
            long contador = 1;
            readBitacora();
            // cout << "[" << b << b << b << "      ]" <<" 33% completado..." << endl;
            // delay(1);
        
            mergeSort(0 , ipLogs.size() - 1 );

            //writeToFile();
            // cout << "[" << b << b << b << b << b << b << b << b << b << "]" << " 100% completado..." << endl;
            // delay(1);
        }
 
};

int main()
{
    
    cout << "Leyendo archivo..." << endl;
    Bitacora bitacora;



    return 0;
}

