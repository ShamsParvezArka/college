#include <stdio.h>

int main()
{
	int month_number;
	scanf("input month number: %d", &month_number);

	if (month_number > 12 || month_number < 1) {
		printf("Error: invalid month number");
		return 0;
	}

	if (month_number == 1)
		printf("January\n");
	if (month_number == 2)
		printf("February\n");
	if (month_number == 3)
		printf("March\n");
	if (month_number == 4)
		printf("April\n");
	if (month_number == 5)
		printf("May\n");
	if (month_number == 6)
		printf("June\n");
	if (month_number == 7)
		printf("July\n");
	if (month_number == 8)
		printf("August\n");
	if (month_number == 9)
		printf("September\n");
	if (month_number == 10)
		printf("October\n");
	if (month_number == 11)
		printf("November\n");
	if (month_number == 12)
		printf("December\n");
	return 0;
}
