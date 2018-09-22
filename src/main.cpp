#include <SFML/Graphics.hpp>
#include <iostream>
#include "initSprite.h"
#include "Player.h"
#include "constantes.h"
#include "Background.h"
#include "DJ.hpp"
#include <ctime>

void afficherFin(sf::RenderWindow &window, sf::Texture &endScreen);

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
	sol.setFillColor(sf::Color(153, 76, 0));

	//ini position
	std::vector<sf::Vector2f> spawnPositions = { {0,400},{0,150},{ 100,0 },{ 200,0 },{ 300,0 },{ 400,0 },{ 500,0 },{ 600,0 },{ 700,0 } };
	std::vector<Obstacle> obstacles;
	sf::Time spawnRate = sf::milliseconds(2000);
	sf::Time spawnProgression = sf::Time::Zero;
	srand(time(NULL));

	//freeze de fin de game
	sf::Texture tscreen;
	tscreen.create(WINDOW_SIZE_X, WINDOW_SIZE_Y);
	sf::Sprite sscreen;

	//Création de la fenetre du jeux
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "SUPER RUNNER", sf::Style::Default, sf::ContextSettings(0, 0, 8));
	
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

		}

		player.gestion(window, elapsedTime);

		spawnProgression += elapsedTime;
		if (spawnProgression > spawnRate)
		{
			obstacles.push_back(Obstacle(initSprite, spawnPositions[rand() % spawnPositions.size()]));
			//obstacles.push_back(Obstacle(initSprite, { 0,0 }));
			spawnProgression = sf::Time::Zero;
		}

		for (size_t i = 0; i < obstacles.size(); i++)
		{
			if (player.isCollision(window, obstacles[i]))
			{
				std::cout << "kill" << std::endl;
				player.kill();		
			}
			if (obstacles[i].isDead())
			{
				obstacles[i] = obstacles.back();
				obstacles.pop_back();
			}
		}

		//----Zone d'affichage----//
		//Efface la fenetre
		window.clear();

		//Dessin des images
		backgound.draw(window, elapsedTime);
		player.drawImageAnime(window, elapsedTime);
		window.draw(sol);

		for (size_t i = 0; i < obstacles.size(); i++)
			obstacles[i].draw(window, elapsedTime);

		window.display();

		if (!player.isAlive())
		{
			tscreen.update(window);
			afficherFin(window, tscreen);
			player.ressurect();
			obstacles.clear();
		}

		sf::sleep(sf::milliseconds(10));
	}
	return 0;
}

void afficherFin(sf::RenderWindow &window, sf::Texture &endScreen)
{
	bool continuer = true;
	sf::Sprite sprite;
	sprite.setTexture(endScreen);

	while (continuer && window.isOpen())
	{
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
				if (event.key.code == sf::Keyboard::Return)
					continuer = false;
			}
		}

		//----Zone d'affichage----//
		//Efface la fenetre
		window.clear();
		window.draw(sprite);
		window.display();

		sf::sleep(sf::milliseconds(10));
	}
}