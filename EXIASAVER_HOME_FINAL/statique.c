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
	char stop=' ';
	int longueur=0;
	int largeur=0;
	struct winsize w; //structure pour la largeur de la fenetre
	int xImg, yImg;
	int f;
	FILE* fichier;
	
	
	fichier=fopen(argv[1],"r"); //ouverture du fichier pbm mis en argument

	tailleImage(&longueur, &largeur, fichier);	//analyse de la taille de l'image
	fclose(fichier); //fermeture du fichier

	ioctl(1, TIOCGWINSZ, &w); //fonction mettant dans les variable ws_row et ws_col la taille de la fenetre
	yImg=(w.ws_row-largeur)/2; //calcul de la position de l'image
	xImg=(w.ws_col-longueur)/2;
	
	
	
	fichier=fopen(argv[1],"r");	
	afficher(fichier, xImg, yImg);// affichage de l'image
	fclose(fichier); //fermeture du fichier

	while (continuer){ //boucle infinie pour ne pas avoir le prompt
		system("/bin/stty raw");
		if (stop=getchar()!='µ'){
			continuer=0;
			system("/bin/stty cooked");
			system("clear");
		}
	}
	
}


