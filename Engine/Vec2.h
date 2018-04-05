#ifndef VEC2_H_
#define VEC2_H_

class Vec2{
    public:
        float x;
        float y;
        Vec2(float x, float y);
        Vec2 operator+(const Vec2& lhs,const Vec2& rhs);

};

#endif