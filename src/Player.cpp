#include "Player.hpp"

int a = 0;

Player::Player() {
    gameObjects.push_back(this);
}

void Player::Update() {
    
}

void Player::Start() {
    std::cout << "Player Spawned";
}
