#include<stdio.h>

int countSubstr(char str[], int starting_index){
	static int count=0, start=0, end=1;
	int length=0, i;

	// strings after terminating char from the beginning 
	for(i=start; str[i]!='\0'; i++) length++;
	if(length==1) return count;
	if(start!=0) {
		for(i=starting_index; str[i]!='\0'; i++) continue;

		if(str[starting_index]==str[i-1]) count++;
	}

	// strings after terminating char from the end 
	for(i=0; str[i+end]!='\0'; i++) length++;
	if(length==1) return count;
	if(end<=length){
		for(i=0; str[i+end]!='\0'; i++) continue;

		if(str[0]==str[i-1]) count++;
	}

	// strings after terminating char from the end and beginning
	/* for(i=starting_index; str[i+end]!='\0'; i++) length++; */
	/* if(length==1) return count; */
	/* if(start!=0 && end<=length){ */
	/* 	for(i=starting_index; str[i+end]!='\0'; i++) printf("%c", str[i]); */
	/* 	printf("\n"); */
	/* } */
	
	start++; end++;
	countSubstr(str, start);
}

int main()
{
	char str[20];
	printf("Enter the string: "); scanf("%s", str);

	int result=countSubstr(str, 0);
	printf("\nTOTAL OF REQUIRED STRINGS = %d\n", result);

	return 0;
}
