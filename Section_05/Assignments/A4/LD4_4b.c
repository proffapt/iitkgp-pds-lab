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

	// Displaying data having same marks:
	printf("Displaying data with same marks:\n");
	int k = 0;
	int i_count[20];
	int count = 0;
	for (int i = 0; i < 20; i++)
	{
		i_count[i] = 0;
	}
	int same_marks_index1[20], same_marks_index2[20];
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (marks[j] == marks[i] && j != i)
			{
				// if the same pair has not occured in the reverse order do this
				if (i_count[j] == 0 && i_count[i] == 0)
				{
					// storing same marks index numbers in arrays
					same_marks_index1[k] = i;
					same_marks_index2[k] = j;
					k++;
					count++; // for checking whether there are any same entries or not
				}
				
				// logic to not to count same pair twice in the reverse order
				i_count[i] = 1; 
				i_count[j] = 1;
			}
		}
	}

	if (count != 0)
	{
		// if there was same data then print them
		for (int i = 0; i < k; i++)
		{
			printf("\nRoll: %d Age: %d Mark: %d", roll[same_marks_index1[i]], age[same_marks_index1[i]], marks[same_marks_index1[i]]);
			printf("\nRoll: %d Age: %d Mark: %d", roll[same_marks_index2[i]], age[same_marks_index2[i]], marks[same_marks_index2[i]]);
			printf("\n*********************");
		}
		// just to remove the ***** for the last entry
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	}
	else
	{
		// just in case there was no same data
		printf("\nUnfortunately there's no data with same marks.\n");
	}

	return 0;
}
