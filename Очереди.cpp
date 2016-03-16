#include <stdio.h>
#include <iostream>
using namespace std;

struct info
{
	char color = 'b';
	info *next;
};

struct queue
{
	info *begin_queue = NULL, *last_element = NULL;
};

queue *q;
info *first_p, *second_p;
char ball_color;

void input_elem(char ball_color)
{
	info *temp;
	temp = new info;
	temp->color = ball_color;
	temp->next = NULL;
	if (q->last_element != NULL)
		q->last_element->next = temp;
	else
		q->begin_queue = temp;
	q->last_element = temp;
};

void watch_queue()
{
	info *temp = NULL;
	//temp = new queue;
	temp = q->begin_queue;
	while (temp != NULL)
	{
		printf("%c ",temp->color);
		temp = temp->next;
	}
}

void create_queue()
{
	q = new queue;
	q->begin_queue = NULL;
	q->last_element = NULL;
}

void input_queue(int i)
{
	if ((i % 2) == 0)
	{
		ball_color = 'w';
		input_elem(ball_color);
	}
	else
	{
		ball_color = 'b';
		input_elem(ball_color);
	}
}

void sort_queue(int n)
{
	char tempcolor = 'b';
	int j;
	first_p = q->begin_queue;
	second_p = q->begin_queue->next;
	j = (n / 2) + 1;
	for (int i = 0; i < j; i++)
	{
		while (second_p != NULL)
		{
			if (first_p->color == 'w')
			{
				first_p = first_p->next;
				second_p = first_p->next;
				break;
			}
			if ((second_p->color == 'w') && (first_p->color == 'b'))
			{
				first_p->color = 'w';
				second_p->color = 'b';
				first_p = first_p->next;
				second_p = first_p->next;
				break;
			}
			second_p = second_p->next;
		}
	}
}

void main()
{
	create_queue();
	int n = 0;
	
	printf("Enter element value: ");
	scanf_s("%d",&n);
	fflush(stdin);

	if ((n % 2) == 0)
	{
		printf("Your \"n\" is an even, now n = n + 1\n");
		n++;
	}

	for (int i = 0; i < n; i++)
	{
		input_queue(i);
	}

	printf("Previously: ");
	watch_queue();

	sort_queue(n);
	printf("\n");

	printf("After: ");
	watch_queue();

	printf("\n");
	system("pause");
}