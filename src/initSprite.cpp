#include"initSprite.h"
#include"Utils.h"
#include "constantes.h"

InitialiseurDeSprite::InitialiseurDeSprite() 
{
	TexturePlayer_.reserve(NOMBRE_IMAGE_PLAYER);
	initialiserSpritePlayer();
}

//initialise le sprite du joueur
void InitialiseurDeSprite::initialiserSpritePlayer()
{
	for (unsigned int i = 1; i < NOMBRE_IMAGE_PLAYER+1; i++)
	{
		std::string chemin = RUNNING_PLAYER_PATH + "player_run";
		chemin.append(intToString(i)+".png");
		sf::Texture texture;
		texture.loadFromFile(chemin);
		TexturePlayer_.push_back(texture);
		sf::Sprite sprite;
		sprite.setTexture(TexturePlayer_[i-1]);
		SpritePlayer_.push_back(sprite);
	}
}