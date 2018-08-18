#include "entite.h"
#include "constantes.h"

void AttaqueCaster::attaque(const sf::Time& elapsedTime)
{
	shootProgression_ += elapsedTime;
	if (shootProgression_ >= shootDelay_)
	{
		projectiles_.push_back(std::make_unique<SpriteAnimer>(projectilesSprite_, swapRateProjectiles_));
		shootProgression_ = sf::Time::Zero;
	}

}

void AttaqueCaster::draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < projectiles_.size(); i++)
		projectiles_[i]->draw(window);
}

void AttaqueCac::attaque(const sf::Time& elapsedTime)
{
	attaqueProgression_ += elapsedTime;
	if (attaqueProgression_ >= attaqueDelay_)
		attaqueProgression_ = sf::Time::Zero;
}

void AttaqueCac::draw(sf::RenderWindow& window)
{
	//draw annimation ? sprites ? rien ?
}

void IEntite::hurt(const unsigned int& degat)
{
	if (pvActuel_ - degat > 0)
		pvActuel_ -= degat;
	else
	{
		pvActuel_ = 0;
		isAlive_ = false;
	}	
}

//L'entite saute avec une accélération de base, la gravité la fait redessendre. l'objet attendu est le sol
void IEntiteMovable::gestionPositionY(const sf::Time& elapsedTime, const sf::FloatRect& sol)
{
	if (isCollision(sol))
	{
		isOnGround_ = true;
		isJumping_ = false;
		nbTour_ = 0;
	}

	if (isJumping_)
	{
		nbTour_++;
		position_.y -=  (unsigned int)(elapsedTime.asSeconds()*(speedY_ - gravite_ * nbTour_));
	}

	if (!isOnGround_)
		position_.y -= (unsigned int)(elapsedTime.asSeconds()*gravite_);
}

//l'entité bouge dans les limites de la fenetre
void IEntiteMovable::move(const sf::Time& elapsedTime)
{
	unsigned int newPosition = position_.x + (unsigned int)(elapsedTime.asSeconds() * speedX_);
	if (newPosition <= WINDOW_SIZE_X)
		position_.x = newPosition;
	else
		position_.x = WINDOW_SIZE_X - spriteAnimer_->getSize().x;
}

Player::Player(std::unique_ptr<SpriteAnimer> spriteanimer, unsigned int PvMax, unsigned int Degat, std::unique_ptr<IComportementAttaque> comportementattaque) : IEntiteMovable(std::move(spriteanimer), PvMax, Degat, std::move(comportementattaque))
{

}

void Player::heal(const unsigned int heal)
{
	unsigned int newPv = pvActuel_ + heal;
	pvActuel_ = (newPv > pvMax_)? pvMax_ : newPv;
}


