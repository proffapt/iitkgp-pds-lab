#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand(time(0));
	int i, j;

	int array[100], n;
	printf("enter an integer <= 100: "); scanf("%d", &n);
	for(i = 0; i < n; i++) array[i] = -100 + (rand() % 201);

	printf("The randomly populated array is: [");
	for (i = 0; i < n; i++) printf("%d,", array[i]);
	printf("\b]\n");

	int left_sum=0, sls=0, right_sum=0, srs=0, split = 0;
	int sum_diff = 0, minimum;
	for(i = 0; i < n; i++){

		for(j = 0; j <= i; j++) left_sum+=array[j];	

		for(j = i+1; j < n; j++) right_sum+=array[j];	

		sum_diff = left_sum - right_sum;
		if (sum_diff < 0) sum_diff = 0 - sum_diff;

		if (i == 0) minimum = sum_diff;	

		if (sum_diff < minimum){
			minimum = sum_diff;
			split = i;
			srs = right_sum;
			sls = left_sum;
		}
		left_sum = right_sum = 0;
	}
	printf("Array split position is: %d\n", split);
	printf("The sums of the left and right subarrays are %d and %d\n", sls, srs);


	int dist, min = array[0] - array[1];
	int i_index = 0, j_index = 1;
	for(i = 0; i < n; i++){
		for(j = i+1; j < n; j++){
			dist = array[i] - array[j];
			if (dist < 0) dist = 0 - dist;

			if ( dist < min ){
				min = dist;
				i_index = i; j_index = j;
			}
		}
	}

	printf("One closest pair is %d and %d\n", i_index, j_index);

	return 0;
}
