#include "SFML/Graphics.hpp"
#include "players.hpp"
#include "enemy.hpp"

class Engine {

    public:
        Engine();
        void start();
    private:
        RenderWindow window;
        Texture backGroundTexture;
        Sprite backGroundSprite;
        Players playerOne;
        Enemy enemy;
        Clock timeDamageDrago;
        bool canDamage;

         void input();
         void update(float dtAsSeconds);
         void draw();
         void interaction();

};
