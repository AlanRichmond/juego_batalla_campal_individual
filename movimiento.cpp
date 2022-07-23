#include "main.h"
#include "movimiento.h"
#include <iostream>

using namespace std;

void cargarOpcionesDeMovimiento(){
	cout <<"Ingrese " <<ARRIBA<< " si quiere que el soldado se mueva una casilla arriba"<< endl;
	cout<<"Ingrese "<<ABAJO<<" si quiere que el soldado se mueva una casilla para abajo"<< endl;
	cout<<"Ingrese "<<DERECHA<<" si quiere que el soldado se mueva una casilla para la derecha"<<endl;
	cout<<"Ingrese "<<IZQUIERDA<< " si quiere que el soldado se mueva una casilla para la izquierda"<<endl;
	cout<<"Ingrese "<<DIAGONAL<<" si se quiere mover en diagonal"<<endl;
}

void moverArriba(int jugadorContrario, Soldado *jugador,Jugador*jugador1, Jugador *enemigo, Tablero * tablero,Tablero * tablero2, Casilla * posicion){
   	if(jugador->fila > 1 &&  tablero->tablero[jugador->fila - 1][jugador->col - 1]->contenido != CASILLA_INACTIVA){
   		jugador->fila--;
   		if(tablero->tablero[jugador->fila - 1][jugador->col - 1]->contenido == CASILLA_INACTIVA){
   			jugador->fila++;
  		}
   		if(tablero2->tablero[jugador->fila - 1][jugador->col - 1]->contenido == jugadorContrario+'0' ){
   			tablero->tablero[jugador->fila - 1][jugador->col - 1]->contenido = CASILLA_INACTIVA;
   			tablero2->tablero[jugador->fila - 1][jugador->col - 1]->contenido = CASILLA_INACTIVA;
   			jugador1->soldados--;
   			enemigo->soldados--;
   			cout<<"AL JUGADOR 1 LE QUEDAN "<<jugador1->soldados<<" SOLDADOS"<<endl;
   			cout<<"AL JUGADOR 2 LE QUEDAN "<<enemigo->soldados<<" SOLDADOS"<<endl;
   		}
   	}
}

void moverAbajo(int jugadorContrario, Soldado *jugador,Jugador*jugador1, Jugador *enemigo, Tablero * tablero,Tablero * tablero2, Casilla * posicion){
   	if(jugador->fila < 10 && tablero->tablero[jugador->fila - 1][jugador->col - 1]->contenido != CASILLA_INACTIVA){
   		jugador->fila++;
   		if(tablero->tablero[jugador->fila - 1][jugador->col - 1]->contenido == CASILLA_INACTIVA){
   			jugador->fila--;
   		}
   		if(tablero2->tablero[jugador->fila - 1][jugador->col - 1]->contenido == jugadorContrario+'0'){
   			tablero->tablero[jugador->fila - 1][jugador->col - 1]->contenido = CASILLA_INACTIVA;
   			tablero2->tablero[jugador->fila - 1][jugador->col - 1]->contenido = CASILLA_INACTIVA;
   			jugador1->soldados--;
   			enemigo->soldados--;
   			cout<<"AL JUGADOR 1 LE QUEDAN "<<jugador1->soldados<<" SOLDADOS"<<endl;
   			cout<<"AL JUGADOR 2 LE QUEDAN "<<enemigo->soldados<<" SOLDADOS"<<endl;
   		}

   	}
}

void moverIzquierda(int jugadorContrario, Soldado *jugador,Jugador*jugador1, Jugador *enemigo, Tablero * tablero,Tablero * tablero2, Casilla * posicion){
	if(jugador->col > 1 && tablero->tablero[jugador->fila - 1][jugador->col - 1]->contenido != CASILLA_INACTIVA){
		jugador->col--;
		if(tablero->tablero[jugador->fila - 1][jugador->col - 1]->contenido == CASILLA_INACTIVA){
			jugador->col++;
		}
   		if(tablero2->tablero[jugador->fila - 1][jugador->col - 1]->contenido == jugadorContrario+'0'){
   			tablero->tablero[jugador->fila - 1][jugador->col - 1]->contenido = CASILLA_INACTIVA;
   			tablero2->tablero[jugador->fila - 1][jugador->col - 1]->contenido = CASILLA_INACTIVA;
   			jugador1->soldados--;
   			enemigo->soldados--;
   			cout<<"AL JUGADOR 1 LE QUEDAN "<<jugador1->soldados<<" SOLDADOS"<<endl;
   			cout<<"AL JUGADOR 2 LE QUEDAN "<<enemigo->soldados<<" SOLDADOS"<<endl;
   		}
	}
}

