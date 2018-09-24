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
static constexpr float GRAVITY = 20;

//Position du sol
static constexpr float FLOOR = 500;

//Chemin vers les images du player run
static const std::string path = "../../"; //-----> modifier ce path pour importer les images comme il le faut
static const std::string PLAYER_PATH = path + "img/player/";
static const std::string BACKGROUND_PATH = path + "img/bg/";
static const std::string LAZER_PATH = path + "img/lazer/";
static const std::string FONT_MONSERRAT = path + "font/montserrat.ttf";
static const std::string SOUNDS_PATH = path + "sounds/";

#endif // !CONSTANTES_H
