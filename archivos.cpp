#include "main.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void escribirArchivo(int numeroJugador,string archivoJugador, Jugador * jugador, Jugador *enemigo, Tablero * tablero){
	ofstream salida;
	salida.open(archivoJugador.c_str());
	if(tablero->tablero[jugador->soldadosPos[0].fila -1][jugador->soldadosPos[0].col -1]->contenido != CASILLA_INACTIVA){
		salida<<"SOLDADO 0: "<<endl;
		salida<<"FILA "<<jugador->soldadosPos[0].fila<<"COL: "<<jugador->soldadosPos[0].col<<endl;
	}
	if(tablero->tablero[jugador->soldadosPos[1].fila -1][jugador->soldadosPos[1].col -1]->contenido != CASILLA_INACTIVA){
		salida<<"SOLDADO 1: "<<endl;
		salida<<"FILA "<<jugador->soldadosPos[1].fila<<"COL: "<<jugador->soldadosPos[1].col<<endl;
	}
	if(tablero->tablero[jugador->soldadosPos[2].fila -1][jugador->soldadosPos[2].col -1]->contenido != CASILLA_INACTIVA){
		salida<<"SOLDADO 2: "<<endl;
		salida<<"FILA "<<jugador->soldadosPos[2].fila<<"COL: "<<jugador->soldadosPos[2].col<<endl;
	}

    for(int i = 0; i < TABLERO_COMPLETO; i++){
   	    salida << i + 1 << " ";
        for(int j = 0; j < TABLERO_COMPLETO; j++){
        salida << tablero->tablero[i][j]->contenido << " ";
        }
        salida << " " << endl;
    }
	salida.close();
}



