/************************************

* Name : Arpit Bhardwaj

* Roll No : 21IM10009

* Section : 1

* Assignment No : 3

* Date : 20-Apr-2022

* ************************************/

#include <stdio.h>

int main()
{
    int m, n;
    
    printf("Enter the value of m and n: ");
    scanf("%d %d", &m, &n);
    
    /* Making sure n > m */
    if( m > n ){
		m = m + n;
		n = m - n;
		m = m - n;
    }

	/* Printing divisors of m and n */
    printf("Divisors of %d are: ", m);
    for(int i = 2 ; i < m ; i++){
        if( m%i == 0 ){
            printf("%d ",i);
        }
    }
	printf("\n");

    printf("Divisors of %d are: ", n);
    for( int i = 2 ; i < n ; i++){
        if( n%i == 0 ){
            printf("%d ", i);
        }
    }
	printf("\n");

	/* Printing divisors of m and n */
	printf("Common divisors of %d and %d are: ", m, n);
	int hcf;
    for(int i = 2; i < m; i++){
        if(m%i == 0 && n%i == 0){
            printf("%d ",i);
            hcf=i;
        }
    }
	printf("\n");

	printf("The largest common divisor of %d and %d is: %d\n" , m, n, hcf);

	int lcm = n;
	while (1) {
		if (lcm % n == 0 && lcm % m == 0) {
			printf("The smallest common multiple of %d and %d is %d\n", m, n, lcm);
			break;
		}
		++lcm;
	}

	printf("The multiples of %d till the LCM %d are : " , m, lcm);

    for(int i = 1; i*m <= ((m*n)/hcf); i++){
        printf("%d ",(m*i));
    }
	printf("\n");

	printf("The multiples of %d till the LCM %d are : " , n, lcm);

    for(int i = 1; i*n <= ((m*n)/hcf); i++){
        printf("%d ",(n*i));
    }
	printf("\n");
    
    return 0;
}