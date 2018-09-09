#include"initSprite.h"
#include"Utils.h"
#include "constantes.h"

InitialiseurDeSprite::InitialiseurDeSprite() 
{
	texturePlayer_.reserve(NOMBRE_IMAGE_PLAYER);
	initialiserSpritePlayer();
}

//initialise le sprite du joueur
void InitialiseurDeSprite::initialiserSpritePlayer()
{
	for (unsigned int i = 1; i < NOMBRE_IMAGE_PLAYER+1; i++)
	{
		std::string chemin = RUNNING_PLAYER_PATH + "player_run";
		chemin.append(std::to_string(i)+".png");
		sf::Texture texture;
		texture.loadFromFile(chemin);
		texturePlayer_.push_back(texture);
		sf::Sprite sprite;
		sprite.setTexture(texturePlayer_[i-1]);
		spritePlayer_.push_back(sprite);
	}
}