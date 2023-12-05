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

vec4 vec4_add(vec4 a, vec4 b);

vec4 vec4_subtract(vec4 a, vec4 b);

vec4 vec4_multiply(vec4 a, vec4 b);

vec4 vec4_scale(vec4 a, float scale);

float vec4_length(vec4 a);

vec4 vec4_normalize(vec4 a);

vec4 vec4_conjugate(vec4 a);

vec4 vec4_inverse(vec4 a);

vec4 vec4_rotation(vec3 from, vec3 to);

vec3 vec3_add(vec3 a, vec3 b);

vec3 vec3_subtract(vec3 a, vec3 b);

vec3 vec3_scale(vec3 a, float scale);

float vec3 length(vec3 a);

vec3 vec3_normalize(vec3 a);

float vector3_dot(vec3 a, vec3 b);

vec3 vector3_cross(vec3 a, vec3 b);

#endif
