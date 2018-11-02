# ICALib
## Libreria para la asignatura de Microprocesadores.
### Utilizada en el examen de Microprocesadores de 2018. Consegui un
### 10 sin muchas complicaciones. Tambien la use para el proyecto final.
### Parece complicada, pero es bastante sencilla una vez le pillas el
### truco parece facil.

-Chuletario: Un breve fichero txt con un resumen muy breve del temario.

-ICALib.c : Es la propia libreria.

    - configurarPinIn(int address, int port) : Configura un pin como
    entrada. El puerto es 1 para el A, 2 para B y 3 para C.
    
    - configurarPinOut(int address, int port) : Lo mismo pero para configurarlo
    como salida.
    
    -configurarTMR1(uint16_t esperams) configurarTMR1(uint16_t esperams): Introduce
    una espera en milisegundos en el timer 1 0 2.
    
-UART1.c : Libreria para las comunicaciones bluetooth.
