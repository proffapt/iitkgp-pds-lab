/************************************
* Name : Arpit Bhardwaj
* Roll No : 21IM10009
* Section : 1
* Group: 5
* Test No : 3
* Part : 2
* Date : 15-06-2022
* ************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct _poly{
	unsigned int coef;
	unsigned int degree;
	struct _poly *next;
} poly;

int k=0;
int degree(char *poly){
	int data[50]={}, deg=-1;
	for(int i=0; poly[i]!='\0'; i++)
		if(poly[i]=='+' || poly[i]=='-') ++k;
		else ++data[k];
	int index=0, carat=0;
	for(int i=0; i<k; i++) index+=data[i];
	index+=2; // taking account of `+` symbols
	for(int i=index; poly[i]!='\0'; i++)
		if(poly[i]=='^') {
			carat=1;
			break;
		}
	if(carat){
		for(int i=index; poly[i]!='\0'; i++)
			if(poly[i]>='0' && poly[i]<='9') deg=poly[i]-48;
	}
	else deg=1;
	return deg;
}

void sanitize(char *poly){
	printf("Polynomial after removing ERROR: f(x) = ");
	for(int i=0; poly[i]!='\0'; i++){
		if(poly[i]=='E' || poly[i]=='R' || poly[i]=='O') continue;
		printf("%c", poly[i]);
	}
}

void PrintPoly(poly *p){
	printf("\nOutput of PrintPoly: f(x) = %d", p->coef); p=p->next;
	for( ;p!=NULL; p=p->next)
		if(p->degree!=1)printf("+%dx^%d", p->coef, p->degree);
		else printf("+%dx", p->coef);
	printf("\n");
}

poly *SanPoly(char *p){
	poly *head=(poly *)malloc(sizeof(poly));
	int i, coef=0, degree=0;
	// getting constant term
	for (i=0; p[i]!='+'; i++)
		{ if(p[i]=='E' || p[i]=='R' || p[i]=='O') continue;
		  coef=coef*10+(p[i]-48);}
	head->coef=coef;
	head->degree=0;
	// getting non-constant terms
    coef=0; degree=0;
	poly *ptr=head;
	for(int j=0; j<k; j++)
		{ poly *term=(poly *)malloc(sizeof(poly));
		  ptr->next=term;
		  ptr=term;
		  // setting up coef for this term
		  for(i+=1; p[i]!='x'; i++)
			  { if(p[i]=='E' || p[i]=='R' || p[i]=='O') continue;
			    coef=coef*10+(p[i]-48); }
		  ptr->coef=coef;
		  // setting up degree for this term
		  for(i+=1 ; p[i]!='+' ; i++)
			  { if(p[i]>='0' && p[i]<='9') degree=p[i]-48;
			  if (p[i]=='\0') break; }
		  if(degree==0) degree=1;
		  ptr->degree=degree;
		  coef=0; degree=0; }
	ptr->next=NULL;
	return head;
}

int power(int a, int b){
	int result=1;
	for (; b!=0; b--) result*=a;
	return result;
}

int EvalPoly(poly *p, int x){
	int value=p->coef; p=p->next;
	while(p!=NULL)
		{ value=value+(p->coef*power(x, p->degree));
		p=p->next; }
	return value;
}

int main(){
	// Taking input for the erroneous polynomial
	char *polynomial=(char *)malloc(sizeof(char)); 
	printf("Enter the polynomial with ERROR: "); scanf(" %s", polynomial);
	// Outputting the degree of that polynomial using defined function
	printf("Degree of the polynomial: %d\n", degree(polynomial));
	// Printing the polynomial after removing error using the defined function
	sanitize(polynomial);
	poly *llp=SanPoly(polynomial);
	PrintPoly(llp);
	// Evaluation of the polynomial at given point
	int point;
	printf("Please enter a point: "); scanf(" %d", &point);
	int value=EvalPoly(llp, point);
	printf("Result of the Evaluatio: f(%d) = %d\n", point, value);
	printf("Have fun!\n");
	return 0;
}
