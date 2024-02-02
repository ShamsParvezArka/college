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
void array_push(Array *a, int item);
void array_insert(Array *a, size_t index, int item);
void array_fill(Array *a, size_t begin, size_t end, int c);
void array_erase(Array *a, size_t index);
size_t array_search(Array haystack, int needle);

#endif //ARRAY_H

#ifdef ARRAY_IMPLEMENTATION

Array array_init(size_t size)
{
	Array a = {
		.items = malloc(sizeof(*a.items)*size),
		.count = 0,
		.size = size
	};
	memset(a.items, 0, sizeof(*a.items)*a.size);
	return a;
}

void array_push(Array *a, int item)
{
	if (a->count >= a->size - 1) {
		printf("%s: error: [overflow] heap memory limit reached\n", __FILE__);
		exit(1);
	}
	a->items[a->count] = item;
	a->count++;
}

void array_insert(Array *a, size_t index, int item)
{
	if (a->count >= a->size - 1) {
		printf("%s: error: [overflow] heap memory limit reached\n", __FILE__);
		exit(1);
	}
	if (a->size < index) {
		printf("%s: error: [overflow] index is out of bound\n", __FILE__);
		exit(1);
	}
	if (a->count > index) {
		for (size_t i = a->count; i > index; i--) {
			a->items[i] = a->items[i - 1];
		}
		a->items[index] = item;
	}
	if (a->count < index && a->size > index)
		a->items[index] = item;
	a->count++;
}

void array_fill(Array *a, size_t begin, size_t end, int c)
{
	for (size_t i = begin; i <= end; i++)
		a->items[i] = c;
}

void array_erase(Array *a, int index)
{
	if (a->count == 0) {
		printf("%s: error: [underflow] heap memory is empty\n", __FILE__);
		exit(1);
	}
	for (int i = index; i < a->size; i++) {
		a->items[i] = a->items[i + 1];
	}
	a->count--;
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
