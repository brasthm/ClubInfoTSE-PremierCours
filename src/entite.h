#ifndef ENTITE_H
#define ENTITE_H

#include "initSprite.h"
#include "AnimatedSprite.h"
#include "constantes.h"

class Obstacle
{
private:
	sf::Vector2f position_;
	sf::FloatRect contour_;
	sf::RectangleShape shape_;
	sf::Sprite sprite_;
	AnimatedSprite* animatedSprite_;
public:
	Obstacle(float x, float y) { position_ = { x,y }; }
	void drawRectangle(sf::RenderWindow& window) { shape_.setPosition(position_); window.draw(shape_); }
	void drawImage(sf::RenderWindow& window) { sprite_.setPosition(position_); window.draw(sprite_); }
	void drawImageAnime(sf::RenderWindow& window, const sf::Time& elapsedTime) { animatedSprite_->setPosition(position_); animatedSprite_->Animer(elapsedTime); animatedSprite_->draw(window); }
	void move(float x, float y) { position_.x += x; position_.y += y; }
	const sf::FloatRect& getGlobalBounds() const { return contour_; }
};
#endif // !ENTITE_H


