#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
	int *items;
	size_t count;
	size_t size;
} Array;

Array array_init(size_t size);
void array_push(Array *arr, int item);
void array_insert(Array *arr, size_t index, int item);
void array_fill(Array *arr, size_t begin, size_t end, int c);
void array_erase(Array *arr, size_t index);
size_t array_search(Array haystack, int needle);

#endif //ARRAY_H

#ifdef ARRAY_IMPLEMENTATION

Array array_init(size_t size)
{
	Array arr = {
		.items = malloc(sizeof(*arr.items)*size),
		.count = 0,
		.size = size
	};
	memset(arr.items, 0, sizeof(*arr.items)*arr.size);
	return arr;
}

void array_push(Array *arr, int item)
{
	if (arr->count >= arr->size - 1) {
		printf("%s: error: [overflow] heap memory limit reached\n", __FILE__);
		exit(1);
	}
	arr->items[arr->count] = item;
	arr->count++;
}

void array_insert(Array *arr, size_t index, int item)
{
	if (arr->count >= arr->size - 1) {
		printf("%s: error: [overflow] heap memory limit reached\n", __FILE__);
		exit(1);
	}
	if (arr->size < index) {
		printf("%s: error: [overflow] index is out of bound\n", __FILE__);
		exit(1);
	}
	if (arr->count > index) {
		for (size_t i = arr->count; i > index; i--) {
			arr->items[i] = arr->items[i - 1];
		}
		arr->items[index] = item;
	}
	if (arr->count < index && arr->size > index)
		arr->items[index] = item;
	arr->count++;
}

void array_fill(Array *arr, size_t begin, size_t end, int c)
{
	for (size_t i = begin; i <= end; i++)
		arr->items[i] = c;
}

void array_erase(Array *arr, int index)
{
	if (arr->count == 0) {
		printf("%s: error: [underflow] heap memory is empty\n", __FILE__);
		exit(1);
	}
	for (int i = index; i < arr->size; i++) {
		arr->items[i] = arr->items[i + 1];
	}
	arr->count--;
}

size_t array_search(Array haystack, int needle)
{
	for (size_t i = 0; i < haystack.count; i++) {
		if (haystack.items[i] == needle)
			return i;
	}
	return haystack.size;
}

#endif //ARRAY_IMPLEMENTATION
