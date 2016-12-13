#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>

// On suppose a<b
int rand_a_b(int a, int b){ // fonction random aux bornes [a;b[
    return rand()%(b-a) +a;
}

void afficher(FILE* fichier,int posX,int posY){// Affichage de l'image!

	int i=0;
	int n=35;
	char ligne[255];
	
	system("clear"); //on suprime le contenu de la console

	for (i=0; i<posY; i++){printf("\n");} //nombre de retour a la ligne pour le positionnement de l'image en Y

	while (fgets(ligne, 255, fichier)!=NULL){ //pour chaques lignes du fichier

		for (i=0; i<posX; i++){printf(" ");} //nombre d'espaces pour le positionnement de l'image en X

		for (i=0; i<255; i++){ // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image
			if (ligne[i]=='1'){printf("%c",n);}
			if (ligne[i]=='0'){printf(" ");}	

		}
		printf("\n");
	}
		
	
}
void afficherHeure(FILE* deuxPoints, FILE* num0, FILE* num1, FILE* num2, FILE* num3, FILE* num4, FILE* num5, int posX, int posY){// Affichage de l'image!

	int i=0, j=0, k=0;
	int n=35;
	char ligne0[100], ligne1[100] ,ligne2[100], ligne3[100], ligne4[100], ligne5[100], points[100];
	
	system("clear"); //on suprime le contenu de la console

	for (i=0; i<posY; i++){printf("\n");} //nombre de retour a la ligne pour le positionnement de l'image en Y

	for (i=0; i<5; i++){//pour chaques lignes du fichier

		for (j=0; j<posX; j++){printf(" ");} //nombre d'espaces pour le positionnement de l'image en X
		fgets(points, 100, deuxPoints);
		fgets(ligne0, 100, num0);
		fgets(ligne1, 100, num1);
		fgets(ligne2, 100, num2);
		fgets(ligne3, 100, num3);
		fgets(ligne4, 100, num4);
		fgets(ligne5, 100, num5);

		
		for (k=0; k<3; k++){ // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
			if (ligne0[k]=='1'){printf("%c",n);}
			if (ligne0[k]=='0'){printf(" ");}
		}
		for (k=0; k<3; k++){ // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
			if (ligne1[k]=='1'){printf("%c",n);}
			if (ligne1[k]=='0'){printf(" ");}
		}
		for (k=0; k<3; k++){ // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
			if (points[k]=='1'){printf("%c",n);}
			if (points[k]=='0'){printf(" ");}
		}
		for (k=0; k<3; k++){ // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
			if (ligne2[k]=='1'){printf("%c",n);}
			if (ligne2[k]=='0'){printf(" ");}
		}
		for (k=0; k<3; k++){ // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
			if (ligne3[k]=='1'){printf("%c",n);}
			if (ligne3[k]=='0'){printf(" ");}
		}
		for (k=0; k<3; k++){ // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
			if (points[k]=='1'){printf("%c",n);}
			if (points[k]=='0'){printf(" ");}
		}
		for (k=0; k<3; k++){ // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
			if (ligne4[k]=='1'){printf("%c",n);}
			if (ligne4[k]=='0'){printf(" ");}
		}
		for (k=0; k<3; k++){ // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
			if (ligne5[k]=='1'){printf("%c",n);}
			if (ligne5[k]=='0'){printf(" ");}
		}
			
		printf("\n");
	}
		
	
}


void tailleImage(int *longueur, int *hauteur,FILE* fichier){//fonction qui détermine la taille de l'image

	char ligneImg[255];
	int i=0;
	int n=0;
	while (fgets(ligneImg, 255, fichier)!=NULL){//on analyse le nombre de lignes
		while (ligneImg[i]=='1' || ligneImg[i]=='0'){//on analyse le nombre de colonnes
			i++;
		}
		n++;
	}
	*longueur=i;//on renvoie les valeurs dans les variables longueur et largeur.
	*hauteur=n;
	
	
}


  
void mode_raw(int activer) 
{ 
    static struct termios cooked; 
    static int raw_actif = 0; 
  
    if (raw_actif == activer) 
        return; 
  
    if (activer) 
    { 
        struct termios raw; 
  
        tcgetattr(STDIN_FILENO, &cooked); 
  
        raw = cooked; 
        cfmakeraw(&raw); 
        tcsetattr(STDIN_FILENO, TCSANOW, &raw); 
    } 
    else 
        tcsetattr(STDIN_FILENO, TCSANOW, &cooked); 
  
    raw_actif = activer; 
}
