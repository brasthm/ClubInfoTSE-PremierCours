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
	for(auto& projectile : projectiles_)
        projectile->draw(window);
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

//Teste si l'entite est en vie, vérifie la position gauche et basse ainsi que les pv
bool IEntite::isAlive() {
	if (position_.x < -100 || position_.y > WINDOW_SIZE_Y || pvActuel_ <=0)
		isAlive_ = false;
	return isAlive_; 
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

void IEntite::setPositionSprite(sf::Vector2f position)
{
	if (position.x <= WINDOW_SIZE_X || position.x >= 0 || position.y <= WINDOW_SIZE_Y || position.y >= 0)
		spriteAnimer_->setPosition(position);
}

//L'entite saute avec une accélération de base, la gravité la fait redessendre. l'objet attendu est le sol. peut depasser par le haut
void IEntiteMovable::gestionPositionY(const sf::Time& elapsedTime, const sf::FloatRect& sol)
{
	float gravity = 5000;
	if (isJumping_)
	{
		position_.y += elapsedTime.asSeconds()*vspeed_;
		vspeed_ += elapsedTime.asSeconds()*gravity;
	}

	isOnGround_ = isCollision(sol);

	if (isOnGround_)
	{
		isJumping_ = false;
		position_.y = sol.top - spriteAnimer_->getSize().y; //getSize fct ici car on cale par le bas 
	}
		

	setPositionSprite(position_);
}

//l'entité bouge dans les limites de la fenetre
void IEntiteMovable::moveLeft(const sf::Time& elapsedTime)
{
	float newPosition = position_.x - (elapsedTime.asSeconds() * speedX_);
	if (newPosition >= 0)
		position_.x = newPosition;
	else
		position_.x = 0;
	setPositionSprite(position_);
}

//l'entité bouge dans les limites de la fenetre
void IEntiteMovable::moveRight(const sf::Time& elapsedTime)
{
	float newPosition = position_.x + (elapsedTime.asSeconds() * speedX_);
	if (newPosition + spriteAnimer_->getSize().x <= WINDOW_SIZE_X)
		position_.x = newPosition;
	else
		position_.x = (float)WINDOW_SIZE_X - spriteAnimer_->getSize().x;
	setPositionSprite(position_);
}

Player::Player(std::unique_ptr<SpriteAnimer> spriteanimer, unsigned int PvMax, unsigned int Degat, std::unique_ptr<IComportementAttaque> comportementattaque) : IEntiteMovable(std::move(spriteanimer), PvMax, Degat, std::move(comportementattaque))
{

}

void Player::heal(const unsigned int heal)
{
	unsigned int newPv = pvActuel_ + heal;
	pvActuel_ = (newPv > pvMax_)? pvMax_ : newPv;
}


