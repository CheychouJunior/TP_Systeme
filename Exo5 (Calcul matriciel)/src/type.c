#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "type.h"

#define MAX 100 // Le plus grand nombre qui pourra etre genere aleatoirement

//---------- Fonction pour la creation d'une matrice ------------------------
matrice* Creer(int lignes, int colonnes, float **tab){
    matrice* mat = (matrice*)malloc(sizeof(matrice));

    mat->nb_lignes = lignes;
    mat->nb_colonnes = colonnes;
    mat->tab = tab;

    return mat;
}


//---------- Fonction pour generer une matrice avec les valeurs aleatoires --------------------
matrice* Generer(int lignes, int colonnes){
    matrice* mat = (matrice*)malloc(sizeof(matrice));
    srand(time(0));

    mat->nb_lignes = lignes;
    mat->nb_colonnes = colonnes;

    // Allocation memoire de la matrice
    for(int i=0; i<lignes; i++)
        mat->tab[i] = (float *)malloc(colonnes * sizeof(float));
    
    for(int i=0; i<lignes; i++){
        for(int j=0; j<colonnes; j++){
            mat->tab[i][j] = rand() % MAX;
        }
    }

    return mat;
}


//---------- Fonction pour generer une matrice a partir d'un fichier -------------------
matrice* Charger(char *fichier, int lignes, int colonnes){
    matrice* mat = (matrice*)malloc(sizeof(matrice));
    FILE *in = fopen(fichier, "r");

    mat->nb_lignes = lignes;
    mat->nb_colonnes = colonnes;

    if(in == NULL)
        return NULL;

    // Allocation memoire de la matrice
    for(int i=0; i<lignes; i++)
        mat->tab[i] = (float *)malloc(colonnes * sizeof(float));

    for(int i=0; i<lignes; i++){
        for(int j=0; j<colonnes; j++){
            fscanf(in, " %f", &mat->tab[i][j]);
        }
    }

    fclose(in);

    return mat;
}


//---------- Fonction pour Afficher le contenu d'une matrice -------------------------
void Afficher(matrice mat){
    int i,j;

    for(i=0; i<mat.nb_lignes; i++){
        for(j=0; j<mat.nb_colonnes; j++)
            printf("%.2f\t",mat.tab[i][j]);
        printf("\n");
    }    
}


//---------- Fonction pour retourner le nombre de ligne d'une matrice ----------------
int no_lignes(matrice mat){
    return mat.nb_lignes;
}


//---------- Fonction pour retourner le nombre de colonnes d'une matrice ---------------
int no_colonnes(matrice mat){
    return mat.nb_colonnes;
}


//---------- Fonction pour retourner les donnees d'une matrice -------------------
float** donnees(matrice mat){
    return mat.tab;
}
