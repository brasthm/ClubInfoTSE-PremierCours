#include "AnimatedSprite.h"
#include "constantes.h"


void AnimatedSprite::animer(const sf::Time& elapsedTime)
{
	// Mise à jour de la durée écoulé depuis le dernier changement de frame
	swapProgression_ += elapsedTime;

	// Si le temps écoulé est supérieur au temps nécessaire
	if (swapProgression_ >= swapRate_)
	{
		// Si on arrive sur la dernière frame
		if (idSprite_ == sprites_.size()-1)
			// On retourne à la première frame
			idSprite_ = 0; 
		else
			// Sinon on passe à la frame suivante
			idSprite_++;

		// On sauvegarde la frame à afficher
		spriteDrawable_ = sprites_[idSprite_];
		// Réinitialisation du timer
		swapProgression_ = sf::Time::Zero;
	}
}

void AnimatedSprite::draw(sf::RenderWindow& window) 
{ 
	spriteDrawable_.setPosition(position_);
	window.draw(spriteDrawable_); 
}
