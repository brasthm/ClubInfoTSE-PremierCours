#include"initSprite.h"
#include"Utils.h"

InitialiseurDeSprite::InitialiseurDeSprite() 
{
	initialiserSpritePlayer();
	initialiserSpriteAttaquePlayer();
}

//initialise le sprite du joueur
void InitialiseurDeSprite::initialiserSpritePlayer()
{
	for (unsigned int i = 1; i < 9; i++)
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

//initialise les sprites de l'attaque du joueur
void InitialiseurDeSprite::initialiserSpriteAttaquePlayer()
{

}