// Initialisation du son
sf::Music music;
DJ dj(music);

// Initialisation des textures
InitialiseurDeSprite initSprite;

// Création du joueur
Player player(initSprite);

// Obstacles
std::vector<sf::Vector2f> spawnPositions = { {0,400},{0,150},{ 100,0 },{ 200,0 },{ 300,0 },{ 400,0 },{ 500,0 },{ 600,0 },{ 700,0 } };
std::vector<Obstacle> obstacles;

// Fond
Background background;
background.init(BACKGROUND_PATH + "grassland/bg-grass", 4);
background.setSpeed(0, 0);
background.setSpeed(1, -10);
background.setSpeed(2, -40);
background.setSpeed(3, -20);

// Création de la fenetre du jeux
sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "SUPER RUNNER");


// Création de la clock
sf::Clock clock;