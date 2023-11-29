#include <SFML/Graphics.hpp>

using namespace sf;

class Players {

    public:
        float dx,dy;
        FloatRect rect;
        float currentFrame;
        bool onGround;
        bool sitDown;
        bool attack;
        bool attackSit;
        Players();
        ~Players();
        void goLeft();
        void goRight();
        void stopLeft();
        void stopRight();
        void update(float elasedTime);
        void goJump();
        void stopJump();
        void defaultPosition();
        void goSitDown();
        void stopSitDown();
        void attackSitDown();
        void stopAttackSitDown();
        void stamin();
        void attackStand();
        void stopAttackStand();
        void getDamage(bool goRigth);
        Sprite getSprite();
        void getMidle();
        Vector2f position;
        Vector2f positionMidle;

    private:
        bool enemyGoRigth;
        bool getDamageFlag;
        double staminCount;
        float ground;
        Texture texture;
        Sprite sprite;
        bool m_LeftPressed;
        bool m_RightPressed;
        float m_speed;
        bool offsetFlagSit;
        bool offsetFlagStand;
        Clock timerDamage;
};
