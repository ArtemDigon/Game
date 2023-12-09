#include "players.hpp"

Players::Players() {
    hp = 10;
    onGround = true;
    float //cur = 0;
    dx = dy = 0;
    ground = 530;
    m_speed = 250;
    leftBorder = 0;
    rigthBorder = 1300;
    position.x = 500;
    position.y = VideoMode::getDesktopMode().height/3;
    texture.loadFromFile("../texturs/Спрайт_Гладиатор.png");
    sprite.setTexture(texture);
    sprite.setTextureRect( IntRect(0,0,136,200));
}

Players::~Players() {

}

void Players::goLeft() {
    m_LeftPressed = true;
    currentFrame += 0.003;
    if (m_RightPressed)
        return;
    if (currentFrame > 5) {
        currentFrame = 0;
    }
    if (position.y == ground) {
        sprite.setTextureRect( IntRect(136 * (int)floor(currentFrame) + 136, 0, -136, 200));
    }
}

void Players::defaultPosition() {
    if (dx > 0)
        sprite.setTextureRect(IntRect(0,0,136,200));
    else
        sprite.setTextureRect(IntRect(136,0,-136,200));
}

void Players::stopLeft() {
    m_LeftPressed = false;
}

void Players::goRight() {
    m_RightPressed = true;
    if (m_LeftPressed)
        return;
    currentFrame += 0.003;
    if (currentFrame > 5) {
       currentFrame = 0;
    }
    if (position.y == ground) {
        sprite.setTextureRect( IntRect(136 * (int)floor(currentFrame), 0, 136, 200));
    }

}

void Players::stopRight() {
    m_RightPressed = false;

}

void Players::goJump() {
    onGround = false;
    dy = -40;
    if (m_RightPressed)
        sprite.setTextureRect(IntRect(697,0,125,190));
    else
        sprite.setTextureRect(IntRect(817,0,-125,190));
}
 void Players::stopJump() {
         onGround = true;
}
Sprite Players::getSprite(){
    return sprite;
}
 void Players::goSitDown() {
    sitDown = true;
    m_speed = 0;
    currentFrame += 0.003;
    if (currentFrame > 2)
        currentFrame = 2;
    if (dx == 1){
        sprite.setTextureRect(IntRect((int)floor(currentFrame)*134,585,134,200));
    }
    else{
        sprite.setTextureRect(IntRect((int)floor(currentFrame)*134+134,585,-134,200));
    }
}

void Players::stopSitDown(){
        sitDown = false;
        m_speed = 400;
}

void Players::attackSitDown(){
        sitDown = true;
        attackSit = true;
        if (dx == 1){
           sprite.setTextureRect(IntRect(555,585,234,200));
        }
        else{
           if (!offsetFlagSit){
                position.x -=120;
                 offsetFlagSit = true;
            }
            sprite.setTextureRect(IntRect(555+234,585,-234,200));
        }

}

void Players::getDamage(bool goRight){
    if (goRight)
        sprite.setTextureRect(IntRect(160,200,-160,175));
    else
        sprite.setTextureRect(IntRect(0,200,160,175));

    getDamageFlag = true;
    dy = -25;
    timerDamage.restart();
    enemyGoRigth = goRight;
    hp -= 1;
}

void Players::dead(){
    if (hp == 0){
        m_LeftPressed = false;
        m_RightPressed = false;
        attack = false;
        attackSit = false;
        gladiatorDead = true;
        currentFrame += 0.004;
        if (dx > 0) {
            switch ((int)floor(currentFrame))
            {
            case 0:
                sprite.setTextureRect(IntRect(0,795,180,175));
                break;
            case 1:
                sprite.setTextureRect(IntRect(180,795,145,175));
                break;
            case 2:
                sprite.setTextureRect(IntRect(325,795,200,175));
                break;
            default:
                sprite.setTextureRect(IntRect(525,795,215,175));
                break;
            }
        }else{
            switch ((int)floor(currentFrame))
            {
            case 0:
                sprite.setTextureRect(IntRect(180,795,-180,175));
                break;
            case 1:
                sprite.setTextureRect(IntRect(325,795,-145,175));
                break;
            case 2:
                sprite.setTextureRect(IntRect(525,795,-200,175));
                break;
            default:
                sprite.setTextureRect(IntRect(740,795,-215,175));
                break;
            }
        }
    }
}

void Players::attackStand(){
        attack = true;
        m_speed = 0;
        if (dx == 1){
            sprite.setTextureRect(IntRect(280,393,240,190));
        }
        else {
            if (!offsetFlagStand){
                position.x -=120;
                offsetFlagStand = true;
            }
            sprite.setTextureRect(IntRect(280 + 240,393,-240,190));
        }
}

void Players::stopAttackSitDown(){
    if (offsetFlagSit){
        position.x +=120;
        offsetFlagSit = false;
    }
    attackSit = false;
    offsetFlagSit = false;
}

void Players::stopAttackStand(){
    if (offsetFlagStand){
        offsetFlagStand = false;
        position.x +=120;
    }
    if (attack) {
        m_speed = 250;
        attack = false;
        offsetFlagStand = false;
        defaultPosition();
    }
}


void Players:: update(float elapsedtime) {

    if(!sitDown && attackSit) {
        stopAttackSitDown();
    }

    if (m_RightPressed && !(m_LeftPressed)) {
        position.x += elapsedtime * m_speed;
            if (position.x > rigthBorder)
                position.x = rigthBorder;
    }
    if (m_LeftPressed && !(m_RightPressed)) {
        position.x -= elapsedtime * m_speed;
            if (position.x < leftBorder)
                position.x = leftBorder;
    }
    if (onGround == false) {
        dy +=90 * elapsedtime;
        position.y +=dy * elapsedtime * 35;
        onGround = false;
    }
    if (position.y > ground) {
        position.y = ground;
        dy = 0;
        onGround = true;
        defaultPosition();
    }
    if (getDamageFlag){
        //dy +=90 * elapsedtime;
        onGround = false;
        position.y +=dy * elapsedtime * 35;
        if (enemyGoRigth){
            position.x += 1.5*  elapsedtime * m_speed;
            if (position.x > rigthBorder)
                position.x = rigthBorder;
        }
        else{
           position.x += -1.5 *  elapsedtime * m_speed;
           if (position.x < leftBorder)
                position.x = leftBorder;
        }
        if (timerDamage.getElapsedTime().asSeconds() > 0.5f)
            getDamageFlag = false;
            //defaultPosition();
    }
    dead();
    sprite.setPosition(position);
}
