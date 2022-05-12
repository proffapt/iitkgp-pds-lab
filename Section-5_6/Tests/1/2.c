#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));
	int i, k, a1[10], a2[10], a3[10], a4[10];

	// >> Part a

	// Populating random number into the arrays 
	for (i = 0; i < 10; i++){
		a1[i] = rand() % (30 + 1 - 10) + 10;
		a2[i] = rand() % (60 + 1 - 30) + 30;
		a3[i] = rand() % (90 + 1 - 60) + 60;
		a4[i] = rand() % (120 + 1 - 90) + 90;
	}	

	// Printing those arrays
	printf("a1 = [");
	for(i=0; i<10; i++){
		printf("%d, ", a1[i]);	
	}
	printf("\b\b] \n");
	printf("a2 = [");
	for(i=0; i<10; i++){
		printf("%d, ", a2[i]);	
	}
	printf("\b\b] \n");
	printf("a3 = [");
	for(i=0; i<10; i++){
		printf("%d, ", a3[i]);	
	}
	printf("\b\b] \n");
	printf("a4 = [");
	for(i=0; i<10; i++){
		printf("%d, ", a4[i]);	
	}
	printf("\b\b] \n");

	// >> Part b

	int a5[20];
	
	// Interpersing contents of a1 and a2 into a5
	for(i = 0, k = 0; i < 10; i++, k+=2) a5[k] = a1[i];  
	for(i = 0, k = 1; i < 10; i++, k+=2) a5[k] = a2[i];

	// Displaying contents of a5
	printf("a5 = [");
	for(i=0; i<20; i++){
		printf("%d, ", a5[i]);	
	}
	printf("\b] \n");

	// >> Part c

	int a6[20];
	
	// Interpersing contents of a3 and a4 into a6
	for(i = 0, k = 0; i < 10; i++, k+=2) a6[k] = a3[i];  
	for(i = 0, k = 1; i < 10; i++, k+=2) a6[k] = a4[i];

	// Displaying contents of a6
	printf("a6 = [");
	for(i=0; i<20; i++){
		printf("%d, ", a6[i]);	
	}
	printf("\b\b] \n");

	// >> Part d

	int a7[40];

	// Interpersing contents of a5 and a6 into a7
	for(i = 0, k = 0; i < 20; i++, k+=2) a7[k] = a5[i];  
	for(i = 0, k = 1; i < 20; i++, k+=2) a7[k] = a6[i];

	// Displaying contents of a6
	printf("a7 = [");
	for(i=0; i<40; i++){
		printf("%d, ", a7[i]);	
	}
	printf("\b\b] \n");

	return 0;
}
