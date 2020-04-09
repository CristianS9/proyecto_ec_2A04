/*---------------------------------------------------------------------------------
Este código se ha implementado basándose en el ejemplo "Simple sprite demo" de 
dovoto y otro de Jaeden Amero
---------------------------------------------------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>       	// time 

#include "fondos.h"
#include "sprites.h"
#include "defines.h"
#include "rutserv.h"
#include "teclado.h"
#include "temporizadores.h"

//-----------------------------------------------------
// Variables globales
//-----------------------------------------------------

int seg=0;
int tseg=0;
int estado;
int TactilTocada();//no esta en defines aun
//extern int segs;


int main() {
	

	// Variables del main
	touchPosition pos_pantalla;

	//  Poner en marcha el motor gráfico 2D.
    	powerOn(POWER_ALL_2D);

     	// Establecer la pantalla inferior como principal, inicializar el sistema gráfico
     	// y configurar el sistema de fondos.
    	lcdMainOnBottom();
    	initVideo();
    	initFondos();

    	// Mostrar fondos en pantalla. 
   // 	MostrarPuerta();

	// Inicializar memoria de sprites y guardar en ella los sprites 
	initSpriteMem();
	guardarSpritesEnMemoria();

	// Establecer las paletas para los sprites 
	establecerPaletaPrincipal();

	// Para poder imprimir en pantalla (hacer trazas) 
	consoleDemoInit();
	
 	// Para inicializar el generador de números aleatorios en función de una semilla,
	// en este caso time(NULL). 
	// srand() sólo se suele activar una vez por ejecución y no devuelve ningún valor 
	srand (time(NULL));
	
//	int tecla;  
    
// ...
	MostrarRombo(1,8,8);
//	MostrarPuertaAbierta();
	
	interrupciones();
	
	
	estado=ESPERA;
	while(1)
	{	
		if(estado==ESPERA){
			switch(TeclaPulsada()){
				case A:
					iprintf("\x1b[04;00H                A               ");	
					break;	
				case B:
					iprintf("\x1b[04;00H                B               ");	
					break;	
				case SELECT:
					iprintf("\x1b[04;00H              SELECT            ");	
					break;	
//				case START:
//					iprintf("\x1b[04;00H                                ");	
//					MostrarPuerta();
//					estado=CERRADA;
//					//segs=0;
//					break;	
				case DCHA:
					iprintf("\x1b[04;00H               DCHA             ");	
					break;	
				case IZDA:
					iprintf("\x1b[04;00H               IZDA             ");	
					break;	
				case ARRIBA:
					iprintf("\x1b[04;00H              ARRIBA            ");	
					break;	
				case ABAJO:
					iprintf("\x1b[04;00H               ABAJO            ");	
					break;	
				case L:
					iprintf("\x1b[04;00H                 L              ");
					break;	
				case R:
					iprintf("\x1b[04;00H                 RRR              ");
					break;	
				default:
					break;
			}

		}
	}
} 
TactilTocada(){
	int r=0;
	touchPosition p_pan;
	touchRead(&p_pan);
	if(p_pan.px!=0 || p_pan.py!=0){
		r=1;	
	}
	return r;
}

