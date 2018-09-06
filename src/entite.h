#ifndef ENTITE_H
#define ENTITE_H

#include "AnimatedSprite.h"
#include "constantes.h"

class Player
{
protected :
	bool isAlive_ = true;
	unsigned int gravite_ = 800;
	int speedY_ = 1500;
	int vspeed_;
	bool isOnGround_ = true;
	bool isJumping_ = false;
	float positionY_;
	sf::FloatRect contour_;

public :
	Player(){}
	void kill() { isAlive_ = false; }
	bool isAlive() { return isAlive_; }
	void setContour(sf::RectangleShape shape) { contour_ = shape.getGlobalBounds(); }
	void setContour(sf::Sprite sprite) { contour_ = sprite.getGlobalBounds(); }
	void setContour(AnimatedSprite& animatedSprite) { contour_ = animatedSprite.getGlobalBounds(); }
	void draw(sf::RenderWindow& window, sf::RectangleShape shape) { shape.setPosition(0,positionY_); window.draw(shape); }
	void draw(sf::RenderWindow& window, sf::Sprite sprite) {sprite.setPosition(0, positionY_); window.draw(sprite); }
	void draw(sf::RenderWindow& window, AnimatedSprite& animatedSprite, const sf::Time& elapsedTime) { animatedSprite.setPosition({ 0,positionY_ }); animatedSprite.Animer(elapsedTime); animatedSprite.draw(window); }
	bool isCollision(const Obstacle& obstacle);
	void jump();
};

class Obstacle
{
public :
	sf::Vector2f position_;
	sf::FloatRect contour_;
private : 
	Obstacle(float x, float y) { position_ = { x,y }; }
	void setContour(sf::RectangleShape shape) { contour_ = shape.getGlobalBounds(); }
	void setContour(sf::Sprite sprite) { contour_ = sprite.getGlobalBounds(); }
	void setContour(AnimatedSprite& animatedSprite) { contour_ = animatedSprite.getGlobalBounds(); }
	void draw(sf::RenderWindow& window, sf::RectangleShape shape) { shape.setPosition(position_); window.draw(shape); }
	void draw(sf::RenderWindow& window, sf::Sprite sprite) { sprite.setPosition(position_); window.draw(sprite); }
	void draw(sf::RenderWindow& window, AnimatedSprite& animatedSprite, const sf::Time& elapsedTime) { animatedSprite.setPosition(position_); animatedSprite.Animer(elapsedTime); animatedSprite.draw(window); }
	void move(float x, float y) { position_.x += x; position_.y += y; }
	const sf::FloatRect& getContour() const { return contour_; }
};
#endif // !ENTITE_H


