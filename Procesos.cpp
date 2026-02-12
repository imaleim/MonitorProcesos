#include "Procesos.h"
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <stdexcept>

Proceso* obtenerProcesos(int &total) {
    FILE* fp = popen("tasklist /FO CSV /NH", "r");
    if (!fp) throw std::runtime_error("Error obteniendo procesos");

    Proceso* lista = new Proceso[500];
    total = 0;
    char linea[1024];

    while (fgets(linea, sizeof(linea), fp) && total < 500) {
        std::string s(linea);
        std::stringstream ss(s);

        std::string nombre, pidStr, sesion, numSesion, memoria;

        getline(ss, nombre, ',');
        getline(ss, pidStr, ',');
        getline(ss, sesion, ',');
        getline(ss, numSesion, ',');
        getline(ss, memoria, ',');

        nombre.erase(remove(nombre.begin(), nombre.end(), '"'), nombre.end());
        pidStr.erase(remove(pidStr.begin(), pidStr.end(), '"'), pidStr.end());
        memoria.erase(remove(memoria.begin(), memoria.end(), '"'), memoria.end());

        lista[total].nombre = nombre;
        lista[total].pid = stoi(pidStr);
        lista[total].memoria = memoria;

        total++;
    }

    pclose(fp);
    return lista;
}
