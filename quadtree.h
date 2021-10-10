#ifndef QUADTREE_H
#define QUADTREE_H

#include "GameObject.h"
#include <vector>

class QuadTree
{
private :
    Vector2d m_a;
    Vector2d m_b;
    Vector2d m_c;
    Vector2d m_d;
    std::vector<GameObject> m_gameObjects;
    bool isLeaf() const;

public :
    QuadTree* m_sw;
    QuadTree* m_se;
    QuadTree* m_ne;
    QuadTree* m_nw;


    QuadTree();
    QuadTree(const Vector2d &v1 , const Vector2d &v2 , const Vector2d &v3 , const Vector2d & v4);
    void subDivide (int n);
    void printCenter() const;
    void printCorners() const;
    void printAllLeaves() const;
    Vector2d findCenter() const;
    QuadTree* insert( const GameObject& gameObject);
    QuadTree* find(const Vector2d& p);
} ;

#endif // QUADTREE_H
