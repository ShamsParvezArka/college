#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>

#define MOD_ARRAY_AT(a, i) (a)->items[(i)]
#define ARRAY_AT(a, i) (a).items[(i)]

typedef struct array {
	int *items;
	size_t count;
	size_t size;
} array;

array array_init(size_t size);
void array_push_back(array *arr, int item);
void array_push_front(array *arr, int item);
void array_insert(array *arr, size_t index, int item);
void array_pop_front(array *arr);
void array_pop_back(array *arr);
void array_fill(array *arr, size_t begin, size_t end, int c);
void array_erase(array *arr, size_t index);
size_t array_search(array haystack, int needle);

#endif //ARRAY_H

#ifdef ARRAY_IMPLEMENTATION

array array_init(size_t size)
{
	array arr = {
		.items = malloc(sizeof(*arr.items)*size),
		.count = 0,
		.size = size
	};
	memset(arr.items, '\0', sizeof(*arr.items)*arr.size);
	return arr;
}

void array_push_front(array *arr, int item)
{
	if (arr->count >= arr->size) {
		printf("%s: error: [overflow] heap memory limit reached\n", __FILE__);
		exit(1);
	}
	for (size_t i = arr->count; i > 0; i--) {
		MOD_ARRAY_AT(arr, i) = MOD_ARRAY_AT(arr, i - 1);
	}
	MOD_ARRAY_AT(arr, 0) = item;
	arr->count++;
}

void array_push_back(array *arr, int item)
{
	if (arr->count >= arr->size) {
		printf("%s: error: [overflow] heap memory limit reached\n", __FILE__);
		exit(1);
	}
	MOD_ARRAY_AT(arr, arr->count) = item;
	arr->count++;
}

void array_pop_front(array *arr)
{
	if (arr->count == 0) {
		printf("%s: error: [underflow] heap memory is empty\n", __FILE__);
		exit(1);
	}
	for (size_t i = 0; i < arr->count - 1; i++) {
		MOD_ARRAY_AT(arr, i) = MOD_ARRAY_AT(arr, i + 1);
	}
	MOD_ARRAY_AT(arr, arr->count) = '\0';
	arr->count--;
}

void array_pop_back(array *arr)
{
	if (arr->count == 0) {
		printf("%s: error: [underflow] heap memory is empty\n", __FILE__);
		exit(1);
	}
	MOD_ARRAY_AT(arr, arr->count) = '\0';
	arr->count--;
}

void array_insert(array *arr, size_t index, int item)
{
	if (arr->count >= arr->size) {
		printf("%s: error: [overflow] heap memory limit reached\n", __FILE__);
		exit(1);
	}
	if (arr->size < index) {
		printf("%s: error: [overflow] index is out of bound\n", __FILE__);
		exit(1);
	}
	for (size_t i = arr->count; i > index; i--) {
		MOD_ARRAY_AT(arr, i) = MOD_ARRAY_AT(arr, i - 1);
	}
	MOD_ARRAY_AT(arr, index) = item;
	arr->count++;
}

void array_erase(array *arr, size_t index)
{
	if (arr->count == 0) {
		printf("%s: error: [underflow] heap memory is empty\n", __FILE__);
		exit(1);
	}
	for (size_t i = index; i < arr->count - 1; i++) {
		MOD_ARRAY_AT(arr, i) = MOD_ARRAY_AT(arr, i + 1);
	}
	MOD_ARRAY_AT(arr, arr->count) = '\0';
	arr->count--;
}

void array_fill(array *arr, size_t begin, size_t end, int c)
{
	for (size_t i = begin; i < end; i++) {
		MOD_ARRAY_AT(arr, i) = c;
	}
}

size_t array_search(array haystack, int needle)
{
	for (size_t i = 0; i < haystack.count; i++) {
		if (ARRAY_AT(haystack, i) == needle)
			return i;
	}
	return haystack.size;
}

#endif //ARRAY_IMPLEMENTATION
