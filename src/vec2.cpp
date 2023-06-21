#include "fpa/vec2.hpp"

#include <fpm/math.hpp>

namespace fpa
{
    f32 vec2::length() const
    {
        return sqrt(x*x + y*y);
    }

    f32 vec2::lengthSquared() const
    {
        return (x*x + y*y);
    }
    f32 vec2::dist(const vec2 &b) const
    {
        return sqrt((x-b.x)*(x-b.x) + (y-b.y)*(y-b.y));
    }

    f32 vec2::distSquared(const vec2 &b) const
    {
        return ((x-b.x)*(x-b.x) + (y-b.y)*(y-b.y));
    }

    f32 vec2::dot(const vec2 &b) const
    {
        return (x*b.x + y*b.y);
    }

    vec2 vec2::normalized() const
    {
        auto l = length();
        if(l == ZERO) {
            return *new vec2(ZERO, ZERO);
        }
        return *new vec2(x/l, y/l);
    }

    vec2 vec2::normalize()
    {
        auto l = length();
        if(l == ZERO){
            x = ZERO;
            y = ZERO;
            return *this;
        }

        x /= l;
        y /= l;
        return *this;
    }
} // namespace fpa