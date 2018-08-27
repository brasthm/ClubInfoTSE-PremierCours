#ifndef ENTITE_H
#define ENTITE_H

#include "spriteAnimer.h"
#include "constantes.h"
#include <memory>


//Comportement d'attaque pour les entites
class IComportementAttaque
{
public:
    virtual ~IComportementAttaque() = default;
	virtual void attaque(const sf::Time& elapsedTime) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
};

//Comportement de caster
class AttaqueCaster : public IComportementAttaque
{
protected:
	sf::Time shootDelay_;
	sf::Time shootProgression_;
	std::vector<std::unique_ptr<SpriteAnimer>> projectiles_;
	std::vector<sf::Sprite> projectilesSprite_;
	sf::Time swapRateProjectiles_;

public:
	AttaqueCaster(sf::Time shootDelay, std::vector<sf::Sprite>& sprites, sf::Time swap) : shootDelay_(shootDelay), projectilesSprite_(sprites), swapRateProjectiles_(swap) {}
	void attaque(const sf::Time& elapsedTime) override;
	void draw(sf::RenderWindow& window) override;
};

class AttaqueCac : public IComportementAttaque
{
protected:
	sf::Time attaqueDelay_;
	sf::Time attaqueProgression_;
	std::vector<sf::Sprite> attaqueSprite_; //utile ??
public:
	AttaqueCac(sf::Time attaqueDelay, std::vector<sf::Sprite>& sprites) : attaqueDelay_(attaqueDelay), attaqueSprite_(sprites){}
	void attaque(const sf::Time& elapsedTime) override;
	void draw(sf::RenderWindow& window) override;

};

//Class regroupant le minimum pour avoir une entité
class IEntite
{
protected :
	std::unique_ptr<SpriteAnimer> spriteAnimer_;
	unsigned int pvMax_ = 100;
	unsigned int pvActuel_ = 100;
	unsigned int degat_ = 10;
	sf::Vector2f position_ = sf::Vector2f(0,260);
	bool isAlive_ = true;
	std::unique_ptr<IComportementAttaque> comportementAttaque_;

public :
	IEntite(std::unique_ptr<SpriteAnimer> spriteanimer, unsigned int PvMax, unsigned int Degat, std::unique_ptr<IComportementAttaque> comportementattaque):spriteAnimer_(std::move(spriteanimer)), pvMax_(PvMax), pvActuel_(PvMax), degat_(Degat), comportementAttaque_(std::move(comportementattaque)){}
	virtual ~IEntite() = default;
    virtual void hurt(const unsigned int& degat);
	virtual const sf::Vector2f& getPosition() { return position_; }
	virtual bool isCollision(const sf::FloatRect& objet) { return spriteAnimer_->getGlobalBounds().intersects(objet); }
	virtual bool isAlive();
	virtual void draw(sf::RenderWindow& window, const sf::Time& elapsedTime) { spriteAnimer_->Animer(elapsedTime); spriteAnimer_->draw(window); comportementAttaque_->draw(window); }
	virtual void attaque(const sf::Time& elapsedTime) { comportementAttaque_->attaque(elapsedTime); }
	virtual void setPositionSprite(sf::Vector2f position);
};

//Entite pouvant sauter et se deplacer
class IEntiteMovable: public IEntite
{
protected : 
	unsigned int speedX_ = 8000;
	unsigned int gravite_ = 800;
	int speedY_ = 1600;
	int vspeed_;
	bool isOnGround_ = true;
	bool isJumping_ = false;

public:
	IEntiteMovable(std::unique_ptr<SpriteAnimer> spriteanimer, unsigned int PvMax, unsigned int Degat, std::unique_ptr<IComportementAttaque> comportementattaque) : IEntite(std::move(spriteanimer), PvMax, Degat, std::move(comportementattaque)) {}
	~IEntiteMovable() override = default;
    virtual void moveLeft(const sf::Time& elapsedTime);
	virtual void moveRight(const sf::Time& elapsedTime);
	virtual void jump();
	//Méthode à appeller en permanance ---UTILE ???---
	void gestionPositionY(const sf::Time& elapsedTime, const sf::FloatRect& ground);
};

//Class Player avec les methodes de base non redefinie, ne PAS heriter
class Player : public IEntiteMovable
{
private:
	std::vector<Bonus> bonusVector_;
	std::vector<Malus> malusVector_;
public :
	Player(std::unique_ptr<SpriteAnimer> spriteanimer, unsigned int PvMax, unsigned int Degat, std::unique_ptr<IComportementAttaque> comportementattaque);
	void setBonus(const Bonus& bonus) { bonusVector_.push_back(bonus); }
	void setMalus(const Malus& malus) { malusVector_.push_back(malus); }
	void heal(unsigned int heal);
};

#endif // !ENTITE_H


