#include "spriteAnimer.h"
#include "constantes.h"

//Anime les sprites : à chaque appel on ajoute le temps du dernier appel à swapProgression, si ce dernier est supérieur ou égal 
// à swapRate alors on change le sprite qui sera dessiné
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
