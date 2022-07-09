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
void usernameSearch(char name[], int table1[], char table2[], int entries);
void updateLimit(char name[], int newlimit, int table1[], char table2[], int entries);
void transaction(int cardnumber[], int amount, int table1[], char table2[], int entries);

int main(){
	srand(time(0)); // seeding the rand function
	// taking input for the number of entries
	int n; printf("Please enter n: "); scanf("%d", &n);
	// Declaring tables
	int table1[6*n];
	char table2[14*n];
	// Generating both the tables
	generateTable1(table1, n);
	generateTable2(table2, table1, n);
	//printing both the tables
	printTable1(table1, n);
	printTable2(table2, n);

	// Searching the tables
	int choice, oneChoice, newLimit, id, amount, cardnumber[4];
	char username[11];
	while(1){
		printf("\n  1) Search\n");
		printf("  2) Update Usage Limit\n");
		printf("  3) Use card\n");
		printf("  4) EXIT\n");
		printf("\nEnter your choice: "); scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("   1) Search by ID\n");
				printf("   2) Search by name\n");
				printf(" Enter your choice: "); scanf("%d", &oneChoice);
				switch(oneChoice){
					case 1:
						printf("Please enter an ID: "); scanf("%d", &id);
						idSearch(id, table1, table2, n);
						break;
					case 2:
						printf("Please enter an Name: "); scanf(" %s", username);
						usernameSearch(username, table1, table2, n);
						break;
				}
				break;
			case 2:
				printf("Please enter the name: "); scanf(" %s", username);
				printf("Please enter new Limit: "); scanf("%d", &newLimit);
				updateLimit(username, newLimit, table1, table2, n);
				break;
			case 3: 	
				printf("Enter card number: "); scanf("%d %d %d %d", &cardnumber[0], &cardnumber[1], &cardnumber[2], &cardnumber[3]);
				printf("Enter amount: "); scanf("%d", &amount);
				transaction(cardnumber, amount, table1, table2, n);
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

// to carry out transaction:
void transaction(int cardnumber[], int amount, int table1[], char table2[], int entries){
	// checking for the authenticity of the card number
	int card_found=0, i, check=0;
	for(i=1; i<6*entries; i+=6, check=0){
		for(int ci=0; ci<4; ci++) if(cardnumber[ci]==table1[i+ci]) check++;
		if (check==4) {
			card_found=1;
			break;
		}
	}
	if(!card_found) printf("\nERROR: Invalid Card NUmber!\n");
	else {
		int limit_index=i+4;
		// checking whether amount entered is possible to withdraw
		if(amount>table1[limit_index]) printf("\nERROR: Limit exceeded!\n");
		else{
			// Proceeding with the withdrawal
			table1[limit_index]-=amount;
			// Printing updated account info
			int name_index=3+(i/6)*14, id_index=i-1;
			printf("ID %d: Name: ", table1[id_index++]);
			do{
				printf("%c", table2[name_index++]);
			}while(table2[name_index]!='\n');
			printf("  Card Number: %d %.4d %.4d %.4d ", table1[id_index++], table1[id_index++], table1[id_index++], table1[id_index++]);
			printf("  Limit: %.3d\n", table1[id_index++]);
		}
	}
}

// search based on id
void idSearch(int id, int table1[], char table2[], int entries){
	int found=0;
	for(int i=0; i<6*entries; i+=6){
		if(id==table1[i]){
			found=1;
			// priting details of the user:
			int name_index=3+(i/6)*14,
			id_index=i;
			printf("ID %d: Name: ", table1[id_index++]);
			do{
				printf("%c", table2[name_index++]);
			}while(table2[name_index]!='\n');
			printf("  Card Number: %d %.4d %.4d %.4d ", table1[id_index++], table1[id_index++], table1[id_index++], table1[id_index++]);
			printf("  Limit: %.3d\n", table1[id_index++]);
			break;
		}
	}
	if(!found) printf("\nUser not found!\n");
}

// search based on username
void usernameSearch(char name[], int table1[], char table2[], int entries){
	int found=1, len_name, len_of_name=0;
	for(int i=0, j=0; i<14*entries; i+=(10-len_of_name), len_of_name=j=0, found=1){
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
			// priting details of the user:
			int name_index=i-len_of_name,
			factor=(i-(len_of_name+3))/14,
			id_index=0;
			for( ; factor>0; factor--) id_index+=6;
			printf("ID %d: Name: ", table1[id_index++]);
			do{
				printf("%c", table2[name_index++]);
			}while(table2[name_index]!='\n');
			printf("  Card Number: %d %.4d %.4d %.4d ", table1[id_index++], table1[id_index++], table1[id_index++], table1[id_index++]);
			printf("  Limit: %.3d\n", table1[id_index++]);
			break;
		}
	}
	if(!(len_name==len_of_name && found)) printf("\nUser not found!\n");
}

void updateLimit(char name[],int newlimit, int table1[], char table2[], int entries){
	int found=1, len_name, len_of_name=0;
	for(int i=0, j=0; i<14*entries; i+=(10-len_of_name), len_of_name=j=0, found=1){
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
			int limit_index=5;
			for( ; factor>0; factor--) limit_index+=6;
			table1[limit_index]=newlimit;
			printf("Updated ");
			printTable1(table1, entries);
			break;
		}
	}
	if(!(len_name==len_of_name && found)) printf("\nIvalid username specified!\n");
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
	char garbage; scanf("%c", &garbage);
	for(int i=0, len_of_name=0, j=0; i<14*entries; i+=(11-len_of_name), len_of_name=0){
		// Copying ID from the table1 
		int id=table1[j];
		table[i]=id/100; id-=(id/100)*100;
		printf("Enter username for ID %d", table[i++]);
		table[i]=id/10; id-=(id/10)*10; printf("%d", table[i++]); 
		table[i]=id; printf("%d: ", table[i++]);
		j+=6;
		// getting names from the user
		do{
			scanf("%c", &table[i++]);
			len_of_name++;
		}while(table[i-1]!='\n'); len_of_name--; i--;
	}
}

// Printing table number 2
void printTable2(char table[], int entries){
	printf("\nTable 2:\n");
	for(int i=0, len_of_name=0; i<14*entries; i+=(11-len_of_name), len_of_name=0){
		printf("ID %d%d%d:   Name: ", table[i++], table[i++], table[i++]);
		do{
			printf("%c", table[i++]);
			len_of_name++;
		}while(table[i-1]!='\n'); len_of_name--; i--;
	}
}
