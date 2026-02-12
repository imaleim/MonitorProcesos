//Luis Santiago Cantú Niño

#include "Analisis.h"

Riesgo evaluarProceso(const Proceso &p, int modo) {
    Riesgo r = {"Normal", "Bajo"};

    // CRITERIOS DE SEGURIDAD 
    if (p.nombre.find("cmd") != std::string::npos ||
        p.nombre.find("powershell") != std::string::npos) {
        r.razon = "Proceso de consola potencialmente usado para comandos maliciosos";
        r.nivel = "Alto";
    }

    if (modo == 2 && p.nombre.find("svchost") != std::string::npos) {
        r.razon = "Muchos procesos svchost pueden ocultar malware";
        r.nivel = "Medio";
    }

    if (p.nombre.find(".tmp") != std::string::npos) {
        r.razon = "Ejecutable temporal sospechoso";
        r.nivel = "Alto";
    }

    if (p.nombre.find("123") != std::string::npos) {
        r.razon = "Nombre con patrón extraño típico de malware";
        r.nivel = "Medio";
    }

    if (p.memoria.find("K") != std::string::npos) {
        int mem = stoi(p.memoria.substr(0, p.memoria.find(" ")));
        if (mem > 200000) {
            r.razon = "Consumo alto de memoria";
            r.nivel = "Medio";
        }
    }

    return r;
}
