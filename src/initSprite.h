#ifndef INIT_H
#define INIT_H
#include"entite.h"

class InitialiseurDeSprite
{
private:
	std::vector<sf::Texture> TexturePlayer_;
	std::vector<sf::Sprite> SpritePlayer_;

	std::vector<sf::Texture> TextureAttaquePlayer_;
	std::vector<sf::Sprite> SpriteAttaquePlayer_;

	//Methode priver
	void initialiserSpritePlayer();
	void initialiserSpriteAttaquePlayer();
public:
	InitialiseurDeSprite();
	const std::vector<sf::Sprite>& getSpritePlayer() const { return SpritePlayer_; }
	const std::vector<sf::Sprite>& getSpriteAttaquePlayer() const { return SpriteAttaquePlayer_; }
};

#endif // !INIT_H



