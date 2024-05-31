#include <stdio.h>

void swap(int *a, int *b);
void selection_sort(int arr[], size_t size);

int main() {
	int container[5] = { 3, 1, 4, 1, 5 };
	selection_sort(container, 5);

	for (int i = 0; i < 5; i++)
		printf("%d ", container[i]);

	return 0;
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void selection_sort(int arr[], size_t size) {
	for (int i = 0; i < size - 1; i++) {
		int min = i;

		for (int j = i + 1; j < size; j++) {
			if (arr[min] > arr[j])
				min = j;
		}

		swap(&arr[i], &arr[min]);
	}
}