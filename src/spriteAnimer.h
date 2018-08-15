#ifndef SPRITE_ANIMER_H
#define SPRITE_ANIMER_H

#include <SFML/Graphics.hpp>
#include <vector>

//Class dont le but est de gérer plusieur sprite pour faire un sprite animé
class SpriteAnimer
{
private:
	std::vector<sf::Sprite> sprites;
	sf::Sprite spriteDrawable;
	sf::Time swapRate;
	sf::Time swapProgression;
	size_t idSprite;
	
public:
	SpriteAnimer(std::vector<sf::Sprite>& spriteVector, sf::Time swaprate) : sprites(spriteVector), swapRate(swaprate) {}
	void Animer(sf::Time elapsedTime);
	void draw(sf::RenderWindow& window) { window.draw(spriteDrawable);}
	sf::Vector2u getSize() { return spriteDrawable.getTexture()->getSize(); }
	sf::FloatRect getGlobalBounds() { return spriteDrawable.getGlobalBounds(); }
};

#endif // !SPRITE_ANIMER_H
