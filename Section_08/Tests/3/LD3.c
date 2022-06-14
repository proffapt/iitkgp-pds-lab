#include<stdio.h>
#include<stdlib.h>

// Logic for findig popular persons
static int n;
int *popular(int known[][n], int n){
	int id=1, condition=1; // we assume first condtion to be satisfied by default and other is not.
	int *arr=(int *)malloc(sizeof(int));
	// fixint the person..
	for(int k=0; k<n; k++){
		// looping simultaneously to check both the conditions
		for(int i=0; i<n; i++) {
			// Checking whether everyone knows person with ID=k or not
			// Checking row wise.. for the column of this guy(ID=colunmn number of this guy) 
			// which contains the information whether other person(with current row number=i) know
			// this guy with ID=k or not.. there shall not be any -1, because everyone must know this 
			// guy, and -1 means that other person doesn't know him.
			if(known[i][k]==(-1)) {
				condition=0; // oops condition failed
				break; // break the loop, ek baar agya matlab usko nahi janta, no need to continue further
			}
			// Checking if there is any person which our kth person doesn't know
			// Checking column wise.. for the row of this guy(ID=row number of this guy)
			// which contains the information whether this person knows the person with current value of
			// i as ID.. that is i is now the column of other person.. and out of all such columns 
			// corresponding to our row k, must have atleast one -1, that is he shall not know
			// atleast of the person, else he is not famous
			if(known[k][i]==(-1)) {
				condition=0; // oops condition failed
				break; // ek bar agya kaafi hai no need to check further thus breaking
			}
		}
		// If both the entries are satisfied, add them to the array list
		if(condition==1){
			// storing from the initial index of 1
			arr[id]=k;
			++id;
		}
		// reinitialising the conditions
		condition=0;
	}
	// Updating the total number of popular persons;
	arr[0]=id-1;
	return arr;
}

int main(){
	// Taking required inputs from the user
	printf("Enter the number of persons: "); scanf("%d", &n);	
	int known[n][n]; printf("Enter the matrix known[%d][%d] :\n", n, n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &known[i][j]);
	// Getting results from the popular function
	int *result=popular(known, n);
	// Printing the results we got!
	printf("\nNumber of popular persons: %d\n", result[0]);
	printf("ID of popular persons: ");
	if(result[0]!=0){
		// printing the contents of array when it has something..
		for(int i=1; i<=result[0]; i++)
			printf("%d, ", result[i]);
		printf("\b\b \n");
	} // other wise printing nil.. if there are no popular persons
	else printf("nil\n");
	return 0;
}
