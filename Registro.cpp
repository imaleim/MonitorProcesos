//Joustin Joel Martinez Carranza
#include "Registro.h"
#include <fstream>
#include <ctime>
#include <stdexcept>

void guardarRegistro(std::string archivo, Proceso* lista, int total, int modo) {
    std::ofstream ofs(archivo);
    if (!ofs) throw std::runtime_error("No se pudo abrir el archivo");

    time_t ahora = time(0);
    ofs << "Fecha: " << ctime(&ahora);
    ofs << "Total procesos: " << total << "\n\n";

    for (int i = 0; i < total; i++) {
        Riesgo r = evaluarProceso(lista[i], modo);
        ofs << lista[i].pid << " | " << lista[i].nombre
            << " | Memoria: " << lista[i].memoria
            << " | Riesgo: " << r.nivel
            << " | Razon: " << r.razon << "\n";
    }

    ofs.close();
}
