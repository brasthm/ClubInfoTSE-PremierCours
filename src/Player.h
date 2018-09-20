#ifndef ENTITE_H
#define ENTITE_H

#include "InitSprite.h"
#include "AnimatedSprite.h"
#include "constantes.h"
#include "Obstacle.h"

//Cyril fait le jump
class Player
{
	protected :
		int hSpeed_ = 500;
		float vSpeed_ = 0;
		bool isAlive_ = true;
		bool isjumping_ = false;
		sf::Vector2f position_;
		sf::RectangleShape shape_;
		sf::Sprite sprite_;
		AnimatedSprite* animatedSprite_;

	public :
		Player(const InitialiseurDeSprite& initsprite);
		void kill() { isAlive_ = false; }
		bool isAlive() const { return isAlive_; }
		void drawRectangle(sf::RenderWindow& window);
		void drawImage(sf::RenderWindow& window);
		void drawImageAnime(sf::RenderWindow& window, const sf::Time& elapsedTime);
		bool isCollision(const Obstacle& obstacle);
		void jump();
		void moveLeft(const float& x) { position_.x -= x; }
		void moveRight(const float& x){ position_.x += x; }
		void gestion(sf::RenderWindow &window, const sf::Time& elapsedTime);
		~Player() { delete animatedSprite_; }
};


#endif // !ENTITE_H

