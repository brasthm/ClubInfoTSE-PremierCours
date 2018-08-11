#include "spriteAnimer.h"
#include "constantes.h"

//Anime les sprites : � chaque appel on ajoute le temps du dernier appel � swapProgression, si ce dernier est sup�rieur ou �gal 
// � swapRate alors on change le sprite qui sera dessin�
void SpriteAnimer::Animer(sf::Time elapsedTime)
{
	swapProgression += elapsedTime;
	if (swapProgression >= swapRate)
	{
		idSprite++;
		spriteDrawable = sprites[idSprite];
		swapProgression = sf::Time::Zero;
	}
}
