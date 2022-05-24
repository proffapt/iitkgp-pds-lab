#include<stdio.h>

int main()
{
	int sum, exp, temp_pow, pow, number, digit, temp_number, number_of_digits;
	printf("Enter a positive integer(<99999): "); scanf("%d", &number);

	// finding total number of digits in the given number
	for(temp_number=number, number_of_digits=0; temp_number!=0; temp_number/=10) number_of_digits++;

	// calculating power of 10 corresponding to number_of_digits of the number
	for(temp_pow=1, exp=number_of_digits-1;exp!=0;exp--) temp_pow=temp_pow*10;
	
	// creating the encoded integer
	printf("Encoded integer is: ");
	for(pow=temp_pow, temp_number=number; pow!=0; pow/=10){
		// extracting digit from the beginning of the number
		digit=(temp_number/pow);
		// removing the extracted digit from the number
		temp_number-=(digit*pow);
		// incrementing the digit by 1
		digit+=1;
		printf("%d", digit);
	}

	// creating the encoded integer with checksum
	printf("\nEncoded integer with checksum is: ");
	for(sum=0, temp_number=number, pow=temp_pow; pow!=0; pow/=10){
		// extracting digit from the beginning of the number
		digit=(temp_number/pow);
		// removing the extracted digit from the number
		temp_number-=(digit*pow);
		// incrementing the digit by 1
		digit+=1;
		printf("%d", digit);
		// since we don't have to add 10 we have to do 1+0 thus changing value of digit to 1 when it is 10 for calculating the checksum 
		if(digit==10) digit=1;
		// adding all digits of the encoded number
		sum+=digit;
	}
	// appending 0 before checksum if it is one digit number
	if(sum/10==0) printf("0");
	printf("%d\n", sum);

	return 0;
}
