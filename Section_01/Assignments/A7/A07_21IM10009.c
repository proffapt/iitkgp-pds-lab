/************************************
* Name : Arpit Bhardwaj
* Roll No : 21IM10009
* Section : 1
* Assignment No : 7
* Date : 25-May-2022
* ************************************/

#include<stdio.h>
#include<string.h>

typedef struct stud{
	char name[19];
	float marks[5];
	char rollno[7];
} student;

void readlist(student list[], int size){
	// reading the data for the structure
    printf("\nEnter data for the structure\n\n");
    for(int i=0; i<size; i++){
		// getting names
        printf("Enter name(<19 characters): ");
        scanf("%s", list[i].name);

		// getting roll numbers
        printf("Enter roll number: ");
        scanf("%s", list[i].rollno);

		// getting marks
        printf("Enter the marks for the 5 subjects: ");
        for(int j=0; j<5; j++) scanf("%f", &list[i].marks[j]);
		printf("----------------\n");
    }	
}

void printlist(student list[], int size){
	// printing all the data form the structure
    printf("\nPrinting all the data\n\n");

    for(int i=0;i<size;i++){
		// printing names
        printf("Name: ");
        printf("%s",list[i].name);

		// priting roll number
        printf("\nRoll number: ");
        printf("%s",list[i].rollno);

		// printing marks
        printf("\nMarks for the 5 subjects: ");
        for(int j=0;j<5;j++) printf("%f,", list[i].marks[j]);
		printf("\b \n");
		printf("**************\n");
    }
}	

void sortlist(student list[], int size, int code){
	// defining variable all at once
	int i,j,k,check;
    student temp;
    float aggregate[2];

	// implementing the switch based sorting algorithm
    switch(code){
        case 1: 
            for(i=0;i<size;i++){
                for(j=i;j<size;j++){
                    check=strcmp(list[i].name,list[j].name);
                    if(check>0){
                        temp=list[i];
                        list[i]=list[j];
                        list[j]=temp;
                    }
                }
            }
            break;
    	case 2: 
            for(i=0;i<size;i++){
                for(j=i;j<size;j++){
                    check=strcmp(list[i].rollno,list[j].rollno);
                    if(check>0){
                        temp=list[i];
                        list[i]=list[j];
                        list[j]=temp;
                    }
                }
            }
            break;
    	case 3: 
            aggregate[0]=aggregate[1]=0;
            for(i=0;i<size;i++){
                for(j=i;j<size;j++){
                    for(k=0;k<5;k++) aggregate[0]+=list[i].marks[k];
                    
                    for(k=0;k<5;k++) aggregate[1]+=list[j].marks[k];
                    
                    if(aggregate[0]>aggregate[1]){
                        temp=list[i];
                        list[i]=list[j];
                        list[j]=temp;
                    }
                }
            }
            break;
	}
}

int main(){
	
	int entries, code;
	printf("Enter the number of entries in the list: "); scanf("%d", &entries);

	student list[entries];

	readlist(list, entries);
	printlist(list, entries);

	printf("\nEnter the code to sort the dataset with: "); scanf("%d", &code);
	sortlist(list, entries, code);
	printlist(list, entries);

	return 0;
}
