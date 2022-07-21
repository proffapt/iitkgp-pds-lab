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

	// Part 4+5(bonus):
	// getting 2n+1 array values and initialising them as 0
	float m_coeff[2*n+1]; for (i=0; i<2*n+1; i++) m_coeff[i]=0;
	// calculating coeff of m using langranges interpolation
	float factor, num=0, den=1; int k, l, q, pnc=1, permutations=1, used[2*n+1], this/*, qdibba[2*n], p=0, o=0, combinations[600], found=0, counter=0*/;
	for(i=0; i<=2*n; i++){ // completion of one iteration gives one coeff
		for(j=0; j<=2*n; j++){ // completion of one iteration gives factor
			// getting total permutations of terms in numerator
			for(l=2*n; l>1; l--) permutations*=l;
			for(l=2*n-i; l>1; l--) permutations/=l;
			for(l=i; l>1; l--) permutations/=l;
			// getting numerator for current factor
			if(i==0 || i>2*n-2){
				for(l=0; l<=2*n; l++) used[l]=0;
				/* printf("R"); */
				this=0;
			}
			else {
				/* for(l=0; l<o; l++) combinations[l]=-1; */
				/* o=0; */
				this=1;
			}
			/* printf("("); */
			for(k=0; k<permutations ; k++){ // how many combinations
				if (this){
					for(l=0; l<=2*n; l++) used[l]=0;
					/* for(l=0; l<p; l++) qdibba[l]=-1; */
					/* p=0; */
					/* printf("r"); */
				}
				for(l=0; l<2*n-i; l++){ // individual numbers
					q=rand()%(2*n+1);
					if(q==j || used[q]) { --l; continue; }
					used[q]=1;
					/* qdibba[p++]=q; */
					/* combinations[o++]=q; */
					pnc*=points[q];
					/* printf("[%d]", q); */
				}
				/* if (this){ for(l=0; l<o ;l++){ */
				/* 				for(int b=0; b<p; b++){ */
				/* 					if(qdibba[b]==combinations[l]){ */
				/* 						int index=l-(l%(2*n-i)); */
				/* 						for (int a=0; a<2*n-i; a++, index++){ */
				/* 							if(qdibba[a]==combinations[index]) counter++; */
				/* 						} */
				/* 						if(counter==2*n-i){ found=1; break; } */
				/* 						counter=0; */
				/* 					} */
				/* 				} */
				/* 			} */
				/* 			if(found) { k--; found=0; continue; } */
				/* 			pnc=1; */	
				/* 		} */
				num+=pnc;
				pnc=1;
				/* printf("+"); */
			}
			num*=(float)m[j];
			/* printf("\b)*f"); */
			// getting denominator for the factor
			for(k=0; k<=2*n; k++){
				if(k==j) continue;
				den*=(points[j]-points[k]);
			}
			/* printf("/d+"); */
			factor=num/den;
			if(!(i%2)) m_coeff[i]+=factor; // for even numbered term
			else m_coeff[i]-=factor; // for odd numbered term
			// resetting num, den and all the factorials
			num=0, den=1, permutations=1;
		}
		/* printf("\b |\n"); */
	}
	// printing m
	printf("\nThe result of interpolation is:\n");
	printf("m(x) = %f", m_coeff[0]);
	for(int i = 1; i<=2*n;i++) printf(" + %fx^%d", m_coeff[i], i);
	// comparing m_coeff with h_coeff
	float error=0.9; barabar_hai=1;
	for(i=0; i<=2*n; i++)
		if(((float)h_coeff[i]-m_coeff[i])>error || (m_coeff[i]-(float)h_coeff[i])>error) {
			barabar_hai=0;
			break;
		}
	if (barabar_hai) printf("\nYay! Success.\n");
	else printf("\nShit! Failed.\n");
	return 0;
}
