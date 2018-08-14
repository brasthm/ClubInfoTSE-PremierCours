#include "entite.h"
#include "constantes.h"

#pragma region IEntiteMovable
//L'entite saute avec une accélération de base, la gravité la fait redessendre. l'objet attendu est le sol
void IEntiteMovable::gestionPositionY(sf::Time elapsedTime, sf::FloatRect sol)
{
	if (isCollision(sol))
	{
		isOnGround = true;
		isJumping = false;
		nbTour = 0;
	}

	if (isJumping)
	{
		nbTour++;
		position.y -= elapsedTime.asSeconds()*(speedY - gravite * nbTour);
	}

	if (!isOnGround)
		position.y -= elapsedTime.asSeconds()*gravite;
}

//l'entité bouge dans les limites de la fenetre
void IEntiteMovable::move(sf::Time elapsedTime)
{
	unsigned int newPosition = position.x + elapsedTime.asSeconds() * speedX;
	if (newPosition <= WINDOW_SIZE_X)
		position.x = newPosition;
	else
		position.x = WINDOW_SIZE_X - spriteAnimer.getSize().x;
}
#pragma endregion

#pragma region ICaster
ICaster::~ICaster() 
{
	for(std::vector<SpriteAnimer*>::const_iterator it = projectiles.begin(); it != projectiles.end(); it++)
		delete *it;
}

void ICaster::shoot(sf::Time elapsedTime)
{
	shootProgression += elapsedTime;
	if (shootProgression >= shootDelay)
	{
		projectiles.push_back(new SpriteAnimer(projectilesSprite, swapRateProjectiles));
		shootProgression = sf::Time::Zero;
	}

}

void ICaster::drawProjectiles(sf::RenderWindow& window)
{
	for (size_t i = 0; i < projectiles.size(); i++)
		projectiles[i]->draw(window);
}
#pragma endregion

#pragma region Player
Player::Player(SpriteAnimer spriteanimer, unsigned int PvMax, unsigned int Degat, sf::Time shootDelay, std::vector<sf::Sprite>& shootSprites, sf::Time shootSwap) :ICaster(shootDelay, shootSprites, shootSwap), IEntiteMovable(spriteanimer, PvMax, Degat)
{

}

void Player::heal(unsigned int heal)
{
	unsigned int newPv = pvActuel + heal;
	pvActuel = (newPv > pvMax)? pvMax : newPv;
}
#pragma endregion

