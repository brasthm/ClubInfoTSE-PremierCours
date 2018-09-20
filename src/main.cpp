#include <SFML/Graphics.hpp>
#include <iostream>
#include "InitSprite.h"
#include "player.h"
#include "constantes.h"
#include "Background.h"
#include "DJ.hpp"

int main()
{
	//init le son
	sf::Music music;
	DJ dj(music);
	//dj.playMusicForever("../../music/game.ogg");

	//init les skins
	InitialiseurDeSprite initSprite;

	//création du joueur
	Player player(initSprite);

	//initialisation du fond
	Background backgound;
	backgound.init(BACKGROUND_PATH + "grassland/bg-grass", 4);
	backgound.setSpeed(0, 0);
	backgound.setSpeed(1, -10);
	backgound.setSpeed(2, -40);
	backgound.setSpeed(3, -20);

	sf::RectangleShape sol;
	sol.setSize({ 800,100 });
	sol.setPosition(0, FLOOR);
	sol.setFillColor(sf::Color::Color(153, 76, 0));

	//Création de la fenetre du jeux
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "SUPER RUNNER");
	
	//Création de la clock
	sf::Clock clock;

	//Tant que l'on joue (fenetre ouverte)
	while (window.isOpen())
	{
		sf::Time elapsedTime = clock.getElapsedTime();
		clock.restart();

		//Création d'un objet récupérant les événements (touche clavier et autre)
		sf::Event event {};

		//Boucle des évennements
		while (window.pollEvent(event))
		{
			//Evenement de fermeture de la fenetre : on ferme le jeux
			if (event.type == sf::Event::Closed)
				window.close();

			//Evenement clavier
			if (event.type == sf::Event::KeyPressed)
			{
				//Evenement de saut
				if (event.key.code == sf::Keyboard::Space)
					player.jump();
			}

		}

		//----Zone d'affichage----//
		//Efface la fenetre
		window.clear();

		backgound.draw(window, elapsedTime);
		player.gestion(window, elapsedTime);
		window.draw(sol);

		//Affiche la fenetre
		window.display();

		sf::sleep(sf::milliseconds(10));
	}
	return 0;

}