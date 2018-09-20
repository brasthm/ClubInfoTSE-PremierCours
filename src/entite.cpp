#include "entite.h"

void Obstacle::drawTimer(const sf::Time& elapsedTime) 
{
	sf::RectangleShape barre;
	sol.setSize({ 800,100 });
	sol.setPosition(0, FLOOR);
	sol.setFillColor(sf::Color::Color(153, 76, 0));
}