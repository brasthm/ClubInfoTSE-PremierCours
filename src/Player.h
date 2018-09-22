#ifndef ENTITE_H
#define ENTITE_H

#include "initSprite.h"
#include "AnimatedSprite.h"
#include "Obstacle.h"

class Player
{
	protected :
		int hSpeed_ = 500;
		float vSpeed_ = 0;
		bool isAlive_ = true;
		bool isjumping_ = false;
		sf::Vector2f position_;
		sf::RectangleShape shape_;
		sf::Sprite sprite_, spriteJump_;
		AnimatedSprite* animatedSprite_;
		sf::FloatRect hitbox_;

	public :
		Player(const InitialiseurDeSprite& initsprite);
		void kill() { isAlive_ = false; }
		bool isAlive() const { return isAlive_; }
		void drawRectangle(sf::RenderWindow& window);
		void drawImage(sf::RenderWindow& window);
		void drawImageAnimee(sf::RenderWindow& window, const sf::Time& elapsedTime);
		bool isCollision(sf::RenderWindow& window,const Obstacle& obstacle);
		void jump();
		void moveLeft(const float& x) { position_.x -= x; }
		void moveRight(const float& x){ position_.x += x; }
		void gestion(sf::RenderWindow &window, const sf::Time& elapsedTime);
		void ressurect();
		~Player() { delete animatedSprite_; }
};


#endif // !ENTITE_H


