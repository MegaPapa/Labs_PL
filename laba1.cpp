#include <stdio.h>

void main()
{
	int i = 0;
	int j = 0;
	int myarray[6][6];
	int rrr = 0;
	int min = 99999;
	int max = -99999;
	int maxs = -1;
	int mins = -1;

	for (j = 0; j != 6; ++j)
	for (i = 0; i != 6; ++i)
	{
		myarray[i][j] = rrr;
		rrr += 1;
	}

	for (j = 0; j != 6; ++j)
	for (i = 0; i != 6; ++i)
	{
		if (myarray[i][j] > max)
		{
			max = myarray[i][j];
			maxs = j;
		}
		if (myarray[i][j] < min)
		{
			min = myarray[i][j];
			mins = j;
		}
	}

	int test[5];

//	if (maxs != mins)
	for (i = 0; i != 6; ++i)
	{
		test[i] = myarray[i][maxs];
		myarray[i][maxs] = myarray[i][mins];
		myarray[i][mins] = test[i];
	}

	for (j = 0; j != 6; ++j)
	{
		for (i = 0; i != 6; ++i)
			printf("%4d",myarray[i][j]);
		printf("\n");
	}

	getchar();
}