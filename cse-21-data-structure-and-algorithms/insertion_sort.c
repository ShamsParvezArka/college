#include <stdio.h>

void insertion_sort(int arr[], size_t size);

int main() {
	int container[5] = { 3, 1, 4, 1, 5 };
	insertion_sort(container, 5);

	for (int i = 0; i < 5; i++)
		printf("%d ", container[i]);

	return 0;
}

void insertion_sort(int arr[], size_t size) {
	for (int i = 1; i < size; i++) {
		int tmp = arr[i];
		int j = i - 1;

		for (; j >= 0; j--) {
			if (arr[j] > tmp)
				arr[j + 1] = arr[j];
			else
				break;
		}

		arr[j + 1] = tmp;
	}
}