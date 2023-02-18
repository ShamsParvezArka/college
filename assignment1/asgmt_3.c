#include <stdio.h>

int main()
{
	float height, base;
	scanf("input height: %f", &height);
	scanf("input base  : %f", &base);

	float area = (height * base) / 2;
	printf("the are of triangle: %.2f square unit", area);

	return 0;
}
