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

vec4 quaternion_add(vec4 a, vec4 b);

vec4 quaternion_subtract(vec4 a, vec4 b);

vec4 quaternion_multiply(vec4 a, vec4 b);

vec4 quaternion_scale(vec4 a, float scale);

float quaternion_length(vec4 a);

vec4 quaternion_normalize(vec4 a);

vec4 quaternion_conjugate(vec4 a);

vec4 quaternion_inverse(vec4 a);

#endif
