#ifndef PROCESOS_H
#define PROCESOS_H

#include <string>

struct Proceso {
    int pid;
    std::string nombre;
    std::string memoria;
};

Proceso* obtenerProcesos(int &total);

#endif
