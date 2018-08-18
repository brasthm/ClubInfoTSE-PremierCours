#include "spriteAnimer.h"
#include "constantes.h"

//Anime les sprites : � chaque appel on ajoute le temps du dernier appel � swapProgression, si ce dernier est sup�rieur ou �gal 
// � swapRate alors on change le sprite qui sera dessin�
void SpriteAnimer::Animer(const sf::Time& elapsedTime)
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
