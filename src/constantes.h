#ifndef CONSTANTES_H
#define CONSTANTES_H
//Toutes les constantes sont ici

//Taille max de la fenetre de rendu en x
static constexpr unsigned int WINDOW_SIZE_X = 800;

//Taille max de la fenetre de rendu en y
static constexpr unsigned int WINDOW_SIZE_Y = 600;

static constexpr size_t NOMBRE_IMAGE_PLAYER = 8;

//Enum des bonus
enum Bonus
{SPEED, SHIELD, FURY};

//Enum des malus
enum Malus
{SLOW, LOWHP, WEAK};

//Chemin vers les images du player run
static const std::string RUNNING_PLAYER_PATH = "../../img/player/run/";

#endif // !CONSTANTES_H
