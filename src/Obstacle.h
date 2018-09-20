#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "SFML\Graphics.hpp"
#include "AnimatedSprite.h"
#include "initSprite.h"

class Obstacle
{
	private:
		sf::Vector2f position_;
		sf::RectangleShape shape_, barre1_, barre2_;
		sf::Sprite sprite_;
		sf::Time time_ = sf::milliseconds(500);
		sf::Time timeProgression_;
		bool dead_ = false;
		bool deadly_ = false;
		bool isHorizontal_ = false;

	public:
		Obstacle(const InitialiseurDeSprite& inisprite, const sf::Vector2f& position);
		void drawImage(sf::RenderWindow& window);
		sf::FloatRect getGlobalBounds() const { return sprite_.getGlobalBounds(); }
		void draw(sf::RenderWindow& window, const sf::Time& elapsedTime);
		bool isDead() { return dead_; }
		bool isDeadly() const { return deadly_; }
};


#endif // !OBSTACLE_H

