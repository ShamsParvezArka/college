#include <stdio.h>
#include <math.h>

int main() 
{
	double a, b, c;
	printf("coefficient of x^2: ");
	scanf("%lf", &a);
	printf("coefficient of x: ");
	scanf("%lf", &b);
	printf("constant c: ");
	scanf("%lf", &c);
	printf("YOUR EQUATION: %.1lfx^2 + %.1lfx + %.1lf = 0\n", a, b, c);

	double x_1, x_2;
	double dis = b*b - 4*a*c;
	if (dis == 0) {
		x_1 = - b/(2*a);
		x_2 = x_1;
		printf("\t\t\bx_1 = %lf\n,\t\t\bx_2 = %lf\n", x_1, x_2);
	}
	if (dis > 0) {
		x_1 = (-b + sqrt(dis)) / 2*a;
		x_2 = (-b - sqrt(dis)) / 2*a;
		printf("\t\t\bx_1 = %lf\n\t\t\bx_2 = %lf\n", x_1, x_2);
	}
	else {
		printf("error: can't calculate imaginary value; [D < 0]\n");
		return -1;
	}
	return 0;
}

