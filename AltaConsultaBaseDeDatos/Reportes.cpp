#include "Alumnos.cpp"

class Reportes {
public:
	string espaciado(string str, int max_len, string pos) {
		int len = max_len - str.length();
		string espacios;
		for (int i = 1; i <= len; i++)
			espacios += ' ';
		if (pos == "Izquierda")
			str = espacios + str;
		else if (pos == "Derecha")
			str = str + espacios;
		return str;
	}

	void alumnos_estatus(int op_reportes) {

		ut.cls();
		ifstream Lec;
		Lec.open("alumnos.txt", ios::in);
		string _carrera, _estatus;
		int _unidad;
		if (op_reportes == 3)
			_carrera = ut.pide_cadena(1, 4, "Indica la carrera a listar: ");
		if (op_reportes == 2)
			_unidad = ut.pide_entero(1, 999999, "Indica la unidad de trabajo a listar: ");
		if (op_reportes == 4) {
			int op_estatus = 0;
			cout << "1. Premio nacional CENEVAL\n";
			cout << "2. Sobresaliente\n";
			cout << "3. Satisfactorio\n";
			cout << "4. No satisfactorio\n";
			op_estatus = ut.pide_entero(1, 4, "Indica la opcion a listar: ");
			if (op_estatus == 1)
				_estatus = "Premio nacional CENEVAL";
			if (op_estatus == 2)
				_estatus = "Sobresaliente";
			if (op_estatus == 3)
				_estatus = "Satisfactorio";
			if (op_estatus == 4)
				_estatus = "No satisfactorio";
		}
		printf("--------------------------------------------------------------------------------------------\n");
		printf("Folio   Nombre     ApPat      Apmat      PDis Ptra Pglo Unidad Car  Estatus\n");
		printf("--------------------------------------------------------------------------------------------\n");
		while (!Lec.eof())
		{
			string nombre, ap_materno, ap_paterno, carrera;
			int folio, puntaje_dis, puntaje_trans, puntaje_global, unidad;
			Lec >> folio;
			Lec >> nombre;
			Lec >> ap_paterno;
			Lec >> ap_materno;
			Lec >> puntaje_dis;
			Lec >> puntaje_trans;
			Lec >> puntaje_global;
			Lec >> unidad;
			Lec >> carrera;
			string registro;

			string estatus = ut.estatus(puntaje_dis, puntaje_trans, puntaje_global);
			stringstream stream1, stream2, stream3, stream4, stream5;

			string sfolio, spuntaje_dis, spuntaje_trans, spuntaje_global, sunidad;
			stream1 << folio;
			stream1 >> sfolio;
			stream2 << puntaje_dis;
			stream2 >> spuntaje_dis;
			stream3 << puntaje_trans;
			stream3 >> spuntaje_trans;
			stream4 << puntaje_global;
			stream4 >> spuntaje_global;
			stream5 << unidad;
			stream5 >> sunidad;
			registro = this->espaciado(sfolio, 6, "Izquierda") + ' ' + this->espaciado(nombre, 10, "Derecha") + ' ' + this->espaciado(ap_materno, 10, "Derecha") + ' ' + this->espaciado(ap_paterno, 10, "Derecha") + ' ' + this->espaciado(spuntaje_dis, 4, "Izquierda") + ' ' + this->espaciado(spuntaje_trans, 4, "Izquierda") + ' ' + this->espaciado(spuntaje_global, 4, "Izquierda") + ' ' + this->espaciado(sunidad, 6, "Izquierda") + ' ' + this->espaciado(carrera, 4, "Derecha") + ' ' + this->espaciado(estatus, 6, "Derecha") + "\n";

			if (op_reportes == 1)
				cout << registro;

			if (op_reportes == 3 && carrera == _carrera)
				cout << registro;

			if (op_reportes == 2 && unidad == _unidad)
				cout << registro;

			if (op_reportes == 4 && estatus == _estatus)
				cout << registro;

		}
		Lec.close();
		system("pause");
	}

	void reportes_escuelas(int op_reportes) {
		ut.cls();
		ifstream Lec;
		Lec.open("escuelas.txt", ios::in);
		string _estado;
		if (op_reportes == 6)
			_estado = ut.pide_cadena(1, 20, "Indica el estado a listar: ");
		printf("----------------------------------------------------------\n");
		printf("Unidad  Nombre                                   Estado   \n");
		printf("----------------------------------------------------------\n");
		while (!Lec.eof())
		{
			string clave, nombre, estado;
			Lec >> clave;
			Lec >> nombre;
			Lec >> estado;
			string registro;
			registro = this->espaciado(clave, 6, "Izquierda") + ' ' + this->espaciado(nombre, 40, "Derecha") + ' ' + this->espaciado(estado, 4, "Derecha") + "\n";


			if (op_reportes == 5)
				cout << registro;

			if (op_reportes == 6 && estado == _estado)
				cout << registro;
		}
		Lec.close();
		system("pause");
	}
};
	

Reportes rep;
