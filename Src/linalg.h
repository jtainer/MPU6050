// 
// Various linear algebra utilities
//
// Copyright (c) 2023, Jonathan Tainer
//

#ifndef LINALG_H
#define LINALG_H

typedef struct vec4 {
	float w, x, y, z;
} vec4;

typedef struct vec3 {
	float x, y, z;
} vec3;

vec4 quaternion_add(vec4 a, vec4 b);

vec4 quaternion_subtract(vec4 a, vec4 b);

vec4 quaternion_multiply(vec4 a, vec4 b);

vec4 quaternion_scale(vec4 a, float scale);

float quaternion_length(vec4 a);

vec4 quaternion_normalize(vec4 a);

vec4 quaternion_conjugate(vec4 a);

vec4 quaternion_inverse(vec4 a);

vec4 quaternion_rotation(vec3 from, vec3 to);

float vector3_dot(vec3 a, vec3 b);

vec3 vector3_cross(vec3 a, vec3 b);

#endif
