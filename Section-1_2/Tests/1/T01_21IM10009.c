#include <stdio.h>

int main()
{

	// Taking input from the user for the number:
	int num;
	printf("Enter an integer: ");
	scanf("%d", &num);
	printf("The number you entered is: %d\n", num);

	// Finding the number of digits in the entered number:
	int count = 0;
	int temp_num = num;
	while (temp_num != 0)
	{
		temp_num = temp_num / 10;
		++count;
	}
	printf("The number of digits in entered number is: %d\n", count);

	// Printing sub integers made from the given input:

	temp_num = num;
	int number = num;
	int digits[count];
	for (int i = 0; i < count; i++)
	{
		digits[i] = temp_num % 10;
		temp_num = temp_num / 10;
	}

	int total = ((count) * (count + 1)) / 2;
	int numbers[total];
    int initiate;
    int p=1;
    int sum=0;
    
    for(int i = 0 ; i < total;i++)
    {
        numbers[i]=digits[total-(i+1)];
    }
    int k=total;
    for(int i=2; i <= total ; i++)
    {

        for(initiate=0;initiate<i;initiate++)
        {
            p=1;
            sum=0;
            for(int r =0;r <i;r++)
            {
                sum+=digits[initiate+r]*p;
                p=p*10;
            }
            numbers[k]=sum;
            k++;
        }
    }

	printf("The modified numbers are :\n");
    for(int i = 0; i < total;i++)
    {
        printf("%d, ",numbers[i]);
    }
	printf("\b\b \n");

    // Individual prime number
    printf("All the prime number from the individual numbers are : ");
    for(int i=0; i < total ;i++)
    {
        int check=1;
        for(int j = 2 ;j<numbers[i]/2 ; i++)
        {
            if(numbers[i]%j==0)
            {
                check=0;
            }
        }
        if(check==1)
        {
            printf("%d, ",numbers[i]);
        }
    }
	printf("\b\b \n");

	return 0;
}