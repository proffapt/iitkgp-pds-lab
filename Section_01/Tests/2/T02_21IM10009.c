/************************************

* Name : Arpit Bhardwaj

* Roll No : 21IM10009

* Section : 1

* Group: 5

* Test No : 2

* Date : 25-05-2022

* ************************************/

#include<stdio.h>

void readlists(int A[], int B[], n, m){
	printf("Enter elements for sequence A[%d]: ", n);
	// for loop to take input for the sequence A
	for(int i=0; i<n; i++) scanf("%d", &A[i]);

	printf("Enter elements for sequence B[%d]: ", m);
	// for loop to take input for the sequence B
	for(int i=0; i<m; i++) scanf("%d", &B[i]);
}

void printlist(int A[], int B[], n, m){
	printf("Printing elements for sequence A[%d]: <", n);
	// for loop to print elements for the sequence A
	for(int i=0; i<n; i++) printf("%d,", A[i]);
	printf("\b> \n"); // removing that comma in last

	printf("Printing elements for sequence B[%d]: <", m);
	// for loop to print elements for the sequence B
	for(int i=0; i<m; i++) printf("%d,", B[i]);
	printf("\b> \n"); // removing that comma in last
}

int search(int A[], int B[], int C[], int n,int m){
    int count=0, found=0, j, k=0; 

	// checking the occurances
    for(int i=0;i<n;i++) {
        for(j=0; j<m; j++){
            if(A[i+j]==B[j]) found=1; 
            else {
                found=0;
                break;
            }
        }
        if(found==1){
            count++;
            j++;
            C[k++]=(i+1);
        }
    }

	printf("The matching positions were found to be = <", count);
	// for loop to print elements for the sequence C
	for(int i=0; i<count; i++) printf("%d,", C[i]);
	printf("\b> \n"); // removing that comma in last

    return count;
}

int main(){
	// reading n and m, along with printing them
	int n, m;
	printf("Enter integers n and m: "); scanf("%d %d", &n, &m);
	printf("YOU ENTERED n = %d and m = %d\n", n, m);
		
	int A[n], B[m], C[20];

	readlists(A, B, n, m);
	printlist(A, B, n, m);

	// calling the search function
	int matches=search(A, B, C, n, m);
	printf("The number of matches of B[%d] in A[%d] are: %d\n", m, n, matches);


	for (int i=0; i<m; i++) {
        for (int j=i; j< m; j++) {
            int length = j-i+1;
            int D[length]; // store the subsequence
            for (int k=0; k<length; k++) D[k]=B[k+i];

            // printing the subsequence
            printf("\nSubsequence D[%d] = <", length);
			// for loop to print elements for the sequence D
			for(int q=0; q<length; q++) printf("%d,", D[q]);
			printf("\b> \n"); // removing that comma in last

            // calling the search function 
            matches = search(A, D, C, n, length);
            printf("The number of matches in A[%d] are: %d\n", n, matches);
        }
    }

	return 0;
}
