# Monitor de Procesos en C++

## Descripcion General 
Este proyecto consiste en el desarrollo de un monitor real de procesos del sistema utilizando C++. El programa obtiene en tiempo real los procesos activos del sistema operativo, analiza cuáles podrían representar un riesgo de seguridad según criterios definidos por el equipo y registra todos los resultados en un archivo de texto.

No se utilizan datos simulados. Toda la información proviene directamente del sistema, lo que hace que el programa funcione como una herramienta básica de monitoreo de seguridad.

El proyecto está dividido en módulos para aplicar buenas prácticas de programación modular, manejo de memoria dinámica y análisis con enfoque en ciberseguridad.

### Integrantes del Equipo 
Alejandra Itzel Ojeda Valdez — GitHub - imaleim

Nombre 2 — Luis Santiago Cantú Niño - Github - sqntii

Nombre 3 — [opcional]

Nombre 4 — [opcional]

## Instrucciones de compilación y ejecución

### ***Requisitos***

- Sistema operativo: Windows

- Compilador: g++ (MinGW / MSYS2 / VS Code)

- Herramientas usadas:

  - Comando del sistema tasklist
    
  - Función popen() para capturar procesos reales
    
  - Librerías estándar de C++ (iostream, fstream, string, etc.)

### ***Compilacion***
    g++ Main.cpp Procesos.cpp Analisis.cpp Registro.cpp -o monitor.exe

### ***Ejecucion***  
    ./monitor.exe

## Entrada Esperada 

El programa solicita al usuario:

### ***Modo de análisis*** 

***1 → Análisis básico***  Solo detecta riesgos evidentes (consolas y memoria alta).

***2 → Análisis estricto*** Aplica reglas adicionales como revisión de svchost.

### ***Nombre del archivo de salida*** 

***Ejemplo: AnalisisV1.txt***

## Enfoque tecnico 

El programa obtiene procesos reales del sistema mediante:

- El comando de Windows: *tasklist /FO CSV /NH*

- Uso de *popen()* para leer la salida del comando

Almacenamiento en memoria dinámica usando:

    Proceso* lista = new Proceso[500];

Cada proceso se guarda en una estructura struct Proceso, que contiene su PID, nombre y uso de memoria.

El sistema está dividido en módulos:

| Modulo | Funcion | 
| :--- | :--- | 
| Procesos | Obtiene procesos reales del sistema | 
| Analisis| Evalúa el nivel de riesgo | 
| Registro | Guarda resultados en archivo |
| Main | Controla flujo y entradas del usuario |


## Criterios para procesos sospechosos 

Estos criterios se eligieron con base en prácticas comunes en ciberseguridad y posibles comportamientos asociados a malware o uso indebido del sistema.

| Criterio Detectado | Razon | Nivel de Riesgo |
| :--- | :--- | :--- | 
| *Procesos como cmd.exe o powershell.exe* | *Pueden ejecutar comandos maliciosos o scripts* | *🔴 Alto* |
| *Muchos procesos svchost.exe (modo estricto)* | *Malware puede ocultarse bajo este nombre* | *🟠 Medio* |
| *Consumo de memoria muy alto* | *Posible comportamiento anómalo* | *🟡 Medio* | 
| *Procesos normales del sistema* | *Funcionamiento habitual* | *🟢 Bajo* |

## Salida Generada 

### ***En consola:*** 

Se muestran todos los procesos con:
- PID
- Nombre
- Memoria usada
- Nivel de riesgo

### ***En Archivo:*** 

El archivo de salida contiene:

- Fecha y hora del análisis
- Total de procesos detectados
- Lista completa de procesos

Procesos sospechosos con:

- Razón de clasificación
- Nivel de riesgo asignado

Ejemplo:

    Fecha: Tue Feb 10 22:26:16 2026
    Total procesos: 269
    0 | System Idle Process | Memoria: 8 KB
     | Riesgo: Bajo | Razon: Normal
    4 | System | Memoria: 2 | Riesgo: Bajo | Razon: Normal
    92 | Secure System | Memoria: 39 | Riesgo: Bajo | Razon: Normal
    136 | Registry | Memoria: 25 | Riesgo: Bajo | Razon: Normal
    18784 | cmd.exe | Memoria: 4 | Riesgo: Alto | Razon: Proceso de consola potencialmente usado para comandos maliciosos
    5304 | tasklist.exe | Memoria: 11 | Riesgo: Bajo | Razon: Normal
  
## Referencias 

Investigaciones para realizar este programa basadas en:
- [Documentación del comando tasklist de Windows](https://learn-microsoft-com.translate.goog/en-us/windows-server/administration/windows-commands/tasklist?_x_tr_sl=en&_x_tr_tl=es&_x_tr_hl=es&_x_tr_pto=tc).

- [popen() en C/C++](https://learn.microsoft.com/es-es/cpp/c-runtime-library/reference/popen-wpopen?view=msvc-170).
- Conceptos de monitoreo de procesos en sistemas operativos
