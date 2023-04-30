#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int bot, jugador, puntos, rondas, vueltas, prbot, prjugador, pvbot, pvjugador;
//pr= puntos ronda | pv= puntos vueltas
main ()
{
	//1 piedra, 2 papel, 3 tijeras
	for (rondas=0;rondas<5;rondas++)
	{
		for (vueltas=0; vueltas<3; vueltas++)
		{
		//genera un numero aleatorio, correspondiente a los que va a elegir la maquina
			srand(time(NULL));
			bot=rand()%3; 
		//pide que ingrese al jugador que va a elegir
			printf ("\n piedra papel o tijeras?  1 = piedra, 2 = papel y 3 = tijera: ");
			scanf ("%d", &jugador);
		//muestra que "eligio el bot"
		if (bot==1)
		{printf ("\n el bot eligio piedra");}
		if (bot==2)
		{printf ("\n el bot eligio papel");}
		if (bot==3)
		{printf ("\n el bot eligio tijera");}
		//se fija quien gano o si es empate
		//si gano el bot le suma un punto
		if ( (bot==1&&jugador==3) || (bot==2&&jugador==1) || (bot==3&&jugador==2) )	
		{
		printf ("\n gano el bot");
		pvbot++;
		}
		//si gano el jugador le suma un punto
		if ( (bot==3&&jugador==1) || (bot==1&&jugador==2) || (bot==2&&jugador==3) )	
		{
		printf ("\n ganaste");
		pvjugador++;
		}	
		//si empataron ambos suman 1 punto	
		if (bot==jugador)
		{pvbot++;pvjugador++;}
		}
		//le suma un punto en general al que haya ganado mas vueltas
		if (pvbot>pvjugador)
		{prbot++;}
		if (pvbot<pvjugador)
		{prjugador++;}
		//si empataron le suma un punto a los 2
		if (pvbot==pvjugador)
		{prbot++;prjugador++;}
		//resetea las vueltas
		pvbot=0;pvjugador=0;
	}
	//el ganador es quien tenga mas pr (mas rondas ganadas)
	if (prbot>prjugador)
	{printf("\n el ganador del juego es el bot");}	

	if (prbot<prjugador)
	{printf("\n el ganador del juego es el jugador");}	
}