#include <stdio.h>

size_t fibonacci(size_t n)
{
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	size_t n = 10;
	printf("Fibonacci series within range [0, %zu] ", n);
	for (size_t i = 0; i <= n; i++) {
		if (i == n)
			printf("%zu\n", fibonacci(i));
		else 
			printf("%zu, ", fibonacci(i));
	}
	return 0;
}
