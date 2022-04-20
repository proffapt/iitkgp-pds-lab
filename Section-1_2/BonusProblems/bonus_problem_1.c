/************************************

* Name : Arpit Bhardwaj

* Roll No : 21IM10009

* Section : 1

* Description : BONUS PROBLEM

* Date : 13-Apr-2022

* ************************************/

#include<stdio.h>

int main(){

	int num, den, one_count_gr = 0, one_count_ls = 0;
	printf("Enter num and den for (num/den): ");
	scanf("%d %d", &num, &den);

	int gi, ig;
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
				one_count_gr++;
			}
			else{
				printf("%d)", gi);
				break;
			}
		}

		for (int i = 1; i < one_count_gr; i++){
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

			ig = num/den;

			num = num - ig*den;

			num = num + den;
			den = num - den;
			num = num - den;

			if (num > 1 && ig != 0){
				printf("(%d", ig);
				printf(" + 1/");
				one_count_ls++;
			}
			else{
				printf("%d)", ig);
				break;
			}
		}

		for (int i = 0; i < one_count_ls; i++){
			printf(")");
		}

		printf("\n");
		printf("\n");		
	}

	return 0;
}