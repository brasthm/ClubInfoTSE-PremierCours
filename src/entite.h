#ifndef ENTITE_H
#define ENTITE_H
#include <memory>
#include "spriteAnimer.h"
#include "constantes.h"

//Comportement d'attaque pour les entites
class IComportementAttaque
{
public:
	virtual void attaque(const sf::Time& elapsedTime) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
};

//Comportement de caster
class AttaqueCaster : public IComportementAttaque
{
protected:
	sf::Time _shootDelay;
	sf::Time _shootProgression;
	std::vector<std::unique_ptr<SpriteAnimer>> _projectiles;
	std::vector<sf::Sprite> _projectilesSprite;
	sf::Time _swapRateProjectiles;

public:
	AttaqueCaster(sf::Time shootDelay, std::vector<sf::Sprite>& sprites, sf::Time swap) : _shootDelay(shootDelay), _projectilesSprite(sprites), _swapRateProjectiles(swap) {}
	void shoot(const sf::Time& elapsedTime);
	void draw(sf::RenderWindow& window);
};

class AttaqueCac : public IComportementAttaque
{
protected:
	sf::Time _attaqueDelay;
	sf::Time _attaqueProgression;
	std::vector<sf::Sprite> _attaqueSprite; //utile ??
public:
	AttaqueCac(sf::Time attaqueDelay, std::vector<sf::Sprite>& sprites) : _attaqueDelay(attaqueDelay), _attaqueSprite(sprites){}
	void shoot(const sf::Time& elapsedTime);
	void draw(sf::RenderWindow& window);

};

//Class regroupant le minimum pour avoir une entité
class IEntite
{
protected :
	std::unique_ptr<SpriteAnimer> _spriteAnimer;
	unsigned int _pvMax;
	unsigned int _pvActuel;
	unsigned int _degat;
	sf::Vector2u _position;
	bool _isAlive = true;
	std::unique_ptr<IComportementAttaque> _comportementAttaque;

public :
	IEntite(std::unique_ptr<SpriteAnimer> spriteanimer, unsigned int PvMax, unsigned int Degat, std::unique_ptr<IComportementAttaque> comportementattaque):_spriteAnimer(std::make_unique<SpriteAnimer>(spriteanimer)), _pvMax(PvMax), _degat(Degat), _pvActuel(PvMax), _position(0,0), _comportementAttaque(std::make_unique<IComportementAttaque>(comportementattaque)){}
	virtual void hurt(const unsigned int& degat);
	virtual const sf::Vector2u& getPosition() { return _position; }
	virtual const bool& isCollision(const sf::FloatRect& objet) { return _spriteAnimer->getGlobalBounds().intersects(objet); }
	virtual const bool& isAlive() { return _isAlive; }
	virtual void draw(sf::RenderWindow& window) { _spriteAnimer->draw(window); _comportementAttaque->draw(window); }
	virtual void attaque(const sf::Time& elapsedTime) { _comportementAttaque->attaque(elapsedTime); }
};

//Entite pouvant sauter et se deplacer
class IEntiteMovable: public IEntite
{
protected : 
	unsigned int _speedX = 100;
	unsigned int _gravite = 10;
	unsigned int _speedY = 100;
	bool _isOnGround = true;
	unsigned int _nbTour = 0;
	bool _isJumping = false;

	//Méthode non visible aux utilisateur à appeller en permanance ---UTILE ???---
	void gestionPositionY(const sf::Time& elapsedTime, const sf::FloatRect& objet);
public:
	IEntiteMovable(std::unique_ptr<SpriteAnimer> spriteanimer, unsigned int PvMax, unsigned int Degat, std::unique_ptr<IComportementAttaque> comportementattaque) : IEntite(std::make_unique<SpriteAnimer>(spriteanimer), PvMax, Degat, std::make_unique<IComportementAttaque>(comportementattaque)) {}
	virtual void move(const sf::Time& elapsedTime);
	virtual void jump() { _isJumping = true; }
};

//Class Player avec les methodes de base non redefinie, ne PAS heriter
class Player : public IEntiteMovable
{
private:
	std::vector<Bonus> _bonusVector;
	std::vector<Malus> _malusVector;
public :
	Player(std::unique_ptr<SpriteAnimer> spriteanimer, unsigned int PvMax, unsigned int Degat, std::unique_ptr<IComportementAttaque> comportementattaque);
	void setBonus(Bonus bonus) { _bonusVector.push_back(bonus); }
	void setMalus(Malus malus) { _malusVector.push_back(malus); }
	void heal(unsigned int heal);
};

#endif // !ENTITE_H


