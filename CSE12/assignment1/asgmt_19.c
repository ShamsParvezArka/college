#include <stdio.h>

int main()
{
	float unit;
	printf("input total use elecrticity unit: ");
	scanf("%f", &unit);

	if (unit <= 200)
		printf("total bill: %f\n", unit * 10);
	else 
		printf("total bill: %f\n", ((unit - 200) * 10 + (200 * 10)));

	return 0;
}
