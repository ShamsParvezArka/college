#include <stdio.h>

int main()
{
	int age, salary; 

	if (age > 30 && salary > 50000)
		printf("total salary: %d\n", salary + 1000);
	else 
		printf("total salary: %d\n", salary + 500);

	return 0;
}
