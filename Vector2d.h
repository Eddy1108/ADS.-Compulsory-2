#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2d
{
public:
    Vector2d();
    Vector2d(double x, double y);

    double x ;
    double y ;

    Vector2d operator + ( const Vector2d& v ) const
    {
        Vector2d u;
        u.x = x + v.x;
        u.y = y + v.y;

        return u;
    }

    Vector2d operator / ( int d )
    {
        Vector2d u;
        u.x = x/d;
        u.y = y/d;

        return u;
    }


};


#endif // VECTOR2D_H
