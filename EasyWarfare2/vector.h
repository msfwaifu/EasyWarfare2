#pragma once

typedef float vec3_t[3];

bool VectorCompare(vec3_t v1, vec3_t v2);

void CrossProduct(vec3_t v1, vec3_t v2, vec3_t cross);

float DotProduct(vec3_t v1, vec3_t v2);

void VectorSubtract(vec3_t va, vec3_t vb, vec3_t out);

void VectorAdd(vec3_t va, vec3_t vb, vec3_t out);

void VectorCopy(vec3_t in, vec3_t out);

void VectorInverse(vec3_t v);

float VectorLength(const vec3_t v);