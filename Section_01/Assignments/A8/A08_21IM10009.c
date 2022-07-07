/************************************
* Name : Arpit Bhardwaj
* Roll No : 21IM10009
* Section : 1
* Assignment No : 8
* Date : 1-June-2022
* ************************************/

// Including header files
#include<stdio.h> // for standard input and output
#include<stdlib.h> // for functions related to random number generation
#include<time.h> // for using time function

// Globally declaring size of array to use in functions directly
// Declaring as constant so that it doesn't change by mistake
int size;

void patternOne(int a[][size]){
	// circle/ellipse in middle
	for (int i=0; i<size; i++)
		for (int j=0; j<size; j++)
			if(i==0 || j==0 || i==size-1 || j==size-1 || 
				(i==1 && j==1) || (i==1 && j==size-2) || (i==size-2 && j==1) || (i==size-2 && j==size-2) ||
				 (j>1 && j<size-2 && i>1 && i<size-2)) a[i][j]=1;
			else a[i][j]=0;
}

void patternTwo(int a[][size]){
	// dikh jayega don't worry
	for (int i=size-1; i>=0; i--)
		for (int j=0; j<size; j++)
			if((i+j<size-1 && i<size/2 && j<size/2) || 
				(i+j>size-1 && i>=size/2 && j>=size/2 )) a[i][j]=1;
			else a[i][j]=0;
}

// This is the logic for printing the arrays
void printArray(int a[][size])
  { // Traversing rows
  	for(int i=0; i<size; i++)
	  { // Traversing columns
		for(int j=0; j<size; j++)
		  { // Printing them beautifully
			printf("  %d", a[i][j]); }
		// New line after every row
		printf("\n"); }
	// One more new line after the last line so that other printed things are separated
	printf("\n"); }

// This is the logic for bad encryption
int BadEnc(int a[][size], int e[][size])
  { // Genarating random key, same for every entry
	int k=rand()%2;
	// Traversing rows
	for (int i=0; i<size; i++)
	    // Traversing columns
		for (int j=0; j<size; j++)
		    // Logic for encryption.. badly..
			e[i][j]=(a[i][j]+k)%2;  
	return k; }

// Decrypting the matrix encrypted via bad decryption
void BadDec(int e[][size], int d[][size], int key)
  { // Traversing rows
	for (int i=0; i<size; i++)
	   // Traversing columns
		for (int j=0; j<size; j++)
		   // Logic for decryptiong after badly encrypting
			d[i][j]=(e[i][j]+key)%2; }

// This is the function for good encryption method
int **GoodEnc(int a[][size], int e[][size])
  { // generating random keys for every entry
	int **k;
	k=(int **)calloc(size ,sizeof(int*));
	for(int i=0;i<size ;i++)
	  k[i]=(int *)calloc(size ,sizeof(int));
	// Traversing rows
	for (int i=0; i<size; i++)
		// Traversing columns
		for (int j=0; j<size; j++)
			k[i][j]=rand()%2;
	// Process of encryption
	// Traversing rows
	for (int i=0; i<size; i++)
		// Traversing columns
		for (int j=0; j<size; j++)
			// Logic for encryption.. goodly?(idk the word.. hehe)
			e[i][j]=(a[i][j]+k[i][j])%2;
	
	return k; }

// fucntion to decrypt the encrypted matrix.. encrypted via good encryption
void GoodDec(int e[][size], int d[][size], int **k)
  { // Traversing rows
	for (int i=0; i<size; i++)
		// Traversing columns
		for (int j=0; j<size; j++)
			// Logic for decryption..
			d[i][j]=(e[i][j]+k[i][j])%2; }

int main(){
	// seedint the rand() function so that we don't get unique random numbers on every subsequent run
	srand(time(0));

	// taking input for the size of array from the user
	printf("Enter size of matrix [size of matrix=(nxn)]: "); scanf("%d", &size);
	// declaring all the arrays being used
	int arrayOne[size][size];
	int arrayTwo[size][size];
	int encrypted[size][size];
	int decrypted[size][size];

	// Populating both arrays with specified and unique patterns
	patternOne(arrayOne);
	patternTwo(arrayTwo);

	// Printing both the arrays
	printf("Matrix with pattern-1:\n\n");
	printArray(arrayOne);
	printf("Matrix with pattern-2:\n\n");
	printArray(arrayTwo);

	// code for menu which keeps running you command it to exit
	int choice=0, badKey;
	int **goodKey;
	while(choice!=3)
	  { printf("Enter 1 to play with pattern-1\n");
		printf("Enter 2 to play with pattern-2\n");
		printf("Enter 3 to exit\n\n");
		printf("Enter your choice: "); scanf("%d", &choice);

		switch(choice){
			case 1:
				// Bad encryption
				badKey=BadEnc(arrayOne, encrypted); // calling bad encryption function and storing the key generated in the variable named key 
				BadDec(encrypted, decrypted, badKey); // calling the bad decryption function
				printf("Bad Encrypted Matrix:\n\n");
				printArray(encrypted); // printing the encrypted matrix
				printf("Matrix after Bad Decryption:\n\n");
				printArray(decrypted); // printing the decrypted matrix
				// Good encryption
				goodKey=GoodEnc(arrayOne, encrypted); // calling the good encryption fucntion
				GoodDec(encrypted, decrypted, goodKey); // calling the good decryption function
				printf("Good Encrypted Matrix:\n\n");
				printArray(encrypted); // printing the encrypted matrix
				printf("Matrix after Good Decryption:\n\n");
				printArray(decrypted); // priting the decrypted matrix
				break;
			case 2:
				// Bad encryption
				badKey=BadEnc(arrayTwo, encrypted); // calling bad encryption function and storing the key generated in the variable named key
				BadDec(encrypted, decrypted, badKey); // calling the bad decryption function
				printf("Bad Encrypted Matrix:\n\n");
				printArray(encrypted); // printing the encrypted matrix
				printf("Matrix after Bad Decryption:\n\n");
				printArray(decrypted); // priting the decrypted matrix
				// Good encryption
				goodKey=GoodEnc(arrayTwo, encrypted); // calling the good encryption fucntion
				GoodDec(encrypted, decrypted, goodKey); // calling the good decryption function
				printf("Good Encrypted Matrix:\n\n");
				printArray(encrypted); // printing the encrypted matrix
				printf("Matrix after Good Decryption:\n\n");
				printArray(decrypted); // priting the decrypted matrix
				break;
			case 3:
				// exit out of the while loop
				break;
			default: 
				// The user is most probably dumb or smart, he might try to break the code?.. but let's handle the situation too
				printf("\nInvalid choice chosen!\n\n");
		} }
	return 0;
}
