#ifndef INIT_H
#define INIT_H
#include <SFML/Graphics.hpp>

//class stockant les textures en mémoire
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



