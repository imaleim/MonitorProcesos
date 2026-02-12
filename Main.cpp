//Alejandra Itzel Ojeda Valdez 
#include <iostream>
#include "Procesos.h"
#include "Analisis.h"
#include "Registro.h"

using namespace std;

int main() {
    try {
        int modo;
        string archivo;

        cout << "Modo de analisis (1 basico / 2 estricto): ";
        cin >> modo;
        if (modo != 1 && modo != 2) throw runtime_error("Modo invalido");

        cout << "Nombre del archivo de salida: ";
        cin >> archivo;

        int total;
        Proceso* lista = obtenerProcesos(total);

        cout << "\nPROCESOS ACTIVOS\n";
        for (int i = 0; i < total; i++) {
            Riesgo r = evaluarProceso(lista[i], modo);
            cout << lista[i].pid << " | " << lista[i].nombre
                 << " | Memoria: " << lista[i].memoria
                 << " | Riesgo: " << r.nivel << endl;
        }

        guardarRegistro(archivo, lista, total, modo);

        delete[] lista;
        cout << "\nRegistro guardado correctamente\n";

    } catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
