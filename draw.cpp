#include "engine.hpp"

void Engine::draw() {
    Event event;

    while(window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        }
    }
    window.clear();

    window.draw(backGroundSprite);
    window.draw(playerOne.getSprite());
    window.draw(enemy.getSprite());

    window.display();
}
