#include "engine.hpp"
#include "math.h"
#include "iostream"

void Engine::interaction(){
    if (!canDamage) {
            timeDamageDrago.restart();
            canDamage = true;
        }
    if (timeDamageDrago.getElapsedTime().asSeconds() > 1.0f) {//225
        if(!playerOne.attack) {
            if (enemy.rigth &&  enemy.position.x + 30 + 265 >= playerOne.position.x && enemy.position.y - playerOne.position.y <= 70)
                playerOne.getDamage(enemy.rigth);
            if (enemy.left && enemy.position.x - playerOne.position.x <= 150 && enemy.position.y - playerOne.position.y <= 70)
                playerOne.getDamage(enemy.rigth);//124
            if ((abs(enemy.position.x - playerOne.position.x) <= 56))
                playerOne.getDamage(enemy.rigth);
        } else{
            if (enemy.rigth &&  enemy.position.x + 190 >= playerOne.position.x && enemy.position.y - playerOne.position.y <= 70)
                playerOne.getDamage(enemy.rigth);
            if (enemy.left && enemy.position.x - playerOne.position.x <= 230 && enemy.position.y - playerOne.position.y <= 70)
                playerOne.getDamage(enemy.rigth);//124
            if ((abs(enemy.position.x - playerOne.position.x) <= 105))
                playerOne.getDamage(enemy.rigth);
        }
        canDamage = false;
    }

}

