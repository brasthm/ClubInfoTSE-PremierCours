#ifndef INIT_H
#define INIT_H
#include"entite.h"

class InitialiseurDeSprite
{
private:
	std::vector<sf::Texture> TexturePlayer_;
	std::vector<sf::Sprite> SpritePlayer_;

	//Methode priver
	void initialiserSpritePlayer();
public:
	InitialiseurDeSprite();
	const std::vector<sf::Sprite>& getSpritePlayer() const { return SpritePlayer_; }
};

#endif // !INIT_H



