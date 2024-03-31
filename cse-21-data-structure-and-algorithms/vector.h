#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

#define DEFAULT_CAPACITY 64
#define GROWTH_FACTOR 1.125
#define MOD_VEC_AT(v, i) (v)->items[(i)]
#define VEC_AT(v, i) (v).items[(i)]

typedef struct vec {
	int *items;
	size_t size;
	size_t capacity;
} vec;

vec vec_init();
void vec_resolve_capacity(vec *v);
void vec_push_back(vec *v, int item);
void vec_push_front(vec *v, int item);
void vec_pop_front(vec *v);
void vec_pop_back(vec *v);
void vec_insert(vec *v, size_t index, int item);
void vec_erase(vec *v, size_t index);
void vec_fill(vec *v, size_t begin, size_t end, int c);

#endif //VECTOR_H

#ifdef VECTOR_IMPLEMENTATION

vec vec_init()
{
	vec v = {
		.items = malloc(sizeof(*v.items)*DEFAULT_CAPACITY),
		.size = 0,
		.capacity = DEFAULT_CAPACITY
	};
	memset(v.items, '\0', sizeof(*v.items)*v.capacity);
	return v;
}

void vec_resolve_capacity(vec *v)
{
	if (v->size == v->capacity) {
		int new_capacity = v->capacity + v->capacity*GROWTH_FACTOR;
		v->items = realloc(v->items, sizeof(*v->items)*new_capacity);
		v->capacity = new_capacity;
	}
}

void vec_push_back(vec *v, int item)
{
	vec_resolve_capacity(v);
	MOD_VEC_AT(v, v->size) = item;
	v->size++;
}

void vec_push_front(vec *v, int item)
{
	vec_resolve_capacity(v);
	for (size_t i = v->size; i > 0; i--) {
		MOD_VEC_AT(v, i) = MOD_VEC_AT(v, i - 1);
	}
	MOD_VEC_AT(v, 0) = item;
	v->size++;
}

void vec_pop_front(vec *v)
{
	if (v->size == 0) {
		printf("%s: error: [underflow] heap memory is empty\n", __FILE__);
		exit(1);
	}
	for (size_t i = 0; i < v->size - 1; i++) {
		MOD_VEC_AT(v, i) = MOD_VEC_AT(v, i + 1);
	}
	MOD_VEC_AT(v, v->size) = '\0';
	v->size--;
}

void vec_pop_back(vec *v)
{
	if (v->size == 0) {
		printf("%s: error: [underflow] heap memory is empty\n", __FILE__);
		exit(1);
	}
	MOD_VEC_AT(v, v->size) = '\0';
	v->size--;
}

void vec_insert(vec *v, size_t index, int item)
{
	vec_resolve_capacity(v);
	for (size_t i = v->size; i > index; i--) {
		MOD_VEC_AT(v, i) = MOD_VEC_AT(v, i - 1);
	}
	MOD_VEC_AT(v, index) = item;
	v->size++;
}

void vec_erase(vec *v, size_t index)
{
	if (v->size == 0) {
		printf("%s: error: [underflow] heap memory is empty\n", __FILE__);
		exit(1);
	}
	for (size_t i = index; i < v->size - 1; i++) {
		MOD_VEC_AT(v, i) = MOD_VEC_AT(v, i + 1);
	}
	MOD_VEC_AT(v, v->size) = '\0';
	v->size--;
}

void vec_fill(vec *v, size_t begin, size_t end, int c)
{
	for (size_t i = begin; i < v->size; i++) {
		MOD_VEC_AT(v, i) = c;
	}
}

#endif //VECTOR_IMPLEMENTATION
