/************************************

* Name : Arpit Bhardwaj

* Roll No : 21IM10009

* Section : 1

* Description : BONUS PROBLEM

* Date : 20-Apr-2022

* ************************************/

#include<stdio.h>

int main(){

	int num, den, one_count = 0, gi = 0;
	printf("Enter num and den for (num/den): ");
	scanf("%d %d", &num, &den);

	printf("The continuous fraction form of (%d/%d) is\n", num, den);
	printf("\n");
	if (num > den){
		while ( num > 1 ){
			gi = num/den;

			num = num - gi*den;

			num = num + den;
			den = num - den;
			num = num - den;

			if (num > 1 && gi != 0){
				printf("(%d", gi);
				printf(" + 1/");
				one_count++;
			}
			else{
				printf("%d)", gi);
				break;
			}
		}

		for (int i = 1; i < one_count; i++){
			printf(")");
		}

		printf("\n");
		printf("\n");
	}
	else if ( num < den ){
		printf("(0 + 1/");

		num = num + den;
		den = num - den;
		num = num - den;

		while ( num > 1 ){

			gi = num/den;

			num = num - gi*den;

			num = num + den;
			den = num - den;
			num = num - den;

			if (num > 1 && gi != 0){
				printf("(%d", gi);
				printf(" + 1/");
				one_count++;
			}
			else{
				printf("%d)", gi);
				break;
			}
		}

		for (int i = 0; i < one_count; i++){
			printf(")");
		}

		printf("\n");
		printf("\n");		
	}

	return 0;
}
