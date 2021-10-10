#include "quadtree.h"
#include "Vector2d.h"

bool QuadTree::isLeaf() const
{
    return m_sw == nullptr && m_se == nullptr && m_ne == nullptr && m_nw == nullptr;
}

void QuadTree::printAllLeaves() const
{
    if(isLeaf())
    {
        printCorners();
    }
    else
    {
        m_se->printAllLeaves();
        m_sw->printAllLeaves();
        m_nw->printAllLeaves();
        m_ne->printAllLeaves();
    }
    return;
}

QuadTree::QuadTree()
{

}

QuadTree::QuadTree(const Vector2d &v1, const Vector2d &v2, const Vector2d &v3, const Vector2d &v4) : m_a{v1}, m_b{v2}, m_c{v3}, m_d{v4},
    m_sw{nullptr}, m_se{nullptr}, m_ne{nullptr}, m_nw{nullptr}
{

}

void QuadTree::subDivide(int n)
{
    if (n > 0)
    {
        Vector2d v1 = (m_a + m_b) / 2;
        Vector2d v2 = (m_b + m_c) / 2;
        Vector2d v3 = (m_c + m_d) / 2;
        Vector2d v4 = (m_d + m_a) / 2;
        Vector2d middle = (m_a + m_c) / 2;

        m_sw = new QuadTree(m_a, v1, middle, v4);
        m_sw->subDivide(n-1);
        m_se = new QuadTree(v1, m_b, v2, middle);
        m_se->subDivide(n-1);
        m_ne = new QuadTree(middle, v2, m_c, v3);
        m_ne->subDivide(n-1);
        m_nw = new QuadTree(v4, middle, v3, m_d);
        m_nw->subDivide(n-1);
    }
}

void QuadTree::printCorners() const
{
    std::cout << "Printing Corners: \nA = (" << m_a.x << ", " << m_a.y << "), ";
    std::cout << "\nB = (" << m_b.x << ", " << m_b.y << "), ";
    std::cout << "\nC = (" << m_c.x << ", " << m_c.y << "), ";
    std::cout << "\nD = (" << m_d.x << ", " << m_d.y << ")." << std::endl;
}
