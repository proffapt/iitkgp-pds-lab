/************************************
* Name : Arpit Bhardwaj
* Roll No : 21IM10009
* Section : 1
* Group: 5
* Assignment No : 6
* Description : Credit Card
* Date : 11-05-2022
* ************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Declaration of the functions to be used
void generateTable1(int table[], int entries);
void generateTable2(char table[], int table1[], int entries);
void printTable1(int table[], int entries);
void printTable2(char table[], int entries);
void idSearch(int id, int table1[], char table2[], int entries);
void usernameSearch(char username, int table1[], char table2[], int entries);
void updateLimit(char name[], int newlimit, int table1[], char table2[], int entries);
void transaction(int card_number, int amount, int table1[], char table2[], int entries);

int main(){
	srand(time(0)); // seeding the rand function
	// taking input for the number of entries
	int n; printf("Please enter n: "); scanf("%d", &n);
	// Declaring tables
	int table1[23*n];
	char table2[14*n];
	// Generating both the tables
	generateTable1(table1, n);
	generateTable2(table2, table1, n);
	//printing both the tables
	printTable1(table1, n);
	printTable2(table2, n);

	// Searching the tables
	int choice, newLimit;
	char username[11];
	while(1){
		printf("\n  1) Search\n");
		printf("  2) Update Usage Limit\n");
		printf("  3) Use card\n");
		printf("  4) EXIT\n");
		printf("\nEnter your choice: "); scanf("%d", &choice);
		switch(choice){
			case 1:
				/* int oneChoice; */
				/* printf("Enter 1 to search by ID and 2 to search by name\n"); */
				/* printf("Enter your choice: "); scanf("%d", &oneChoice); */
				/* if(oneChoice==1){ */
				/* 	int id; */
				/* 	printf("Please enter an ID: "); scanf("%d", id); */
				/* 	idSearch(id, table1, table2, n); */
				/* } */
				/* else if(oneChoice==2){ */
				/* 	char username[]={}; */
				/* 	printf("Please enter an Name: "); scanf("%s", username); */
				/* 	usernameSearch(username, table1, table2, n); */
				/* } */
				break;
			case 2:
				printf("Please enter the name: "); scanf(" %s", username);
				printf("Please enter new Limit: "); scanf("%d", &newLimit);
				updateLimit(username, newLimit, table1, table2, n);
				/* printf("Updated "); */
				/* printTable1(table1, n); */
				break;
			case 3: 	
				/* unsigned long long int cardnumber; */
				/* int amount; */
				/* printf("Enter card number: "); scanf("%llu", &cardnumber); */
				/* printf("Enter amount: "); scanf("%d", amount); */
				/* transaction(cardnumber, amount, table1, table2, n); */
				break;
			case 4:
				printf("Goodbye!\n");
				return 0;
				break;
			default:
				printf("Invalid choice selected!\n");
		}
	}
}

void updateLimit(char name[],int newlimit, int table1[], char table2[], int entries){
	int found=1, len_name;
	// getting length of name
	for(int i=0, len_of_name=0, j=0; i<13*entries; i+=(10-len_of_name), len_of_name=j=0){
		i+=3;
		do{
			if(table2[i++]!=name[j++]) {
				printf("didn't match: %c .. %c\n", table2[i-1], name[j-1]);
				found=0;
				break;
			}
			len_of_name++;
		}while(table2[i]!='\n'); i--;
		for(len_name=0; name[len_name]!='\0'; len_name++) continue;
		printf("len_name = %d, len_of_name=%d, found=%d\n", len_name, len_of_name, found);
		if(len_name==len_of_name && found){
			printf("milgya\n");
			break;
		}
	}
}

// Generating table number 1
void generateTable1(int table[], int entries){
	for(int i=0, index=3; i<22*entries; i++){
		table[i]=rand()%10; // appending random numbers from 0 to 9.
		// making sure the first number of credit card is not 0.
		if (table[index]==0){
			table[index]=1+rand()%9; // random numbers from 1 to 9.
			index+=23;
		}
		else if(i==index) index+=23;
	}
}

// Printing table number 1
void printTable1(int table[], int entries){
	printf("Table 1:\n");
	for(int i=0; i<22*entries;){
		printf("ID %d%d%d: ", table[i++], table[i++], table[i++]);
		printf("  Card Number: %d%d%d%d ", table[i++], table[i++], table[i++], table[i++]);
		printf("%d%d%d%d %d%d%d%d %d%d%d%d", table[i++], table[i++], table[i++], table[i++], table[i++], table[i++], table[i++], table[i++], table[i++], table[i++], table[i++], table[i++]);
		printf("  Limit: %d%d%d\n", table[i++], table[i++], table[i++]);
	}
}

// Generating table number 2
void generateTable2(char table[], int table1[], int entries){
	// Copying ID from the table1 
	for(int i1=0, i2=0; i2<13*entries; i1+=22, i2+=13)
		for(int j=0; j<3; j++)
			table[i2+j]=table1[i1+j];
	// Taking input from the user for usernames
	char garbage; scanf("%c", &garbage);
	for(int i=0, len_of_name=0; i<13*entries; i+=(10-len_of_name), len_of_name=0){
		printf("Enter username for ID %d%d%d: ", table[i++], table[i++], table[i++]);
		do{
			scanf("%c", &table[i++]);
			len_of_name++;
		}while(table[i-1]!='\n');
	}
}

// Printing table number 2
void printTable2(char table[], int entries){
	printf("\nTable 2:\n");
	for(int i=0, len_of_name=0; i<13*entries; i+=(10-len_of_name), len_of_name=0){
		printf("ID %d%d%d:  ", table[i++], table[i++], table[i++]);
		printf(" Name: ");
		do{
			printf("%c", table[i++]);
			len_of_name++;
		}while(table[i-1]!='\n');
	}
}
