#include <SFML/Graphics.hpp>
#include "initSprite.h"
#include "Player.h"
#include "constantes.h"
#include "Background.h"
#include "DJ.h"
#include <ctime>

int main()
{
	//init le son
	sf::Music music;
	DJ dj(music);
	dj.playMusicForever("../../music/Surf Shimmy.ogg");

	//init les skins
	InitialiseurDeSprite initSprite;

	//création du joueur
	Player player(initSprite);

	//initialisation du fond
	Background background;
	background.init(BACKGROUND_PATH + "grassland/bg-grass", 4);
	background.setSpeed(0, 0);
	background.setSpeed(1, -10);
	background.setSpeed(2, -40);
	background.setSpeed(3, -20);

	sf::RectangleShape sol;
	sol.setSize({ 800,100 });
	sol.setPosition(0, FLOOR);
	sol.setFillColor(sf::Color(153, 76, 0));

	//ini position
	std::vector<sf::Vector2f> spawnPositions = { {0,400},{0,150},{ 100,0 },{ 200,0 },{ 300,0 },{ 400,0 },{ 500,0 },{ 600,0 },{ 700,0 } };
	std::vector<Obstacle> obstacles;
	sf::Time spawnRate = sf::milliseconds(2000);
	sf::Time spawnProgression = sf::Time::Zero;
	srand(static_cast<unsigned int>(time(NULL)));

	//Ecran de fin de game
	sf::Texture tscreen;
	tscreen.create(WINDOW_SIZE_X, WINDOW_SIZE_Y);
	sf::Sprite sscreen;

	//Interface
	sf::Font mons;
	sf::Text distanceText;
	float distance = 0;

	mons.loadFromFile(FONT_MONSERRAT);
	distanceText.setFillColor(sf::Color::Black);
	distanceText.setFont(mons);
	distanceText.setCharacterSize(32);

	//Création de la fenetre du jeux
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "SUPER RUNNER", sf::Style::Default, sf::ContextSettings(0, 0, 8));
	
	//Création de la clock
	sf::Clock clock;

	//Tant que l'on joue (fenetre ouverte)
	while (window.isOpen())
	{
		sf::Time elapsedTime = clock.getElapsedTime();
		distance += elapsedTime.asSeconds() * 15.f;
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
		dj.play(0);

		spawnProgression += elapsedTime;
		if (spawnProgression > spawnRate)
		{
			dj.play(1);
			obstacles.push_back(Obstacle(initSprite, spawnPositions[rand() % 2]));

			for (int i = 0; i < rand() % 2; i++)
				obstacles.push_back(Obstacle(initSprite, spawnPositions[rand() % (spawnPositions.size() - 2) + 2]));
			
			//obstacles.push_back(Obstacle(initSprite, { 0,0 }));
			spawnProgression = sf::Time::Zero;
		}

		for (size_t i = 0; i < obstacles.size(); i++)
		{
			if (player.isCollision(window, obstacles[i]))
				player.kill();

			if (obstacles[i].isDead())
			{
				obstacles[i] = obstacles.back();
				obstacles.pop_back();
			}
		}

		distanceText.setString(std::to_string(int(distance + 0.5)) +" m");
		distanceText.setPosition((WINDOW_SIZE_X - distanceText.getGlobalBounds().width) / 2, 100);
		

		//----Zone d'affichage----//
		//Efface la fenetre
		window.clear();

		//Dessin des images
		background.draw(window, elapsedTime);
		player.drawImageAnime(window, elapsedTime);
		window.draw(sol);

		for (size_t i = 0; i < obstacles.size(); i++)
			obstacles[i].draw(window, elapsedTime);

		window.draw(distanceText);
		window.display();

		if (!player.isAlive())
		{
			tscreen.update(window);
			afficherFin(window, tscreen);
			player.ressurect();
			obstacles.clear();
			distance = 0;
			clock.restart();
		}

		sf::sleep(sf::milliseconds(10));
	}
	return 0;
}
