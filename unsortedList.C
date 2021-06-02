

// For unsorted list.
#include <stdio.h>
#include<stdlib.h>

int* insert(int n,int* arr,int k, int data){
	n++; 
    for (int i = n; i > k; i--){ 
        arr[i] = arr[i - 1]; 
    }    
    arr[k] = data; 

    return arr;
}

int* deletE(int n,int* arr,int k){
	for(int i=k;i<n;i++){
		arr[i]=arr[i+1];
	}
	return arr;
}

int searchElement(int n,int* arr,int data ){
	int i;
	for(i=0;i<n;i++){
		if(arr[i]==data){
			return data;
		}
	}

	if(i==n){
		return -100000;
	}
}

void displayList(int n,int* arr){
	for(int i=0;i<n;i++){
		printf("%d, ",arr[i]);
	}
	printf("\n");
}

void findMin(int n,int* arr){
	int currMin = 100000000;
	for(int i =0;i<n;i++){
		if(arr[i]<currMin){
			currMin = arr[i];
		}
	}
	printf("%d\n",currMin);
}

void findMax(int n, int* arr){
	int currMax = -100000000;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i]>currMax)
		{
			currMax = arr[i];
		}
	}
	printf("%d\n",currMax);
}
  
int main() 
{ 

    int arr[100]; 
    int n;
    printf("Give the size of array\n");
    scanf("%d",&n);
    printf("type the array\n");
    for (int i = 0; i < n; i++){ 
       scanf("%d",&arr[i]);
    } 

    while(1){

    printf("Choose an operation:\n");	
    printf("1)Insert\n2)Delete\n3)Search\n4)Display\n5)findMin\n6)findMax\n0)Exit\n");
    int k,data,x,z;
    int operation;    
    scanf("%d",&operation);

    switch(operation){
    	case 1:
    		printf("Enter the value of index and data to be inserted respectively\n");
    		scanf("%d",&k);
    		scanf("%d",&data);
    		insert(n,arr,k,data);
    		displayList(n+1,arr);
    		printf("\n");
    		break;

    	case 2: 
    		printf("Enter the index to be deleted\n");
    		scanf("%d",&x);
    		deletE(n,arr,x);
    		displayList(n,arr);
    		break; 

    	case 3: 	
    		printf("Enter the element to be searched\n");
    		scanf("%d",&z);
    		if(searchElement(n,arr,z) != z)
    			printf("Element not found.\n");
    		break; 

    	case 4:
    		displayList(n,arr);
    		break;

    	case 5:
    		findMin(n,arr);
    		break;

    	case 6:
    		findMax(n,arr);
    		break;

    	case 0:
    		return(0);

    	default:
    		printf("No valid result");
    		break;	   			 

    }
    printf("**************************************************************\n");
}

    return 0; 
}