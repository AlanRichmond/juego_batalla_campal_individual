#include "main.h"
#ifndef POSICIONES_H_
#define POSICIONES_H_

//pre: recibe un tablero.
//post: Rellena la matriz con caracteres VACIO.
void inicializarTablero(Tablero * tablero);


//pre: recibe un tablero ya relleno.
//post: muestra por pantalla el tablero.
void mostrarTablero(Tablero * tablero);


//pre: Recibe una posicion del tipo int
//post: Devolvera verdadero si la posicion esta en el rango deseable, de lo contrario devolvera false.
bool posicionValida(int posicion);



//pre: Recibe una posicion tipo int.
//post: Si la posicion es incorrecta, volvera a pedir la posicion hasta que el usuario ingrese una posicion deseable
void filaValidaEnTablero(Casilla * posicion);


//pre: Recibe una posicion tipo int.
//post: Si la posicion es incorrecta, volvera a pedir la posicion hasta que el usuario ingrese una posicion deseable
void colValidaEnTablero(Casilla * posicion);


//pre: Recibe el jugador que esta jugando, y un tablero relleno de VACIO y pide una posicion al jugador.
//post: Pondra cada soldado en su respectiva posicion, si se posicionan dos soldados en la misma posicion, se volvera
//      a pedir otra fila y columna.
void posicionarSoldados(int jugadorTurno, Jugador * jugador, Tablero * tablero, Casilla * posicion);


//pre: Recibe el jugador que esta jugando, y el contenido que hay en cada casilla del tablero, por ejemplo si hay un jugador.
//post: Pondra un caracter "CASILLA_INACTIVA" si la posicion que ingreso el jugador, coincide con el enemigo, y restara el sondado al jugador enemigo,
//      en cada  de que no coincida la posicion ingresa con algun soldado enemigo, no hara nada.
void jugadaDeJugador(int jugador, Jugador * jugador1, Jugador * jugador2, Tablero * tablero, Casilla * posicion, Tablero*tablero2);


//pre: Recibe el tablero con los jugadores y las CASILLA_INACTIVAS
//post: Pondra el soldado en su nueva casilla, si en su casilla hay una CASILLA_INACTICA, se dejara la casilla inactiva.
void asignarSoldados(Jugador *jugador1, Tablero* tablero,int jugador);


#endif
