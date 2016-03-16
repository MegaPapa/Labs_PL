#include <stdio.h>

void main()
{
	int Matrix[5][6];
	int TestM;

	for (int j = 0; j <= 4; j++)//vvod
	{
		for (int i = 0; i <= 4; i++)
		{
			printf("Matrix [%d,%d]", i, j);
			scanf_s("%d", &Matrix[i][j]);
		}
	}

	printf("Your Matrix:\n");//nachalni vivod matrici
	for (int j = 0; j <= 4; j++)
	{
		for (int i = 0; i <= 4; i++)
			printf("%4d", Matrix[i][j]);
		printf("\n");
	}

	for (int j = 0; j <= 4; j++)  //summa
	for (int i = 0; i <= 4; i++)
		Matrix[j][5] = Matrix[j][5] + Matrix[j][i];

	for (int k = 0; k <= 3; k++)//sortirovka
	for (int i = 0; i <= 3 - k; i++)
	if (Matrix[i][5] < Matrix[i+1][5])
	for (int j = 0; j <= 4; j++)
	{
		TestM = Matrix[i][j];
		Matrix[i][j] = Matrix[i + 1][j];
		Matrix[i + 1][j] = TestM;
		TestM = Matrix[i][5];
		Matrix[i][5] = Matrix[i + 1][5];
		Matrix[i + 1][5] = TestM;
	}

	printf("New version:\n");// novaya VERSIYAahahahah
	for (int j = 0; j <= 4; j++)
	{
		for (int i = 0; i <= 4; i++)
			printf("%4d", Matrix[i][j]);
		printf("\n");
	}

	scanf_s("%d",&Matrix[1][1]);
}