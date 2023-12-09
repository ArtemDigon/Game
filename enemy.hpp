#include "SFML/Graphics.hpp"
//#include "players.hpp"

using namespace sf;

class Enemy{

    public:

        Enemy();
        void go();
        void findGlagiator(Vector2f position);
        Sprite getSprite();
        Vector2f position;
        void update(float elasedTime,Vector2f position);
        bool rigth;
        bool left;
        void getDamage(bool rigthSide);
        Clock timeDamageDrago;
        bool canDamage;
        bool deadDrado;

    private:
        void dead();
        int hp;
        int ground;
        Clock damageTimer;
        bool getDamageFlag;
        double dy;
        bool onGround;
        bool glagiatorGoRigth;
        double currentFrame;
        Texture texture;
        Sprite sprite;
        int speed;
};
