#include "main.h"
#ifndef MOVIMIENTO_H_
#define MOVIMIENTO_H_

//post: Se encarga de mostrar los movimientos que puede hacer el jugador
void cargarOpcionesDeMovimiento();


//pre: Recibe el soldado que se quiere mover, el tablero con los soldados y las CASILLAS_INACTIVAS.
//post: Si el soldado no esta en el maximo del tablero, se podra mover.
//      Si el soldado al moverse se choca con un soldado enemigo, se le restara un soldado a cada uno, y en esa posicion
//      se pondra una CASILLA_INACTIVA.
void moverArriba(int jugadorContrario, Soldado *jugador,Jugador*jugador1, Jugador *enemigo, Tablero * tablero,Tablero * tablero2, Casilla * posicion);


//pre: Recibe el soldado que se quiere mover, el tablero con los soldados y las CASILLAS_INACTIVAS.
//post: Si el soldado no esta en el maximo del tablero, se podra mover.
//      Si el soldado al moverse se choca con un soldado enemigo, se le restara un soldado a cada uno, y en esa posicion
//      se pondra una CASILLA_INACTIVA.
void moverAbajo(int jugadorContrario, Soldado *jugador,Jugador*jugador1, Jugador *enemigo, Tablero * tablero,Tablero * tablero2, Casilla * posicion);


//pre: Recibe el soldado que se quiere mover, el tablero con los soldados y las CASILLAS_INACTIVAS.
//post: Si el soldado no esta en el maximo del tablero, se podra mover.
//      Si el soldado al moverse se choca con un soldado enemigo, se le restara un soldado a cada uno, y en esa posicion
//      se pondra una CASILLA_INACTIVA.
void moverIzquierda(int jugadorContrario, Soldado *jugador,Jugador*jugador1, Jugador *enemigo, Tablero * tablero,Tablero * tablero2, Casilla * posicion);


//pre: Recibe el soldado que se quiere mover, el tablero con los soldados y las CASILLAS_INACTIVAS.
//post: Si el soldado no esta en el maximo del tablero, se podra mover.
//      Si el soldado al moverse se choca con un soldado enemigo, se le restara un soldado a cada uno, y en esa posicion
//      se pondra una CASILLA_INACTIVA.
void moverDerecha(int jugadorContrario, Soldado *jugador,Jugador*jugador1, Jugador *enemigo, Tablero * tablero,Tablero * tablero2, Casilla * posicion);


//pre: Recibe el soldado que se quiere mover, el tablero con los soldados y las CASILLAS_INACTIVAS.
//post: Si el soldado no esta en el maximo del tablero, se podra mover.
//      Si el soldado al moverse se choca con un soldado enemigo, se le restara un soldado a cada uno, y en esa posicion
//      se pondra una CASILLA_INACTIVA.
void moverDiagonal(int jugadorContrario, Soldado *jugador,Jugador*jugador1, Jugador *enemigo, Tablero * tablero,Tablero * tablero2, Casilla * posicion);


//pre: Recibe el movimiento que hizo el jugador, el tablero con todos los soldados.
//post: Dependiendo el movimiento que realizo el jugador se movera el soldado.
void moverSoldados(int jugadorContrario,char movimiento, Soldado *jugador1, Jugador *jugador, Jugador*enemigo, Tablero * tablero,Tablero * tablero2, Casilla * posicion);


//pre: Recibe el soldado que se quiere mover, el tablero con todos los soldados.
//post: Movera el soldado que se ingreso.
void movimientoDelSoldado(int jugadorContrario,int soldadoElegido, char movimiento, Jugador *jugador, Jugador*enemigo, Tablero *tablero,Tablero*tablero2, Casilla *posicion);


//pre: Recibe un movimiento tipo caracter
//post: Devolvera verdadero si el movimiento es ARRIBA,ABAJO,DERECHA,IZQUIERDA,DIAGONAL.
//      de lo contrario devolvera falso.
bool movimientoValido(char movimiento);


//pre: Recibe un caracter ingresado por el jugador
//post: Devolvera el mismo caracter pero cuando el caracter ingresado sea valido.
void pedirMovimiento(char *movimiento,int valor);


//post: MUESTRA QUE NUMERO INGRESAR SI SE QUIERE O NO MOVER UN SOLDADO.
void opcionesSoldados();


//post: Pedira al jugador un soldado para mover.
int soldadoElegido();


#endif
