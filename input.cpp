#include "engine.hpp"

void Engine::input() {
    static sf::Clock keyPressTimer;
    static bool isKeyPressed = false;


    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        window.close();
    }
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        playerOne.goLeft();
        playerOne.dx = -1;
    }
    else {
        playerOne.stopLeft();
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        playerOne.goRight();
        playerOne.dx = 1;
    }
    else {
        playerOne.stopRight();
    }
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        if (playerOne.onGround)
            playerOne.goJump();
    }

    if (Keyboard::isKeyPressed(Keyboard::S)) {
        if (playerOne.onGround && !playerOne.attack)
            playerOne.goSitDown();
    }
    else {
        playerOne.stopSitDown();
    }
    if (Keyboard::isKeyPressed(Keyboard::O)) {
        if (!isKeyPressed) {
            keyPressTimer.restart();
            isKeyPressed = true;
        }

        if (playerOne.sitDown)
            playerOne.attackSitDown();
        else
            playerOne.attackStand();

    }
    else{
        if (playerOne.sitDown)
            playerOne.stopAttackSitDown();
        else
            playerOne.stopAttackStand();
    }
    //keyPressTimer.restart();
}

