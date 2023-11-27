// 
// Various linear algebra utilities
//
// Copyright (c) 2023, Jonathan Tainer
//

#ifndef LINALG_H
#define LINALG_H

#include <math.h>

typedef struct vec4 {
	float w, x, y, z;
} vec4;

vec4 quaternion_add(vec4 a, vec4 b) {
	return (vec4) { a.w+b.w, a.x+b.x, a.y+b.y, a.z+b.z };
}

vec4 quaternion_subtract(vec4 a, vec4 b) {
	return (vec4) { a.w-b.w, a.x-b.x, a.y-b.y, a.z-b.z };
}

vec4 quaternion_multiply(vec4 a, vec4 b) {
	vec4 res = { 0, 0, 0, 0 };
	res.w = a.w*b.w - a.x*b.x - a.y*b.y - a.z*b.z;
	res.x = a.w*b.x + a.x*b.w + a.y*b.z - a.z*b.y;
	res.y = a.w*b.y - a.x*b.z + a.y*b.w + a.z*b.x;
	res.z = a.w*b.z + a.x*b.y - a.y*b.x + a.z*b.w;
	return res;
}

vec4 quaternion_scale(vec4 a, float scale) {
	return (vec4) { a.w*scale, a.x*scale, a.y*scale, a.z*scale };
}

float quaternion_length(vec4 a) {
	return sqrtf(a.w*a.w + a.x*a.x + a.y*a.y + a.z*a.z);
}

vec4 quaternion_normalize(vec4 a) {
	float inv_len = 1.f / quaternion_length(a);
	return quaternion_scale(a, inv_len);
}

vec4 quaternion_conjugate(vec4 a) {
	return (vec4) { a.w, -a.x, -a.y, -a.z };
}

vec4 quaternion_inverse(vec4 a) {
	float norm = quaternion_length(a);
	float scale = 1.f / (norm*norm);
	vec4 conj = quaternion_conjugate(a);
	return quaternion_scale(conj, scale);
}

#endif
