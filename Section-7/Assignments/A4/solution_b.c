#include<stdio.h>

int main(){
	int i, j, checked = 0;
	char S[100], Q[100];	

	printf("Enter S: "); scanf("%[^\n]s", S);
	printf("Enter Q: "); scanf(" %[^\n]s", Q);

	int used[100] = {};
	for(i = 0; Q[i] != '\0'; i++){
		checked = 0;
		for(j = 0; S[j] != '\0'; j++){
			if(used[j] == 0 && Q[i] == S[j]){
				used[j] = 1;
				checked = 1;
				break;
			}
		}
		if(!checked){
			printf("Q = \"%s\" - Q can NOT be formed from S.\n", Q);
			return 0;
		}
	}

	if(checked) printf("Q = \"%s\" - Q can be formed from S.\n", Q);

	return 0;
}
