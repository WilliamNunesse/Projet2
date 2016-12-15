#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>


//PROTOTYPE DES FONCTIONS DU FICHIER "fonctions.c"

// On suppose a<b
int rand_a_b(int a, int b);//Fonction qui génere un nb aleatoire

void afficher(FILE* fichier,int posX,int posY); //Fonction qui affiche une image pbm

void afficherHeure(FILE* deuxPoints, FILE* num0, FILE* num1, FILE* num2, FILE* num3, FILE* num4, FILE* num5, int posX, int posY, int taille);//fonction qui affiche l'heure

void tailleImage(int *longueur, int *hauteur,FILE* fichier);//fonction qui détermine la taille de l'image

FILE* switchFichierHeure(int valeur); //fonction qui coisi le le fichier pbm adapté a l'heure
