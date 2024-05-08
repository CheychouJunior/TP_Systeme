#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

	extern matrice* Transposer(matrice mat); // Fonction pour retourner la transposee d'une matrice
	extern matrice* Additionner(matrice matA, matrice matB); // Fonction pour additionner 2 matrice
	extern matrice* Soustraire(matrice matA, matrice matB); // Fonction pour soustraire 2 matrice
	extern matrice* Multiplier_S(matrice mat, float nombre); // Fonction pour effectuer la multiplication scalaire
	extern matrice* Multiplier(matrice matA, matrice matB); // Fonction pour effectuer la multiplication de 2 matrices

#endif // MATRIX_H_INCLUDED
