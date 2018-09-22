#include"Player.h"
#include<iostream>

Player::Player(const InitialiseurDeSprite& initsprite)
{
	//ini du skin rectangle du joueur
	shape_.setSize({ 200,250 });
	shape_.setPosition(0, 160);
	shape_.setFillColor(sf::Color::Blue);

	hitbox_.width = 50;
	hitbox_.height = 200;

	std::vector<sf::Sprite> sprites = initsprite.getSpritePlayer();

	//ini de l'image du joueur
	sprite_ = sprites[0];

	spriteJump_ = sprites.back();
	sprites.pop_back();

	//ini de l'image anim� du joueur
	animatedSprite_ = new AnimatedSprite(sprites, sf::milliseconds(100));
}


void Player::jump() 
{
	if(!isjumping_)
	{ 
		vSpeed_ = -10;
		isjumping_ = true;
		hitbox_.height = 150;
	}
}

void Player::gestion(sf::RenderWindow & window, const sf::Time& elapsedTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)&&position_.x>0)
		moveLeft(hSpeed_*elapsedTime.asSeconds());
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&position_.x<WINDOW_SIZE_X- shape_.getGlobalBounds().width)
		moveRight(hSpeed_*elapsedTime.asSeconds());
	//Evenement de saut
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		jump();

	vSpeed_ += GRAVITY * elapsedTime.asSeconds();

	position_.y += vSpeed_;
	if (position_.y > FLOOR - shape_.getGlobalBounds().height)
	{
		position_.y = FLOOR - shape_.getGlobalBounds().height;
		isjumping_ = false;
		hitbox_.height = 200;
	}
		
}

void Player::ressurect()
{
	isAlive_ = true;
}

bool Player::isCollision(sf::RenderWindow& window, const Obstacle& obstacle)
{
	hitbox_.left = position_.x + 100;
	hitbox_.top = position_.y + 50;

	if (!obstacle.isDeadly()) return false;
	return hitbox_.intersects(obstacle.getGlobalBounds());
}


void Player::drawRectangle(sf::RenderWindow& window) 
{ 
	shape_.setPosition(position_); 
	window.draw(shape_); 
}

void Player::drawImage(sf::RenderWindow& window) 
{ 
	sprite_.setPosition(position_); 
	window.draw(sprite_); 
}

void Player::drawImageAnime(sf::RenderWindow& window, const sf::Time& elapsedTime)
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



