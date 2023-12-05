// 
// Various linear algebra utilities
//
// Copyright (c) 2023, Jonathan Tainer
//

#include "linalg.h"
#include <math.h>

vec4 vec4_add(vec4 a, vec4 b) {
	return (vec4) { a.w+b.w, a.x+b.x, a.y+b.y, a.z+b.z };
}

vec4 vec4_subtract(vec4 a, vec4 b) {
	return (vec4) { a.w-b.w, a.x-b.x, a.y-b.y, a.z-b.z };
}

vec4 vec4_multiply(vec4 a, vec4 b) {
	vec4 res = { 0, 0, 0, 0 };
	res.w = a.w*b.w - a.x*b.x - a.y*b.y - a.z*b.z;
	res.x = a.w*b.x + a.x*b.w + a.y*b.z - a.z*b.y;
	res.y = a.w*b.y - a.x*b.z + a.y*b.w + a.z*b.x;
	res.z = a.w*b.z + a.x*b.y - a.y*b.x + a.z*b.w;
	return res;
}

vec4 vec4_scale(vec4 a, float scale) {
	return (vec4) { a.w*scale, a.x*scale, a.y*scale, a.z*scale };
}

float vec4_length(vec4 a) {
	return sqrtf(a.w*a.w + a.x*a.x + a.y*a.y + a.z*a.z);
}

vec4 vec4_normalize(vec4 a) {
	float inv_len = 1.f / quaternion_length(a);
	return vec4_scale(a, inv_len);
}

vec4 vec4_conjugate(vec4 a) {
	return (vec4) { a.w, -a.x, -a.y, -a.z };
}

vec4 vec4_inverse(vec4 a) {
	float norm = quaternion_length(a);
	float scale = 1.f / (norm*norm);
	vec4 conj = quaternion_conjugate(a);
	return quaternion_scale(conj, scale);
}

vec4 vec4_rotation(vec3 from, vec3 to) {
    vec4 result = { 0 };

    float dot = vec3_dot(from, to);
    vec3 cross = vec3_cross(from, to);

    result.x = cross.x;
    result.y = cross.y;
    result.z = cross.z;
    result.w = 1.f + dot;

    return vec4_normalize(result);
}

vec3 vec3_add(vec3 a, vec3 b) {
	return (vec3) { a.x+b.x, a.y+b.y, a.z+b.z };
}

vec3 vec3_subtract(vec3 a, vec3 b) {
	return (vec3) { a.x-b.x, a.y-b.y, a.z-b.z };
}

vec3 vec3_scale(vec3 a, float scale) {
	return (vec3) { a.x*scale, a.y*scale, a.z*scale };
}

float vec3_length(vec3 a) {
	return sqrtf(a.x*a.x + a.y*a.y + a.z*a.z);
}

vec3 vec3_normalize(vec3 a) {
	float inv_len = 1.f / vec3_length(a);
	return vec3_scale(a, inv_len);
}

float vec3_dot(vec3 a, vec3 b) {
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

vec3 vec3_cross(vec3 a, vec3 b) {
	return (vec3) { a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x };
}


