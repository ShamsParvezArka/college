#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
	int n;
	printf("input an integer: ");
	scanf("%d", &n);

	if (n % 2 != 0)
		printf("odd\n");
	else
		printf("even\n");
	return 0;
}
