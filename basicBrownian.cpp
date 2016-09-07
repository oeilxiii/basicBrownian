#include "basicBrownian.h"
// testGIT
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <sstream>  

void my_handler(int s){
           printf("Caught signal %d\n",s);
           exit(1); 

}


BasicBrownian::BasicBrownian(){


	srand(time(0));

	TAILLE_ELEMENT = 5;	// Taille des éléments en pixels
	TAILLE_ECRAN = 70;	// Taille de l'ecran en éléments
									// Multiplier par TAILLE-ELEMENT por obtenir la taille en px
	TAILLE_PASTILLE = 2;

	DELAI = 100;			// Delai pour la vitesse du jeu

	TAILLE_SERPENT_DEBUT = 10; // taille du serpent au lancement du jeu
	POS_X_DEPART = 20; // position X du serpent au debut du jeu
	POS_Y_DEPART = 20; // position Y du serpent au debut du jeu

	//TAB_SIZE = 10000; 

	SDL_Surface *ecranS = NULL;
	positionTab[4]={-1};

	currentTabPos = 0;
	totalZero = 0;
	totalUn = 0;
	totalDeux = 0;
	totalTrois = 0;

}

int BasicBrownian::drawBro()
{
    SDL_Surface *ecran = NULL, *zozor = NULL;
    SDL_Rect positionZozor;
    SDL_Event event;
    int continuer = 1;

    SDL_Init(SDL_INIT_VIDEO);

    //ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    ecran = SDL_SetVideoMode(XScreenSize, YScreenSize, 32, SDL_HWSURFACE);
    ecranS = ecran;
    SDL_WM_SetCaption("Gestion des événements en SDL", NULL);
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    this->positionTab[0] = (rand() % (int)(XScreenSize - 0 + 1));//XScreenSize /2;//ecran->w / 2;	
    this->positionTab[1] = (rand() % (int)(YScreenSize - 0 + 1));//YScreenSize /2;//ecran->h / 2;

    while (continuer)
    {
    SDL_Delay(1);
    //int randomV = rand()%4;
    

    int randomV = 0 + (rand() % (int)(3 - 0 + 1));
    //std::cout << "number of 0 " << totalZero << "number of 1 " << totalUn << "number of 2 " << totalDeux << "number of 3 " << totalTrois <<std::endl;	
	//std::cout << "this->positionTab[0]" << this->positionTab[0]<< std::endl;
	//std::cout << "this->positionTab[1]" << this->positionTab[1] <<std::endl;
        /*SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
		std::cout << "QUITTT" << std::endl;
                continuer = 0;
                break;	
	}*/


		SDL_Rect rect;
		rect.x = this->positionTab[0] ;
		rect.y = this->positionTab[1] ;

	//switch(randomV)
        //{
            /*case SDL_QUIT:
                continuer = 0;
                break;*/
            //case 0://SDL_KEYDOWN:
                //switch(event.key.keysym.sym)
		switch(randomV)
                {
                    case 0://SDLK_UP: // Flèche haut
			currentTabPos++;
			totalZero++;
			if (this->positionTab[1] > 0){
			this->positionTab[0] = this->positionTab[0];	
    		this->positionTab[1] = this->positionTab[1]  - TAILLE_PASTILLE;   
			this->positionTab[2] = 0;

			rect.x = this->positionTab[0] ;
			rect.y = this->positionTab[1] ;
			rect.h = TAILLE_PASTILLE;
			rect.w = 1;
			}
			else{
				//std::cout << "NOT going UP !" << std::endl;
			}			
			//std::cout << "going UP !" << std::endl;	

			break;
                    case 1://SDLK_DOWN: // Flèche bas
			currentTabPos++;
			totalUn++;
			if (this->positionTab[1] < YScreenSize){
			this->positionTab[0] = this->positionTab[0];	
    			this->positionTab[1] = this->positionTab[1]  + TAILLE_PASTILLE;   
			this->positionTab[2] = 1;

			rect.x = this->positionTab[0] ;

			rect.h = TAILLE_PASTILLE;
			rect.w = 1;
			rect.y = this->positionTab[1] - TAILLE_PASTILLE;
			}
			else{
				//std::cout << "NOT going DOWN !" << std::endl;
			}
			//std::cout << "going DOWN !" << std::endl;		

                        break;
                    case 2://SDLK_RIGHT: // Flèche droite
			currentTabPos++;
			totalDeux++;
			if (this->positionTab[0] < XScreenSize){
			this->positionTab[0] = this->positionTab[0] + TAILLE_PASTILLE;	
    			this->positionTab[1] = this->positionTab[1]  ;   
			this->positionTab[2] = 2;
			
			//rect.x = this->positionTab[0] ;
			rect.y = this->positionTab[1] ;

			rect.h = 1;
			rect.w = TAILLE_PASTILLE;
			rect.x = this->positionTab[0] - TAILLE_PASTILLE;
			}
			else{
				//std::cout << "NOT going RIGHT !" << std::endl;
			}
			//std::cout << "going RIGHT !" << std::endl;	
                        break;
                    case 3://SDLK_LEFT: // Flèche gauche
			currentTabPos++;
			totalTrois++;
			if (this->positionTab[0] > 0){
			this->positionTab[0] = this->positionTab[0] - TAILLE_PASTILLE;	
    		this->positionTab[1] = this->positionTab[1]  ;   
			this->positionTab[2] = 3;

			rect.x = this->positionTab[0] ;
			rect.y = this->positionTab[1] ;

			rect.h = 1;
			rect.w = TAILLE_PASTILLE;			
			}
			else{
				//std::cout << "NOT going LEFT !" << std::endl;
			}
			//std::cout << "going LEFT !" << std::endl;	
                        break;
                }
                //break;
        //}



    // pixel rouge pour la pastille


    
        /* On efface l'écran PAS L'ECRAN */
        //SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

	
		int randomR = 0 + (rand() % (int)(255 - 0 + 1));
		int randomG = 0 + (rand() % (int)(255 - 0 + 1));
		int randomB = 0 + (rand() % (int)(255 - 0 + 1));
		SDL_FillRect( ecran, &rect, SDL_MapRGB( ecran->format, randomR, randomG, randomB ) );
		//pos2++;
	//}
	
        /* On met à jour l'affichage */
        SDL_Flip(ecran);
    }

    SDL_Quit();

    return EXIT_SUCCESS;
}

