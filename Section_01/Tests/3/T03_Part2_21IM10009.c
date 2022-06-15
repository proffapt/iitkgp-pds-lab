/************************************
* Name : Arpit Bhardwaj
* Roll No : 21IM10009
* Section : 1
* Group: 5
* Test No : 3
* Part : 2
* Date : 15-06-2022
* ************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct _poly{
	unsigned int coef;
	unsigned int degree;
	struct _poly *next;
} poly;

int degree(char *poly){
	int data[100]={}, k=0;
	int deg=-1;
	for(int i=0; poly[i]!='\0'; i++){
		if(poly[i]!='+') ++data[k];
		else if(poly[i]!='-') ++data[k];
		else k++;
	}
	int index=0, carat=0;
	for(int i=0; i<k; i++) index+=data[i];
	index+=2; // taking account of `+` symbols
	for(int i=index; poly[i]!='\0'; i++){
		if(poly[i]=='^') {
			carat=1;
			break;
		}
	}
	if(carat){
		for(int i=index; poly[i]!='\0'; i++)
			if(poly[i]>='0' && poly[i]<='9') deg=poly[i]-48;
	}
	else deg=1;
	return deg;
}

void sanitize(char *poly){
	printf("Polynomial after removing ERROR: f(x) = ");
	for(int i=0; poly[i]!='\0'; i++){
		if(poly[i]=='E' || poly[i]=='R' || poly[i]=='O') continue;
		printf("%c", poly[i]);
	}
}

void printPoly(poly *p){

}

int main(){
	// Taking input for the erroneous polynomial
	char *polynomial=(char *)malloc(sizeof(char)); 
	printf("Enter the polynomial with ERROR: "); scanf(" %s", polynomial);
	// Outputting the degree of that polynomial using defined function
	printf("Degree of the polynomial: %d\n", degree(polynomial));
	// Printing the polynomial after removing error using the defined function
	sanitize(polynomial);
	return 0;
}
