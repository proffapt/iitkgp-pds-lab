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
		while (ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=heads[i+1];
	}
	return heads[0];
}

node *insert(node *ptr, int key, char *name){
    node *head=ptr;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
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
        for (int i=1; i<index-1; i++){
            ptr=ptr->next;
        }
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
}

int main(){
	int n;
	printf("Enter n: "); scanf("%d", &n);
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

	int choice, i, key, pos;
	char *name=(char *)malloc(sizeof(char));
	node *concatlist;
	while(10){
  
		printf("Enter 1 to insert a node at the end\n");
		printf("Enter 2 to delete the node\n");
		printf("Enter 3 to concatinate the lists\n");
		printf("Enter 4 to destroy the lists\n");
		printf("Enter 0 to terminate\n");
  
		scanf("%d",&choice);
		switch (choice){
			case 1:
                printf("In which list do you want to a enter a node\n");
                printf("enter key\n"); scanf("%d", &key);
                printf("enter name\n"); scanf(" %s",name);
                scanf("%d",&i);
				insert(heads[i], key, name);
				break;
			case 2:
			    printf("Enter the key   ");
				scanf("%d",&pos);
                printf("in which list do you want to a enter a node\n");
                scanf("%d",&i);
				deletion(heads[i], key);
				break;
		  	case 3:
				printf("concating\n");
                concatlist=concatenate(heads,n);
                printf("concated list :\n");
                display(concatlist);
				break;
			case 4:
                printf("in which list do you want to a enter a node\n");
                scanf("%d",&i);
				destroylist(heads[i]);
				break;
			case 0:
				printf("The program is terminated\n");
				return 0;
			default:
				printf("Invalid response  \n");
		}
    }  
	return 0;
}
