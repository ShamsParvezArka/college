#include <stdio.h>

#define ARRAY_IMPLEMENTATION
#include "array.h"

int main(int argc, char *argv[])
{
	Array arr = array_init(10);
	array_fill(&arr, 2, 5, 69);
	
	for (int i = 0; i < arr.size; i++) {
		printf("%d ", arr.items[i]);
	}

	return 0;
}