/************************************
* Name : Arpit Bhardwaj
* Roll No : 21IM10009
* Section : 1
* Group: 5
* Assignment No : 4
* Description : polynomials...
* Date : 27-04-2022
* ************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

	// Part 1:
	// taking input for degree of polynomial
	int n; printf("Please enter Degree of the polynomial f(x): "); scanf("%d", &n);
	if (n > 4){
		printf("Value of degree should be less than or equal to 4..\n");
		printf("EXITTING THE CODE!\n");
		return 0;
	}
	// generating the polynomial randomly
	srand(time(0));
	int f_coeff[n+1];
	for(int i=0; i<=n; i++) f_coeff[i]=(rand()%10)+0;
	if (f_coeff[n]==0) f_coeff[n]=(rand()%9)+1;
	// printing the polynomial
	printf("The Degree %d polynomial is: f (x) = %d", n, f_coeff[0]);
	for (int i = 1; i <= n; i++)
		printf(" + %dx^%d", f_coeff[i], i);
	// taking input for the evaluation point
	int e; printf("\nPlease enter an evaluation point : "); scanf("%d", &e);
	// evaluating the polynomail at e and printing it
	int x=e, f_value=f_coeff[0];
	printf("f(%d) = ", e);
	for (int i=1; i<=n; i++, x*=x) f_value += f_coeff[i]*x;
	printf("%d\n", f_value);

	// Part 2:
	// generating another polynomial randomly
	int g_coeff[n+1];
	for(int i=0;i <=n; i++) g_coeff[i] = (rand()%10)+0;
	if (g_coeff[n]==0) g_coeff[n] = (rand()%9)+1;
	// printing the polynomial in coefficient form
	printf("Another Degree %d polynomial is: g(x) = %d", n, g_coeff[0]);
	for (int i = 1; i <= n; i++) printf(" + %dx^%d", g_coeff[i], i);
	// defining h for storing the product
	int h_coeff[(2*n)+1], i, j;
	for (int k=0; k<=2*n; k++) h_coeff[k]=0;
	// multiplying f and g to get h
	for(i=0 ; i<=n; i++, j=0)
        for(j=0 ; j<=n; j++)
           		h_coeff[i+j]+=f_coeff[i]*g_coeff[j];
	// printing the product
	printf("\nThe product of f(x) and g(x) is: h(x) = %d", h_coeff[0]);
	for (i = 1; i <= 2*n; i++) printf(" + %dx^%d", h_coeff[i], i);
	printf("\n");

	// PART 3:
	// generating 2n+1 unique and random points for evaluation
	int points[2*n+1];
	printf("%d distinct points are: ", (2*n)+1);
	for (i = 0; i <= 2*n; ){
		int random = rand()%15, hai = 0;
		for (j = 0; j < i; j++)
			if (points[j] == random)
				hai = 1;
		if (!hai){
			points[i] = random;
			i++;
		}
	}
	for(i=0; i<= 2*n; i++) printf("%d, ", points[i]);
	printf("\b\b \n");
	// initialising the final value of funcs with respective constant terms before exact evaluation
	int f[2*n+1], g[2*n+1], h[2*n+1], m[2*n+1];
	for (i = 0; i <= 2*n; i++){
		f[i]=f_coeff[0];
		g[i]=g_coeff[0];
		h[i]=h_coeff[0];
		m[i]=0;
	}
	// printing point value representation of f
	printf("\nPoint value representation of f:\n");
	printf("f(x) := {");
	for (i=0; i<=2*n; i++){ // loop for iterating over various points of evaluation
		printf("(%d,", points[i]);
		x=points[i];
		for(j=1; j<=n; j++){ // loop which actually calculates the value for given point
			f[i]+=f_coeff[j]*x;
			x*=points[i];
		}
		printf("%d),", f[i]);
	}
	printf("\b}\n");
	// printing point value representation of g
	printf("Point value representation of g:\n");
	printf("g(x) := {");
	for (i=0; i<=2*n; i++){
		printf("(%d,", points[i]);
		x = points[i];
		for(j=1; j<=n; j++){
			g[i]+=g_coeff[j]*x;
			x*=points[i];
		}
		printf("%d),", g[i]);
	}
	printf("\b}\n");
	// calculating point value representation of h=f*g using h(x)
	for (i=0; i<=2*n; i++){
		x=points[i];
		for(j=1; j<=2*n; j++){
			h[i]+=h_coeff[j]*x;
			x*=points[i];
		}
	}
	// printing point value representation of m
	printf("Point value representation of fg:\n");
	printf("m(x) := {");
	for (i=0; i<=2*n; i++){
		printf("(%d,", points[i]);
		m[i]=f[i]*g[i];
		printf("%d),", m[i]);
	}
	printf("\b}\n");
	// checking whether m and h are equivalent
	int barabar_hai=1;
	for(int i=0; i<=2*n; i++)
		if (h[i]!=m[i]){
			barabar_hai=0;
			break;
		}
	// printing based on previous check
	if (barabar_hai) printf("\nCheck successful. h(x) and m(x) are equivalent\n");
	else printf("\nCheck FAILED! h(x) and m(x) are NOT equivalent\n");

	// Part 4:
	// getting 2n+1 array values
	float m1[2*n+1];
	for (i=0; i<2*n+1; i++)
		m1[i]=0;
	printf("\nThe result of interpolation is:\n");

	m1[0] = ((float)m[0]*points[1]*points[2]/((points[0]-points[1])*(points[0]-points[2])))+((float)m[1]*points[0]*points[2]/((points[1]-points[0])*(points[1]-points[2])))+((float)m[2]*points[0]*points[1]/((points[2]-points[1])*(points[2]-points[0])));

	m1[1] -= ((float)m[0]*(points[1]+points[2])/((points[0]-points[1])*(points[0]-points[2])));
	m1[1] -= ((float)m[1]*(points[2]+points[0])/((points[1]-points[2])*(points[1]-points[0])));
	m1[1] -= ((float)m[2]*(points[1]+points[0])/((points[2]-points[1])*(points[2]-points[0])));

	m1[2] = ((float)m[0]/((points[0]-points[1])*(points[0]-points[2])))+((float)m[1]/((points[1]-points[0])*(points[1]-points[2])))+((float)m[2]/((points[2]-points[1])*(points[2]-points[0])));


	printf("m(x) = %f", m1[0]);
	for(int i = 1; i <= 2;i++){
		printf(" + %fx^%d", m1[i], i);
	}

	// comparing m_coeff with h_coeff
	// EDIT
	if (barabar_hai) printf("\nYay! Success.\n");
	else printf("\nShit! Failed.\n");
	return 0;
}
