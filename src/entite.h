#ifndef ENTITE_H
#define ENTITE_H
#include "spriteAnimer.h"
#include"constantes.h"

//Abstract class (regroupe le minimum pour avoir une entité)
class IEntite
{
protected :
	SpriteAnimer spriteAnimer;
	unsigned int pvMax;
	unsigned int pvActuel;
	unsigned int degat;
	sf::Vector2u position;

public :
	IEntite(SpriteAnimer spriteanimer, unsigned int PvMax, unsigned int Degat):spriteAnimer(spriteanimer), pvMax(PvMax), degat(Degat), pvActuel(PvMax), position(0,0){}
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual sf::Vector2u getPosition() = 0;
	virtual void attaque() = 0;
	virtual void hurt(unsigned int degat) = 0;
	virtual bool isCollision(sf::FloatRect objet) = 0;
};

//Abstract (ne definie pas IEntite)
class IEntiteMovable: public IEntite
{
protected : 
	unsigned int speedX = 100;
	unsigned int gravite = 10;
	unsigned int speedY = 100;
	bool isOnGround = true;
	unsigned int nbTour = 0;
	bool isJumping = false;

	//Méthode non visible aux utilisateur
	void gestionPositionY(sf::Time elapsedTime, sf::FloatRect objet);
public:
	IEntiteMovable(SpriteAnimer spriteanimer, unsigned int PvMax, unsigned int Degat) : IEntite(spriteanimer, PvMax, Degat) {}
	virtual void move(sf::Time elapsedTime);
	virtual void jump() { isJumping = true; };
	virtual bool isCollision(sf::FloatRect objet) { return spriteAnimer.getGlobalBounds().intersects(objet); };
};

//Abstract
class ICaster
{
protected : 
	sf::Time shootDelay;
	sf::Time shootProgression;
	std::vector<SpriteAnimer*> projectiles;
	std::vector<sf::Sprite> projectilesSprite;
	sf::Time swapRateProjectiles;

public : 
	ICaster(sf::Time shootDelay, std::vector<sf::Sprite>& sprites, sf::Time swap) : shootDelay(shootDelay), projectilesSprite(sprites), swapRateProjectiles(swap){}
	virtual void shoot(sf::Time elapsedTime);
	virtual void drawProjectiles(sf::RenderWindow& window);
	~ICaster();
};

//Concrete
class Player : public IEntiteMovable, public ICaster
{
private:
	std::vector<Bonus> bonusVector;
	std::vector<Malus> malusVector;
public :
	Player(SpriteAnimer spriteanimer, unsigned int PvMax, unsigned int Degat, sf::Time shootDelay, std::vector<sf::Sprite>& shootSprites, sf::Time shootSwap);
	void setBonus(Bonus bonus) { bonusVector.push_back(bonus); }
	void setMalus(Malus malus) { malusVector.push_back(malus); }
	void heal(unsigned int heal);
	void draw(sf::RenderWindow& window) {}
	sf::Vector2u getPosition() {}
	void attaque() {}
	void hurt(unsigned int degat) {}
	bool isCollision(sf::FloatRect objet) {}
};

#endif // !ENTITE_H


