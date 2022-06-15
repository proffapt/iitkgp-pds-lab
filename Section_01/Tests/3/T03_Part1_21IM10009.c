/************************************
* Name : Arpit Bhardwaj
* Roll No : 21IM10009
* Section : 1
* Group: 5
* Test No : 3
* Part : 1
* Date : 15-06-2022
* ************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getdata(char ***m, int n){
	printf("\nEnter the data for the matrix M1[%d][%d]:\n", n, n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf(" %s", m[i][j]);
}

void printdata(char ***m, int n, int matrix_number){
	printf("\nPrinting the data for the matrix M%d[%d][%d]:\n\n", matrix_number, n, n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("   %s   ", m[i][j]);
		}
		printf("\n");
	}
}

char *max(char *a, char *b){
	// Getting the lexicographical maximum of two strings
    char *lexmax = (strcmp(a,b)>0) ? a : b;
	return lexmax;
}

void square(char ***a, char ***b, int n){
	// Logic for matrix mutliplication
    char *addition = (char *)malloc(39*sizeof(char));
    char *x=(char *)malloc(39*sizeof(char));
    char *y=(char *)malloc(39*sizeof(char));
    char *entry= " ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            strcpy(b[i][j],"\0");
            for(int k=0; k<n; k++){
                strcpy(x, a[i][k]);
                strcpy(y, a[k][j]);
                entry=strcat(x, y);
                strcpy(addition, entry);
                entry=max(b[i][j], addition);
                strcpy(b[i][j], entry);
            }
        }
    }
}

int main(){
	// Taking input for the size of square matrix of character entries
	int n; printf("Enter the value of n: "); scanf("%d", &n);
	// DMA for the two matrices
	char ***M1=(char ***)malloc(n*sizeof(char));
    char ***M2=(char ***)malloc(n*sizeof(char));
    for(int i=0;i<n;i++){
        M1[i]=(char **)malloc(n*sizeof(char *)); 
        M2[i]=(char **)malloc(n*sizeof(char *)); 
        for(int j=0;j<n;j++){
			// Limiting the size of entries by 19 chars in M1.. one extra for '\0'
            M1[i][j]=(char *)malloc(20*sizeof(char)); 
			// Limiting the size of entries by 38 chars in M2.. one extra for '\0'
            M2[i][j]=(char *)malloc(39*sizeof(char)); 
        }
    }
	// Taking input for the matrix M1 from the user
	getdata(M1, n);
	// Printing the data for matrix M1
	printdata(M1, n, 1);
	// Calling the function to perform the squaring process
	square(M1, M2, n);
	// Printing the data for matrix M2
	printdata(M2, n, 2);
	return 0;
}
