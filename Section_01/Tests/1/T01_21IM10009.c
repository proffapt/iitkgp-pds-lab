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

	// Taking input for the number 
	int n; 
	printf("Enter a number : "); scanf("%d", &n);
	printf("You entered \"%d\"\n", n);

	// Determining the number of digits in the input and printing it
	int temp_number, digits=0;
	for(temp_number = n; temp_number != 0; digits++) temp_number /= 10;
	printf("The number of digit(s) in %d is/are: %d\n", n, digits);

	/*PART 2*/

	// 1-digit...nod-digit numbers
	int counter = 0, k = 0, ten = 10, power, index = 0, total = ((digits + 1) * digits)/2, nums[total], nums_sorted[total];
	
	for(int i = 0; i < digits; i++){
		// Calculating 10^(i+1)
		for (ten = 10, power = i+1;power != 1; --power) ten *= 10;

		// Storing those mother fucking digits
		for (temp_number = n; temp_number >= ten/10; index++){
			nums[index] = temp_number%ten;
			temp_number = temp_number/10;
		}

		for (int j=digits-i-1; j >= 0 ; j--, k++)
				nums_sorted[k] = nums[j+counter];
		counter = k;
	}

	// Fixing repeated numbers and Printing the numbers
 	int i, i_flagged[total];
	printf("Required Constructed integers are: ");

	for(i = 0, i_flagged[0] = 0; i < total; i++, i_flagged[i] = 0){
		for(int j=i+1; j < total; j++)
			if(nums_sorted[i] == nums_sorted[j])
				i_flagged[i] = 1;

		if (!i_flagged[i]) printf("%d,", nums_sorted[i]);
	}
	printf("\b \n");

	/*PART 3*/
	printf("Printing all co-prime pairs: ");	

	for(int a = 0, is_coprime = 1; a < index; a++, is_coprime = 1){
		if(!i_flagged[a] && nums_sorted[a] != 0){
			for(int b = a+1; b < index; b++){
				if (!i_flagged[b] && nums_sorted[b] != 0){
					int A = nums_sorted[a];
					int B = nums_sorted[b];

					// making sure A < B
					if (A > B){
						A = A + B;
						B = A - B;
						A = A - B;
					}

					for(i = 2; i < B; i++){
						if (A%i == 0 && B%i == 0){
							is_coprime = 0;
						}
					}
					if(is_coprime) printf("(%d, %d),", A, B);
				}
			}
		}
	}
	printf("\b \n");

	/*PART 4*/

	// Finding and printing all prime numbers
	printf("Printing all prime numbers: ");

	for(int i = 0, is_prime = 1; i < total; i++, is_prime = 1){
		if(!i_flagged[i]){
			if(nums_sorted[i] <= 1) {
				is_prime = 0; 
				continue;
			}
			for(int w = 2; w <= nums_sorted[i]/2; w++){
				if (nums_sorted[i]%w == 0){
					is_prime = 0; 
					break;
				}
			}
			if(is_prime) printf("%d, ", nums_sorted[i]);
		}
	}
	printf("\b\b. \n");
}
