#include "enemy.hpp"
#include "math.h"

Enemy::Enemy(){
    hp = 10;
    rigth = true;
    left = false;
    speed = 125;
    ground = 530;
    position.x = 100;
    position.y = 530;
    texture.loadFromFile("../texturs/дракон.png");
    sprite.setTexture(texture);
    sprite.setTextureRect( IntRect(0,0,265,182));

}

Sprite Enemy::getSprite(){
    return sprite;
}

void  Enemy::findGlagiator(Vector2f position){
        if (position.x > Enemy::position.x ){
            rigth = true;
            left = false;
            speed = 125;
        } else if (abs(position.x - Enemy::position.x) < 10) {
            left = false;
            rigth = false;
            speed = 0;
        }else if (position.x < Enemy::position.x)  {
            left = true;
            rigth = false;
            speed = 125;
        }
}

void Enemy::getDamage(bool rigthSide){
    damageTimer.restart();
    getDamageFlag = true;
    glagiatorGoRigth = rigthSide;
    dy = -25;
    if (hp > 0){
        hp -= 1;
    }
}

void Enemy::go(){
    currentFrame += 0.003;
    if (currentFrame >= 2)
        currentFrame = 0;

    if (rigth){
        sprite.setTextureRect(IntRect((int)floor(currentFrame)*265,0,265,182));
    }
    if (left){
        sprite.setTextureRect(IntRect(((int)floor(currentFrame) + 1)*265,0,-265,182));
    }
}

void Enemy::dead(){
    if (hp == 0){

        deadDrado = true;
        sprite.setTextureRect(IntRect(0,210,205,180));
    }
}

void Enemy::update(float elapsedTime,Vector2f positionA){
    if (!deadDrado){
        findGlagiator(positionA);
        go();
        if (onGround == false) {
            dy +=90 * elapsedTime;
            position.y +=dy * elapsedTime * 35;
            onGround = false;
        }
        if (position.y > ground) {
            position.y = ground;
            dy = 0;
            onGround = true;
        }
        if (rigth)
            position.x += elapsedTime * speed;
        if(left)
            position.x -= elapsedTime * speed;
        if (position.x > 1250){
            position.x = 1250;
            rigth = false;
            left = true;
        }
        if (position.x < -50){
            position.x = -50;
            left = false;
            rigth = true;
        }
        if (getDamageFlag){
            onGround = false;
            position.y +=dy * elapsedTime * 35;
            if (glagiatorGoRigth){
                position.x += 3*  elapsedTime * speed;
                if (position.x > 1200)
                    position.x = 1200;
            }
            else{
                position.x += -3 *  elapsedTime * speed;
                if (position.x < 0)
                    position.x = 0;
            }
            if (damageTimer.getElapsedTime().asSeconds() > 0.5f)
                getDamageFlag = false;
        }
    }
    dead();
    sprite.setPosition(position);
}
