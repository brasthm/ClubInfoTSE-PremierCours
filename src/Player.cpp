#include"Player.h"
#include<iostream>

Player::Player(const InitialiseurDeSprite& initsprite)
{
	// Initialisation du rectangle représentant le joueur
	shape_.setSize({ 200,250 });
	shape_.setPosition(0, 160);
	shape_.setFillColor(sf::Color::Blue);

	hitbox_.width = 50;
	hitbox_.height = 200;

	std::vector<sf::Sprite> sprites = initsprite.getSpritePlayer();

	// Initialisation de l'image animée du joueur
	sprites.pop_back();
	animatedSprite_ = new AnimatedSprite(sprites, sf::milliseconds(100));
}



void Player::gestion(sf::RenderWindow& window, const sf::Time& elapsedTime)
{
    // ----Zone de gestion du joueur
    
}

void Player::ressurect()
{
	isAlive_ = true;
}

bool Player::isCollision(const Obstacle& obstacle)
{
	hitbox_.left = position_.x + 100;
	hitbox_.top = position_.y + 50;

	if (!obstacle.isDeadly()) return false;
	return hitbox_.intersects(obstacle.getGlobalBounds());
}


void Player::drawRectangle(sf::RenderWindow& window) 
{ 
	// Affichage du rectangle
	window.draw(shape_); 
}

void Player::drawImage(sf::RenderWindow& window)
{ 
	sprite_.setPosition(position_);
	window.draw(sprite_);
}

void Player::drawImageAnimee(sf::RenderWindow& window, const sf::Time& elapsedTime)
{ 
	animatedSprite_->setPosition(position_);
	spriteJump_.setPosition(position_);

	if (!isjumping_)
	{
		animatedSprite_->animer(elapsedTime);
		animatedSprite_->draw(window);
	}
	else
		window.draw(spriteJump_);
	
}



