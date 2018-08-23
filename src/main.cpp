#include <SFML/Graphics.hpp>
#include <iostream>
#include"initSprite.h"
#include"entite.h"
#include "constantes.h"
#include "background.h"

int main()
{
	InitialiseurDeSprite initSprite;
	
	//initialisation du joueur
	std::vector<sf::Sprite> spritesPlayer = initSprite.getSpritePlayer();
	std::unique_ptr<SpriteAnimer> spriteAnimerPlayer = std::make_unique<SpriteAnimer>(spritesPlayer, sf::Time(sf::milliseconds(100)));
	std::vector<sf::Sprite> spritesAttaque = initSprite.getSpriteAttaquePlayer();
	std::unique_ptr<IComportementAttaque> cmptAttPlayer = std::make_unique<AttaqueCaster>(sf::Time(sf::seconds(0.5)),spritesAttaque,sf::Time(sf::milliseconds(333)));
	Player player(std::move(spriteAnimerPlayer),100,10,std::move(cmptAttPlayer));

	//initialisation du fond
	Background backgound;
	backgound.init(BACKGROUND_PATH + "test/test", 4);

	sf::RectangleShape sol;
	sol.setSize({ 800,100 });
	sol.setPosition(0, 500);
	sol.setFillColor(sf::Color::White);

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

				//Evenement de deplacement lateral
				if (event.key.code == sf::Keyboard::D)
					player.moveRight(elapsedTime);

				//Evenement de deplacement lateral
				if (event.key.code == sf::Keyboard::Q)
					player.moveLeft(elapsedTime);
			}

			//POUR DEBUG 
			if (event.type == sf::Event::MouseButtonPressed)
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					std::cout << "position : " << player.getPosition().x << ", " << player.getPosition().y << std::endl;
				}

		}

		player.gestionPositionY(elapsedTime, sol.getGlobalBounds());

		//----Zone d'affichage----//
		//Efface la fenetre
		window.clear();

		backgound.draw(window, elapsedTime);
		player.draw(window, elapsedTime);
		window.draw(sol);

		//Affiche la fenetre
		window.display();
	}
	return 0;

}