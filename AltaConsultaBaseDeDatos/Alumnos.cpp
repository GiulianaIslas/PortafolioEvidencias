
#include "Utilerias.cpp"



class Alumnos
{
public:
	void altas() {
		ut.cls();
		ut.encabezado("ALTAS DE ALUMNOS");
		ofstream Esc;
		ifstream Lec;
		int folio, clave;
		while (true)
		{
			folio = ut.pide_entero(1, 999999, "Indica el folio del alumno: ");
			string existe = ut.buscar_registro_alumnos(Lec, folio);
			if (existe != "Inexistente")
			{
				ut.error("Error, el folio se duplica ... ");
			}
			else {
				clave = ut.pide_entero(1, 999999, "Indica la unidad de trabajo: ");
				existe = ut.buscar_registro_escuelas(Lec, clave);
				if (existe == "Inexistente")
				{
					ut.error("Error, la unidad de trabajo no existe ... ");
				}
				else {
					string nombre = ut.pide_cadena(1, 15, "Indica el nombre del alumno: ");
					string apellido_pat = ut.pide_cadena(1, 15, "Indica el apellido paterno: ");
					string apellido_mat = ut.pide_cadena(1, 15, "Indica el apellido materno: ");
					int puntaje_dis = ut.pide_entero(100, 1200, "Indica el puntaje disciplinar: ");
					int puntaje_trans = ut.pide_entero(100, 1200, "Indica el puntaje transversal: ");
					int puntaje_global = ut.pide_entero(100, 1200, "Indica el puntaje global: ");
					string carrera = ut.pide_cadena(1, 4, "Indica la carrera del alumno: ");

					char foliostr[256], punt_disstr[256], punt_transstr[256], punt_globalstr[256], clavestr[256];
					itoa(folio, foliostr, 10);
					itoa(puntaje_dis, punt_disstr, 10);
					itoa(puntaje_trans, punt_transstr, 10);
					itoa(puntaje_global, punt_globalstr, 10);
					itoa(clave, clavestr, 10);
					string strf, strpd, strpt, strpg, strclave = string(foliostr);
					strf = string(foliostr);
					strpd = string(punt_disstr);
					strpt = string(punt_transstr);
					strpg = string(punt_globalstr);
					strclave = string(clavestr);
					string registro = strf + " " + nombre + " " + apellido_pat + " " + apellido_mat + " " + strpd + " " + strpt + " " + strpg + " " + strclave + " " + carrera;
					ut.graba_registro(Esc, registro, "alumnos.txt");
					ut.error("Registro exitoso ... ");
					break;
				}
			}
		}
	}
	void consultas() {
		ifstream Lec;
		ut.cls();
		ut.encabezado("CONSULTAS DE ALUMNOS");
		int folio;
		folio = ut.pide_entero(1, 999999, "Indica el folio a consultar: ");
		string registro = ut.buscar_registro_alumnos(Lec, folio);
		if (registro == "Inexistente") {
			ut.error("Error, registro inexistente en archivo de alumnos ...");
		}
		else {
			stringstream iregistro(registro);
			string folio, nombre, apellido_pat,apellido_mat, puntaje_dis, puntaje_trans, puntaje_glob, unidad, carrera;
			getline(iregistro, folio, ' ');
			getline(iregistro, nombre, ' ');
			getline(iregistro, apellido_pat, ' ');
			getline(iregistro, apellido_mat, ' ');
			getline(iregistro, puntaje_dis, ' ');
			getline(iregistro, puntaje_trans, ' ');
			getline(iregistro, puntaje_glob, ' ');
			getline(iregistro, unidad, ' ');
			getline(iregistro, carrera, ' ');
			cout << "Nombre: " << nombre << "\n";
			cout << "Apelllido paterno: " << apellido_pat << "\n";
			cout << "Apelllido materno: " << apellido_mat << "\n";
			cout << "Puntaje disciplinar: " << puntaje_dis << "\n";
			cout << "Puntaje transversal: " << puntaje_trans << "\n";
			cout << "Puntaje global: " << puntaje_glob << "\n";
			cout << "Unidad: " << unidad << "\n";
			cout << "Carrera: " << carrera << "\n";
			system("pause");
		}
	}
	
	Alumnos(){}
};

Alumnos alum = Alumnos();
