#include "Button.h"


Button::Button(std::string btnNom,int srcX, int srcY, int srcW, int srcH, int destX, int destY, int destW, int destH)
{
	this->btnNom = btnNom;
 set_dest( destX,  destY,  destW,  destH);
 set_src( srcX,  srcY,  srcW,  srcH);
}

//Recupere le X et Y du clic
void Button::setClicPos(){
	SDL_Event eventListener;
	if (SDL_PollEvent(&eventListener))
	{
		if (eventListener.type == SDL_MOUSEBUTTONDOWN)
		{
			SDL_GetMouseState(&this->mouseX, &this->mouseY);
		}
	}
}
void Button::estCliquer(int mouseX, int mouseY, SDL_Renderer* renderer) {
	int btnX = this->dest.x;
	int btnY = this->dest.y;
	int btnW = this->dest.w;
	int btnH = this->dest.h;
	//verifier si la sourie x y est dans la surface du carré a la position x y
			if (mouseX > btnX && mouseX <(btnX + btnW + 1) && mouseY > btnY && mouseY < (btnY + btnH + 1))
			{
				unsigned int tempDown = SDL_GetTicks();
				SDL_Event eventListener;
				//mettre le deuxieme texture;
				setImage(this->pathPressed, renderer);

				if (SDL_PollEvent(&eventListener))
				{
					if (eventListener.type == SDL_MOUSEBUTTONUP)
					{	
						setImage(this->pathPassif, renderer); //image passif
						//recupere les clic au relachement
						setClicPos();
						//si il relache le clic sur le boutton
						if (mouseX > btnX && mouseX <(btnX + btnW + 1) && mouseY > btnY && mouseY < (btnY + btnH + 1))
						{
							std::cout << "Action du clic" << std::endl;
							/*Peut etre ajouter un parametre "nom boutton" dans cette fonction et faire un switch juste ici*/
							/*Ou retourner une valeur dans game pour changer de fenettre et L'etat du jeu*/
						}
					}
				}
				
			}
}

void Button::setImagePressed(std::string pathPressed, SDL_Renderer* renderer)
{
	SDL_Surface* surface = IMG_Load(pathPressed.c_str());
	this->texture = SDL_CreateTextureFromSurface(renderer, surface);
}


Button::Button()
		{

		}
Button::~Button()
		{
		}

