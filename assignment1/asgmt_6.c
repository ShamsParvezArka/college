#include <stdio.h>

int main()
{
	int day_number;
	scanf("input day number of week: %d", &day_number);
	
	if (day_number > 7 || day_number < 1) {
		printf("error: invalid day number");
		return 0;
	}

	if (day_number == 1) 
		printf("Saturdar\n");
	if (day_number == 2) 
		printf("Sunday\n");
	if (day_number == 3) 
		printf("Monday\n");
	if (day_number == 4) 
		printf("Tuesday\n");
	if (day_number == 5) 
		printf("Wednesday\n");
	if (day_number == 6) 
		printf("Thursday\n");
	if (day_number == 7) 
		printf("Friday\n");
	return 0;
}
