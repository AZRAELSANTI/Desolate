#pragma once

#include "vector3d.hpp"
class vec2_t {
public:
	float x, y;

	vec2_t() {
		x = 0; y = 0;
	};
	vec2_t(float _x, float _y) {
		x = _x; y = _y;
	};
	vec2_t(vec3_t vec) {
		x = vec.x; y = vec.y;
	}

	inline vec2_t operator*(const float n) const {
		return vec2_t(x * n, y * n);
	}
	inline vec2_t operator+(const vec2_t& v) const {
		return vec2_t(x + v.x, y + v.y);
	}
	inline vec2_t operator-(const vec2_t & v) const {
		return vec2_t(x - v.x, y - v.y);
	}
	inline void operator+=(const vec2_t & v) {
		x += v.x;
		y += v.y;
	}
	inline void operator-=(const vec2_t & v) {
		x -= v.x;
		y -= v.y;
	}

	bool operator==(const vec2_t & v) const {
		return (v.x == x && v.y == y);
	}
	bool operator!=(const vec2_t & v) const {
		return (v.x != x || v.y != y);
	}

	inline float length() {
		return sqrt((x * x) + (y * y));
	}

	__forceinline void clear() {
		x = y = 0.f;
	}
	__forceinline vec2_t& operator/=(float f) {
		x /= f;
		y /= f;
		return *this;
	}
	__forceinline bool valid() const {
		return x > 1 && y > 1;
	}

	bool __inline is_zero()
	{
		return x == 0.0f && y == 0.0f;
	}

	inline vec2_t operator+(float value) const { return vec2_t(x + value, y + value); }
};
