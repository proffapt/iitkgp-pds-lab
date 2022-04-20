/************************************

* Name : Arpit Bhardwaj

* Roll No : 21IM10009

* Section : 1

* Assignment No : 2

* Date : 20-Apr-2022

* ************************************/

#include<stdio.h>

int main(){

	/* Taking input for the prime number */
	int n;
	printf("Enter a prime number: ");
	scanf("%d", &n);

	/* Checking whether the number is really prime or not */
	int isPrime = 1;
	if (n == 0 || n == 1){
    isPrime = 0;
	}

	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
		isPrime = 0;
		break;
		}
	}

	if (isPrime == 0){
    	printf("%d is not a prime number.\n", n);
		return 0;
	}

	/* Finding the generator for n */
	int r , checker ;
	int k = 1 ;

	unsigned long long int power = 1, p;

		for (r = 2; r < n; r ++){
			printf("Checking for r = %d\n", r);
			for ( ; ; ){
				int init_k = k;
				for (int i = 1; i <= n-1; i++) {
					power = power * r;
					p = (power)%n;
					printf("%llu - power\n", p);
					if (p == k){
						printf("%llu found\n", p);
						k++;
					}
				}
				if( k == init_k){
					checker = 0;
					k = 1;
					break;
				}
				power = 1;

				if(k > n -1 ){
					checker = 1;
					break;
				}
			}
			if (checker == 1){
				break;
			}
		}
	
	if (checker == 1){
		printf("The generator for %d is: %d\n", n, r);
	}

	return 0;
}