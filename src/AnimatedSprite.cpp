#include "AnimatedSprite.h"


// Anime les sprites : à chaque appel on ajoute le temps du dernier appel à swapProgression, si ce dernier est supérieur ou égal 
// à swapRate alors on change le sprite qui sera dessiné
void AnimatedSprite::animer(const sf::Time& elapsedTime)
{
	swapProgression_ += elapsedTime;
	if (swapProgression_ >= swapRate_)
	{
		if (idSprite_ == sprites_.size()-1)
			idSprite_ = 0; 
		else
			idSprite_++;
		spriteDrawable_ = sprites_[idSprite_];
		swapProgression_ = sf::Time::Zero;
	}
}

void AnimatedSprite::draw(sf::RenderWindow& window) 
{ 
	spriteDrawable_.setPosition(position_);
	window.draw(spriteDrawable_); 
}
