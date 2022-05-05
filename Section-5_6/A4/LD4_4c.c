#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));
	int roll[20], age[20], marks[20];

	// Generating age and marks -- can be same
	for (int i = 0; i < 20; i++)
	{
		roll[i] = rand() % (2000 + 1 - 1000) + 1000;
		age[i] = rand() % (25 + 1 - 15) + 15;
		marks[i] = rand() % (100 + 1 - 0) + 0;
	}
	
	// Generating unique roll numbers -- can not be same
	for (int i = 0; i < 20;)
	{
		int random = rand() % (2000 + 1 - 1000) + 1000;
		int hai = 0;
		for (int j = 0; j < i; j++)
		{
			if (roll[j] == random)
			{
				hai = 1;
			}
		}
		if (!hai)
		{
			roll[i] = random;
			i++;
		}
	}

	// Displaying whole data:
	for (int i = 0; i < 20; i++)
	{
		printf("Roll: %d Age: %d Mark: %d\n", roll[i], age[i], marks[i]);
	}
	printf("---------------------\n\n");

	// Sorting data
	int min, k;
	for (int i = 0; i <= 20 - 2; i++)
	{
		min = roll[i];
		for (int j = i + 1; j <= 20 - 1; j++)
		{
			if (roll[j] < min)
			{
				min = roll[j];
				k = j;
			}
		}
		if (min != roll[i])
		{
			roll[i] = roll[i] + roll[k];
			roll[k] = roll[i] - roll[k];
			roll[i] = roll[i] - roll[k];

			age[i] = age[i] + age[k];
			age[k] = age[i] - age[k];
			age[i] = age[i] - age[k];

			marks[i] = marks[i] + marks[k];
			marks[k] = marks[i] - marks[k];
			marks[i] = marks[i] - marks[k];
		}
	}

	// Displaying data sorted according to their marks:
	printf("Displaying sorted data according to roll number:\n\n");

	for (int i = 0; i < 20; i++)
	{
		printf("Roll: %d Age: %d Mark: %d\n", roll[i], age[i], marks[i]);
	}

	return 0;
}
