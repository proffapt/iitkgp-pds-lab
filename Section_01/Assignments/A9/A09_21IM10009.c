/************************************
* Name : Arpit Bhardwaj
* Roll No : 21IM10009
* Section : 1
* Assignment No : 9
* Date : 8-June-2022
* ************************************/

#include<stdio.h>
#include<stdlib.h>

const int size=3;

typedef struct _node {
	int key;
	char *name;
	struct _node *next;
} node;

node *createlist(int size){
    node *error, *head, *ptr;
	error=NULL, head=NULL;
	ptr=(node *)malloc(sizeof(node));
	if (size<2) {
		printf("Size of list must be greater than or equal to 2\n");
		return error;
	}
	head=ptr;
	int index=1;
	head->name=(char*)malloc(sizeof(char));
	printf("Enter name %d: ", index); scanf(" %[^\n]s", ptr->name);
	printf("Enter key %d: ", index); scanf("%d", &(ptr->key));
	ptr->next=NULL;
	size--; index++;
	while(size){
		ptr->next=(node*)malloc(sizeof(node));
		ptr=ptr->next;
		ptr->name=(char*)malloc(sizeof(char));
		printf("Enter name %d: ", index); scanf(" %[^\n]s", ptr->name);
		printf("Enter key %d: ", index); scanf("%d", &(ptr->key));
		size--; index++;
	}
	printf("\n");
	ptr->next=NULL;
	return head;
}

void display(node *ptr){
    while(ptr!=NULL){
        printf("Key: %d   Name: %s\n", ptr->key, ptr->name);
        ptr=ptr->next;
    }
}

node *concatenate(node *heads[], int number_of_lists){
	for(int i=0; i<number_of_lists-1; i++){
		node *ptr=heads[i];
		while (ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=heads[i+1];
	}
	return heads[0];
}

node *insert(node *ptr, int key, char *name){
    node *head=ptr;
    while(ptr->next!=NULL)
        ptr = ptr->next;
	node *insert=(node *)malloc(sizeof(node));
	insert->key=key;
	insert->name=name;
    ptr->next=insert; // persistent
    insert->next=NULL; // persistent
    return head;
}

node *deletion(node *start, int key){
    node *error = NULL;
    node *ptr = start;
    int end =1;
    while (ptr->next!=NULL){
        ptr=ptr->next;
        end++;
    }
    ptr=start; //never forget!! 
	int index=1;
	while(ptr->key!=key){
		ptr=ptr->next;
		index++;
	}
    ptr=start; //never forget!! 
    if (index==1){
        ptr=ptr->next;
        free(start); // freeing the memory is important while deleting.
        return ptr;
    }
    else if (1<index && index<=end) {
        for (int i=1; i<index-1; i++)
            ptr=ptr->next;
        node *delete=ptr->next; // pointing to the to be deleted node
        ptr->next=ptr->next->next;
        free(delete); // freeing the memory
        return start;
    }
    else {
        printf("You are trying to delete an index which doesn't even exist in this list!");
        return error;
    }
}

void destroylist(node *tobedeleted){
	node *ptr1, *ptr2;
	ptr1=tobedeleted;
	ptr2=tobedeleted;
	while(ptr2!=NULL){
		ptr2=ptr2->next;		
		free(ptr1);
		ptr1=ptr2;
	}
	free(ptr2);
}

int main(){
	int n; printf("Enter n: "); scanf("%d", &n);
	printf("\n");
		
	node *heads[n];
	for(int i=0; i<n; i++){
		printf("Populate list %d:\n\n", i+1);
		heads[i]=createlist(size);
	}
	for(int i=0; i<n; i++){
		printf("Printing list %d:\n\n", i+1);
		display(heads[i]);
	}

	int choice, i, key, lists[n];
	char *name=(char *)malloc(sizeof(char));
	for(int i=0; i<n; i++) lists[i]=1;
	while(10){
		printf("\n1) Insert a node at the end\n");
		printf("2) Delete the node with specific key\n");
		printf("3) Concatinate the lists\n");
		printf("4) Destroy the lists\n");
		printf("5) Display the lists\n");
		printf("0) Terminate\n");
		printf("\nEnter your choice: "); scanf("%d",&choice);
		printf("\nAvailable lists: <");
		for(int i=0; i<n; i++)
			if(lists[i]) printf(" %d,", i+1);
		printf("\b > \n");
		switch (choice){
			case 1:
				do{
					printf("In which list do you want to a enter a node: "); scanf("%d", &i);
					if(i<1 || i>n) {
						printf("Surely you are blind or foolish enough to unsee that Available lists ¯\\_(ツ)_/¯ \n");
						continue;
					}
					else break;
				} while(1);
                printf("Enter key: "); scanf("%d", &key);
                printf("Enter name: "); scanf(" %s", name);
				heads[i-1]=insert(heads[i-1], key, name);
				printf("Printing UPDATED list %d:\n\n", i);
				display(heads[i-1]);
				break;
			case 2:
				do{
					printf("In which list do you want to a delete the node: "); scanf("%d", &i);
					if(i<1 || i>n) {
						printf("Surely you are blind or foolish enough to unsee that Available lists ¯\\_(ツ)_/¯ \n");
						continue;
					}
					else break;
				} while(1);
			    printf("Enter the key: "); scanf("%d",&key);
				heads[i-1]=deletion(heads[i-1], key);
				printf("Printing UPDATED list %d:\n\n", i);
				display(heads[i-1]);
				break;
		  	case 3:
                printf("CONCATED LIST :\n");
                display(concatenate(heads, n));
				for(int i=1; i<n; i++) lists[i]=0;
				break;
			case 4:
				do{
					printf("Enter the number of list you wanna destroy: "); scanf("%d",&i);
					if(i<1 || i>n) {
						printf("Surely you are blind or foolish enough to unsee that Available lists ¯\\_(ツ)_/¯ \n");
						continue;
					}
					else break;
				} while(1);
				destroylist(heads[i-1]);
				lists[i-1]=0;
				break;
			case 5:
				do{
					printf("Which list do you want to display: "); scanf("%d",&i);
					if(i<1 || i>n) {
						printf("Surely you are blind or foolish enough to unsee that Available lists ¯\\_(ツ)_/¯ \n");
						continue;
					}
					else break;
				} while(1);
				display(heads[i-1]);
				break;
			case 0:
				printf("The program is terminated.\n");
				return 0;
			default:
				printf("Invalid response !! \n");
		}
    }  
	return 0;
}
