#include <SFML/Graphics.hpp>
#include <iostream>
#include "constantes.h"

int main()
{
	//Cr�ation de la fenetre du jeux
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "SUPER RUNNER");
	
	//Tant que l'on joue (fenetre ouverte)
	while (window.isOpen())
	{
		//Cr�ation d'un objet r�cup�rant les �v�nements (touche clavier et autre)
		sf::Event event;

		//Boucle des �vennements
		while (window.pollEvent(event))
		{	
			//Evenement de fermeture de la fenetre : on ferme le jeux
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Efface la fenetre
		window.clear();

		//Affiche la fenetre
		window.display();

	}
	return 0;

}