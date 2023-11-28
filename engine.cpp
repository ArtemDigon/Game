#include "engine.hpp"

Engine::Engine() {
    Vector2f position;
    position.x = VideoMode::getDesktopMode().width;
    position.y = VideoMode::getDesktopMode().height;

    window.create(VideoMode(1600,1000),"Game",Style::Fullscreen);
    backGroundTexture.loadFromFile("/Users/artem/Cplusplus/SFML_engine/texturs/лес.jpg");
    backGroundSprite.setTexture(backGroundTexture);
}

void Engine::start() {
    Clock clock;

    while (window.isOpen()) {
        Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();

        find();
        input();
        update(dtAsSeconds);
        draw();
    }
}

void Engine::find() {
    enemy.findGlagiator(playerOne.position);
}
