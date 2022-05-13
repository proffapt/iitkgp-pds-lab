#include<stdio.h>

int main()
{
	int n, i, j;
	printf("Enter an integer: "); scanf("%d", &n);

	int t_n, sum_fact, fact=1;
	printf("Printing all PDS numbers from 1 to %d : ", n);
	for(i=1; i<=n; i++){
		for (t_n=i, sum_fact=0; t_n!=0; t_n/=10, fact=1){
			for (int d=t_n%10; d!=0; d--) fact*=d;
			sum_fact+=fact;
		}
		if(sum_fact == i) printf("%d," ,i);
	}
	printf("\b \n");

	int sum_div;
	printf("Printing all LAB numbers from 1 to %d : ", n);
	for(i=1; i<=n; i++){
		for(t_n=i, j=2, sum_div=1; j<t_n; j++){
			if(t_n%j==0){
				sum_div+=j;
			}
		}
		if(sum_div == i) printf("%d," ,i);
	}
	printf("\b \n");

	for(t_n=n, sum_fact=0; t_n!=0; t_n/=10, fact=1){
		for (int d=t_n%10; d!=0; d--) fact*=d;
		sum_fact+=fact;
	}
	for(t_n=n, i=2, sum_div=1; i<t_n; i++){
		if(t_n%i==0){
			sum_div+=i;
		}
	}
	if(sum_fact==n && sum_div==n){
		printf("Printing %d-bow pattern\n", n);
		for(i=n; i>1; i--){
			for(j=i; j>0;j--){
				printf("*");
			}
			printf("\n");
		}
		printf("*\n");
		for(i=2; i<=n; i++){
			for(j=i; j>0; j--){
				printf("*");
			}
			printf("\n");
		}
	}

	return 0;
}
