//Luis Santiago Cantú Niño

#ifndef ANALISIS_H
#define ANALISIS_H

#include "Procesos.h"
#include <string>

struct Riesgo {
    std::string razon;
    std::string nivel;
};

Riesgo evaluarProceso(const Proceso &p, int modo);

#endif
