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
	int table1[6*n];
	char table2[12*n];
	// Generating both the tables
	generateTable1(table1, n);
	/* generateTable2(table2, table1, n); */
	//printing both the tables
	printTable1(table1, n);
	/* printTable2(table2, n); */

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
				printf("Updated ");
				printTable1(table1, n);
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
	for(int i=0, len_of_name=0, j=0; i<13*entries; i+=(10-len_of_name), len_of_name=j=0, found=1){
		i+=3;
		// comparing data from input
		do{
			if(table2[i++]!=name[j++]) {
				found=0;
				break;
			}
			len_of_name++;
		}while(table2[i]!='\n');
		// getting length of name
		for(len_name=0; name[len_name]!='\0'; len_name++) continue;
		if(len_name==len_of_name && found){
			// updating the value of limit
			int factor=(i-(len_of_name+3))/14;
			int limit_index=21;
			for( ; factor>0; factor--) limit_index+=22;
			for(int count=0; count<3; count++){
				table1[limit_index]=newlimit%10;
				newlimit/=10;
				limit_index--;
			}
			break;
		}
	}
}

// Generating table number 1
void generateTable1(int table[], int entries){
	for(int i=0; i<6*entries; ){
		table[i++]=rand()%1000;
		table[i++]=1000+rand()%9000;
		for(int j=0; j<3; j++)table[i++]=rand()%10000;
		table[i++]=rand()%1000;
	}
}

// Printing table number 1
void printTable1(int table[], int entries){
	printf("Table 1:\n");
	for(int i=0; i<6*entries;){
		printf("ID %.3d: ", table[i++]);
		printf("  Card Number: %d %.4d %.4d %.4d ", table[i++], table[i++], table[i++], table[i++]);
		printf("  Limit: %.3d\n", table[i++]);
	}
}

// Generating table number 2
void generateTable2(char table[], int table1[], int entries){
	// Copying ID from the table1 
	for(int i1=0, i2=0; i2<13*entries; i1+=22, i2+=14)
		for(int j=0; j<3; j++){
			table[i2+j]=(char)table1[i1+j];
		}
	// Taking input from the user for usernames
	char garbage; scanf("%c", &garbage);
	for(int i=0, len_of_name=0; i<13*entries; i+=(11-len_of_name), len_of_name=0){
		printf("Enter username for ID %d%d%d: ", table[i++], table[i++], table[i++]);
		do{
			scanf("%c", &table[i++]);
			len_of_name++;
		}while(table[i-1]!='\n'); len_of_name--; i--;
	}
}

// Printing table number 2
void printTable2(char table[], int entries){
	printf("\nTable 2:\n");
	for(int i=0, len_of_name=0; i<13*entries; i+=(11-len_of_name), len_of_name=0){
		printf("ID %d%d%d:  ", table[i++], table[i++], table[i++]);
		printf(" Name: ");
		do{
			printf("%c", table[i++]);
			len_of_name++;
		}while(table[i-1]!='\n'); len_of_name--; i--;
	}
}
