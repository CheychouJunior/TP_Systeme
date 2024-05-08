#ifndef TYPE_H_INCLUDED
#define TYPE_H_INCLUDED
	
	typedef struct matrice{
		int nb_lignes, nb_colonnes;
		float **tab;
	}matrice;

	extern matrice* Creer(int lignes, int colonnes, float **tab); // Creation d'une matrice
	extern matrice* Generer(int lignes, int colonnes); // Generation d'une matrice avec valeur aleatoire
	extern matrice* Charger(char* fichier, int lignes, int colonnes); // Generation d'une matrice en lisant les valeurs d'un fichier
	extern void Afficher(matrice mat); // Afficher la matrice
	extern int no_lignes(matrice mat); // Retourner le nombre de ligne de la matrice
	extern int no_colonnes(matrice mat); // Retourner le nombre de colonnes de la matrice
	extern float** donnees(matrice mat); // Retourner les donnees de la matrice

#endif // TYPE_H_INCLUDED
