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

	int n;
    printf("Please enter Degree of the polynomial f(x): ");
	scanf("%d", &n);

	if (n > 4){
		printf("Value of degree should be less than or equal to 4..\n");
		printf("EXITTING THE CODE!\n");
		return 0;
	}

	srand(time(0));

	int f_coeff[n+1];
	for(int i = 0; i <= n; i++){
		f_coeff[i] = (rand()%10)+0;
	}
	if (f_coeff[n] == 0){
		f_coeff[n] = (rand()%9)+1;
	}

	printf("The Degree %d polynomial is: f (x) = %d", n, f_coeff[0]);
	for (int i = 1; i <= n; i++){
		printf(" + %dx^%d", f_coeff[i], i);
	}

	int e;
	printf("\nPlease enter an evaluation point : ");
	scanf("%d", &e);

	int x = e;
	int f_value = f_coeff[0];
	printf("f(%d) = ", e);
	for (int i = 1; i <= n; i++){
		f_value += f_coeff[i]*x;
		x *= e;
	}
	printf("%d\n", f_value);

	// Part 2:

	int g_coeff[n+1];
	for(int i = 0; i <= n; i++){
		g_coeff[i] = (rand()%10)+0;
	}
	if (g_coeff[n] == 0){
		g_coeff[n] = (rand()%9)+1;
	}

	printf("Another Degree %d polynomial is: g(x) = %d", n, g_coeff[0]);
	for (int i = 1; i <= n; i++){
		printf(" + %dx^%d", g_coeff[i], i);
	}

	int h_coeff[(2*n)+1];
	int i = 0, j = 0;
	for (int k = 0; k <= 2*n; k++){
		h_coeff[k] = 0;
	}
	for( ; i<=n; i++){
		j = 0;
        for( ; j <= n; j++){
           		h_coeff[i+j] += f_coeff[i]*g_coeff[j];
        }
    }

	printf("\nThe product of f(x) and g(x) is: h(x) = %d", h_coeff[0]);
	for (int i = 1; i <= 2*n; i++){
		printf(" + %dx^%d", h_coeff[i], i);
	}
	printf("\n");

	// PART 3:

	int points[2*n+1];
	printf("%d distinct points are: ", (2*n)+1);
	for (int i = 0; i <= 2*n; ){
		int random = rand()%15;
		int hai = 0;
		for (int j = 0; j < i; j++){
			if (points[j] == random){
				hai = 1;
			}
		}
		if (!hai){
			points[i] = random;
			i++;
		}
	}
	for(int i=0; i<= 2*n; i++){
		printf("%d ", points[i]);
	}

	int f[2*n+1];
	int g[2*n+1];
	int h[2*n+1];
	int m[2*n+1];
	for (int i = 0; i <= 2*n; i++){
		f[i] = f_coeff[0];
	}
	for (int i = 0; i <= 2*n; i++){
		g[i] = g_coeff[0];
	}
	for (int i = 0; i <= 2*n; i++){
		h[i] = h_coeff[0];
	}
	for (int i = 0; i <= 2*n; i++){
		m[i] = 0;
	}

	printf("\nPoint value representation of f:\n");
	printf("f(x) := {");
	for (int i = 0; i <= 2*n; i++){
		printf("(%d,", points[i]);
		x = points[i];
		for(int j = 1; j <= n; j++){
			f[i] += f_coeff[j]*x;
			x *= points[i];
		}
		printf("%d),", f[i]);
	}
	printf("\b}\n");

	printf("Point value representation of g:\n");
	printf("g(x) := {");
	for (int i = 0; i <= 2*n; i++){
		printf("(%d,", points[i]);
		x = points[i];
		for(int j = 1; j <= n; j++){
			g[i] += g_coeff[j]*x;
			x *= points[i];
		}
		printf("%d),", g[i]);
	}
	printf("\b}\n");

	for (int i = 0; i <= 2*n; i++){
		x = points[i];
		for(int j = 1; j <= 2*n; j++){
			h[i] += h_coeff[j]*x;
			x *= points[i];
		}
	}

	printf("Point value representation of fg:\n");
	printf("m(x) := {");
	for (int i = 0; i <= 2*n; i++){
		printf("(%d,", points[i]);
		m[i] = f[i]*g[i];
		printf("%d),", m[i]);
	}
	printf("\b}\n");

	int barabar_hai = 1;
	for(int i = 0; i <= 2*n; i++){
		if (h[i] != m[i]){
			barabar_hai = 0;
		}
	}

	if (barabar_hai == 1){
		printf("\nCheck successful. h(x) and m(x) are equivalent\n");
	}
	else{
		printf("\nCheck FAILED! h(x) and m(x) are NOT equivalent\n");
	}

	// Part 4:

	if (n == 1){
		printf("The result of interpolation is:\n");

		float m1[3];
		for (int i = 0; i < 3; i++){
			m1[i] = 0;
		}

		m1[0] = (m[0]*points[1]*points[2]/((points[0]-points[1])*(points[0]-points[2])))+(m[1]*points[0]*points[2]/((points[1]-points[0])*(points[1]-points[2])))+(m[2]*points[0]*points[1]/((points[2]-points[1])*(points[2]-points[0])));

		m1[1] -= (m[0]*(points[1]+points[2])/((points[0]-points[1])*(points[0]-points[2])));
    	m1[1] -= (m[1]*(points[2]+points[0])/((points[1]-points[2])*(points[1]-points[0])));
   		m1[1] -= (m[2]*(points[1]+points[0])/((points[2]-points[1])*(points[2]-points[0])));

		m1[2] = (m[0]/((points[0]-points[1])*(points[0]-points[2])))+(m[1]/((points[1]-points[0])*(points[1]-points[2])))+(m[2]/((points[2]-points[1])*(points[2]-points[0])));


		printf("m(x) = %f", m1[0]);
    	for(int i = 1; i <= 2;i++){
        	printf(" + %fx^%d", m1[i], i);
    	}

		if (barabar_hai == 1){
			printf("\nYay! Success.\n");
		}
		else{
			printf("\nShit! Failed.\n");
		}
	}
	else{
		printf("\nThe next check is only valid for n == 1\n");
	}

	// BONUS

	

	return 0;
}