#include "Button.h"


Button::Button(SDL_Rect src, SDL_Rect dest, bool isSquare, SDL_Renderer* pRenderer)
{
 set_dest( dest.x, dest.y, dest.w, dest.h);
 set_src( src.x,  src.y,  src.w,  src.h);
 this->isSquare = isSquare;
 this->mRenderer = pRenderer;
}


void Button::btnClic_down(int mouseX, int mouseY)
{
	//si il clic sur le boutton
	if (mouseX > this->dest.x && mouseX <(this->dest.x + this->dest.w + 1) && mouseY > this->dest.y && mouseY < (this->dest.y + this->dest.h + 1))
	{
		setImage(this->pathPressed, this->mRenderer);
		std::cout << "le clic est sur le boutton" << std::endl;
	}
}
void Button::btnClic_up(int mouseX, int mouseY)
{
	setImage(this->pathPassif, this->mRenderer); //image passif
	//si il relache le clic sur le boutton
	if (mouseX > this->dest.x && mouseX <(this->dest.x + this->dest.w + 1) && mouseY > this->dest.y && mouseY < (this->dest.y + this->dest.h + 1))
	{
		std::cout << "Action du clic" << std::endl;
		this->action = true;
		/*Peut etre ajouter un parametre "nom boutton" dans cette fonction et faire un switch juste ici*/
		/*Ou retourner une valeur dans game pour changer de fenettre et L'etat du jeu*/
	}
	else puts("Le clic est relacher or du boutton");
}

void Button::draw() {
	// afficher a la position x et y
	SDL_RenderCopy(this->mRenderer, this->texture, &this->src, &this->dest);
}

void Button::setPath(std::string pathPassif, std::string pathPressed) {
	this->pathPassif = pathPassif;
	this->pathPressed = pathPressed;
	this->setImage(this->pathPassif, this->mRenderer);
}


void Button::updateBtn(int WinW, int WinH) {
	//redimensionner le boutton en fonction de la fenettre
	if (this->isSquare == false) {
		this->dest.w = WinW / 16;
		this->dest.h = WinH / 25;
	}
	else {
		this->dest.w = WinW / 16;
		this->dest.h = WinH / 16;
	}
 }

Button::Button()
		{
		}
Button::~Button()
		{
		}

bool Button::get_action() { return this->action; }
void Button::set_action(bool faux) { this->action = faux; }