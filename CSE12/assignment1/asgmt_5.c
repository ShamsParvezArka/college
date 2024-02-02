#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("input 3 integers: %d %d %d", &a, &b, &c);
	int sum = a + b + c;
	int average = (sum) / 2;
	printf("sum: %d,\n average: %d\n", sum, average);
	return 0;
}
