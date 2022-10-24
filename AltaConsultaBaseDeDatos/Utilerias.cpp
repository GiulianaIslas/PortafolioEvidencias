

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <sstream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include <fstream>
#include <string.h> 
using namespace std;

class Utilerias {
public:
    Utilerias() {}
    void cls() {
    for (int i=1;i<40;i++) cout<<" "<<endl;
	}
    void encabezado(string msg) {
        int len = msg.length() + 8;
        string newmsg = "*** " + msg + " ***";
        string line;
        for (int i = 1; i <= len; i++) {
            line += '*';
        }
        cout << line << "\n";
        cout << newmsg << "\n";
        cout << line << "\n";
    }
    void error(string msg) {
        cout << msg << "\n";
        system("pause");
    }
    int pide_entero(int lim_inf, int lim_sup, string msg) {
        while (true)
        {
            string valor;
            cout << msg;
            cin >> valor;
            if (!this->isNumeric(valor))
            {
                this->error("Error, solo valores numericos ... ");
            }
            else
            {
                char valchar[256];
                strcpy(valchar, valor.c_str());
                if (atoi(valchar) < lim_inf || atoi(valchar) > lim_sup)
                {
                    this->error("Error, valor fuera de rango ... ");
                }
                else return atoi(valchar);
            }
        }
    }
    bool isNumeric(string str) {
        size_t found = str.find_first_not_of("0123456789");
        if (found != string::npos) return false;
        return true;
    }
    string pide_cadena(int lim_inf, int lim_sup, string msg) {
        while (true)
        {
            string cadena;
            locale loc;
            cout << msg;
            fflush(stdin);
            getline(cin, cadena);
            for (int i = 0; i < cadena.length(); i++)
            {
                if (cadena[i] == ' ') 
                    cadena[i] = '_';
                
            }
            if (cadena.length() < lim_inf || cadena.length() > lim_sup)
            {
                this->error("Error, longitud de cadena fuera de rango");
            }
            else
            {
                char cadenachar[256];
                strcpy(cadenachar, cadena.c_str());
                return strupr(cadenachar);
            }
        }
    };
    string buscar_registro_escuelas(ifstream &Lec,int id) {
        Lec.open("escuelas.txt", ios::in);
        string registro;
        bool encontrado = false;
        while (!Lec.eof() && !encontrado) 
        {
            string clave, nombre, estado;
            Lec >> clave;
            Lec >> nombre;
            Lec >> estado;
            char newclave[256];
            strcpy(newclave, clave.c_str());
            
            if (atoi(newclave) == id)
            {
                registro = clave + ' ' + nombre + ' ' + estado;
                encontrado = true;
                Lec.close();
            }
        }
        Lec.close();

        if (!encontrado)
            return "Inexistente";
        else
            return registro;
    }
    string buscar_registro_alumnos(ifstream& Lec, int _folio) {
        Lec.open("alumnos.txt", ios::in);
        string registro;
        bool encontrado = false;
        while (!Lec.eof() && !encontrado)
        {
            string folio, nombre, ap_materno, ap_paterno, puntaje_dis, puntaje_trans, puntaje_global, unidad, carrera;
            Lec >> folio;
            Lec >> nombre;
            Lec >> ap_paterno;
            Lec >> ap_materno;
            Lec >> puntaje_dis;
            Lec >> puntaje_trans;
            Lec >> puntaje_global;
            Lec >> unidad;
            Lec >> carrera;
            char newfolio[256];
            strcpy(newfolio, folio.c_str());

            if (atoi(newfolio)== _folio)
            {
                registro = folio + ' '+ nombre +' '+ ap_materno+ ' '+ ap_paterno+ ' '+ puntaje_dis + ' '+ puntaje_trans + ' '+ puntaje_global + ' '+ unidad + ' '+ carrera;
                encontrado = true;
                Lec.close();
            }
        }
        Lec.close();

        if (!encontrado)
            return "Inexistente";
        else
            return registro;
    }
    void graba_registro(ofstream &Es, string registro, string archivo) {
        if (archivo == "escuelas.txt")
		    Es.open("escuelas.txt",ios::out | ios::app); 
        if (archivo == "alumnos.txt")
            Es.open("alumnos.txt", ios::out | ios::app);
        Es << registro << "\n";
        Es.close();
    }
    string estatus(int puntaje_dis, int puntaje_trans, int puntaje_glob) {
        string estatus;
        if (puntaje_dis >= 1000 && puntaje_glob >= 1000)
            estatus = "Premio nacional CENEVAL";
        else if (puntaje_dis >= 900 && puntaje_trans >= 900 && puntaje_glob >= 900)
            estatus = "Sobresaliente";
        else if (puntaje_dis >= 800 && puntaje_trans >= 800 & puntaje_glob >= 800)
            estatus = "Satisfactorio";
        else
        {
            int contador = 0;
            if (puntaje_dis >= 800)
                contador++;
            if (puntaje_trans >= 800)
                contador++;
            if (puntaje_glob >= 800)
                contador++;
            if (contador >= 2)
                estatus = "Satisfactorio";
            else
                estatus = "No satisfactorio";
        }
        return estatus;
    }
};
Utilerias ut = Utilerias();