int BasicBrownian::drawBroMult(int numberOfBro)
{
    SDL_Surface *ecran = NULL, *zozor = NULL;
    SDL_Rect positionZozor;
    SDL_Event event;
    int continuer = 1;

    SDL_Init(SDL_INIT_VIDEO);

    //ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    ecran = SDL_SetVideoMode(XScreenSize, YScreenSize, 32, SDL_HWSURFACE);
    ecranS = ecran;
    SDL_WM_SetCaption("Gestion des événements en SDL", NULL);
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    for (int broCount = 0; broCount < numberOfBro; broCount++)
    { 
	int temp1 = (rand() % (int)(XScreenSize - 0 + 1)) ;
    	this->positionTabMult[broCount][0] = temp1 ;//XScreenSize /2;//ecran->w / 2;	
	std::cout << "temp1  " << temp1 <<std::endl;
	int temp2 = (rand() % (int)(YScreenSize - 0 + 1)) ;
    	this->positionTabMult[broCount][1] = temp2 ;//YScreenSize /2;//ecran->h / 2;
	std::cout << "temp2  " << temp2 <<std::endl;
		randomR[broCount] = 0 + (rand() % (int)(255 - 0 + 1));
		randomG[broCount] = 0 + (rand() % (int)(255 - 0 + 1));
		randomB[broCount] = 0 + (rand() % (int)(255 - 0 + 1));
    }

    int cpt = 0;
    int cptScreenshot = 0;

    while (continuer)
    {
    SDL_Delay(1);
    //int randomV = rand()%4;
    

    //int randomV = 0 + (rand() % (int)(3 - 0 + 1));
    //std::cout << "number of 0 " << totalZero << "number of 1 " << totalUn << "number of 2 " << totalDeux << "number of 3 " << totalTrois <<std::endl;	
	//std::cout << "this->positionTab[0]" << this->positionTab[0]<< std::endl;
	//std::cout << "this->positionTab[1]" << this->positionTab[1] <<std::endl;
        /*SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
		std::cout << "QUITTT" << std::endl;
                continuer = 0;
                break;	
	}*/


		SDL_Rect rect;
		SDL_Rect rect2[numberOfBro];
    		for (int broCount = 0; broCount < numberOfBro; broCount++)
		{
		rect2[broCount].x = this->positionTabMult[broCount][0] ;
		rect2[broCount].y = this->positionTabMult[broCount][1] ;
		}
	//switch(randomV)
        //{
            /*case SDL_QUIT:
                continuer = 0;
                break;*/
            //case 0://SDL_KEYDOWN:
                //switch(event.key.keysym.sym)
    		for (int broCount = 0; broCount < numberOfBro; broCount++)
		{
			int randomV = 0 + (rand() % (int)(3 - 0 + 1));
			switch(randomV)
		        {
		            case 0://SDLK_UP: // Flèche haut
				currentTabPos++;
				totalZero++;
				if (this->positionTabMult[broCount][1] > 0){
				this->positionTabMult[broCount][0] = this->positionTabMult[broCount][0];	
	    		this->positionTabMult[broCount][1] = this->positionTabMult[broCount][1]  - TAILLE_PASTILLE;   
				this->positionTabMult[broCount][2] = 0;

				rect2[broCount].x = this->positionTabMult[broCount][0] ;
				rect2[broCount].y = this->positionTabMult[broCount][1] ;
				rect2[broCount].h = TAILLE_PASTILLE;
				rect2[broCount].w = 1;
				}
				else{
					//std::cout << "NOT going UP !" << std::endl;
				}			
				//std::cout << "going UP !" << std::endl;	

				break;
		            case 1://SDLK_DOWN: // Flèche bas
				currentTabPos++;
				totalUn++;
				if (this->positionTabMult[broCount][1] < YScreenSize){
				this->positionTabMult[broCount][0] = this->positionTabMult[broCount][0];	
	    			this->positionTabMult[broCount][1] = this->positionTabMult[broCount][1]  + TAILLE_PASTILLE;   
				this->positionTabMult[broCount][2] = 1;

				rect2[broCount].x = this->positionTabMult[broCount][0] ;

				rect2[broCount].h = TAILLE_PASTILLE;
				rect2[broCount].w = 1;
				rect2[broCount].y = this->positionTabMult[broCount][1] - TAILLE_PASTILLE;
				}
				else{
					//std::cout << "NOT going DOWN !" << std::endl;
				}
				//std::cout << "going DOWN !" << std::endl;		

		                break;
		            case 2://SDLK_RIGHT: // Flèche droite
				currentTabPos++;
				totalDeux++;
				if (this->positionTabMult[broCount][0] < XScreenSize){
				this->positionTabMult[broCount][0] = this->positionTabMult[broCount][0] + TAILLE_PASTILLE;	
	    			this->positionTabMult[broCount][1] = this->positionTabMult[broCount][1]  ;   
				this->positionTabMult[broCount][2] = 2;
			
				//rect2[broCount].x = this->positionTabMult[broCount][0] ;
				rect2[broCount].y = this->positionTabMult[broCount][1] ;

				rect2[broCount].h = 1;
				rect2[broCount].w = TAILLE_PASTILLE;
				rect2[broCount].x = this->positionTabMult[broCount][0] - TAILLE_PASTILLE;
				}
				else{
					//std::cout << "NOT going RIGHT !" << std::endl;
				}
				//std::cout << "going RIGHT !" << std::endl;	
		                break;
		            case 3://SDLK_LEFT: // Flèche gauche
				currentTabPos++;
				totalTrois++;
				if (this->positionTabMult[broCount][0] > 0){
				this->positionTabMult[broCount][0] = this->positionTabMult[broCount][0] - TAILLE_PASTILLE;	
	    		this->positionTabMult[broCount][1] = this->positionTabMult[broCount][1]  ;   
				this->positionTabMult[broCount][2] = 3;

				rect2[broCount].x = this->positionTabMult[broCount][0] ;
				rect2[broCount].y = this->positionTabMult[broCount][1] ;

				rect2[broCount].h = 1;
				rect2[broCount].w = TAILLE_PASTILLE;			
				}
				else{
					//std::cout << "NOT going LEFT !" << std::endl;
				}
				//std::cout << "going LEFT !" << std::endl;	
		                break;
		        }
		}
                //break;
        //}



    // pixel rouge pour la pastille


    
        /* On efface l'écran PAS L'ECRAN */
        //SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

    		for (int broCount = 0; broCount < numberOfBro; broCount++)
		{	
		int randomR2 = 0 + (rand() % (int)(255 - 0 + 1));
		int randomG2 = 0 + (rand() % (int)(255 - 0 + 1));
		int randomB2 = 0 + (rand() % (int)(255 - 0 + 1));
		SDL_FillRect( ecran, &rect2[broCount], SDL_MapRGB( ecran->format, randomR[broCount], randomG[broCount], randomB[broCount] ) );
		}
		//pos2++;
	//}
	
		if(cpt%10000 == 0)
		{
			cptScreenshot++;
			std::ostringstream convert ;
			//std::string screenshotName = "saveImg/screenshot" + std::string(cptScreenshot) + ".bmp";


			convert << "saveImg/screenshot";
			convert << cptScreenshot;  
			convert << ".bmp";

			std::string temp = convert.str();
			std::cout << "TTTTTTT :  "  <<  temp << std::endl; 

			SDL_SaveBMP(ecran, temp.c_str());
		}

		cpt++;



        /* On met à jour l'affichage */
        SDL_Flip(ecran);
    }

    SDL_Quit();

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{


if (argc < 5){
	std::cout << " usage : ./out XScreenSize YScreenSize numberOfBro taillePastille" << std::endl;
	return 1;
}



struct sigaction sigIntHandler;

   sigIntHandler.sa_handler = my_handler;
   sigemptyset(&sigIntHandler.sa_mask);
   sigIntHandler.sa_flags = 0;

   sigaction(SIGINT, &sigIntHandler, NULL);

	BasicBrownian* temp = new BasicBrownian();
	temp->XScreenSize = atoi(argv[1]);
	temp->YScreenSize = atoi(argv[2]);
	temp->nbOfbro = atoi(argv[3]);
	temp->TAILLE_PASTILLE = atoi(argv[4]);
	//temp->drawBro();
	temp->drawBroMult(temp->nbOfbro);	
	return 0;
}
