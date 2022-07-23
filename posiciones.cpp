#include "main.h"
#include <iostream>

using namespace std;

void inicializarTablero(Tablero * tablero){
    tablero->tablero = new  Casilla**[TABLERO_COMPLETO];
    for(int i =0; i < TABLERO_COMPLETO; i++){
        tablero->tablero[i] = new Casilla*[TABLERO_COMPLETO];
        for(int j = 0; j < TABLERO_COMPLETO; j++){
            tablero->tablero[i][j] = new Casilla;
            tablero->tablero[i][j]->contenido = VACIO;
        }
    }
}

void mostrarTablero(Tablero * tablero){
    for(int i = 0; i < TABLERO_COMPLETO; i++){
    	cout << i + 1 << " ";
        for(int j = 0; j < TABLERO_COMPLETO; j++){
            cout << tablero->tablero[i][j]->contenido << " ";
        }
        cout << " " << endl;
   }
}

bool posicionValida(int posicion){
	if(posicion > 0 && posicion < 11){
		return true;
	}
	return false;
}


void filaValidaEnTablero(Casilla * posicion){
    while(posicionValida(posicion->fila) == false ){
    	cout<< "No es valida esa posicion, ingrese una nuevamente"<< endl << "FILA: ";
    	cin>> posicion->fila;
    	}
}

void colValidaEnTablero(Casilla * posicion){
	while(posicionValida(posicion->col) == false){
		cout<< "No es valida esa posicion, ingrese una nuevamente"<< endl << "COL: ";
		cin>> posicion->col;
	}
}

void posicionarSoldados(int jugadorTurno, Jugador * jugador, Tablero * tablero, Casilla * posicion){
    cout << "JUGADOR: " << jugadorTurno << endl;
    for(int soldados = 0; soldados < NUMERO_SOLDADOS; soldados++){
        cout << "Escribe donde desea posicionar su soldado "<< soldados <<": "<<endl;
        cout << "FILA: ";
        cin >> posicion->fila;
        filaValidaEnTablero(posicion);
        cout << "COL: ";
        cin >> posicion->col;
        colValidaEnTablero(posicion);
        if(tablero->tablero[posicion->fila - 1][posicion->col - 1]->contenido == VACIO){
            tablero->tablero[posicion->fila - 1][posicion->col - 1]->contenido = jugadorTurno+'0';

            jugador->soldadosPos[soldados].fila = posicion->fila;
            jugador->soldadosPos[soldados].col = posicion->col;

            cout << "Posicion del soldado "<< soldados << endl;
            cout << "FILA: " << jugador->soldadosPos[soldados].fila << "| COL: " << jugador->soldadosPos[soldados].col << endl;
        }
        else{
            cout << "Posicion ya ocupada." << endl;
            soldados--;
        }
    }
	cout<<endl<<endl<<endl<<endl<<endl;
	cout<<"---------------------------"<<endl;
    mostrarTablero(tablero);
	cout<<endl<<endl<<endl<<endl<<endl;
	cout<<"---------------------------"<<endl;
}

void jugadaDeJugador(int jugador,Jugador*jugador1,Jugador*jugador2,Tablero*tablero, Casilla * posicion, Tablero*tablero2){
    cout << "JUGADOR: " << jugador << endl;
    cout << "Escribe la posicion donde desea atacar: "<<endl;
    cout << "FILA: ";
    cin >> posicion->fila;
    filaValidaEnTablero(posicion);
    cout << "COL: ";
    cin >> posicion->col;
    colValidaEnTablero(posicion);
    if(jugador == PRIMER_JUGADOR){
    	if(tablero2->tablero[posicion->fila - 1][posicion->col - 1]->contenido != VACIO &&
    	    	      tablero2->tablero[posicion->fila - 1][posicion->col - 1]->contenido != PRIMER_JUGADOR+'0'){
    		tablero2->tablero[posicion->fila - 1][posicion->col - 1]->contenido = CASILLA_INACTIVA;
    		tablero->tablero[posicion->fila - 1][posicion->col - 1]->contenido = CASILLA_INACTIVA;

            jugador2->soldados--;
            cout<<endl<<endl<<endl<<endl<<endl;
            cout << "Soldados restantes Jugador2: " << jugador2->soldados <<endl;
            cout << "Has eliminado una posicion enemiga."<<endl;
            cout<<endl;
            mostrarTablero(tablero);
    	}
    }
    else if(jugador == SEGUNDO_JUGADOR){
    	if(tablero->tablero[posicion->fila - 1][posicion->col - 1]->contenido != VACIO &&
    	    	      tablero->tablero[posicion->fila - 1][posicion->col - 1]->contenido != SEGUNDO_JUGADOR+'0'){
    		tablero2->tablero[posicion->fila - 1][posicion->col - 1]->contenido = CASILLA_INACTIVA;
    		tablero->tablero[posicion->fila - 1][posicion->col - 1]->contenido = CASILLA_INACTIVA;

            jugador1->soldados--;
            cout<<endl<<endl<<endl<<endl<<endl;
            cout << "Soldados restantes Jugador1: " << jugador1->soldados <<endl;
            cout << "Has eliminado una posicion enemiga."<<endl;
         	cout<<endl;
         	mostrarTablero(tablero);
    	}
    }
}

void asignarSoldados(Jugador *jugador1, Tablero* tablero,int jugador){
	if(tablero->tablero[jugador1->soldadosPos[PRIMER_SOLDADO].fila - 1][jugador1->soldadosPos[PRIMER_SOLDADO].col - 1]->contenido != CASILLA_INACTIVA){
		tablero->tablero[jugador1->soldadosPos[PRIMER_SOLDADO].fila - 1][jugador1->soldadosPos[PRIMER_SOLDADO].col - 1]->contenido = jugador+'0';
	}
	if(tablero->tablero[jugador1->soldadosPos[SEGUNDO_SOLDADO].fila - 1][jugador1->soldadosPos[SEGUNDO_SOLDADO].col - 1]->contenido != CASILLA_INACTIVA){
		tablero->tablero[jugador1->soldadosPos[SEGUNDO_SOLDADO].fila - 1][jugador1->soldadosPos[SEGUNDO_SOLDADO].col - 1]->contenido = jugador+'0';
	}
	if(tablero->tablero[jugador1->soldadosPos[TERCER_SOLDADO].fila - 1][jugador1->soldadosPos[TERCER_SOLDADO].col - 1]->contenido != CASILLA_INACTIVA){
		tablero->tablero[jugador1->soldadosPos[TERCER_SOLDADO].fila - 1][jugador1->soldadosPos[TERCER_SOLDADO].col - 1]->contenido = jugador+'0';
	}
}
