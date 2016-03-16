#include <stdio.h>
#include <string>


void main()
{
	char string[100];
	int n = 0, k = 0;

	printf("Input string: ");
	gets_s(string);

	n = strlen(string);

	for (int i = n; i >= -1; i--)
	{
		
		if ((string[i] == ' ') || (i == -1))
		{
			for (int j = 0; j != k; j++)
				printf("%c", string[i + j + 1]);
			k = 0;
		}
		k++;
	}
	getchar();
}