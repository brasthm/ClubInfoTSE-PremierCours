#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	//Cr�ation de la fenetre du jeux
	sf::RenderWindow window(sf::VideoMode(800, 600), "SUPER RUNNER");
	
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

#pragma region Affichage des graphics
		//Efface la fenetre
		window.clear();

		//Affiche la fenetre
		window.display();
#pragma endregion

	}
	return 0;

}