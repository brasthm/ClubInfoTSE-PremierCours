#ifndef CONSTANTES_H
#define CONSTANTES_H
//Toutes les constantes sont ici

//Taille max de la fenetre de rendu en x
static constexpr unsigned int WINDOW_SIZE_X = 800;

//Taille max de la fenetre de rendu en y
static constexpr unsigned int WINDOW_SIZE_Y = 600;

//Nombre d'image du joueur
static constexpr size_t NOMBRE_IMAGE_PLAYER = 8;

//Nombre maximum de texture pour le fond
static constexpr size_t BG_TEXTURE_MAX = 10;

//Gravité
static constexpr float GRAVITY = 5000;
//Enum des bonus
enum Bonus
{SPEED, SHIELD, FURY};

//Enum des malus
enum Malus
{SLOW, LOWHP, WEAK};

//Chemin vers les images du player run
static const std::string RUNNING_PLAYER_PATH = "../../img/player/run/";
static const std::string BACKGROUND_PATH = "../../img/bg/";

#endif // !CONSTANTES_H
