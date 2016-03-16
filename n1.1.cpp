# include <stdio.h>

void main()
{
	int x = 10;
	int y = 15;
	int z = 0;

	if (x > y)
		z = x - y;
	else
		z = y - x + 1;
	printf("%d",z);
	getchar();
}