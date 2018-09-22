#ifndef INIT_H
#define INIT_H
#include <SFML/Graphics.hpp>

//class stockant les textures en mémoire
class InitialiseurDeSprite
{
private:
	std::vector<sf::Texture> texturePlayer_;
	std::vector<sf::Sprite> spritePlayer_;

	std::vector<sf::Texture> textureObstacle_;
	std::vector<sf::Sprite> spriteObstacle_;

	//Methodes privées
	void initialiserSpritePlayer();
	void initialiserSpriteObstacle();
public:
	InitialiseurDeSprite();
	const std::vector<sf::Sprite>& getSpritePlayer() const { return spritePlayer_; }
	const std::vector<sf::Sprite>& getSpriteObstacle() const { return spriteObstacle_; }
};

#endif // !INIT_H



