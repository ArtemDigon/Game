#include "engine.hpp"
#include "math.h"

void Engine::interaction(){
    if (!enemy.canDamage) {
            enemy.timeDamageDrago.restart();
            if (!playerOne.gladiatorDead && !enemy.deadDrado)
                enemy.canDamage = true;
        }
    if (enemy.timeDamageDrago.getElapsedTime().asSeconds() > 1.0f && enemy.canDamage && enemy.position.y - playerOne.position.y <= 70) {//225
        if(!playerOne.attack) {
            if (enemy.rigth &&  enemy.position.x + 30 + 265 >= playerOne.position.x)
                playerOne.getDamage(enemy.rigth);
            if (enemy.left && enemy.position.x - playerOne.position.x <= 150)
                playerOne.getDamage(enemy.rigth);
            if ((abs(enemy.position.x - playerOne.position.x) <= 56))
                playerOne.getDamage(enemy.rigth);
        } else{
            if (enemy.rigth &&  enemy.position.x + 190 >= playerOne.position.x)
                playerOne.getDamage(enemy.rigth);
            if (enemy.left && enemy.position.x - playerOne.position.x <= 230 )
                playerOne.getDamage(enemy.rigth);
            if ((abs(enemy.position.x - playerOne.position.x) <= 105))
                playerOne.getDamage(enemy.rigth);
        }
        enemy.canDamage = false;
    }

    if (!playerOne.canDamage) {
            playerOne.timeDamageGlagiator.restart();
            if (!enemy.deadDrado)
                playerOne.canDamage = true;
        }
    if (playerOne.timeDamageGlagiator.getElapsedTime().asSeconds() > 1.0f && playerOne.canDamage && (playerOne.attack || playerOne.attackSit) && enemy.position.y - playerOne.position.y <= 70) {
        if(playerOne.dx > 0 && playerOne.position.x + 195 >= enemy.position.x && playerOne.position.x + 265 <= enemy.position.x + 265)
            enemy.getDamage(true);
        if(playerOne.dx < 0 && playerOne.position.x  >= enemy.position.x && playerOne.position.x + 45 <= enemy.position.x + 280)
            enemy.getDamage(false);
        playerOne.canDamage = false;
    }
}


