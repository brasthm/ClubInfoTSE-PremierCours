#include"Obstacle.h"
#include"constantes.h"

Obstacle::Obstacle(const InitialiseurDeSprite& inisprite, const sf::Vector2f& position)
{
	position_ = position;
	barre1_.setFillColor({ 255, 0, 0, 128 });
	barre2_.setFillColor({ 255, 0, 0, 128 });

	barre1_.setPosition(position_);

	if (position_.y == 0) // vertical
	{
		sprite_ = inisprite.getSpriteObstacle()[1];
		sprite_.setScale(1, WINDOW_SIZE_Y / sprite_.getGlobalBounds().height);
		isHorizontal_ = false;
	}
	else
	{
		sprite_ = inisprite.getSpriteObstacle()[0];
		sprite_.setScale(WINDOW_SIZE_X / sprite_.getGlobalBounds().width, 1);
		isHorizontal_ = true;
	}
	sprite_.setPosition(position_);
}

void Obstacle::drawImage(sf::RenderWindow & window) 
{ 
	sprite_.setPosition(position_); 
	window.draw(sprite_); 
}

void Obstacle::draw(sf::RenderWindow& window, const sf::Time & elapsedTime)
{
	timeProgression_ += elapsedTime;
	
	float ratio = timeProgression_ / time_;
	
	if (isHorizontal_)
	{
		barre1_.setSize({ ratio * WINDOW_SIZE_X / 2, 100 });
		barre2_.setSize({ ratio * WINDOW_SIZE_X / 2, 100 });
		barre2_.setPosition(WINDOW_SIZE_X - barre2_.getSize().x, position_.y);
	}
		
	else
	{
		barre1_.setSize({ 100, ratio * WINDOW_SIZE_Y / 2 });
		barre2_.setSize({ 100, ratio * WINDOW_SIZE_Y / 2 });
		barre2_.setPosition(position_.x, WINDOW_SIZE_Y - barre2_.getSize().y);
	}
	if (timeProgression_ < time_)
	{
		window.draw(barre1_);
		window.draw(barre2_);
	}
		
	else if (timeProgression_ < 2.f*time_)
	{
		window.draw(sprite_);
		deadly_ = true;
	}
	else
		dead_ = true;
}
