#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[])
{
	time_t temps;
	typedef struct tm tm; //structure ou serontt stockées des variable qui détiendront des infos sur le temps.
	tm date;
	time(&temps);
	date=*localtime(&temps);

	int typeScreenSaver=0, aleatoire, choixPbm;
	pid_t pid, pidStatic;

	srand(time(NULL)); //définition de nombres aléatoires
	aleatoire=rand()%3+1;
	choixPbm=rand()%3+1;

	system("clear"); //on supprime le contenu de la console

	if (argc==1){
		FILE* historique=fopen("historique.txt","a"); //on ouvre le fichier
		printf("=====eXiaSaver=====\n\n");
		printf("==Votre Système d'Exploitation possède 3 types de ScreenSaver===\n\n");
		printf("==Statique: Tapez 1! \n==Dynamique: Tapez 2! \n==Interactif: Tapez 3!\n\n");
		printf("===Appuyez sur 4 pour les lancer de façon aléatoire===\n\n");

		while (typeScreenSaver<1 || typeScreenSaver>4){ //sécurité sur le scanf
			scanf("%d", &typeScreenSaver);
			}
		if(typeScreenSaver==4)
			{
			typeScreenSaver=aleatoire; //choix d'un nombre alea si le choix est le nb 4
			}

		switch(typeScreenSaver)
		{
			case 1: //statique
				pid = fork();	//creation d'un processus fils

				if(pid==0) 
					{
					switch(choixPbm){
						case 1: 
							pidStatic=fork(); //creation d'un fils
							if (pidStatic==0){ //on récupere les logs
								char *arguments[]={"dynamique","EXIASAVER1_PBM/affichage.pbm",NULL};
								fprintf(historique,"ScreenSaver! type: Statique ; file: affichage.pbm ; date: %d/%d ; heure: %d:%d:%d \n",date.tm_mday, date.tm_mon, date.tm_hour, date.tm_min, date.tm_sec);
								fclose(historique); //fermeture du fichier
								execv("statique",arguments); //on execute dans le fils Le statique avec le pbm 1
								}
							else{
								wait(NULL); //le processus père attent la fin du fils pour reprendre.
								}
							break;
						
						case 2: 
							pidStatic=fork(); //creation d'un processus fils
							if (pidStatic==0){ //on récupère les logs
								char *arguments[]={"dynamique","EXIASAVER1_PBM/affichage.pbm",NULL};
								fprintf(historique,"ScreenSaver! type: Statique ; file: affichage2.pbm ; date: %d/%d ; heure: %d:%d:%d \n",date.tm_mday, date.tm_mon, date.tm_hour, date.tm_min, date.tm_sec); 
								fclose(historique);//fermeture du fichier
								execv("statique", arguments);//activation du Statique et pbm n2
								}
							else{
								wait(NULL);//le processus père attent la fin du fils
								}
							break;
						case 3:
						pidStatic=fork(); //creation d'un processus fils
							if (pidStatic==0){//logs
								char *arguments[]={"dynamique","EXIASAVER1_PBM/affichage.pbm",NULL};
								fprintf(historique,"ScreenSaver! type: Statique ; file: affichage3.pbm ; date: %d/%d ; heure: %d:%d:%d \n",date.tm_mday, date.tm_mon, date.tm_hour, date.tm_min, date.tm_sec);
								fclose(historique);//fermeture du fichier
								execv("statique", arguments); //Activation Statique + pbm3
								}
							else{
								wait(NULL); ///attente de la fin du père
								}
							break;
						}
					
					} else 
						{
						wait(NULL);
						}	
				break;
		
			case 2: //dynamique
				pid = fork(); //creation du père
				char *arguments2[]={"dynamique",NULL};

				if(pid==0) 
					{//logs
					fprintf(historique,"ScreenSaver! type: Dynamique ; date: %d/%d ; heure: %d:%d:%d \n",date.tm_mday, date.tm_mon, date.tm_hour, date.tm_min, date.tm_sec);
					fclose(historique); //ferme l'historique
					execv("dynamique",arguments2); //execute le dynamique
					} else 
						{
						wait(NULL); //le père attent la fin du fils
						}
				break; 	
			case 3: //interactif

				pid = fork(); //creation d'un fils
				char *arguments3[]={"interactif",NULL};
				if(pid==0) 
					{//logs
					fprintf(historique,"ScreenSaver! type: Interactif ; date: %d/%d ; heure: %d:%d:%d \n",date.tm_mday, date.tm_mon, date.tm_hour, date.tm_min, date.tm_sec);
					fclose(historique); //fermeture du fichier
					execv("interactif",arguments3); //executionde l'interractif
					} else 
						{
						wait(NULL); //le père attent la fin du fils
						}
				break;
		} 

		
		system("clear"); //supprime le contenu de la console
		
	}
	
	if (argc>1 && strcmp(argv[1], "-stat")==0){ //si on a l'aguument -stat
		
		int choix;
		char ligne[255];
		FILE* historique=fopen("historique.txt","r"); //ouverture de l'historique
		printf("== Menu ==\n");
		printf("1/ Ordre Chronologique\n");
		printf("2/ Tri par type d'écran de veille\n");
		
		while (choix<1 || choix>2){//protection sur scanf
			scanf("%d",&choix);
		}
		switch(choix){
			case 1:
				system("clear");
				printf("STATISTIQUES:\n");
		
				while (fgets(ligne, 255, historique)!=NULL){ //affichage des logs
					printf("%s", ligne);
					}
						
				fclose(historique);// fermeture de l'historique
			break;
			
			case 2:	//tri par type
				system("clear");
				printf("STATISTIQUES:\n");
				while (fgets(ligne, 255, historique)!=NULL){ //on lit le fichier
					if (ligne[19]=='S'){ //On affiche que les Statique
						printf("%s",ligne);
						}
				}
				fclose(historique); //on ferme le fichier
				
				historique=fopen("historique.txt","r");//on ouvre le fichier
				while (fgets(ligne, 255, historique)!=NULL){//on lit le fichier
					if (ligne[19]=='D'){//on affiche que les dynamique
						printf("%s",ligne);
						}
				}
				fclose(historique);//on ferme le ficheir
				
				historique=fopen("historique.txt","r");//on ouvre le fichier
				while (fgets(ligne, 255, historique)!=NULL){//on lit le ficheir
					if (ligne[19]=='I'){// on affiche que les interractif
						printf("%s",ligne);
						}
				}
			break;
		
		}	

	return 0;
	}
}
	
	
	
