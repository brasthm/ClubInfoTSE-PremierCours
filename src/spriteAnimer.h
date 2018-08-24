#ifndef SPRITE_ANIMER_H
#define SPRITE_ANIMER_H

#include <SFML/Graphics.hpp>
#include <vector>

//Class dont le but est de gérer plusieur sprite pour faire un sprite animé
class SpriteAnimer
{
private:
	std::vector<sf::Sprite> sprites_;
	sf::Sprite spriteDrawable_;
	sf::Time swapRate_;
	sf::Time swapProgression_;
	size_t idSprite_ =0;
	sf::Vector2f position_ = { 0,0 };
	
public:
	SpriteAnimer(std::vector<sf::Sprite>& spriteVector, sf::Time swaprate) : sprites_(spriteVector), swapRate_(swaprate) {}
	void Animer(const sf::Time& elapsedTime);
	void draw(sf::RenderWindow& window) { spriteDrawable_.setPosition(position_); window.draw(spriteDrawable_); }
	sf::Vector2u getSize() { return spriteDrawable_.getTexture()->getSize(); }
	sf::FloatRect getGlobalBounds() { return spriteDrawable_.getGlobalBounds(); }
	void setPosition(sf::Vector2f position) { position_ = position; }
};

#endif // !SPRITE_ANIMER_H
