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
	allTrack_.resize(1);

	// Chargement des sons
	allTrack_.at(0) = *(new Track("../../sounds/obstacle-sound.wav"));

    for (auto &t : allTrack_)
    {
		t.getSound().setVolume(20);
    }
}

void DJ::playMusicForever(std::string path)
{
	music_.openFromFile(path);
	music_.play();
	music_.setLoop(true);
	//sf::Listener listener;
	//listener.setGlobalVolume(20);
	music_.setVolume(60);
}

void DJ::play(size_t n, bool forced)
{
	if (forced)
		allTrack_[n].getSound().play();
	else
		if (allTrack_[n].getSound().getStatus() != sf::Sound::Playing) allTrack_[n].getSound().play();
}