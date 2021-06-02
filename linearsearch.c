#include<stdio.h>
#include<conio.h>
int main()
{
	int n;
	printf("enter the value of number of elements:");
	scanf("%d",&n);
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d",&arr[i]);
		printf(" ");
	}
	printf("\n");

	int search;
	scanf("%d",&search);
	int i;
	int found = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d",i);
		printf(" ");
		printf("%d",arr[i]);
		printf("\n");
            if(arr[i] == search){
			found =1;
			printf("%d",arr[i]);
			printf(" found");
			printf("\n");
			break;
		}
	}

	if(found){
		printf("%d",search);
		printf(" found\n");
	}
	if(!found){
		printf("%d",search);
		printf(" not found\n");
	}


	return 0;
}
