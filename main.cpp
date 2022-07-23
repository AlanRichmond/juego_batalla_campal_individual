#include "main.h"
#include "movimiento.h"
#include "posiciones.h"
#include "archivos.h"
#include <iostream>

using namespace std;

void iniciaJuego(Jugador*jugador1,Jugador*jugador2,Tablero*tablero,Tablero*tablero2,Casilla*posicion,string archivoJugador1,string archivoJugador2){
    inicializarTablero(tablero);
    inicializarTablero(tablero2);
    jugador1->soldados  = NUMERO_SOLDADOS;
    jugador1->jugadorNumero = PRIMER_JUGADOR;
    jugador2->soldados =  NUMERO_SOLDADOS;
    jugador2->jugadorNumero = SEGUNDO_JUGADOR;
	posicionarSoldados(jugador1->jugadorNumero, jugador1, tablero, posicion);
    posicionarSoldados(jugador2->jugadorNumero, jugador2, tablero2, posicion);
    escribirArchivo(jugador1->jugadorNumero,archivoJugador1, jugador1,jugador2, tablero);
    escribirArchivo(jugador2->jugadorNumero,archivoJugador2, jugador2,jugador1, tablero2);
}

void juegoEnAccion(Jugador*jugador1,Jugador*jugador2,Tablero*tablero,Tablero*tablero2,Casilla*posicion,string archivoJugador1,string archivoJugador2){
	bool jugando = true;
	char movimiento;
	while(jugando == true){
		while(jugador1->soldados != 0 && jugador2->soldados != 0){
	    	for(int turno = 1; turno <= NUMERO_JUGADORES; turno++){
	    		if((turno == 1) && jugador1->soldados != 0 && jugador2->soldados != 0){
	    			jugadaDeJugador(1, jugador1, jugador2, tablero, posicion, tablero2);
	    			int numeroSoldado = soldadoElegido();
	    			int valor = numeroSoldado;
	                pedirMovimiento(&movimiento, valor);
	                movimientoDelSoldado(jugador2->jugadorNumero,valor, movimiento, jugador1, jugador2, tablero,tablero2, posicion);
	                escribirArchivo(jugador1->jugadorNumero, archivoJugador1, jugador1,jugador2, tablero);
	    		}
	   	    	else if(jugador1->soldados != 0 && jugador2->soldados != 0) {
	   	    		jugadaDeJugador(2, jugador1, jugador2, tablero, posicion, tablero2);
	   	    		int numeroSoldado = soldadoElegido();
 		            int valor = numeroSoldado;
	   	            pedirMovimiento(&movimiento, valor);
	   	            movimientoDelSoldado(jugador1->jugadorNumero,valor, movimiento, jugador2,jugador1, tablero2,tablero, posicion);
	   	            escribirArchivo(jugador2->jugadorNumero,archivoJugador2, jugador2,jugador1, tablero2);

	   	    	}
	    	    asignarSoldados(jugador1, tablero, jugador1->jugadorNumero);
        	    asignarSoldados(jugador2, tablero2, jugador2->jugadorNumero);
        	    cout<<"------------------------------------"<<endl<<endl;
        	    if(turno == 1){
        	    	cout<<endl<<endl<<endl<<endl<<endl;
        	    	cout<<"---------------------------"<<endl;
        	    	mostrarTablero(tablero2);
        	    	cout<<endl<<endl<<endl<<endl<<endl;
        	    	cout<<"---------------------------"<<endl;
        	    }
        	    else{
        	    	cout<<endl<<endl<<endl<<endl<<endl;
        	    	cout<<"---------------------------"<<endl;
        	    	mostrarTablero(tablero);
        	    	cout<<endl<<endl<<endl<<endl<<endl;
        	    	cout<<"---------------------------"<<endl;
        	    }
	        }
	    }
	    if(jugador1->soldados == 0){
	    	cout<<"El ganador es el jugador 2!!";
	        jugando = false;
	    }
	    else{
	    	cout<<"el ganador es el jugador 1!!";
	    	jugando = false;
	    }
	}
}

int main() {
    Tablero*tablero = new Tablero;
    Tablero*tablero2 = new Tablero;
    Casilla*posicion = new Casilla;
    Jugador*jugador1 = new Jugador;
    Jugador*jugador2 = new Jugador;
    string archivoJugador1 = "archivos/tableroJugador1.txt";
    string archivoJugador2 = "archivos/tableroJugador2.txt";

    iniciaJuego(jugador1,jugador2,tablero,tablero2,posicion, archivoJugador1, archivoJugador2);
    juegoEnAccion(jugador1,jugador2,tablero,tablero2, posicion, archivoJugador1, archivoJugador2);
    delete[]tablero;
	delete[]tablero2;
	delete[]posicion;
	delete[]jugador1;
	delete[]jugador2;
	return 0;
}

