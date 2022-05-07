/************************************

* Name : Arpit Bhardwaj

* Roll No : 21IM10009

* Section : 1

* Group: 5

* Test No : 1

* Date : 04-05-2022

* ************************************/

#include<stdio.h>

int main()
{
	/*PART 1*/

	// taking input for the number 
	int number; 
	printf("Enter a number : ");
	scanf("%d", &number);
	printf("You entered \"%d\"\n", number);

	// determining the number of digits in the input
	int number_of_digits=0;
	int temp_number = number;
	while(temp_number != 0)	
	{
		temp_number /= 10;
		number_of_digits++;
	}

	printf("The number of digit(s) in %d is/are: %d\n", number, number_of_digits);

	/*PART 2*/

	// 1-digit...nod-digit numbers
	int ten = 10;
	int power;
	int index = 0;
	int total = ((number_of_digits + 1) * number_of_digits)/2;
	int nums[total];
	for(int i = 1; i <= number_of_digits; i++)
	{
		// Calculating 10^i
		power = i;
		ten = 10 ;
		while (power != 1)
		{
			ten *= 10;
			--power;
		}

		// Storing those mother fucking digits
		temp_number = number;
		while (temp_number >= ten/10)
		{
			nums[index] = temp_number%ten;
			index++;
			temp_number = temp_number/10;
		}
	}

	// Sorting numbers for the output in given order
	int counter = 0, k = 0;
	int nums_sorted[total];
	for(int i = 0; i < number_of_digits; i++)
 	{
		for (int j=number_of_digits-i-1; j >= 0 ; j--, k++)
				nums_sorted[k] = nums[j+counter];
		counter = k;
	}

	// Fixing repeated numbers
	int i_flagged[total];
	for(int i = 0; i < total; i++)
		for(int j=i+1; j < total; j++)
			if(nums_sorted[i] == nums_sorted[j])
				i_flagged[i] = 69;

	// Printing the numbers
	printf("Required Constructed integers are: ");

	for (int i = 0; i < total; i++)
		if (i_flagged[i] != 69) printf("%d,", nums_sorted[i]);

	printf("\b \n");

	/*PART 3*/
	
	// Printing co-prime numbers
	printf("Printing all possible pairs of co-prime numbers: ");
	for(int i = 0; i < total; i++)
	{
		for (int m=i+1; m < total; m++)
		{
			int a = nums_sorted[i];
			int b = nums_sorted[m];
			// making sure a is bigger always
			if( a < b )
			{
				a = a + b;
				b = a - b;
				a = a - b;
			}
			if (a%b != 0 && a != 0 && b != 0 && i_flagged[i] != 69 && i_flagged[m] != 69) printf("(%d, %d),", a, b);
		}
	}
	printf("\b. \n");

	/*PART 4*/

	// Finding all prime numbers
	int is_prime[total];
	printf("Printing all prime numbers: ");
	for(int i = 0; i < total; i++)
		for(int w = 2; w <= nums_sorted[i]/2; w++)
		{
			if (nums_sorted[i]%w == 0 || nums_sorted[i] <= 1) 
			{
				is_prime[i] = 69; 
				break;
			}
		}

	// Printing all prime numbers
	for(int i = 0; i < total; i++)
		if(is_prime[i] != 69 && i_flagged[i] != 69) printf("%d, ", nums_sorted[i]);
	printf("\b\b. \n");

	return 0;
}
