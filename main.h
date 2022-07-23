#ifndef MAIN_H_
#define MAIN_H_

const int TABLERO_COMPLETO = 10;
const int NUMERO_JUGADORES = 2;
const int NUMERO_SOLDADOS = 3;
const char VACIO = '-';
const char ARRIBA = 'W';
const char ABAJO = 'S';
const char DERECHA = 'D';
const char IZQUIERDA = 'A';
const char DIAGONAL = 'L';
const int PRIMER_JUGADOR = 1;
const int SEGUNDO_JUGADOR = 2;
const int PRIMER_SOLDADO = 0;
const int SEGUNDO_SOLDADO = 1;
const int TERCER_SOLDADO = 2;
const int CASILLA_INACTIVA = 'X';

struct Casilla{
    char contenido;
    int fila;
    int col;
};

struct Tablero{
    Casilla***tablero;
};

struct Soldado{
    int fila;
    int col;
};

struct Jugador{
    int jugadorNumero;
    int soldados;
    Soldado soldadosPos[NUMERO_SOLDADOS];
};

//pre: Recibe los dos jugadores y el tablero.
//post: Deja al juego en un estado para poder empezar a jugar.
void iniciaJuego(Jugador * jugador1, Jugador * jugador2, Tablero * tablero,Tablero*tablero2, Casilla * posicion);

//pre:  Recibe a los jugadores con sus soldados ya en el tablero colocados.
//post: Inicia el juego, pidiendole al jugador donde atacar y si quiere moverse, cuando uno de los dos jugadores
//      se queda sin soldados pierda y el juego termina.
void juegoEnAccion(Jugador * jugador1, Jugador * jugador2, Tablero * tablero, Tablero* tablero2 , Casilla * posicion);

#endif
