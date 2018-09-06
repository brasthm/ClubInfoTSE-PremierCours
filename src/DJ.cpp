#include"DJ.hpp"

Track::Track() 
{
}

void Track::setTrack(std::string filepath, std::string name) 
{
	buffer_.loadFromFile(filepath);
	sound_.setBuffer(buffer_);
	name_ = name;
}

DJ::DJ(sf::Music& m) : music_(m)
{
	AllTrack_.resize(20);
	//AllTrack_[0].setTrack(location "path", "name");
}

void DJ::playMusicForever(std::string path) 
{
	music_.openFromFile(path);
	music_.play();
	music_.setLoop(true);

	sf::Listener listener;
	listener.setGlobalVolume(50);
}

void DJ::play(size_t n, bool forced)
{
	if (forced)
		AllTrack_[n].getSound().play();
	else
	{
		if (AllTrack_[n].getSound().getStatus() != sf::Sound::Playing) AllTrack_[n].getSound().play();
	}
}