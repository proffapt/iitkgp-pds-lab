#include<stdio.h>

int nod(int n){
	int digits=0;
	while(n!=0){
		n/=10;
		digits++;
	}

	return digits;
}

int raise(int base, int exp){
	int power=1;
	if(exp==0) power=1;
	while(exp!=0){
		power*=base;	
		exp--;
	}

	return power;
}

int seq(int n){
	int d=nod(n), seq=1;
	for(int i=1; i<=d; i++){
		int r=n/raise(10, d-i);
		n=n-r*raise(10, d-i);

		if(r<n/raise(10, d-i-1)) seq++;
		else break;
	}

	return seq;
}

void display(int a[], int len){
	printf("[");
	for(int i=0; i<len; i++){
		printf("%d,", a[i]);
	}	
	printf("\b] \n");
}

int main()
{
	int total, i, k=0, num, inc[20];

	printf("How many integers do you want to give?: "); scanf("%d", &total);	
	
	for(i=0; i<total; i++){
		printf("Enter number %d: ", i+1); scanf("%d", &num);
		printf("k-sequence of \"%d\" is %d.\n", num, seq(num));

		if(nod(num)==seq(num)){
			inc[k]=num;
			k++;
		}
	}

	printf("Print numbers with all digits in increasing order\n");
	if(k) display(inc, k);	
	else printf("No such number was found!\n");

	return 0;
}
