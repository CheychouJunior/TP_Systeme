#include <stdio.h>
#include <stdlib.h>
#include <type.h>
#include <matrix.h>

float **fillTab(int ligne, int colonne){
	float** tab;

	tab = (float**)malloc(ligne * sizeof(float*));
	for(int i=0; i<ligne; i++)
		tab[i] = (float*)malloc(colonne * sizeof(float));

	for(int i=0; i<ligne; i++){
		for(int j=0; j<colonne; j++){
			printf("(%d, %d) : ", i+1, j+1);
			scanf(" %f", &tab[i][j]);
		}
	}

	return tab;
}

matrice* func_Generer(){
	int ligne, colonne;

	printf("Entrer le nombre de ligne de la matrice : ");
	scanf("%d",&ligne);
	printf("Entrer le nombre de colonnes de la matrice: ");
	scanf("%d", &colonne);

	matrice* mat = Creer(ligne, colonne, fillTab(ligne, colonne));

	return mat;
}

matrice* func_creer(){
	int ligne, colonne;

	printf("Entrer le nombre de ligne de la matrice : ");
	scanf("%d",&ligne);
	printf("Entrer le nombre de colonnes de la matrice: ");
	scanf("%d", &colonne);

	matrice* mat = Creer(ligne, colonne, fillTab(ligne, colonne));
	
	return mat;
}

matrice* func_charger(){
	int ligne, colonne;
	char fichier[25];

	printf("Entrer le nombre de ligne de la matrice : ");
	scanf("%d",&ligne);
	printf("Entrer le nombre de colonnes de la matrice: ");
	scanf("%d", &colonne);
	printf("Entrer le nom du fichier a lire : ");
	scanf("%s", fichier);

	matrice* mat = Charger(fichier, ligne, colonne);
	if(mat == NULL)
		printf("Le fichier %s n'existe pas\n", fichier);

	return mat;
}

