#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Globals.hpp"

class Player : public GameObject
{
public:
    Player();
    virtual void Start();
    virtual void Update();
    ~Player(void) = default;
};


#endif