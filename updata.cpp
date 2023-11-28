#include "engine.hpp"

using namespace sf;

void Engine::update(float dtAsSeconds) {
    playerOne.update(dtAsSeconds);
    enemy.update(dtAsSeconds,playerOne.position);
}