void moverDerecha(int jugadorContrario, Soldado *jugador,Jugador*jugador1, Jugador *enemigo, Tablero * tablero,Tablero * tablero2, Casilla * posicion){
	if(jugador->col < 10 && tablero->tablero[jugador->fila - 1][jugador->col - 1]->contenido != CASILLA_INACTIVA){
		jugador->col++;
		if(tablero->tablero[jugador->fila - 1][jugador->col - 1]->contenido == CASILLA_INACTIVA){
			jugador->col--;
		}
   		if(tablero2->tablero[jugador->fila - 1][jugador->col - 1]->contenido == jugadorContrario+'0'){
   			tablero->tablero[jugador->fila - 1][jugador->col - 1]->contenido = CASILLA_INACTIVA;
   			tablero2->tablero[jugador->fila - 1][jugador->col - 1]->contenido = CASILLA_INACTIVA;
   			jugador1->soldados--;
   			enemigo->soldados--;
   			cout<<"AL JUGADOR 1 LE QUEDAN "<<jugador1->soldados<<" SOLDADOS"<<endl;
   			cout<<"AL JUGADOR 2 LE QUEDAN "<<enemigo->soldados<<" SOLDADOS"<<endl;
   		}
	}
}

void moverDiagonal(int jugadorContrario, Soldado *jugador,Jugador*jugador1, Jugador *enemigo, Tablero * tablero,Tablero * tablero2, Casilla * posicion){
	char primerMovimiento;
	cout<<"PRIMERO INGRESE HACIA DONDE QUIERE MOVERSE, ARRIBA ABAJO DERECHA IZQUIERDA";
    cin>>primerMovimiento;
    if(primerMovimiento == ARRIBA){
    	moverArriba(jugadorContrario,jugador,jugador1, enemigo, tablero,tablero2, posicion);
		char segundoMovimiento;
	    cout<<"AHORA INGRESE HACIA DONDE MOVERSE, DERECHA IZQUIERDA";
	    cin>>segundoMovimiento;
	    if(segundoMovimiento == IZQUIERDA){
	    	moverIzquierda(jugadorContrario,jugador,jugador1, enemigo, tablero,tablero2,posicion);
	    }
	    else{
	    	moverDerecha(jugadorContrario,jugador,jugador1, enemigo, tablero,tablero2, posicion);
	    }
    }
    else if(primerMovimiento == ABAJO){
    	moverAbajo(jugadorContrario,jugador,jugador1, enemigo, tablero,tablero2, posicion);
    	char segundoMovimiento;
        cout<<"AHORA INGRESE HACIA DONDE MOVERSE, DERECHA IZQUIERDA";
        cin>>segundoMovimiento;
	    if(segundoMovimiento == IZQUIERDA){
	    	moverIzquierda(jugadorContrario,jugador,jugador1, enemigo, tablero,tablero2, posicion);
	    }
	    else{
	    	moverDerecha(jugadorContrario,jugador,jugador1, enemigo, tablero,tablero2, posicion);
        }
    }
    else if(primerMovimiento == DERECHA){
    	moverDerecha(jugadorContrario,jugador,jugador1, enemigo, tablero,tablero2, posicion);
    	char segundoMovimiento;
    	cout<<"AHORA INGRESE HACIA DONDE MOVERSE, ARRIBA ABAJO";
    	cin>>segundoMovimiento;
    	if(segundoMovimiento == ARRIBA){
    	    moverArriba(jugadorContrario,jugador,jugador1, enemigo, tablero, tablero2,posicion);
        }
        else{
    	    moverAbajo(jugadorContrario,jugador,jugador1, enemigo, tablero, tablero2,posicion);
        }
    }
    else if(primerMovimiento == IZQUIERDA){
    	moverIzquierda(jugadorContrario,jugador,jugador1, enemigo, tablero, tablero2,posicion);
    	char segundoMovimiento;
    	cout<<"AHORA INGRESE HACIA DONDE MOVERSE, ARRIBA ABAJO";
    	cin>>segundoMovimiento;
    	if(segundoMovimiento == ARRIBA){
    	    moverArriba(jugadorContrario,jugador,jugador1, enemigo, tablero,tablero2, posicion);
        }
        else{
    	    moverAbajo(jugadorContrario,jugador,jugador1, enemigo, tablero, tablero2,posicion);
        }
    }
}

