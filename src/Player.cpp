#include"entite.h"

Player::Player(const InitialiseurDeSprite& initsprite)
{
	//ini du skin rectangle du joueur
	shape_.setSize({ 200,250 });
	shape_.setPosition(0, 160);
	shape_.setFillColor(sf::Color::Blue);

	std::vector<sf::Sprite> sprites = initsprite.getSpritePlayer();

	//ini de l'image du joueur
	sprite_ = sprites[1];

	//ini de l'image animé du joueur
	animatedSprite_ = new AnimatedSprite(sprites, sf::milliseconds(100));
}


void Player::jump() 
{

}

bool Player::isCollision(const Obstacle& obstacle) 
{
	//MAJ position sur shape (mm taille que les images)
	shape_.setPosition(position_);
	return shape_.getGlobalBounds().intersects(obstacle.getGlobalBounds());
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
	animatedSprite_->animer(elapsedTime);
	animatedSprite_->draw(window);
}



