#include <stdio.h>

int main()
{
	int a, b;
	char operator;
	printf("input two integers: ");
	scanf("%d %d", &a, &b);
	printf("input operator(+, -, *, /): ");
	scanf("%c", &operator);

	if (operator == '/') {
		if (b == 0) {
			printf("error: cannot divided by zeor");
			return 0;
		} else {
			printf("%d\n", a / b);
		}
	}
	else if (operator == '+')
		printf("%d\n", a + b);
	else if (operator == '-')
		printf("%d\n", a - b);
	else if (operator == '*')
		printf("%d\n", a * b);

	return 0;
}