void moverSoldados(int jugadorContrario,char movimiento, Soldado *jugador1, Jugador *jugador, Jugador*enemigo, Tablero * tablero,Tablero*tablero2, Casilla * posicion){
	if(movimiento == ARRIBA){
		moverArriba(jugadorContrario,jugador1,jugador, enemigo, tablero,tablero2, posicion);
	}
	else if(movimiento == ABAJO){
		moverAbajo(jugadorContrario,jugador1,jugador, enemigo, tablero,tablero2, posicion);
	}
	else if(movimiento == DERECHA){
		moverDerecha(jugadorContrario,jugador1,jugador, enemigo, tablero,tablero2, posicion);
	}
	else if(movimiento == IZQUIERDA){
		moverIzquierda(jugadorContrario,jugador1,jugador,enemigo, tablero,tablero2, posicion);
	}
	else if(movimiento == DIAGONAL){
	    moverDiagonal(jugadorContrario,jugador1,jugador,enemigo, tablero,tablero2, posicion);
	}
}

void movimientoDelSoldado(int jugadorContrario,int soldadoElegido,char movimiento,Jugador*jugador,Jugador*enemigo,Tablero*tablero,Tablero*tablero2,Casilla*posicion){
	if(soldadoElegido == PRIMER_SOLDADO){
		moverSoldados(jugadorContrario, movimiento, &jugador->soldadosPos[PRIMER_SOLDADO],jugador, enemigo, tablero,tablero2, posicion);
	}
	else if(soldadoElegido == SEGUNDO_SOLDADO){
		moverSoldados(jugadorContrario, movimiento, &jugador->soldadosPos[SEGUNDO_SOLDADO],jugador, enemigo,tablero,tablero2, posicion);
	}
	else if(soldadoElegido == TERCER_SOLDADO){
		moverSoldados(jugadorContrario, movimiento, &jugador->soldadosPos[TERCER_SOLDADO],jugador, enemigo,tablero,tablero2, posicion);
	}
}

bool movimientoValido(char movimiento){
	return ((movimiento == ARRIBA) || (movimiento == ABAJO) || (movimiento == DERECHA)
			|| (movimiento == IZQUIERDA) || (movimiento == DIAGONAL));

}

void pedirMovimiento(char *movimiento,int valor){
	if(valor == 0 || valor == 1 || valor == 2){
		cargarOpcionesDeMovimiento();
    	cin>>movimiento;
	    while(movimientoValido(*movimiento) == false){
	    	cout<<"EL MOVIMIENTO NO ES VALIDO, INGRESE OTRO POR FAVOR"<<endl;
		    cargarOpcionesDeMovimiento();
		    cin>>movimiento;
	    }
	}
}

void opcionesSoldados(){
	cout<<"QUE SOLDADO QUIERE MOVER?"<<endl;
	cout<<"SI QUIERE MOVER SU PRIMER SOLDADO INGRESE 0"<<endl;
	cout<<"SI QUIERE MOVER SU SEGUNDO SOLDADO INGRESE 1"<<endl;
	cout<<"SI QUIERE MOVER SU TERCER SOLDADO INGRESE 2"<<endl;
	cout<<"SI NO QUIERE MOVER SU SOLDADO INGRESE CUALQUIER OTRO NUMERO"<<endl;
	cout<<"NUMERO: ";
}

int soldadoElegido(){
	int soldado;
	opcionesSoldados();
	cin>>soldado;
	return soldado;
}

