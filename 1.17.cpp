#include <stdio.h>
#include <math.h>

void main()
{
	int	 i;
	double sum = 0;

	for (i = 1; i <= 50; i++)
		sum = sum + (1.0 / (i*i*i));
	printf("%f",sum);
	getchar();
}