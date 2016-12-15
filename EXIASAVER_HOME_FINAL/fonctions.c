#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>

// On suppose a<b
int rand_a_b(int a, int b){
	srand(time(NULL)); // fonction random aux bornes [a;b[
    	return rand()%(b-a) +a;
}

void afficher(FILE* fichier,int posX,int posY){// Affichage de l'image!

	int i=0;
	int n=35;
	char ligne[255];
	int autorisation=0;
	
	system("clear"); //on suprime le contenu de la console

	for (i=0; i<posY; i++){printf("\n");} //nombre de retour a la ligne pour le positionnement de l'image en Y

	while (fgets(ligne, 255, fichier)!=NULL){ //pour chaques lignes du fichier
		autorisation++;
	
		if (autorisation>3){
			for (i=0; i<posX; i++){printf(" ");} //nombre d'espaces pour le positionnement de l'image en X

			for (i=0; i<255; i++){ // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image
				if (ligne[i]=='1'){printf("%c",n);}
				if (ligne[i]=='0'){printf(" ");}	

			}
			printf("\n");
		}
	}
		
	
}
void afficherHeure(FILE* deuxPoints, FILE* num0, FILE* num1, FILE* num2, FILE* num3, FILE* num4, FILE* num5, int posX, int posY, int taille){// Affichage de l'image!

	int i=0, j=0, k=0;
	int n=35;
	char ligne0[10], ligne1[10] ,ligne2[10], ligne3[10], ligne4[10], ligne5[10], points[10];
	
	system("clear"); //on suprime le contenu de la console

	for (i=0; i<posY; i++){printf("\n");} //nombre de retour a la ligne pour le positionnement de l'image en Y

	for (i=0; i<8; i++){//pour chaques lignes du fichier

		for (j=0; j<posX; j++){printf(" ");} //nombre d'espaces pour le positionnement de l'image en X
		fgets(points, 10, deuxPoints);
		fgets(ligne0, 10, num0);
		fgets(ligne1, 10, num1);
		fgets(ligne2, 10, num2);
		fgets(ligne3, 10, num3);
		fgets(ligne4, 10, num4);
		fgets(ligne5, 10, num5);

		if (i>=3){
			for (k=0; k<6; k++){ // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				if (ligne0[k]=='1'){printf("%c",n);}
				if (ligne0[k]=='0'){printf(" ");}
				if (k==5){printf(" ");}
				if (taille==2){printf(" ");}
			}
			for (k=0; k<6; k++){ // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				if (ligne1[k]=='1'){printf("%c",n);}
				if (ligne1[k]=='0'){printf(" ");}
				if (k==5){printf(" ");}
				if (taille==2){printf(" ");}
			}
			for (k=0; k<6; k++){ // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				if (points[k]=='1'){printf("%c",n);}
				if (points[k]=='0'){printf(" ");}
				if (k==5){printf(" ");}
				if (taille==2){printf(" ");}
			}
			for (k=0; k<6; k++){ // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				if (ligne2[k]=='1'){printf("%c",n);}
				if (ligne2[k]=='0'){printf(" ");}
				if (k==5){printf(" ");}
				if (taille==2){printf(" ");}
			}
			for (k=0; k<6; k++){ // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				if (ligne3[k]=='1'){printf("%c",n);}
				if (ligne3[k]=='0'){printf(" ");}
				if (k==5){printf(" ");}
				if (taille==2){printf(" ");}
			}
			for (k=0; k<6; k++){ // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				if (points[k]=='1'){printf("%c",n);}
				if (points[k]=='0'){printf(" ");}
				if (k==5){printf(" ");}
				if (taille==2){printf(" ");}
			}
			for (k=0; k<6; k++){ // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				if (ligne4[k]=='1'){printf("%c",n);}
				if (ligne4[k]=='0'){printf(" ");}
				if (k==5){printf(" ");}
				if (taille==2){printf(" ");}
			}
			for (k=0; k<6; k++){ // on affiche un caractere en fonction des 1 et 0 qui consitituent l'image	
				if (ligne5[k]=='1'){printf("%c",n);}
				if (ligne5[k]=='0'){printf(" ");}
				if (k==5){printf(" ");}
				if (taille==2){printf(" ");}
			}
				
		}
		printf("\n");
	}
		
	
}


void tailleImage(int *longueur, int *hauteur,FILE* fichier){//fonction qui détermine la taille de l'image

	char ligneImg[255];
	int i=0;
	int n=0;
	int autorisation=0;
	while (fgets(ligneImg, 255, fichier)!=NULL){//on analyse le nombre de lignes
		autorisation++;
		if (autorisation>3){
			while (ligneImg[i]=='0' || ligneImg[i]=='1'){//on analyse le nombre de colonnes
				i+=2;
			}
			n++;
		}
	}
	*longueur=i/2;//on renvoie les valeurs dans les variables longueur et largeur.
	*hauteur=n;
	
	
}

FILE* switchFichierHeure(int valeur){
	
	switch(valeur){

		case 0:
		return fopen("EXIASAVER2_PBM/0.pbm","r"); //en fonction de la valeur du numéro, on associe le fichier pbm correct
		break;

		case 1:
		return fopen("EXIASAVER2_PBM/1.pbm","r");
		break;

		case 2:
		return fopen("EXIASAVER2_PBM/2.pbm","r");
		break;

		case 3:
		return fopen("EXIASAVER2_PBM/3.pbm","r");
		break;

		case 4:
		return fopen("EXIASAVER2_PBM/4.pbm","r");
		break;

		case 5:
		return fopen("EXIASAVER2_PBM/5.pbm","r");
		break;
	
		case 6:
		return fopen("EXIASAVER2_PBM/6.pbm","r");
		break;

		case 7:
		return fopen("EXIASAVER2_PBM/7.pbm","r");
		break;

		case 8:
		return fopen("EXIASAVER2_PBM/8.pbm","r");
		break;

		case 9:
		return fopen("EXIASAVER2_PBM/9.pbm","r");
		break;
	}


}
