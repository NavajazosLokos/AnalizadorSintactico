Analizador Sintáctico con Pila de Objetos
Descripción

Este proyecto implementa un analizador sintáctico LR(1) para gramáticas sencillas, utilizando una pila de objetos en lugar de enteros, lo que permite mostrar los símbolos y estados de forma más clara.

El programa está diseñado para analizar cadenas como "a+b+c" con la gramática recursiva:

E → id + E | id


La pila contiene tres tipos de objetos:

Estado: representa el estado actual del analizador.

Terminal: representa un símbolo terminal (identificador, operador).

NoTerminal: representa un símbolo no terminal (como E).

El analizador realiza desplazamientos (shift) y reducciones (reduce) según la tabla LR(1) definida.

Archivos del proyecto

principal.cpp: Programa principal, contiene el ejemplo recursivo con la cadena "a+b+c" y el bucle iterativo LR(1).

lexico.h / lexico.cpp: Analizador léxico que reconoce identificadores, operadores y el símbolo de fin de cadena.

pila.h / pila.cpp: Implementación de una pila de objetos ElementoPila con métodos push, pop, top y muestra.

ElementoPila.h: Clase base abstracta para los elementos de la pila.

Estado.h / Estado.cpp: Clase que representa los estados del autómata.

Terminal.h / Terminal.cpp: Clase que representa símbolos terminales.

NoTerminal.h / NoTerminal.cpp: Clase que representa símbolos no terminales.

Compilación

Se recomienda compilar todos los archivos juntos. Por ejemplo, usando g++:

g++ -g principal.cpp pila.cpp lexico.cpp Estado.cpp Terminal.cpp NoTerminal.cpp -o analizador.exe


Luego ejecuta el programa:

./analizador.exe

Uso

El programa actualmente analiza la cadena "a+b+c". La salida muestra:

El contenido de la pila en cada paso.

La entrada actual del analizador.

La acción tomada (desplazamiento o reducción).

Mensaje final de aceptación o error.

Ejemplo de salida:

Pila: [Estado(0)]
entrada: a  accion: 2
Pila: [Estado(0)] [Terminal(a)] [Estado(2)]
entrada: +  accion: 3
...
Cadena aceptada!

Modificaciones

Se pueden cambiar las cadenas de entrada modificando el argumento en ejemploRecursivo("...").

Para analizar otras gramáticas, actualiza tablaLR, idReglas y lonReglas según la gramática correspondiente.

El proyecto está preparado para manejar gramáticas con recursión por la izquierda.

Notas

Se utiliza casting dinámico (dynamic_cast) para identificar el tipo de objeto en la pila al momento de obtener el estado superior.

Los terminales y no terminales se imprimen gracias al método mostrar() implementado en cada clase derivada de ElementoPila.
