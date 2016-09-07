#include <iostream>

#include <cstdlib>
	

#include "SDL.h"

#define TAB_SIZE 1000

class BasicBrownian
{

public:

	BasicBrownian();
	void afficher_pastille( const int pastilleX, const int pastilleY );
	void drawUp( const int posX, const int posY );

	int drawBro();
	int drawBroMult(int numberOfBro);
	int XScreenSize;
	int YScreenSize;
	int nbOfbro;
	int TAILLE_PASTILLE;

private:
	int TAILLE_ELEMENT;	// Taille des éléments en pixels
	int TAILLE_ECRAN;	// Taille de l'ecran en éléments
									// Multiplier par TAILLE-ELEMENT por obtenir la taille en px


	int DELAI;			// Delai pour la vitesse du jeu

	int TAILLE_SERPENT_DEBUT; // taille du serpent au lancement du jeu
	int POS_X_DEPART; // position X du serpent au debut du jeu
	int POS_Y_DEPART; // position Y du serpent au debut du jeu

	//const int TAB_SIZE; 

	int totalZero;
	int totalUn;
	int totalDeux;
	int totalTrois;


	SDL_Surface *ecranS;
	int positionTab[4];
	int positionTabMult[TAB_SIZE][4];
	int randomR[TAB_SIZE];
	int randomG[TAB_SIZE];
	int randomB[TAB_SIZE];

	int currentTabPos;

	


};
