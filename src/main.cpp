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
	backgound.init(BACKGROUND_PATH + "grassland/bg-grass", 4);
	backgound.setSpeed(0, 0);
	backgound.setSpeed(1, -20);
	backgound.setSpeed(2, -40);
	backgound.setSpeed(3, -20);

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
		sf::Event event{};

		//Boucle des évennements
		while (window.pollEvent(event))
		{	
			//Evenement de fermeture de la fenetre : on ferme le jeux
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Efface la fenetre
		window.clear();


		backgound.draw(window, elapsedTime);
		player.draw(window, elapsedTime);

		//Affiche la fenetre
		window.display();

	}
	return 0;

}