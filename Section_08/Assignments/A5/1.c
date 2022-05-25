#include<stdio.h>

const int n;
const float x, a;

void readData(void){
	printf("Enter the value of integer n: "); scanf("%d", &n);

	do{
		printf("Enter the floating-point value of x: ");
		scanf("%f", &x);
	} while (x<-1.0 || x>1.0);

	do{
		printf("Enter the floating-point value of a: ");
		scanf("%f", &a);
	} while (a<-0.5 || a>0.5);
}

float findSinX(float x, int n){
	float sinx=0, raised;
	int i, pattern, exp, factorial;
	
	for(i=0; i<n; i++){
		pattern=(2*i)+1;
		
		// power of x calculation on every step
		for(exp=pattern, raised=1; exp!=0; exp--) raised*=x;

		// factorial calculation on every step
		if(i==0) factorial=1;
		else if(i==1) factorial=factorial*(factorial+1)*(factorial+2);
		else factorial=factorial*(pattern+1)*(pattern+2);

		// real calculation of sinx
		if(i%2==0) sinx+=raised/factorial;
		else sinx-=raised/factorial;
	}

	return sinx;
}

float findSinA(float a){
	float sina=0, raised, prev;
	int i, k, pattern, exp, factorial, curr_int=0, prev_int=0;

	for(k=1; ;k++){
		if(k>2) prev=sina;

		sina=0;
		for(i=0; i<k; i++){
			pattern=(2*i)+1;
			
			// power of a calculation on every step
			for(exp=pattern, raised=1; exp!=0; exp--) raised*=a;

			// factorial calculation on every step
			if(i==0) factorial=1;
			else if(i==1) factorial=factorial*(factorial+1)*(factorial+2);
			else factorial=factorial*(pattern+1)*(pattern+2);

			// real calculation of sina
			if(i%2==0) sina+=raised/factorial;
			else sina-=raised/factorial;
		}

		if(k==1) prev=sina;

		if(k>1){
			prev_int=(int)(10000*prev);
			curr_int=(int)(10000*sina);
		}

		if(curr_int==prev_int && k!=1){
			break;
		}
	}

	printf("The value of k for which the result is accurate upto 4 decimal places is: %d\n", k-1);
	return prev;
}

int main()
{
	readData();

	float sine_of_x=findSinX(x, n);
	printf("The value of sin(%f) apporximated to %d terms is: %f\n", x, n, sine_of_x);

	float sine_of_a=findSinA(a);
	printf("The corresponding value of sin(%f) is: %f\n", a, sine_of_a);

	return 0;
}
