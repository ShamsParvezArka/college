#include <stdio.h>

int main()
{
	long id;
	float worked_hours, work_rate;
	
	printf("Employee's ID: ");
	scanf("%ld", &id);
	printf("Employee's worked hours: ");
	scanf("%f", &worked_hours);
	printf("Employee's work rate: ");
	scanf("%f", &work_rate);

	printf("Employee's ID: %ld", id);
	printf("Employee's salary: %.2f", worked_hours * work_rate);
	
	return 0;
}
