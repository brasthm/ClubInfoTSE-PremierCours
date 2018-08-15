#include "entite.h"
#include "constantes.h"

#pragma region ComportementAttaque

#pragma region AttaqueCaster
void AttaqueCaster::shoot(const sf::Time& elapsedTime)
{
	_shootProgression += elapsedTime;
	if (_shootProgression >= _shootDelay)
	{
		_projectiles.push_back(std::make_unique<SpriteAnimer>(_projectilesSprite, _swapRateProjectiles));
		_shootProgression = sf::Time::Zero;
	}

}

void AttaqueCaster::draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < _projectiles.size(); i++)
		_projectiles[i]->draw(window);
}
#pragma endregion

#pragma region AttaqueCac
void AttaqueCac::shoot(const sf::Time& elapsedTime)
{
	_attaqueProgression += elapsedTime;
	if (_attaqueProgression >= _attaqueDelay)
		_attaqueProgression = sf::Time::Zero;
}

void AttaqueCac::draw(sf::RenderWindow& window)
{
	//draw annimation ? sprites ? rien ?
}
#pragma endregion

#pragma endregion

#pragma region Ientite
void IEntite::hurt(const unsigned int& degat)
{
	if (_pvActuel - degat > 0)
		_pvActuel -= degat;
	else
	{
		_pvActuel = 0;
		_isAlive = false;
	}	
}
#pragma endregion

#pragma region IEntiteMovable
//L'entite saute avec une accélération de base, la gravité la fait redessendre. l'objet attendu est le sol
void IEntiteMovable::gestionPositionY(const sf::Time& elapsedTime, const sf::FloatRect& sol)
{
	if (isCollision(sol))
	{
		_isOnGround = true;
		_isJumping = false;
		_nbTour = 0;
	}

	if (_isJumping)
	{
		_nbTour++;
		_position.y -= elapsedTime.asSeconds()*(_speedY - _gravite * _nbTour);
	}

	if (!_isOnGround)
		_position.y -= elapsedTime.asSeconds()*_gravite;
}

//l'entité bouge dans les limites de la fenetre
void IEntiteMovable::move(const sf::Time& elapsedTime)
{
	unsigned int newPosition = _position.x + elapsedTime.asSeconds() * _speedX;
	if (newPosition <= WINDOW_SIZE_X)
		_position.x = newPosition;
	else
		_position.x = WINDOW_SIZE_X - _spriteAnimer->getSize().x;
}
#pragma endregion

#pragma region Player
Player::Player(std::unique_ptr<SpriteAnimer> spriteanimer, unsigned int PvMax, unsigned int Degat, std::unique_ptr<IComportementAttaque> comportementattaque) : IEntiteMovable(std::move(spriteanimer), PvMax, Degat, std::move(comportementattaque))
{

}

void Player::heal(unsigned int heal)
{
	unsigned int newPv = _pvActuel + heal;
	_pvActuel = (newPv > _pvMax)? _pvMax : newPv;
}
#pragma endregion

