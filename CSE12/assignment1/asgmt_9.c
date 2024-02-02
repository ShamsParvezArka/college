#include <stdio.h>

int intcmpn(int a, int b, int c)
{
	if (a > b && a > c) 
		return a;
	else if (b > a && b > c) 
		return b;
	else 
		return c;
}

int main()
{
	int a, b, c;
	scanf("input 3 numbers: %d %d %d", &a, &b, &c);

	printf("largest of three numbers: %d\n", intcmpn(a, b, c));
	return 0;
}
