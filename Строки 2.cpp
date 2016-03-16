#include <stdio.h>
#include <string.h>

void main()
{
	char string_1[100];
	char string_2[100];
	int n = 0, k = 0;

	printf("Input first string: ");
	gets_s(string_1);
	printf("Input second string: ");
	gets_s(string_2);
	n = strlen(string_1);
	k = strlen(string_2);

	char *temp = nullptr;

	if (n > k)
	{
		for (int i = 0; i <= n; i++)
		for (int j = 0; j <= k; j++)
		{
			temp = strchr(string_1,string_2[j]);
			if (temp != nullptr)
				*temp = '\t';
		}

		temp = nullptr;
//		if (string_1[i] = string_2[j])
	//		string_1[i] = '\0';
		
	//	for (int i = 0; i <= n; i++)
	//	if (string_1[i] != '<')
		//	printf("%c", string_1[i]);
		printf("Result : ");
		for (int i = 0; i <= n; i++)
		if (string_1[i] != '\t')
			printf("%c", string_1[i]);
	    
	}
	getchar();
}