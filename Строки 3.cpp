#include <stdio.h>
#include <string>

void main()
{
	char string_1[100],temp;
	int n = 0, k = 0;

	printf("Input string: ");
	gets_s(string_1);
	n = strlen(string_1);
	for (int j = 0; j <= 8; j++)
	for (int i = 0; i <= n; i++)
	if (((int)string_1[i] == 65 + j) ||
		((int)string_1[i] - 32) == 65 + j)
	{
		temp = toupper(string_1[i]);
		printf("%c",temp);
	}

	getchar();
}