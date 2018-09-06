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
	void draw(sf::RenderWindow& window, sf::RectangleShape shape) { window.draw(shape); }
	void draw(sf::RenderWindow& window, sf::Sprite sprite) { window.draw(sprite); }
	void draw(sf::RenderWindow& window, AnimatedSprite& animatedSprite, const sf::Time& elapsedTime) { animatedSprite.Animer(elapsedTime); animatedSprite.draw(window); }
	bool isCollision(const Obstacle& obstacle);
	void jump();
};

class Obstacle
{
public :
	sf::Vector2f position_;
	sf::FloatRect contour_;
private : 
	Obstacle() {}
	void setContour(sf::RectangleShape shape) { contour_ = shape.getGlobalBounds(); }
	void setContour(sf::Sprite sprite) { contour_ = sprite.getGlobalBounds(); }
	void setContour(AnimatedSprite& animatedSprite) { contour_ = animatedSprite.getGlobalBounds(); }
	void draw(sf::RenderWindow& window, sf::RectangleShape shape) { window.draw(shape); }
	void draw(sf::RenderWindow& window, sf::Sprite sprite) { window.draw(sprite); }
	void draw(sf::RenderWindow& window, AnimatedSprite& animatedSprite, const sf::Time& elapsedTime) { animatedSprite.Animer(elapsedTime); animatedSprite.draw(window); }
	void move(float x, float y) { position_.x += x; position_.y += y; }
	const sf::FloatRect& getContour() { return contour_; }
};
#endif // !ENTITE_H


