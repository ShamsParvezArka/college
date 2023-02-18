#include <stdio.h>
#include <math.h>

const float PI = 3.1415;

int main()
{
	float radius;
	scanf("input raidus %f", &radius);

	float area = PI * pow(radius, 2);
	printf("the area of circle is %.2f square unit\n", area);
	return 0;
}
