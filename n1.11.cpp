#include <stdio.h>
#include <math.h>

void main()
{
	int a = 2;
	int n = 3;
	int i;
	int answ = 1;

	printf("%d\n",_Pow_int(a,n));
	a = 2;

	for (i = 1; i <= n; i++)
		answ = answ * (a + i - 1);
	
	printf("%d", answ);
	getchar();

}