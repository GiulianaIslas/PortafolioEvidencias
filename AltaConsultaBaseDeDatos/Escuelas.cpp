#include "Reportes.cpp"



class Escuelas
{
public:
	void altas() {
		ut.cls();
		ut.encabezado("ALTAS DE ESCUELAS");
		ofstream Esc;
		ifstream Lec;
		int clave;
		while (true)
		{
			clave = ut.pide_entero(1, 999999, "Indica la clave/unidad de la escuela: ");
			string existe = ut.buscar_registro_escuelas(Lec, clave);
			if (existe!="Inexistente")
			{
				ut.error("Error, la unidad de trabajo se duplica ... ");
			}
			else {
				string nombre = ut.pide_cadena(1, 40, "Indica el nombre de la escuela: ");
				string estado = ut.pide_cadena(1, 20, "Indica el estado de la escuela: ");
				char clavestr[256];
				itoa(clave,clavestr,10);
				string str = string(clavestr);				
				string registro = str + " " + nombre + " " + estado;
				ut.graba_registro(Esc,registro,"escuelas.txt");
				ut.error("Registro exitoso ... ");
				break;
			}
		}
		
	}
	void consultas() {
		ifstream Lec;
		ut.cls();
		ut.encabezado("CONSULTAS DE ESCUELAS");
		int clave;
		clave = ut.pide_entero(1, 999999, "Indica la unidad a consultar: ");
		string registro = ut.buscar_registro_escuelas(Lec, clave);
		if (registro == "Inexistente") {
			ut.error("Error, registro inexistente en archivo de escuelas ...");
		}
		else {
			stringstream iregistro(registro);
			string unidad, nombre, estado;
			getline(iregistro, unidad, ' ');
			getline(iregistro, nombre, ' ');
			getline(iregistro, estado, ' ');
			cout << "Nombre: " << nombre << "\n";
			cout << "Estado: " << estado << "\n";
			system("pause");
		}
	}
	Escuelas() {}
};

Escuelas esc = Escuelas();
