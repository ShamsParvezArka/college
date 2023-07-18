#include <stdio.h>
#include <math.h>
#include <error.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1024 
#define WHITE "\033[0;37m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"

void factorial(int n);
int multiply(int index, int arr[], int current_arr_size);
size_t numlen(size_t n);

int main()
{
	printf("%sFACTORIAL CLACULATOR%s\n\n", YELLOW, WHITE);
	while (true) {
		char input[SIZE*2];
		printf("[%sIn%s ]: ", GREEN, WHITE);
		fgets(input, sizeof(input), stdin);

		if (strcmp(input, "exit\n") == 0)
			return 0;
		if (strcmp(input, "clear\n") == 0) {
			system("clear");
			printf("%sFACTORIAL CLACULATOR%s\n\n", YELLOW, WHITE);
			continue;
		}
		if (strlen(input) - 1 != numlen(atoi(input))) {
			printf("[%sOut%s]: invalid input\n", RED, WHITE);
			continue;
		}
		printf("[%sOut%s]: ", GREEN, WHITE);
		factorial(atoi(input));
	}
	return 0;
}

void factorial(int n)
{
	int arr[SIZE*100]; 
	arr[0] = 1;
	int current_arr_size = 1;

	for (int i = 2; i <= n; i++) {
		current_arr_size = multiply(i, arr, current_arr_size);
	}

	for (int i = current_arr_size - 1; i >= 0; i--) {
		printf("%d", arr[i]);
	}
	printf("\n");
}

int multiply(int index, int arr[], int current_arr_size)
{
	int carry = 0;
	for (int i = 0; i < current_arr_size; i++) {
		int prod = arr[i] * index + carry;
		arr[i] = prod % 10;
		carry = prod / 10;
	}

	while (carry) {
		arr[current_arr_size] = carry % 10;
		carry /= 10;
		current_arr_size++;
	}

	return current_arr_size;
}

size_t numlen(size_t n)
{
	return floor(log10(n)) + 1;
}

