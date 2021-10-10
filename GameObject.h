#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include "Vector2d.h"

class GameObject
{
public:
    Vector2d m_position ;
    std::string m_name ;
    GameObject ( ) { /* to do */ }
    GameObject ( const Vector2d& position, std::string name ): m_position { position } , m_name{name } { }
    Vector2d getPosition() const { return m_position; }
};


#endif // GAMEOBJECT_H
