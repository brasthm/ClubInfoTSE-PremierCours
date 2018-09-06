#ifndef ENTITE_H
#define ENTITE_H

#include "AnimatedSprite.h"
#include "constantes.h"
#include <memory>

//Class regroupant le minimum pour avoir une entité
class Player
{
protected :
	sf::Vector2f position_ = sf::Vector2f(0,260);
	bool isAlive_ = true;
	unsigned int speedX_ = 800;
	unsigned int gravite_ = 800;
	int speedY_ = 1500;
	int vspeed_;
	bool isOnGround_ = true;
	bool isJumping_ = false;

public :
	Player(){}
	void kill() { isAlive_ = false; }
	const sf::Vector2f& getPosition() { return position_; }
	void setPosition(const sf::Vector2f& position) { position_ = position; }
	bool isAlive() { return isAlive_; }
	void draw(sf::RenderWindow& window, sf::Sprite sprite, const sf::Time& elapsedTime) { window.draw(sprite); }
	void draw(sf::RenderWindow& window, AnimatedSprite& animatedSprite, const sf::Time& elapsedTime) { animatedSprite.Animer(elapsedTime); animatedSprite.draw(window); }
	void moveLeft(const sf::Time& elapsedTime);
	void moveRight(const sf::Time& elapsedTime);
	void jump();
};

#endif // !ENTITE_H


