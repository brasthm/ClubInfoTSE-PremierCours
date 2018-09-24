#include "initSprite.h"
#include "constantes.h"

InitialiseurDeSprite::InitialiseurDeSprite() 
{
	texturePlayer_.reserve(NOMBRE_IMAGE_PLAYER + 1);
	textureObstacle_.reserve(5);
	initialiserSpritePlayer(); 
	initialiserSpriteObstacle();
}

// initialise le sprite du joueur
void InitialiseurDeSprite::initialiserSpritePlayer()
{
	for (unsigned int i = 1; i < NOMBRE_IMAGE_PLAYER+1; i++)
	{
		std::string chemin = PLAYER_PATH + "run/player_run";
		chemin.append(std::to_string(i)+".png");
		sf::Texture texture;
		texture.loadFromFile(chemin);
		texturePlayer_.push_back(texture);
		sf::Sprite sprite;
		sprite.setTexture(texturePlayer_[i-1]);
		spritePlayer_.push_back(sprite);
	}

	std::string chemin = PLAYER_PATH + "jump/jump.png";
	sf::Texture texture;
	texture.loadFromFile(chemin);
	texturePlayer_.push_back(texture);
	sf::Sprite sprite;
	sprite.setTexture(texturePlayer_.back());
	spritePlayer_.push_back(sprite);

}

void InitialiseurDeSprite::initialiserSpriteObstacle() 
{
	sf::Texture texture;
	texture.loadFromFile(LAZER_PATH + "lazer_horizontal.png");
	textureObstacle_.push_back(texture);
	texture.loadFromFile(LAZER_PATH + "lazer_vertical.png");
	textureObstacle_.push_back(texture);
	sf::Sprite sprite;
	sprite.setTexture(textureObstacle_[0]);
	spriteObstacle_.push_back(sprite);
	sprite.setTexture(textureObstacle_[1]);
	spriteObstacle_.push_back(sprite);
}