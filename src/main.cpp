#include <SFML/Graphics.hpp>
#include <iostream>
#include "initSprite.h"
#include "Player.h"
#include "constantes.h"
#include "Background.h"
#include "DJ.h"
#include <ctime>

int main()
{
#pragma region init_seg
	//Initialisation du son
	sf::Music music;
	DJ dj(music);

	//Initialisation des textures
	InitialiseurDeSprite initSprite;

	//Création du joueur
	Player player(initSprite);

	//Obstacles
	std::vector<sf::Vector2f> spawnPositions = { {0,400},{0,150},{ 100,0 },{ 200,0 },{ 300,0 },{ 400,0 },{ 500,0 },{ 600,0 },{ 700,0 } };
	std::vector<Obstacle> obstacles;
	srand((time(NULL)));

	//Fond
	Background background;
	background.init(BACKGROUND_PATH + "grassland/bg-grass", 4);
	background.setSpeed(0, 0);
	background.setSpeed(1, -10);
	background.setSpeed(2, -40);
	background.setSpeed(3, -20);

	//Création de la fenetre du jeux
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "SUPER RUNNER", sf::Style::Default, sf::ContextSettings(0, 0, 8));

	
	//Création de la clock
	sf::Clock clock;
#pragma endregion 

    //----Zone pour créer le sol----
	//sf::RectangleShape sol;
	//sol.setSize({ 800,100 });
    //...

	//Tant que l'on joue (fenetre ouverte)
	while (window.isOpen())
	{
        //Horloge du jeu
		sf::Time elapsedTime = clock.getElapsedTime();
		clock.restart();

		//Création d'un objet récupérant les événements (appui clavier et autre)
		sf::Event event {};

		//Boucle des événements
		while (window.pollEvent(event))
		{
			//Événement de fermeture de la fenêtre : on ferme le jeu
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//----Zone d'affichage----//
		//Efface la fenêtre
		window.clear();
		window.display();
		
		sf::sleep(sf::milliseconds(10));
	}
	return 0;
}
