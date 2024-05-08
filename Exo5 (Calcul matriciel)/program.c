#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "matrix.h"


float **fillTab(int ligne, int colonne){
	float** tab;

	tab = (float**)malloc(ligne * sizeof(float*));
	for(int i=0; i<ligne; i++)
		tab[i] = (float*)malloc(colonne * sizeof(float));

	for(int i=0; i<ligne; i++){
		for(int j=0; j<colonne; j++){
			printf("(%d, %d) : ", i+1, j+1);
			scanf(" %f", tab[i][j]);
		}
	}

	return tab;
}

int main(int argc, char* argv[]){
	int choix, choix2, ligne, colonne;
	char fichier[25];
	do{
		printf(" ----------------- MENU -------------------------------\n");
		printf("| 0- QUITTER                                           |\n");
		printf("| 1- Calculer la transposer d'une matrice              |\n");
		printf("| 2- Additioner deux matrices                          |\n");
		printf("| 3- Soustraire deux matrices                          |\n");
		printf("| 4- Multiplier une matrice par un scalaire            |\n");
		printf("| 5- Multiplication de deux matrices                   |\n");
		printf(" ------------------------------------------------------\n");
		printf("\nFaire un choix : ");
		scanf("%d",&choix);
		switch(choix){
			case 0 :break;
			case 1 :system("clear");
					printf("	Transpose de la matrice\n");
					printf("    -----------------------\n");
					printf("0- Retourner au menu precedent\n");
					printf("1- Creer une matrice\n");
					printf("2- Creer une matrice avec valeur aleatoire\n");
					printf("3- Creer une matrice en lisant d'un fichier\n");
					printf("Entrer la matrice a transposer(1-3): ");
					scanf("%d",&choix2);
					switch(choix2){
						case 0: break;
						case 1: printf("Entrer le nombre de ligne de la matrice : ");
								scanf("%d",&ligne);
								printf("Entrer le nombre de colonnes de la matrice: ");
								scanf("%d", &colonne);

								matrice* mat = Creer(ligne, colonne, fillTab(ligne, colonne));
								Afficher(*mat);

								matrice* Tmat = Transposer(*mat);
								printf("\nLa transpose de cette matrice est...\n");
								Afficher(*Tmat);
								break;
						case 2: printf("Entrer le nombre de ligne de la matrice : ");
								scanf("%d",&ligne);
								printf("Entrer le nombre de colonnes de la matrice: ");
								scanf("%d", &colonne);

								matrice* mat = Generer(ligne, colonne);
								Afficher(*mat);

								matrice* Tmat = Transposer(*mat);
								printf("\nLa transpose de cette matrice est...\n");
								Afficher(*Tmat);
								break;
						case 3: printf("Entrer le nombre de ligne de la matrice : ");
								scanf("%d",&ligne);
								printf("Entrer le nombre de colonnes de la matrice: ");
								scanf("%d", &colonne);
								printf("Entrer le nom du fichier a lire : ");
								scanf("%s", fichier);

								matrice* mat = Charger(fichier, ligne, colonne);
								if(mat == NULL){
									printf("Le fichier %s n'existe pas\n", fichier);
									break;
								}
								Afficher(*mat);
								matrice* Tmat = Transposer(*mat);
								printf("\nLa transpose de cette matrice est...\n");
								Afficher(*Tmat);
								break;
					}
					break;
			case 2 :system("clear");
					printf("	Additionner deux matrices\n");
					printf("    -------------------------\n");
					printf("0- Retourner au menu precedent\n");
					printf("1- Creer les deux matrices\n");
					printf("2- Creer les deux matrices avec valeurs aleatoire\n");
					printf("3- Creer les deux matrices en lisant d'un fichier\n");
					printf("Faire un choix(1-3): ");
					scanf("%d",&choix2);
					switch(choix2){
						case 0: break;
						case 1: printf("Entrer le nombre de ligne de la matrice: ");
								scanf("%d",&ligne);
								printf("Entrer le nombre de colonnes de la matrice: ");
								scanf("%d", &colonne);

								printf("Matrice A\n");
								matrice* matA = Creer(ligne, colonne, fillTab(ligne, colonne));
								Afficher(*matA);

								printf("Matrice B\n");
								matrice* matB = Creer(ligne, colonne, fillTab(ligne, colonne));
								Afficher(*matB);

								matrice* somme = Additionner(*matA, *matB);

								if(somme != NULL){
									printf("\nLa somme de ces deux matrices est...\n");
									Afficher(*somme);
								}else
									printf("Impossible d'effectuer l'addition de ces deux matrices");
								
								break;
						case 2: printf("Entrer le nombre de ligne de la matrice : ");
								scanf("%d",&ligne);
								printf("Entrer le nombre de colonnes de la matrice: ");
								scanf("%d", &colonne);

								printf("Matrice A\n");
								matrice* matA = Generer(ligne, colonne);
								Afficher(*matA);

								printf("Matrice B\n");
								matrice* matB = Generer(ligne, colonne);
								Afficher(*matB);
								matrice* somme = Additionner(*matA, *matB);
								if(somme != NULL){
									printf("\nLa somme de ces deux matrices est...\n");
									Afficher(*somme);
								}else
									printf("Impossible d'effectuer l'addition de ces deux matrices");
								break;
						case 3: printf("Entrer le nombre de ligne de la matrice : ");
								scanf("%d",&ligne);
								printf("Entrer le nombre de colonnes de la matrice: ");
								scanf("%d", &colonne);

								printf("Entrer le nom du fichier contenant la matrice A : ");
								scanf("%s", fichier);
								matrice* matA = Charger(fichier, ligne, colonne);
								if(matA == NULL){
									printf("Le fichier %s n'existe pas\n", fichier);
									break;
								}

								printf("Matrice A\n");
								Afficher(*matA);

								printf("Entrer le nom du fichier contenant la matrice B : ");
								scanf("%s", fichier);
								matrice* matB = Charger(fichier, ligne, colonne);
								if(matB == NULL){
									printf("Le fichier %s n'existe pas\n", fichier);
									break;
								}

								printf("Matrice B\n");
								Afficher(*matB);

								matrice* somme = Additionner(*matA, *matB);
								if(somme != NULL){
									printf("\nLa somme de ces deux matrices est...\n");
									Afficher(*somme);
								}else
									printf("Impossible d'effectuer l'addition de ces deux matrices");
								break;
								break;
					}
					break;
			case 3 :system("clear");
					printf("	Soustraire deux matrices\n");
					printf("    -------------------------\n");
					printf("0- Retourner au menu precedent\n");
					printf("1- Creer les deux matrices\n");
					printf("2- Creer les deux matrices avec valeurs aleatoire\n");
					printf("3- Creer les deux matrices en lisant d'un fichier\n");
					printf("Faire un choix(1-3): ");
					scanf("%d",&choix2);
					switch(choix2){
						case 0: break;
						case 1: printf("Entrer le nombre de ligne de la matrice: ");
								scanf("%d",&ligne);
								printf("Entrer le nombre de colonnes de la matrice: ");
								scanf("%d", &colonne);

								printf("Matrice A\n");
								matrice* matA = Creer(ligne, colonne, fillTab(ligne, colonne));
								Afficher(*matA);

								printf("Matrice B\n");
								matrice* matB = Creer(ligne, colonne, fillTab(ligne, colonne));
								Afficher(*matB);

								matrice* diff = Soustraire(*matA, *matB);

								if(diff != NULL){
									printf("\nLa difference de ces deux matrices est...\n");
									Afficher(*diff);
								}else
									printf("Impossible d'effectuer la soustraction de ces deux matrices");
								
								break;
						case 2: printf("Entrer le nombre de ligne de la matrice : ");
								scanf("%d",&ligne);
								printf("Entrer le nombre de colonnes de la matrice: ");
								scanf("%d", &colonne);

								printf("Matrice A\n");
								matrice* matA = Generer(ligne, colonne);
								Afficher(*matA);

								printf("Matrice B\n");
								matrice* matB = Generer(ligne, colonne);
								Afficher(*matB);

								matrice* diff = Soustraire(*matA, *matB);
								if(diff != NULL){
									printf("\nLa difference de ces deux matrices est...\n");
									Afficher(*diff);
								}else
									printf("Impossible d'effectuer la soustraction de ces deux matrices");
								break;
						case 3: printf("Entrer le nombre de ligne de la matrice : ");
								scanf("%d",&ligne);
								printf("Entrer le nombre de colonnes de la matrice: ");
								scanf("%d", &colonne);

								printf("Entrer le nom du fichier contenant la matrice A : ");
								scanf("%s", fichier);
								matrice* matA = Charger(fichier, ligne, colonne);
								if(matA == NULL){
									printf("Le fichier %s n'existe pas\n", fichier);
									break;
								}

								printf("Matrice A\n");
								Afficher(*matA);

								printf("Entrer le nom du fichier contenant la matrice B : ");
								scanf("%s", fichier);
								matrice* matB = Charger(fichier, ligne, colonne);
								if(matB == NULL){
									printf("Le fichier %s n'existe pas\n", fichier);
									break;
								}

								printf("Matrice B\n");
								Afficher(*matB);
								
								matrice* diff = Soustraire(*matA, *matB);
								if(diff != NULL){
									printf("\nLa difference de ces deux matrices est...\n");
									Afficher(*diff);
								}else
									printf("Impossible d'effectuer la soustraction de ces deux matrices");
								break;
					}
					break;
			case 4 :system("clear");
					printf("	Multiplication de la matrice par un scalaire\n");
					printf("    --------------------------------------------\n");
					printf("0- Retourner au menu precedent\n");
					printf("1- Creer une matrice\n");
					printf("2- Creer une matrice avec valeur aleatoire\n");
					printf("3- Creer une matrice en lisant d'un fichier\n");
					printf("Entrer la matrice a transposer(1-3): ");
					scanf("%d",&choix2);
					float k;
					switch(choix2){
						case 0: break;
						case 1: printf("Entrer le nombre de ligne de la matrice : ");
								scanf("%d",&ligne);
								printf("Entrer le nombre de colonnes de la matrice: ");
								scanf("%d", &colonne);

								matrice* mat = Creer(ligne, colonne, fillTab(ligne, colonne));
								Afficher(*mat);

								printf("Entrer la valeur du scalaire : ");
								scanf(" %f", &k);

								matrice* Smat = Multiplier_S(*mat, k);
								printf("\nLa multiplication de cette matrice par %.2f est...\n", k);
								Afficher(*Smat);
								break;
						case 2: printf("Entrer le nombre de ligne de la matrice : ");
								scanf("%d",&ligne);
								printf("Entrer le nombre de colonnes de la matrice: ");
								scanf("%d", &colonne);

								matrice* mat = Generer(ligne, colonne);
								Afficher(*mat);

								printf("Entrer la valeur du scalaire : ");
								scanf(" %f", &k);

								matrice* Smat = Multiplier_S(*mat, k);
								printf("\nLa transpose de cette matrice par %.2f est...\n", k);
								Afficher(*Smat);
								break;
						case 3: printf("Entrer le nombre de ligne de la matrice : ");
								scanf("%d",&ligne);
								printf("Entrer le nombre de colonnes de la matrice: ");
								scanf("%d", &colonne);
								printf("Entrer le nom du fichier a lire : ");
								scanf("%s", fichier);

								matrice* mat = Charger(fichier, ligne, colonne);
								if(mat == NULL){
									printf("Le fichier %s n'existe pas\n", fichier);
									break;
								}
								Afficher(*mat);

								printf("Entrer la valeur du scalaire : ");
								scanf(" %f", &k);

								matrice* Smat = Multiplier_S(*mat, k);
								printf("\nLa transpose de cette matrice par %.2f est...\n", k);
								Afficher(*Smat);
								break;
					}
					break;
			case 5 :system("clear");
					printf("	Multiplier deux matrices\n");
					printf("    -------------------------\n");
					printf("0- Retourner au menu precedent\n");
					printf("1- Creer les deux matrices\n");
					printf("2- Creer les deux matrices avec valeurs aleatoire\n");
					printf("3- Creer les deux matrices en lisant d'un fichier\n");
					printf("Faire un choix(1-3): ");
					scanf("%d",&choix2);
					switch(choix2){
						case 0: break;
						case 1: printf("Entrer le nombre de ligne de la matrice A: ");
								scanf("%d",&ligne);
								printf("Entrer le nombre de colonnes de la matrice A: ");
								scanf("%d", &colonne);

								printf("Matrice A\n");
								matrice* matA = Creer(ligne, colonne, fillTab(ligne, colonne));
								Afficher(*matA);

								printf("Entrer le nombre de ligne de la matrice B: ");
								scanf("%d",&ligne);
								printf("Entrer le nombre de colonnes de la matrice B: ");
								scanf("%d", &colonne);

								printf("Matrice B\n");
								matrice* matB = Creer(ligne, colonne, fillTab(ligne, colonne));
								Afficher(*matB);

								matrice* mult = Multiplier(*matA, *matB);

								if(mult != NULL){
									printf("\nLe produit de ces deux matrices est...\n");
									Afficher(*mult);
								}else
									printf("Impossible d'effectuer la multiplication de ces deux matrices");
								
								break;
						case 2: printf("Entrer le nombre de ligne de la matrice A: ");
								scanf("%d",&ligne);
								printf("Entrer le nombre de colonnes de la matrice A: ");
								scanf("%d", &colonne);

								printf("Matrice A\n");
								matrice* matA = Generer(ligne, colonne);
								Afficher(*matA);

								printf("Entrer le nombre de ligne de la matrice B: ");
								scanf("%d",&ligne);
								printf("Entrer le nombre de colonnes de la matrice B: ");
								scanf("%d", &colonne);

								printf("Matrice B\n");
								matrice* matB = Generer(ligne, colonne);
								Afficher(*matB);

								matrice* mult = Multiplier(*matA, *matB);
								if(mult != NULL){
									printf("\nLe produit de ces deux matrices est...\n");
									Afficher(*mult);
								}else
									printf("Impossible d'effectuer la multiplication de ces deux matrices");
								break;
						case 3: printf("Entrer le nombre de ligne de la matrice A : ");
								scanf("%d",&ligne);
								printf("Entrer le nombre de colonnes de la matrice A : ");
								scanf("%d", &colonne);

								printf("Entrer le nom du fichier contenant la matrice A : ");
								scanf("%s", fichier);
								matrice* matA = Charger(fichier, ligne, colonne);
								if(matA == NULL){
									printf("Le fichier %s n'existe pas\n", fichier);
									break;
								}

								printf("Matrice A\n");
								Afficher(*matA);

								printf("Entrer le nombre de ligne de la matrice B : ");
								scanf("%d",&ligne);
								printf("Entrer le nombre de colonnes de la matrice B : ");
								scanf("%d", &colonne);

								printf("Entrer le nom du fichier contenant la matrice B : ");
								scanf("%s", fichier);
								matrice* matB = Charger(fichier, ligne, colonne);
								if(matB == NULL){
									printf("Le fichier %s n'existe pas\n", fichier);
									break;
								}

								printf("Matrice B\n");
								Afficher(*matB);

								matrice* mult = Multiplier(*matA, *matB);
								if(mult != NULL){
									printf("\nLe produit de ces deux matrices est...\n");
									Afficher(*mult);
								}else
									printf("Impossible d'effectuer la multiplication de ces deux matrices");

								break;
					}
					break;
			default: printf("Faire un choix entre 0..5");
					break;
		}
		printf("\n\n");
        system("clear");
    }while(choix!=0);
	return 0;
}
