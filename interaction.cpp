#include "engine.hpp"
#include "math.h"
#include "iostream"

void Engine::interaction(){
    if (!canDamage) {
            timeDamageDrago.restart();
            canDamage = true;
        }
    if (timeDamageDrago.getElapsedTime().asSeconds() > 1.0f) {
        if (enemy.rigth && (abs(enemy.position.x - playerOne.position.x) <= 225) && enemy.position.y - playerOne.position.y <= 50)
            playerOne.getDamage(enemy.rigth);
        if (enemy.left && (abs(enemy.position.x - playerOne.position.x) <= 125)&& enemy.position.y - playerOne.position.y <= 50)
            playerOne.getDamage(enemy.rigth);
        canDamage = false;
    }//enemy.position.x  >= - 200 + playerOne.position.x
    //enemy.position.x  <= 125 + playerOne.position.x
}

