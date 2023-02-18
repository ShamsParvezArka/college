#include <stdio.h>

int intmax(int a, int b)
{
	return (a > b) ? a : b;
}

int main()
{
	int a = 2;
	int b = 8;
	printf("%d\n", intmax(a, b));
}
