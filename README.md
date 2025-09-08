# 📝 Analizador Sintáctico con Pila de Objetos

---

## 📖 Descripción

Este proyecto implementa un **analizador sintáctico LR(1)** para gramáticas sencillas, utilizando **una pila de objetos** en lugar de enteros.  
Esto permite mostrar los símbolos y estados de forma más clara durante el análisis.  

El programa analiza cadenas como:
a+b+c

usando la gramática recursiva:
E → id + E | id


La pila contiene tres tipos de objetos:

- **Estado**: representa el estado actual del analizador.
- **Terminal**: representa un símbolo terminal (identificador, operador).
- **NoTerminal**: representa un símbolo no terminal (como `E`).

El analizador realiza **desplazamientos (`shift`)** y **reducciones (`reduce`)** según la **tabla LR(1)** definida.

---

## 📂 Archivos del proyecto

- `principal.cpp` → Programa principal, contiene el ejemplo recursivo con la cadena `"a+b+c"`.  
- `lexico.h / lexico.cpp` → Analizador léxico que reconoce identificadores, operadores y fin de cadena.  
- `pila.h / pila.cpp` → Implementación de una pila de objetos `ElementoPila`.  
- `ElementoPila.h` → Clase base abstracta para elementos de la pila.  
- `Estado.h / Estado.cpp` → Clase que representa los estados del autómata.  
- `Terminal.h / Terminal.cpp` → Clase que representa símbolos terminales.  
- `NoTerminal.h / NoTerminal.cpp` → Clase que representa símbolos no terminales.  

---

## 🛠️ Compilación

Se recomienda compilar todos los archivos juntos:

```bash
g++ -g principal.cpp pila.cpp lexico.cpp Estado.cpp Terminal.cpp NoTerminal.cpp -o analizador.exe

Luego ejecutar:
./principal.exe
