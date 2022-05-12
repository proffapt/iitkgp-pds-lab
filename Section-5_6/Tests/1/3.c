#include<stdio.h>

int main()
{
	int i, j, s, n, num;
	while(1){
		// taking input for scale factor and number of lines:
		printf("Enter scale factor: "); scanf("%d", &s);
		printf("Enter number of lines: "); scanf("%d", &n);

		// Imposing constraints on the values of s and n:
		if(s<=1 || s>=3) {
			printf("value of s must be within [1,3]\n");
		}
		if(n<=1 || n>=6){ 
			printf("value of n must be within [1,6]\n");
		}

		// exiting loop when required values are within range
		if(s>=1 && s<=3 && n>=1 && n<=6) break;
	}

	// printing the required pattern
	for(i=1; i<=n; i++){
		for (j=1; j<=i; j++){
			if(num>s+3) num=1;
			printf("%d", num);
			num++;
		}
		printf("\n");
	}

	return 0;
}
