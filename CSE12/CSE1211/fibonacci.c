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
	size_t lower_limit = 2;
	size_t upper_limit = 10;
	printf("Fibonacci series within range [%zu, %zu] ", lower_limit, upper_limit);
	for (size_t i = lower_limit; i <= upper_limit; i++) {
		if (i == upper_limit)
			printf("%zu\n", fibonacci(i));
		else 
			printf("%zu, ", fibonacci(i));
	}
	return 0;
}
