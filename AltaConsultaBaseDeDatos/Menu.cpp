#include "Escuelas.cpp"

class Menu
{
public:
    void menu_principal() {
        int op = 0;
        while (op != 9) {
            ut.cls();
            ut.encabezado("MENU PRINCIPAL");
            cout << "1. Alumnos" << "\n";
            cout << "2. Escuelas" << "\n";
            cout << "3. Reportes" << "\n";
            cout << "9. Terminar" << "\n";
            op = ut.pide_entero(1, 9, "Indica la opcion: ");
            if (op == 1 || op == 2) {
                system("pause");
                this->menu_alumnos_escuelas(op);
            }
            if (op == 3) {
                system("pause");
                this->menu_reportes();
            }
            cout << " " << "\n";

        }
        ut.cls();
    }
    void menu_alumnos_escuelas(int op_principal) {
        int op_alumnos_escuelas = 0;
        while (op_alumnos_escuelas != 9) {
            ut.cls();
            if (op_principal == 1) {
                ut.encabezado("MENU ALUMNOS");
            }
            if (op_principal == 2) {
                ut.encabezado("MENU DE ESCUELAS");
            }
            cout << "1. Altas" << "\n";
            cout << "2. Consultas" << "\n";
            cout << "9. Principal" << "\n";
            op_alumnos_escuelas = ut.pide_entero(1, 9, "Indica la opcion: ");
            if (op_alumnos_escuelas == 1 && op_principal == 2) {
                esc.altas();
            }
            if (op_alumnos_escuelas == 1 && op_principal == 1) {
                alum.altas();
            }
            if (op_alumnos_escuelas == 2 && op_principal == 1) {
                alum.consultas();
            }
            if (op_alumnos_escuelas == 2 && op_principal == 2) {
                esc.consultas();
            }

        }
    }
    void menu_reportes() {
        int op_reporte = 0;
        while (op_reporte != 9) {
            ut.cls();
            ut.encabezado("MENU DE REPORTES");
            cout << "1. Listado de alumnos" << "\n";
            cout << "2. Listado de alumnos por escuela" << "\n";
            cout << "3. Listado de alumnos por carrera" << "\n";
            cout << "4. Listado de alumnos por estatus" << "\n";
            cout << "5. Listado de escuelas" << "\n";
            cout << "6. Listado de escuelas por estado" << "\n";
            cout << "9. Principal" << "\n";
            op_reporte = ut.pide_entero(1, 9, "Indica la opcion: ");
            if (op_reporte<5)
            	rep.alumnos_estatus(op_reporte);
            else
            	rep.reportes_escuelas(op_reporte);
        }
    }
    Menu() {}
};    

Menu menu = Menu();



