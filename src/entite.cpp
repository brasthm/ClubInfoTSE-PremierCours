#include "entite.h"
#include "constantes.h"

//l'entité bouge dans les limites de la fenetre
void Player::moveLeft(const sf::Time& elapsedTime)
{
	float newPosition = position_.x - (elapsedTime.asSeconds() * speedX_);
	if (newPosition >= 0)
		position_.x = newPosition;
	else
		position_.x = 0;
}

//l'entité bouge dans les limites de la fenetre
void Player::moveRight(const sf::Time& elapsedTime)
{
	float newPosition = position_.x + (elapsedTime.asSeconds() * speedX_);
	if (newPosition <= WINDOW_SIZE_X)
		position_.x = newPosition;
	else
		position_.x = (float)WINDOW_SIZE_X;
}




