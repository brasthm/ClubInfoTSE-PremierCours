#ifndef ENTITE_H
#define ENTITE_H

#include "initSprite.h"
#include "AnimatedSprite.h"
#include "constantes.h"

//Cyril fait le jump
class Player
{
protected :
	bool isAlive_ = true;
	sf::Vector2f position_;
	sf::FloatRect contour_;
	sf::RectangleShape shape_;
	sf::Sprite sprite_;
	AnimatedSprite* animatedSprite_;

public :
	Player(const InitialiseurDeSprite& initsprite);
	void kill() { isAlive_ = false; }
	bool isAlive() const { return isAlive_; }
	void drawRectangle(sf::RenderWindow& window) { shape_.setPosition(position_); window.draw(shape_); }
	void drawImage(sf::RenderWindow& window) {sprite_.setPosition(position_); window.draw(sprite_); }
	void drawImageAnime(sf::RenderWindow& window, const sf::Time& elapsedTime) { animatedSprite_->setPosition(position_); animatedSprite_->Animer(elapsedTime); animatedSprite_->draw(window); }
	bool isCollision(const Obstacle& obstacle);
	void jump();
	void moveLeft(const float& x) { position_.x -= x; }
	void moveRight(const float& x){ position_.x += x; }
	~Player() { delete animatedSprite_; }
};

class Obstacle
{
public :
	sf::Vector2f position_;
	sf::FloatRect contour_;
	sf::RectangleShape shape_;
	sf::Sprite sprite_;
	AnimatedSprite* animatedSprite_;
private : 
	Obstacle(float x, float y) { position_ = { x,y }; }
	void drawRectangle(sf::RenderWindow& window) { shape_.setPosition(position_); window.draw(shape_); }
	void drawImage(sf::RenderWindow& window) { sprite_.setPosition(position_); window.draw(sprite_); }
	void drawImageAnime(sf::RenderWindow& window, const sf::Time& elapsedTime) { animatedSprite_->setPosition(position_); animatedSprite_->Animer(elapsedTime); animatedSprite_->draw(window); }
	void move(float x, float y) { position_.x += x; position_.y += y; }
	const sf::FloatRect& getContour() const { return contour_; }
};
#endif // !ENTITE_H


