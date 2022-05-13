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

void printTable1(int table[], int entries){
	printf("Table 1:\n");
	for(int i=0; i<22*entries;){
		printf("ID %d%d%d: ", table[i++], table[i++], table[i++]);
		printf("  Card Number: %d%d%d%d ", table[i++], table[i++], table[i++], table[i++]);
		printf("%d%d%d%d %d%d%d%d %d%d%d%d", table[i++], table[i++], table[i++], table[i++], table[i++], table[i++], table[i++], table[i++], table[i++], table[i++], table[i++], table[i++]);
		printf("  Limit: %d%d%d\n", table[i++], table[i++], table[i++]);
	}
}

void printTable2(char table[], int entries){
	printf("\nTable 2:\n");
	for(int i=0; i<12*entries;){
		printf("ID %d%d%d:  ", table[i++], table[i++], table[i++]);
		printf("  Name: %c%c%c%c%c%c%c%c%c%c\n", table[i++],  table[i++], table[i++], table[i++], table[i++], table[i++], table[i++], table[i++], table[i++], table[i++]);
	}
}

void generateTable1(int table[], int entries){
	// Generating table number 1
	for(int i=0, index=3; i<22*entries; i++){
		table[i]=rand()%10;
		// making sure the first number of credit card is not 0.
		if (table[index]==0){
			table[index]=1+rand()%9;
			index+=23;
		}
		else if(i == index){
			index+=23;
		}
	}
}

void generateTable2(char table[], int table1[], int entries){
	// Generating table number 2
	
	// Copying ID from the table1 
	for(int i1=0, i2=0; i2<12*entries; i1+=22, i2+=12){
		for(int j=0; j<3; j++){
			table[i2+j]=table1[i1+j];
		}
	}
	// Taking input from the user for usernames
	for(int i=0; i<12*entries; i+=12){
		for(int j=3; j<13; j++){
			printf("Enter username for ID %d%d%d: ", table[i++], table[i++], table[i++]);
			scanf(" %c", table[i+j]);
		}
	}
}

void idSearch(int id, int table1[], int table2[], int entries){
	int temp_id, digit, found;
	for(int i=0; i<22*entries; i+=22){
		temp_id=id;
		for(int j=2; j<=0; j--){
			digit=temp_id%10;
			if(digit==table1[i+j]){
				temp_id/=10;
				found++;
			}
			else {
				found=0;
				break;
			}

			if(found=3){
			printf("ID %d%d%d: ", table1[i++], table1[i++], table1[i++]);
			printf("  Card Number: %d%d%d%d ", table1[i++], table1[i++], table1[i++], table1[i++]);
			printf("%d%d%d%d %d%d%d%d %d%d%d%d", table1[i++], table1[i++], table1[i++], table1[i++],table1[i++], table1[i++], table1[i++], table1[i++], table1[i++], table1[i++], table1[i++],table1[i++]);
			printf("  Limit: %d%d%d\n", table1[i++], table1[i++], table1[i++]);
			
			break;
			}
		}
	}

	printf("Invalid ID!\n");
}

void usernameSearch(char username, int table1[], int table2[], int entries){

}

void updateLimit(int newlimit, int table1[], int table2[], int entries){

}

void transaction(int card_number, int amount, int table1[], int table2[], int entries){

}

int main(){

	srand(time(0)); // seeding the rand function

	// taking input for the number of entries
	int n, i, index;
	printf("Please enter n: "); scanf("%d", &n);

	// Declaring tables
	int table1[23*n];
	char table2[13*n];

	// Generating both the tables
	generateTable1(table1, n);
	printTable1(table1, n);
	
	generateTable2(table2, table1, n);
	
	//printing both the tables
	printTable2(table2, n);

	// Searching the tables
	printf("Enter 1 to Search\n");
	printf("Enter 2 to Update\n");
	printf("Enter 3 to Use card\n");
	printf("Enter 4 to exit\n");

	int choice=0;
	printf("\nEnter your choice: "); scanf("%d", &choice);

	while (choice!=4){
		if(choice==1) {
			int oneChoice;
			printf("Enter 1 to search by ID and 2 to search by name\n");
			printf("Enter your choice: "); scanf("%d", &oneChoice);
			if(oneChoice==1){
				int id;
				printf("Please enter an ID: "); scanf("%d", id);
				idSearch(id, table1, table2, n);
			}
			else if(oneChoice==2){
				char username[]={};
				printf("Please enter an Name: "); scanf("%s", username);
				usernameSearch(username, table1, table2, n);
			}
		}
		else if (choice==2){
			char username[]={};
			int newLimit;
			printf("Please enter the name: "); scanf("%s", username);
			printf("Please enter new Limit: "); scanf("%d", newLimit);
			updateLimit(newLimit, table1, table2, n);
			printf("Updated ");
			printTable1(table1, n);
		}	
		else if (choice==3){
			unsigned long long int cardnumber;
			int amount;
			printf("Enter card number: "); scanf("%llu", &cardnumber);
			printf("Enter amount: "); scanf("%d", amount);
			transaction(cardnumber, amount, table1, table2, n);
		}
	}

	if(choice==4){
		printf("Goodbye!\n");

	    return 0;
	}
}