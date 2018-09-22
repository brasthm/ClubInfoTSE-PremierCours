#include "DJ.h"

Track::Track(std::string filepath, std::string name)
{
	buffer_.loadFromFile(filepath);
	sound_.setBuffer(buffer_);
	name_ = name;
}

void Track::setTrack(std::string filepath, std::string name)
{
	buffer_.loadFromFile(filepath);
	sound_.setBuffer(buffer_);
	name_ = name;
}

DJ::DJ(sf::Music& m) : music_(m)
{
	// Chargement des sons
	allTrack_.emplace_back("../../sounds/pas-course.wav");
	allTrack_.at(0).getSound().setVolume(100);
	allTrack_.emplace_back("../../sounds/obstacle-sound.wav");
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
		allTrack_[n].getSound().play();
	else
		if (allTrack_[n].getSound().getStatus() != sf::Sound::Playing) allTrack_[n].getSound().play();
}