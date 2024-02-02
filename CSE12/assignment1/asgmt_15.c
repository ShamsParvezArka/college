#include <stdio.h>

float tofeh(float temperature) {
	return ((9 * temperature) / 5) + 32;
}



int main()
{
	float temperature;
	printf("input temperature (C): ");
	scanf("%f", &temperature);
	printf("temperature in F: %f\n", tofeh(temperature));
	return 0;
}
