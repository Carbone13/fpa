#ifndef FPA_INCLUDE_FPA_VEC2_HPP_
#define FPA_INCLUDE_FPA_VEC2_HPP_

#include <fpm/fixed.hpp>
typedef fpm::fixed_16_16 f32;

constexpr f32 ZERO {0};

namespace fpa
{
    struct vec2
    {
        f32 x{0};
        f32 y{0};

        vec2(f32 x, f32 y) : x(x), y(y)
        {
        }

        [[nodiscard]] f32 length() const;
        [[nodiscard]] f32 lengthSquared() const;
        [[nodiscard]] f32 dist(const vec2 &b) const;
        [[nodiscard]] f32 distSquared(const vec2 &b) const;
        [[nodiscard]] f32 dot(const vec2 &b) const;

        [[nodiscard]] vec2 normalized() const;
        vec2 normalize();
        
        // ASSIGNMENT AND EQUALITY OPERATIONS
        inline vec2 & operator = (const vec2 & v) = default;
        inline vec2 & operator = (const f32 & f) { x = f; y = f; return *this; }
        inline vec2 & operator - () { x = -x; y = -y; return *this; }
        inline bool operator == (const vec2 & v) const { return (x == v.x) && (y == v.y); }
        inline bool operator != (const vec2 & v) const { return (x != v.x) || (y != v.y); }
        inline bool operator<(vec2 const& rhs) const {return (x < rhs.x) || ((x == rhs.x) && (y < rhs.y));}
        
        // vec2 TO vec2 OPERATIONS
        inline vec2 operator + (const vec2 & v) const { return vec2(x + v.x, y + v.y); }
        inline vec2 operator - (const vec2 & v) const { return vec2(x - v.x, y - v.y); }
        inline vec2 operator * (const vec2 & v) const { return vec2(x * v.x, y * v.y); }
        inline vec2 operator / (const vec2 & v) const { return vec2(x / v.x, y / v.y); }

        // vec2 TO THIS OPERATIONS
        inline vec2 & operator += (const vec2 & v) { x += v.x; y += v.y; return *this; }
        inline vec2 & operator -= (const vec2 & v) { x -= v.x; y -= v.y; return *this; }
        inline vec2 & operator *= (const vec2 & v) { x *= v.x; y *= v.y; return *this; }
        inline vec2 & operator /= (const vec2 & v) { x /= v.x; y /= v.y; return *this; }

        //SCALAR TO vec2 OPERATIONS
        inline vec2 operator + (f32 v) const { return vec2(x + v, y + v); }
        inline vec2 operator - (f32 v) const { return vec2(x - v, y - v); }
        inline vec2 operator * (f32 v) const { return vec2(x * v, y * v); }
        inline vec2 operator / (f32 v) const { return vec2(x / v, y / v); }

        //SCALAR TO THIS OPERATIONS
        inline vec2 & operator += (f32 v) { x += v; y += v; return *this; }
        inline vec2 & operator -= (f32 v) { x -= v; y -= v; return *this; }
        inline vec2 & operator *= (f32 v) { x *= v; y *= v; return *this; }
        inline vec2 & operator /= (f32 v) { x /= v; y /= v; return *this; }
    };
} // namespace fpa

#endif // FPA_INCLUDE_FPA_VEC2_HPP_
