#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <SFML/Graphics.hpp>
#include "constantes.h"
#include <vector>
#include <string>

void afficherFin(sf::RenderWindow &window, const sf::Texture &endScreen);

class Background
{
private:
	sf::Texture textures_[BG_TEXTURE_MAX];
	std::vector<sf::Sprite> layers1_, layers2_;
	std::vector<float> speeds_;
public:
	Background() {};
	~Background() {};

	void init(const std::string path, int nbLayer);
	void setSpeed(int ind, float value);
	void draw(sf::RenderWindow& screen, sf::Time &elapsed);

};

#endif