int main(){
	int choix, choix2;
	
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
						case 1: matrice* mat1 = func_creer();
								Afficher(*mat1);

								matrice* Tmat1 = Transposer(*mat1);
								printf("\nLa transpose de cette matrice est...\n");
								Afficher(*Tmat1);
								free(mat1);
								free(Tmat1);
								break;
						case 2:	matrice* mat2 = func_Generer();
								Afficher(*mat2);
								matrice* Tmat2 = Transposer(*mat2);
								printf("\nLa transpose de cette matrice est...\n");
								Afficher(*Tmat2);
								free(mat2);
								free(Tmat2);
								break;
						case 3: matrice* mat3 = func_charger();
								if(mat3 == NULL)
									break;
								
								Afficher(*mat3);
								matrice* Tmat3 = Transposer(*mat3);
								printf("\nLa transpose de cette matrice est...\n");
								Afficher(*Tmat3);
								free(mat3);
								free(Tmat3);
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
						case 1: printf("Matrice A\n");
								matrice* mat1A = func_creer();
								Afficher(*mat1A);

								printf("Matrice B\n");
								matrice* mat1B = func_creer();
								Afficher(*mat1B);

								matrice* somme1 = Additionner(*mat1A, *mat1B);

								if(somme1 != NULL){
									printf("\nLa somme de ces deux matrices est...\n");
									Afficher(*somme1);
								}else
									printf("Impossible d'effectuer l'addition de ces deux matrices");
								free(mat1A);
								free(mat1B);
								break;
						case 2: printf("Matrice A\n");
								matrice* mat2A = func_Generer();
								Afficher(*mat2A);

								printf("Matrice B\n");
								matrice* mat2B = func_Generer();
								Afficher(*mat2B);

								matrice* somme2 = Additionner(*mat2A, *mat2B);
								if(somme2 != NULL){
									printf("\nLa somme de ces deux matrices est...\n");
									Afficher(*somme2);
								}else
									printf("Impossible d'effectuer l'addition de ces deux matrices");
								free(mat2A);
								free(mat2B);
								break;
						case 3: printf("Matrice A\n");
								matrice* mat3A = func_charger();
								if(mat3A == NULL)
									break;

								Afficher(*mat3A);

								printf("Matrice B\n");
								matrice* mat3B = func_charger();
								if(mat3B == NULL)
									break;

								Afficher(*mat3B);

								matrice* somme3 = Additionner(*mat3A, *mat3B);
								if(somme3 != NULL){
									printf("\nLa somme de ces deux matrices est...\n");
									Afficher(*somme3);
								}else
									printf("Impossible d'effectuer l'addition de ces deux matrices");
								free(mat3A);
								free(mat3B);
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
						case 1: printf("Matrice A\n");
								matrice* mat1A = func_creer();
								Afficher(*mat1A);

								printf("Matrice B\n");
								matrice* mat1B = func_creer();
								Afficher(*mat1B);

								matrice* diff1 = Soustraire(*mat1A, *mat1B);

								if(diff1 != NULL){
									printf("\nLa difference de ces deux matrices est...\n");
									Afficher(*diff1);
								}else
									printf("Impossible d'effectuer la soustraction de ces deux matrices");
								free(mat1A);
								free(mat1B);
								break;
						case 2: printf("Matrice A\n");
								matrice* mat2A = func_Generer();
								Afficher(*mat2A);

								printf("Matrice B\n");
								matrice* mat2B = func_Generer();
								Afficher(*mat2B);

								matrice* diff2 = Soustraire(*mat2A, *mat2B);
								if(diff2 != NULL){
									printf("\nLa difference de ces deux matrices est...\n");
									Afficher(*diff2);
								}else
									printf("Impossible d'effectuer la soustraction de ces deux matrices");
								free(mat2A);
								free(mat2B);
								break;
						case 3: printf("Matrice A\n");
								matrice* mat3A = func_charger();
								if(mat3A == NULL)
									break;
								
								Afficher(*mat3A);

								printf("Matrice B\n");
								matrice* mat3B = func_charger();
								if(mat3B == NULL)
									break;
								
								Afficher(*mat3B);
								
								matrice* diff3 = Soustraire(*mat3A, *mat3B);
								if(diff3 != NULL){
									printf("\nLa difference de ces deux matrices est...\n");
									Afficher(*diff3);
								}else
									printf("Impossible d'effectuer la soustraction de ces deux matrices");
								free(mat3A);
								free(mat3B);
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
						case 1: matrice* mat1 = func_creer();
								Afficher(*mat1);

								printf("Entrer la valeur du scalaire : ");
								scanf(" %f", &k);

								matrice* Smat1 = Multiplier_S(*mat1, k);
								printf("\nLa multiplication de cette matrice par %.2f est...\n", k);
								Afficher(*Smat1);
								free(mat1);
								free(Smat1);
								break;
						case 2: matrice* mat2 = func_Generer();
								Afficher(*mat2);

								printf("Entrer la valeur du scalaire : ");
								scanf(" %f", &k);

								matrice* Smat2 = Multiplier_S(*mat2, k);
								printf("\nLa transpose de cette matrice par %.2f est...\n", k);
								Afficher(*Smat2);
								free(mat2);
								free(Smat2);
								break;
						case 3: matrice* mat3 = func_charger();
								if(mat3 == NULL)
									break;
								
								Afficher(*mat3);

								printf("Entrer la valeur du scalaire : ");
								scanf(" %f", &k);

								matrice* Smat3 = Multiplier_S(*mat3, k);
								printf("\nLa transpose de cette matrice par %.2f est...\n", k);
								Afficher(*Smat3);
								free(mat3);
								free(Smat3);
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
						case 1: printf("Matrice A\n");
								matrice* mat1A = func_creer();
								Afficher(*mat1A);

								printf("Matrice B\n");
								matrice* mat1B = func_creer();
								Afficher(*mat1B);

								matrice* mult1 = Multiplier(*mat1A, *mat1B);

								if(mult1 != NULL){
									printf("\nLe produit de ces deux matrices est...\n");
									Afficher(*mult1);
								}else
									printf("Impossible d'effectuer la multiplication de ces deux matrices");
								free(mat1A);
								free(mat1B);
								break;
						case 2: printf("Matrice A\n");
								matrice* mat2A = func_Generer();
								Afficher(*mat2A);

								printf("Matrice B\n");
								matrice* mat2B = func_Generer();
								Afficher(*mat2B);

								matrice* mult2 = Multiplier(*mat2A, *mat2B);
								if(mult2 != NULL){
									printf("\nLe produit de ces deux matrices est...\n");
									Afficher(*mult2);
								}else
									printf("Impossible d'effectuer la multiplication de ces deux matrices");
								free(mat2A);
								free(mat2B);
								break;
						case 3: printf("Matrice A\n");
								matrice* mat3A = func_charger();
								if(mat3A == NULL)
									break;
								
								Afficher(*mat3A);

								printf("Matrice B\n");
								matrice* mat3B = func_charger();
								if(mat3B == NULL)
									break;
								
								Afficher(*mat3B);

								matrice* mult3 = Multiplier(*mat3A, *mat3B);
								if(mult3 != NULL){
									printf("\nLe produit de ces deux matrices est...\n");
									Afficher(*mult3);
								}else
									printf("Impossible d'effectuer la multiplication de ces deux matrices");
								free(mat3A);
								free(mat3B);
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
