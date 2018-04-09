#include "Vec2.h"



Vec2::Vec2(float x, float y){
    this->x = x;
    this->y = y;
}

Vec2 Vec2::operator +(const Vec2& rhs)const{
    Vec2 result = *this;
    result.x += rhs.x;
    result.y += rhs.y;
    return result;
}

Vec2 Vec2::operator +=(const Vec2& rhs){
   this->x += rhs.x;
   this->y += rhs.y;
    return *this;
}

Vec2 Vec2::operator/(float rhs){
    this->x/=rhs;
    this->y/=rhs;
    return *this;
}
Vec2 Vec2::operator*(float rhs){
    this->x*=rhs;
    this->y*=rhs;
    return *this;
}