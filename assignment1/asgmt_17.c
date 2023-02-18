#include <stdio.h>

int main()
{
	float mark;
	printf("input obtained mark: ");
	scanf("%f", &mark);

	if (mark >= 80)
		printf("A+\n");
	else if (mark >= 75 && mark < 80)
		printf("A-\n");
	else if (mark >= 70 && mark < 75)
		printf("A\n");
	else if (mark >= 65 && mark < 70)
		printf("B+\n");
	else if (mark >= 60 && mark < 65)
		printf("B-\n");
	else if (mark >= 55 && mark < 60)
		printf("B\n");
	else if (mark >= 50 && mark < 55)
		printf("C+\n");
	else if (mark >= 45 && mark < 50)
		printf("C\n");
	else if (mark >= 40 && mark < 45)
		printf("D\n");
	else
		printf("Fail\n");

	return 0;
}
