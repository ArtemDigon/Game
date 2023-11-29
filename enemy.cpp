#include "enemy.hpp"
#include "math.h"
#include "iostream"

Enemy::Enemy(){
    rigth = true;
    left = false;
    speed = 175;
    position.x = 100;
    position.y = 700;
    texture.loadFromFile("/Users/artem/Cplusplus/SFML_engine/texturs/дракон.png");
    sprite.setTexture(texture);
    sprite.setTextureRect( IntRect(0,0,265,160));

}

Sprite Enemy::getSprite(){
    return sprite;
}

void  Enemy::findGlagiator(Vector2f position){
    //std::cout<<position.x << "  " << Enemy::position.x << std::endl;
    //if (position.y == Enemy::position.y){
        if (position.x > Enemy::position.x ){
            rigth = true;
            left = false;
            speed = 125;
        } else if (abs(position.x - Enemy::position.x) < 0.1) {
            Enemy::position.x = position.x;
            left = false;
            rigth = false;
            speed = 0;
        }else if (position.x < Enemy::position.x)  {
            left = true;
            rigth = false;
            speed = 175;
        }
    //}
}

void Enemy::go(){
    currentFrame += 0.003;
    if (currentFrame >= 2)
        currentFrame = 0;

    if (rigth){
        sprite.setTextureRect(IntRect((int)floor(currentFrame)*265,0,265,160));
    }
    else{
        sprite.setTextureRect(IntRect(((int)floor(currentFrame) + 1)*265,0,-265,160));
    }
}

void Enemy::update(float elasedTime,Vector2f positionA){
    findGlagiator(positionA);
    go();
    if (rigth)
        position.x += elasedTime * speed;
    if(left)
        position.x -= elasedTime * speed;
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
    sprite.setPosition(position);
}
