#include "Text.h"
#include <string>


Text::Text()
{
}


/* --------------------------------------------------------------------------
   Create_text
   --------------------------------------------------------------------------
   Fonction privee de creation de texte.
   --------------------------------------------------------------------------
   E: Pointeur de la surface sur laquelle rendre le texte.
   E: Position X du texte.
   E: Position Y du texte.
   E: Taille de la police.
   E: Couleur de la police (a creer avec la fonction SDL_MapRGB).
   E: Nom de la police a utiliser.
   E: Texte a rendre.
   S:
   -------------------------------------------------------------------------- */

 Text::Text(SDL_Renderer * p_renderer,
	int x, int y,
	short font_size, Uint32 i_color,
	std::string font_way, std::string  message) //const char si pas string
{
	this->p_font = NULL;
	this->font_way = font_way;
	SDL_Surface   *   s_text = NULL;
	SDL_Surface *p_screen = SDL_CreateRGBSurface(SDL_SWSURFACE,200,200,);
	this->text = message;

	/* ----- Initialisation de SDL_ttf ----- */
	if (TTF_Init() < 0)
	{
		printf("TTF_Init: %s\n", TTF_GetError());
	}


	/* ----- Chargement de toutes les donnees necessaires ----- */

	/* Recuperation des informations de couleurs. */
	this->color.r = (i_color & SDL_MapRGB(p_screen->format, 255, 0, 0)) >> 16;
	this->color.g = (i_color & SDL_MapRGB(p_screen->format, 0, 255, 0)) >> 8;
	this->color.b = (i_color & SDL_MapRGB(p_screen->format, 0, 0, 255));


	/* Chargement de la police */
	p_font = TTF_OpenFont(font_way.c_str(), font_size); //C:\Windows\Fonts

	if (!p_font)
	{
		std::cout << "erreur police" << std::endl;
	}


	/* ----- Rendu du texte ----- */

	/* Mise en place du message sur la surface de jeu */
	if (s_text == NULL)
	{
		std::cout << "erreur affichage sur la surface" << std::endl;

	}
	else if (s_text != NULL)
	{
		rect_dest.x = x;
		rect_dest.y = y;
		rect_dest.w = s_text->w;
		rect_dest.h = s_text->h;

		/* .......*/
		this->mTexture = SDL_CreateTextureFromSurface(this->mRenderer, s_text);
		SDL_FreeSurface(s_text);
	}

	/* Fermeture de la police */

}



 Text::~Text()
 {
	 TTF_CloseFont(p_font);
	 TTF_Quit();
 }

 void Text::update(std::string message) {SDL_Surface *s_text;s_text = TTF_RenderText_Solid(this->p_font, message.c_str(), this->color); }

 void Text::draw() {
	 SDL_Rect rect;
	 rect.x = 0;
	 rect.y = 0;
	 rect.w = this->rect_dest.w;
	 rect.h = this->rect_dest.h;
	 SDL_RenderCopy(this->mRenderer, this->mTexture, &rect, &rect_dest);
 }