#include <stdio.h>
#include <string>
#define N 3

void main()
{
	struct item{
		char name[100];
		int month;
	};

	struct month{
		char monthname[100];
	};

	struct item items[N];
	struct month array_month[N];

	for (int i = 0; i < N; i++)
	{
		printf("Input item name \n");
		gets_s(items[i].name);
		
	}

	for (int i = 0; i < N; i++)
	{
		printf("Input month \n");
		scanf_s("%d", &items[i].month);
	}

	char temp[100];
	int temp_int = 0,r = 0;

	for (int i = 0; i < N; i++)
	{
		if (items[i].month == 2)
		{
			strcpy_s(array_month[r].monthname, items[i].name);
			r++;
		}
	}

	for (int k = 1; k < r; k++)
	for (int j = 0; j < r - k; j++)
	{
		if (strcmp(items[j].name, items[j + 1].name) > 0)
		{
			strcpy_s(temp, array_month[j].monthname);
			strcpy_s(array_month[j].monthname, array_month[j+1].monthname);
			strcpy_s(array_month[j+1].monthname, temp);
			/*temp_int = array_month[j].month;
			array_month[j].month = array_month[j + 1].month;
			array_month[j + 1].month = temp_int;*/
		}
	}

	for (int i = 0; i < r; i++)
		printf("%s\n",array_month[i].monthname);
	scanf_s("%d", &r);
}