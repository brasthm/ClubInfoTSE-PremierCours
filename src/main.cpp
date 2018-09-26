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
	#include "initialisation"

	// Création du joueur


	/*
		Déclarer les variables ICI
										*/


    // ----Zone pour créer le sol----

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

		/*
			Mettre les fonctions de gestion ICI
														*/

		// ----Zone d'affichage----// 

		window.clear();
		/*
				Mettre les fonction d'affichage ICI
														*/
		window.display();


		// Ecran de fin
		
		sf::sleep(sf::milliseconds(10));
	}
	return 0;
}
