#include<stdio.h>
#include<string.h>

int main()
{
	char e[120], n[120];
	printf("Enter the existing password: "); scanf(" %s", e);	
	
	int check[5]={}, i, hamd=0, final_check=0;

	/*
		0 - checking whether it is different from the existing or not
		1 - vowel
		2 - digit
		3 - special chars
		4 - hamming distance
	*/


	while(1){
		printf("Enter the new password: "); scanf(" %s", n);	

		if(strlen(e)>strlen(n)) hamd=strlen(e)-strlen(n); 
		
		for(i=0; n[i]!='\0'; i++){
			// Matching the two passwords
			if(e[i]==n[i] && check[0]!=1){
				check[0]=0;
			}
			else check[0]=1;

			// checking for atleast one vowel
			if(n[i]=='a' || n[i]=='e' || n[i]=='i' || n[i]=='o' || n[i]=='u' || n[i]=='A' || n[i]=='E' || n[i]=='I' || n[i]=='O' || n[i]=='U' ){
				if(check[1]!=1){
					check[1]=1;
				}
			}

			// checking for atleast one digits 
			if(n[i]<=39 && n[i]>=30 && check[2]!=1){
				check[2]=1;
			}

			// checking for special chars
			if(n[i]>=33 && n[i]<=47) check[3]=1;
			else if(n[i]>=58 && n[i]<=64) check[3]=1;
			else if(n[i]>=91 && n[i]<=96) check[3]=1;
			else if(n[i]>=123 && n[i]<=126) check[3]=1;

			// Checking for hamstring
			if(e[i]!=n[i]) hamd++;
		}

		// checking for hamstring distance condition
		if(hamd>=(strlen(e)*strlen(n))/3) check[4]=1;

		// checking all conditions
		if(!check[0]) printf("Enter a different password from existing one.\n");
		if(!check[1]) printf("The password must contain atleast one vowel.\n");
		if(!check[2]) printf("The password must contain atleast one number.\n");
		if(!check[3]) printf("The password must contain atleast one speical character.\n");
		if(!check[4]) printf("The password has insufficient hamming distance.\n");

		// finally when you have correct matches
		for(final_check=0, i=0; i<5; i++){
			if(check[i]==1) final_check++;	
		}

		if(final_check==5){
			printf("New password accepted.\n");
			break;
		}
	}

	return 0;
}
