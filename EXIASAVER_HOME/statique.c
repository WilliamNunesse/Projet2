#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <time.h>

#include "fonctions.c"


void main(){
	
	int continuer=1;
	char stop=' ';
	int longueur=0;
	int largeur=0;
	struct winsize w; //structure pour la largeur de la fenetre
	int xImg, yImg;
	int nbAlea;
	FILE* fichier;

	srand(time(NULL));
	nbAlea=rand_a_b(1,4);
	
	
	switch(nbAlea){
		case 1: fichier=fopen("EXIASAVER1_PBM/affichage.pbm", "r");break;
		case 2: fichier=fopen("EXIASAVER1_PBM/affichage2.pbm", "r");break;
		case 3: fichier=fopen("EXIASAVER1_PBM/affichage3.pbm", "r");break;
	}

	tailleImage(&longueur, &largeur, fichier);	//analyse de la taille de l'image
	fclose(fichier); //fermeture du fichier

	ioctl(1, TIOCGWINSZ, &w); //fonction mettant dans les variable ws_row et ws_col la taille de la fenetre
	yImg=(w.ws_row-largeur)/2; //calcul de la position de l'image
	xImg=(w.ws_col-longueur)/2;
	
	switch(nbAlea){
		case 1: fichier=fopen("EXIASAVER1_PBM/affichage.pbm", "r");break;
		case 2: fichier=fopen("EXIASAVER1_PBM/affichage2.pbm", "r");break;
		case 3: fichier=fopen("EXIASAVER1_PBM/affichage3.pbm", "r");break;
	}

	afficher(fichier, xImg, yImg);// affichage de l'image
		
	fclose(fichier); //fermeture du fichier

	while (continuer){ //boucle infinie pour ne pas avoir le prompt
		mode_raw(1);
		if (stop=getchar()!='µ'){
			continuer=0;
			mode_raw(0);
		}
	}
	
}


