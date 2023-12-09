#include "engine.hpp"

Engine::Engine() {
    Vector2f position;
    position.x = VideoMode::getDesktopMode().width;
    position.y = VideoMode::getDesktopMode().height;

    window.create(VideoMode(position.x,position.y),"Game",Style::Default);
    backGroundTexture.loadFromFile("../texturs/лес.jpg",IntRect(0,0,position.x,position.y));
    backGroundSprite.setTexture(backGroundTexture);
    backGroundSprite.setScale(static_cast<float>(window.getSize().x) / backGroundSprite.getLocalBounds().width,
                              static_cast<float>(window.getSize().y) / backGroundSprite.getLocalBounds().height);

}

void Engine::start() {
    Clock clock;
    while (window.isOpen()) {
        Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();

        input();
        interaction();
        update(dtAsSeconds);
        draw();
    }
}
