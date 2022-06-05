// declaring the header files
#include<stdio.h> // for printf and scanf functions
#include<stdlib.h> // for using rand() and srand() functions
#include<time.h> // for time() function, as seed to the rand() function

// function to find union of two given sets
void UNION(int set1[], int set2[]){
	int tmp[40], j,k=0;
	// copying set1 into tmp
	for(int i=0;i<20;i++, k++)
		  tmp[k]=set1[i];
	// copying not common elements from set2 to tmp
	for(int i=0;i<20;i++){
		// checking for the presence of element already
		for(j=0;j<k;j++){
			if(tmp[j]==set2[i])
			// not copying if the entries are already there.. just breaking out of this loop
			break;
		}
		// copying only when not found same
		if(j==k){
			tmp[k]=set2[i];
			// tracking k for printing tmp in future
			k++;
		}
	}
	// printing tmp
	printf("\nset1 U set2 = [");
	for(int i=0; i<k; i++)
		printf("%d,", tmp[i]);
	// /b to remove that extra comma in the end.. to print it nicely
	printf("\b] \n\n");
}

// function to find intersection of two given sets
void INTERSECTION(int set1[], int set2[]){
	int tmp[20], k=0;
	// traversing the array once
    for(int i=0;i<20;i++){
		// for every entry traversing the array again
		for(int j=0;j<20;j++){
			// storing only when two entries are same
			if(set1[i]==set2[j]){
				tmp[k]=set1[i];
				k++;
			}
         }
    }
	// considering that rare case when the intersection is a null set
	if (k==0){
		printf("\nset1 ∩ set2 = [ϕ]\n\n");
		// exiting the function in this case
		return;
	}
	// printing tmp
	printf("\nset1 ∩ set2 = [");
	for(int i=0; i<k; i++)
		printf("%d,", tmp[i]);
	// /b to remove that extra comma in the end.. to print it nicely
	printf("\b] \n\n");
}

int main(){
	// seeding the random function
	srand(time(0));
	// declaring arrays and other variables
	int set1[20], set2[20], hai, random;
	// populating set1 with unique values
	for (int i = 0; i < 20; ){
		random=10+(rand()%41);
		hai = 0;
		// checking whether that random value has already been assigned or not
		for (int j = 0; j < i; j++)
			// if yes then change the value of hai to 1
			if (set1[j]==random)
				hai = 1;
		// if that random value is not present.. that is hai=0 then only store that into set1
		if (!hai){
			set1[i] = random;
			i++;
		}
	}
	// populating set2 with unique values
	for (int i = 0; i < 20; ){
		random=10+(rand()%41);
		hai = 0;
		// checking whether that random value has already been assigned or not
		for (int j = 0; j < i; j++)
			// if yes then change the value of hai to 1
			if (set2[j] == random)
				hai = 1;
		// if that random value is not present.. that is hai=0 then only store that into set2
		if (!hai){
			set2[i] = random;
			i++;
		}
	}
	// printing set1
	printf("set1 = [");
	for(int i=0; i< 20; i++)
		printf("%d,", set1[i]);
	// /b to remove that extra comma in the end.. to print it nicely
	printf("\b] \n");
	// printing set2
	printf("set2 = [");
	for(int i=0; i< 20; i++)
		printf("%d,", set2[i]);
	// /b to remove that extra comma in the end.. to print it nicely
	printf("\b] \n\n");
	// menu based on infinite loop
	int choice, proceed=1;
	do {
		printf("Enter 1 for union\n");
		printf("Enter 2 for intersection\n");
		printf("Enter any other number to exit\n\n");
		printf("Enter your choice: "); scanf("%d", &choice);
		switch(choice){
			case 1:
				// calling the UNION function
				UNION(set1, set2);
				break;
			case 2:
				// calling the INTERSECTION function
				INTERSECTION(set1, set2);
				break;
			default:
				printf("\nExiting...\n\n");
		}
		// logic for exiting the loop menu
		if(choice!=1 && choice!=2) break; // if user entered other than 1 or 2 loop will exit so will the program
	} while(1);

	return 0;
}
