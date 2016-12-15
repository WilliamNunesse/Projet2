#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <time.h>

#include "headers.h"
#include "fonctions.c"


void main(int argc, char *argv[]){
	
	int continuer=1;
	int longueur=0;
	int largeur=0;
	struct winsize w; //structure pour la largeur de la fenetre
	int xImg, yImg;
	int direction=1;
	char touche=' ';
	
	FILE* fichier;
	fichier=fopen("EXIASAVER3_PBM/AVIONE.pbm","r"); //ouverture du fichier

	tailleImage(&longueur, &largeur, fichier);	//analyse de la taille de l'image
	fclose(fichier); //fermeture du fichier
	
	
	ioctl(1, TIOCGWINSZ, &w); //fonction mettant dans les variable ws_row et ws_col la taille de la fenetre
	yImg=(w.ws_row-largeur)/2; //calcul de la position de l'image
	xImg=(w.ws_col-longueur)/2;

	while (continuer){

		switch(direction){
			case 1: fichier=fopen("EXIASAVER3_PBM/AVIONE.pbm","r");break; //on choisi la bonne image en fonction de la directiond e l'avions
			case 2: fichier=fopen("EXIASAVER3_PBM/AVIONO.pbm","r");break;
			case 3: fichier=fopen("EXIASAVER3_PBM/AVIONN.pbm","r");break;
			case 4: fichier=fopen("EXIASAVER3_PBM/AVIONS.pbm","r");break;
		}
		if (xImg>w.ws_col-6){xImg=0;}
		if (yImg>w.ws_row-7){yImg=0;}
		if (xImg<0){xImg=w.ws_col-6;} //si l'avion atteint un bout de l'écran, il est renvoyé a l'autre bout
		if (yImg<0){yImg=w.ws_row-6;}
		
		afficher(fichier, xImg, yImg);// affichage de l'image
		fclose(fichier); //fermeture du fichier
		
		
		system("/bin/stty raw"); //passage en mode raw.
		touche=getchar(); //récupperationd de la touche
		if (touche=='a'){ //si la touche est a, on quitte
			continuer=0;
			system("clear"); //vide le contenu de la console
			}
		if (touche=='z' || touche=='A'){
			yImg--;
			direction=3;
			}
		if (touche=='s' || touche=='B'){ //modification des coordonées en fonction de la touche. Modif de la direction!
			yImg++;
			direction=4;
			}
		if (touche=='q' || touche=='D'){
			xImg--;
			direction=2;
			}
		if (touche=='d' || touche=='C'){
			xImg++;
			direction=1;
			}
		system("/bin/stty cooked"); //retour en mode normal
		
	}
	
}

