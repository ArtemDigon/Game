#include "SFML/Graphics.hpp"
//#include "players.hpp"

using namespace sf;

class Enemy{

    public:

        Enemy();
        void go();
        void findGlagiator(Vector2f position);
        Sprite getSprite();
        void update(float elasedTime,Vector2f position);

    private:
        double currentFrame;
        bool rigth;
        bool left;
        Vector2f position;
        Texture texture;
        Sprite sprite;
        int speed;
};
