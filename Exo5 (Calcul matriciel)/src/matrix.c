#include <stdio.h>
#include <type.h>
#include <matrix.h>


//------------ Fonction pour calculer la transposee d'une matrice ------------------------
matrice* Transposer(matrice mat){
    int l = no_lignes(mat);
    int c = no_colonnes(mat);
    matrice *A = Generer(c, l);

    for(int i=0; i<l; i++)
        for(int j=0; j<c; j++)
            A->tab[j][i] = mat.tab[i][j];

    return A;
}


//------------ Fonction pour calculer l'addition de deux matrices ------------------------
matrice* Additionner(matrice matA, matrice matB){
    int l = no_lignes(matA);
    int c = no_colonnes(matA);

    if(l != no_lignes(matB) || c != no_colonnes(matB)) // Addition is not possible
        return NULL;
    
    matrice *A = Generer(l, c);

    for(int i=0; i<l; i++)
        for(int j=0; j<c; j++)
            A->tab[i][j] = matA.tab[i][j] + matB.tab[i][j];
    
    return A;
}


//------------ Fonction pour calculer la soustraction de deux matrices -------------------
matrice* Soustraire(matrice matA, matrice matB){
    int l = no_lignes(matA);
    int c = no_colonnes(matA);

    if(l != no_lignes(matB) || c != no_colonnes(matB)) // Addition is not possible
        return NULL;
    
    matrice *A = Generer(l, c);

    for(int i=0; i<l; i++)
        for(int j=0; j<c; j++)
            A->tab[i][j] = matA.tab[i][j] - matB.tab[i][j];
    
    return A;
}


//------------ Fonction pour effectuer la multiplication scalaire d'une matrice ----------
matrice* Multiplier_S(matrice mat, float nombre){
    int l = no_lignes(mat);
    int c = no_colonnes(mat);
    
    matrice *A = Generer(l, c);

    for(int i=0; i<l; i++)
        for(int j=0; j<c; j++)
            A->tab[i][j] = nombre * mat.tab[i][j];
    
    return A;
}


//------------ Fonction pour effectuer la multiplication de deux matrices ----------------
matrice* Multiplier(matrice matA, matrice matB){
    int p = no_lignes(matA);
    int q = no_colonnes(matA);
    int r = no_colonnes(matB);

    if(q != no_lignes(matB)) // matrice incompatible pour la multiplication
        return NULL;

    matrice *A = Generer(p, r);  // matA = p x q, matB = q x r, mult(matA, matB) = p x r

    for(int i=0; i<p; i++){
        for(int j=0; j<q; j++){
            A->tab[i][j] = 0;
            for(int k=0; k<r; k++)
                A->tab[i][j] += (matA.tab[i][k] * matB.tab[k][j]); 
        }
    }
    return A;
}
