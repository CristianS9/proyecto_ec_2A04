/*-------------------------------------
 temporizadores.c
-------------------------------------*/
// Añadir los includes que sean necesarios
#include "defines.h"
#include "sprites.h"
#include <nds.h>
#include <stdio.h>


// Rutina de atención a la interrupción del temporizador
void IntTemp() {
	static int tic=0;
	tic++;
	if(tic==60){
		tic=0;
		if(estado==CERRADA){
			seg++;
			iprintf("\x1b[04;00H       segundos: %d         ",seg);
		}else if(estado==ABIERTA){
			tseg++;
			if(tseg==3){
				seg=0;
				MostrarPuerta();
				estado=CERRADA;
			}		
		
		}		
	}


}





