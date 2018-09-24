#include <SFML/Graphics.hpp>
#include <iostream>
#include "initSprite.h"
#include "Player.h"
#include "constantes.h"
#include "background.h"
#include "DJ.h"
#include "utilities.h"

int main()
{
	// Initialisation des ressources
	#include "initialisation.cpp"
	
	
    // ----Zone pour créer le sol----
	// sf::RectangleShape sol;
	// sol.setSize({ 800,100 });
    // ...

	// Tant que l'on joue (fenetre ouverte)
	while (window.isOpen())
	{
        // Horloge du jeu
		sf::Time elapsedTime = clock.getElapsedTime();
		clock.restart();

		// Création d'un objet récupérant les événements (appui clavier et autre)
		sf::Event event {};

		// Boucle des événements
		while (window.pollEvent(event))
		{
			// Événement de fermeture de la fenêtre : on ferme le jeu
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// ----Zone d'affichage----// 
		// Efface la fenêtre
		window.clear();
		window.display();
		
		sf::sleep(sf::milliseconds(10));
	}
	return 0;
}
