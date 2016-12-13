#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>

#include "fonctions.c"

void main(){

	time_t temps;
	typedef struct tm tm;
	tm date;
	
	time(&temps);
	date=*localtime(&temps);
	/*
	tm_wday, le jour de la semaine est exprimé en 3 lettres dans son nom anglais (ex : Lundi → Mon) ;
	tm_mon, le nom du mois exprimé en 3 lettres dans son nom anglais (ex : Juin → Jun) ;
	tm_mday, le jour du mois ;
	tm_hour, l'heure ;
	tm_min, les minutes ;
	tm_sec, les secondes ;
	tm_year, l'année.
	*/

	printf("%d:%d:%d",date.tm_hour,date.tm_min,date.tm_sec);





	FILE* num0=fopen("EXIASAVER2_PBM/2.pbm", "r");
	FILE* num1=fopen("EXIASAVER2_PBM/2.pbm", "r");
	FILE* num2=fopen("EXIASAVER2_PBM/4.pbm", "r");
	FILE* num3=fopen("EXIASAVER2_PBM/5.pbm", "r");
	FILE* num4=fopen("EXIASAVER2_PBM/1.pbm", "r");
	FILE* num5=fopen("EXIASAVER2_PBM/7.pbm", "r");
	FILE* deuxPoints=fopen("EXIASAVER2_PBM/deuxPoints.pbm", "r");

	afficherHeure(deuxPoints, num0, num1, num2, num3, num4, num5, 5, 3);

	fclose(num0);
	fclose(num1);
	fclose(num2);
	fclose(num3);
	fclose(num4);
	fclose(num5);
	fclose(deuxPoints);




}
