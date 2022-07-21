#include <stdio.h>

int main(){
	FILE *poly_ptr, *result_ptr;
	char poly[30];
	poly_ptr=fopen("./poly.txt", "r");
	result_ptr=fopen("./result.txt", "w");
	// exception handling
	if(poly_ptr==NULL){
		printf("ERROR: file not found!");
		return 1;
	}
	// reading the file
	fscanf(poly_ptr, "%[^\n]s", poly);
	// printing the polynomial
	printf("The Polynomial with white-spaces: f(x) = %s\n", poly);
	// removing white spaces then prining and appending to new file it
	printf("Polynomial after removing white-spaces: f(x) = ");
	for(int i=0; poly[i]!='\0'; i++) 
		if(poly[i]!=' ') {
			printf("%c", poly[i]);
			fwrite(&poly[i], sizeof(char), 1, result_ptr);
		}
	printf("\n");
	// closing file streams
	fclose(poly_ptr);
	fclose(result_ptr);
	return 0;
}
