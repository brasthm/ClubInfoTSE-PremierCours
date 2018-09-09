#include "Background.h"

void Background::init(const std::string path, int nbLayer)
{
	if (nbLayer >= BG_TEXTURE_MAX) exit(-1);
	float m = 0, s = 1, f = 10;
	for (int i = 0; i < nbLayer; i++)
	{
		layers1_.emplace_back();
		layers2_.emplace_back();
		speeds_.emplace_back(-20 - i * 500);
		textures_[i].loadFromFile(path + std::to_string(i) + ".png");
		layers1_[i].setTexture(textures_[i]);
		layers2_[i].setTexture(textures_[i]);
		layers1_[i].setPosition(0, 0);
		layers2_[i].setPosition(WINDOW_SIZE_X, 0);
	}
}

void Background::setSpeed(int ind, float value)
{
	if (ind >= 0 && ind < speeds_.size()) speeds_[ind] = value;
}

void Background::draw(sf::RenderWindow & screen, sf::Time &elapsed)
{
	for (int i = 0; i < speeds_.size(); i++)
	{
		float delta = speeds_[i] * elapsed.asSeconds();
		layers1_[i].move(delta, 0);
		layers2_[i].move(delta, 0);

		if (-layers1_[i].getPosition().x > WINDOW_SIZE_X) layers1_[i].setPosition(WINDOW_SIZE_X, 0);
		if (-layers2_[i].getPosition().x > WINDOW_SIZE_X) layers2_[i].setPosition(WINDOW_SIZE_X, 0);
	}

	for (int i = 0; i < layers1_.size(); i++)
	{
		screen.draw(layers1_[i]);
		screen.draw(layers2_[i]);
	}
}
