/************************************

* Name : Arpit Bhardwaj

* Roll No : 21IM10009

* Section : 1

* Assignment No : 3

* Date : 20-Apr-2022

* ************************************/

#include <stdio.h>

int main() 
  { int m, n;
    printf("Enter the value of m and n: ");
    scanf("%d %d", &m, &n);
    /* Making sure n > m */
    if( m > n )
	  { m = m + n;
		n = m - n;
		m = m - n; }

	/* Printing divisors of m and n */
	int m_is_prime=1;
    printf("Divisors of %d are: ", m);
    for(int i = 2 ; i < m ; i++)
	  { if( m%i == 0 )
		  { printf("%d ",i);
			m_is_prime=0; } }
	if (m_is_prime) printf("nil (REASON: IS prime)");
	printf("\n");
	int n_is_prime=1;
    printf("Divisors of %d are: ", n);
    for( int i = 2 ; i < n ; i++)
	  { if( n%i == 0 )
		    { printf("%d ", i);
			n_is_prime=0; } }
	if (n_is_prime) printf("nil (REASON: IS prime)");
	printf("\n");

	/* Printing divisors of m and n */
	printf("Common divisors of %d and %d are: ", m, n);
	int hcf;
	if(!n_is_prime && !m_is_prime)
	  { for(int i = 2; i < m; i++)
		  { if(m%i == 0 && n%i == 0)
			    { printf("%d ",i);
				hcf=i; } }
		printf("\n");
		printf("The largest common divisor of %d and %d is: %d\n" , m, n, hcf); }
	else printf("nil (REASON: one or both is/are prime)\n");

	/*Priting LCM and stuff*/
	int lcm = n;
	while (1) 
	  { if (lcm % n == 0 && lcm % m == 0) 
		  { printf("The smallest common multiple of %d and %d is %d\n", m, n, lcm);
			break; }
		++lcm; }
	printf("The multiples of %d till the LCM %d are : " , m, lcm);
    for(int i = 1; i*m <= lcm; i++)
        printf("%d ",(m*i));
	printf("\n");
	printf("The multiples of %d till the LCM %d are : " , n, lcm);
    for(int i = 1; i*n <= lcm; i++)
        printf("%d ",(n*i));
	printf("\n");
    return 0; }
