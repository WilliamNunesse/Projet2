#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <time.h>

#include "headers.h"
#include "fonctions.c"

void main(){

	time_t temps;
	typedef struct tm tm;
	tm date;

	struct winsize w; //structure pour la largeur de la fenetre
	
	int continuer=1;
	int xImg, yImg;
	int longueur=31;
	int largeur=8;
	int taille;
	int i, n;
	int f=0;

	int dizHeure;
	int unitHeure;
	int dizMin;
	int unitMin;
	int dizSec;
	int unitSec;
	
	taille=rand_a_b(1,3); //nb alea
	if (taille==2){longueur=62;} //choix aléatoire entre 2 tailles différentes
	
	while (continuer){
		time(&temps); //on recupere le temps
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
		ioctl(1, TIOCGWINSZ, &w); //fonction mettant dans les variable ws_row et ws_col la taille de la fenetre
		yImg=(w.ws_row-largeur)/2; //calcul de la position de l'image
		xImg=(w.ws_col-longueur)/2;
	
		dizHeure=date.tm_hour/10;
		unitHeure=date.tm_hour%10;
		dizMin=date.tm_min/10; //on reccupere les chiffres de chaque heures
		unitMin=date.tm_min%10;
		dizSec=date.tm_sec/10;
		unitSec=date.tm_sec%10;

		FILE* num0=switchFichierHeure(dizHeure);
		FILE* num1=switchFichierHeure(unitHeure);
		FILE* num2=switchFichierHeure(dizMin); //choix des bons fichiers en fonction des numéros
		FILE* num3=switchFichierHeure(unitMin);
		FILE* num4=switchFichierHeure(dizSec);
		FILE* num5=switchFichierHeure(unitSec);
		FILE* deuxPoints=fopen("EXIASAVER2_PBM/deuxPoints.pbm", "r");

		
		afficherHeure(deuxPoints, num0, num1, num2, num3, num4, num5, xImg, yImg, taille); //affichage de l'jeure
		
		printf("\n\n");
		for (n=0; n<xImg; n++){
				printf(" ");
			}
		printf("ACTUALISATION DANS 4 SECONDES! \n"); 
		
		for (i=0; i<4; i++){
			for (n=0; n<xImg+longueur/2; n++){
				printf(" ");
			}
			sleep(1); //mise en pause de la console pour une seconde
			printf(".\n");
		}
		fclose(num0);
		fclose(num1);
		fclose(num2);
		fclose(num3); //fermeture du fichier
		fclose(num4);
		fclose(num5);
		fclose(deuxPoints);

		}


}
