/************************************

* Name : Arpit Bhardwaj

* Roll No : 21IM10009

* Section : 1

* Group: 5

* Assignment No : 5

* Description : Database

* Date : 04-05-2022

* ************************************/

#include <stdio.h>

int main()
{
	// Taking input for 3 pairs of account number and balance from the user
	int accounts[3];
	int balance[3];

	printf("Data Entry:\n\n");
	printf("Enter 3 pairs account number and currosponding balance \nEXAMPLE: 3456 234 \n");
	for (int i = 0; i < 3; i++)
	{
		scanf("%d %d", &accounts[i], &balance[i]);

		// Limiting the account numbers to 4-digit values
		if (accounts[i] < 1000 || accounts[i] > 9999)
		{
			printf("\nInvalid account entry.\n");
			printf("Account number must be of 4-digits.\n");
			return 0;
		}

		// Limiting the balance to less than 1000 INR
		if (balance[i] >= 1000)
		{
			printf("\nInvalid balance entry.\n");
			printf("Balance must be less than 1000 INR.\n");
			return 0;
		}
	}

	// Making sure you don't enter same account number more than once!
	if (accounts[0] == accounts[1] || accounts[1] == accounts[2] || accounts[0] == accounts[2])
	{
		printf("\nUhh.. please enter 3 unique account number for the sake of god!\n");
		return 0;
	}

	// Printing the databse from the bank system
	printf("\nDatabase:\n\n");

	for (int i = 0; i < 3; i++)
	{
		printf("Account Number of User %d: %d Available Balance: %d\n", i + 1, accounts[i], balance[i]);
	}

	// Code for the transaction portal
	printf("\nTransaction Time:\n\n");
	int account_number;
	int amount;
	int index;
	printf("Please enter your Account Number: ");
	scanf("%d", &account_number);

	// Checking if account number is valid or not
	int hai = 0;
	for (int i = 0; i < 3; i++)
	{
		if (account_number == accounts[i])
		{
			hai = 1;
			index = i;
			break;
		}
	}

	// Quitting the code when the account number is invalid
	if (!hai)
	{
		printf("\nInvalid account!\n");
		return 0;
	}
	else
	{
		// Taking the withdrawal amount
		printf("Withdraw amount: ");
		scanf("%d", &amount);

		// Checking if the withdrawal amount is more than available balance
		if (amount > balance[index])
		{
			// exiting if withdrawal amount is more than available balance
			printf("\nInsufficient Balance!\n");
			return 0;
		}
		else
		{
			printf("Transaction successful.\n");

			// Asking the user whether to output the updated balance for the user or not
			int choice;
			printf("Do you want to see your updated balance? [enter 1 for yes and 0 for no]: ");
			scanf("%d", &choice);
			if (!choice)
			{
				printf("\nThanks for visiting our bank, Have a good day.\n");
			}
			else
			{
				printf("\nAvailable Balance updated:\n");
				printf("Account Number: %d Available Balance: %d\n", account_number, balance[index] - amount); // avaialable balance calculation here
				printf("\nThanks for visiting our bank, Have a good day.\n");
			}
		}
	}

	return 0;
}