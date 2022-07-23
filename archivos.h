#include "main.h"
#ifndef ARCHIVOS_H_
#define ARCHIVOS_H_

#include <string>
#include <fstream>

//pre: Recibe el archivo del jugador que se quiera guardar, con su tablero y su jugador.
//post: Muestra las posiciones del jugador y el tablero actualizado.
void escribirArchivo(int numeroJugador,std::string archivoJugador, Jugador * jugador, Jugador *enemigo, Tablero * tablero);

#endif
