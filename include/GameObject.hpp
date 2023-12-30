#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

class GameObject
{
public:
    GameObject() = default;
    virtual void Start() = 0;
    virtual void Update() = 0;
    ~GameObject(void) = default;
};

#endif