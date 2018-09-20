#ifndef INIT_H
#define INIT_H
#include <SFML/Graphics.hpp>

//class stockant les textures en mémoire
class InitialiseurDeSprite
{
private:
	std::vector<sf::Texture> texturePlayer_;
	std::vector<sf::Sprite> spritePlayer_;

	//Methode priver
	void initialiserSpritePlayer();
public:
	InitialiseurDeSprite();
	const std::vector<sf::Sprite>& getSpritePlayer() const { return spritePlayer_; }
};

#endif // !INIT_H



