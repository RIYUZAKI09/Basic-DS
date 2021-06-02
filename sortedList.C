

// For sorted list.
#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20

void insert(int size,int* arr, int data){
    int i,k;
    for(i=0;i<size;i++){
        if(arr[i]>data) break;
    }
    if(i==size){
        arr[i]=data;
            
    }
    else {
        for(k=size;k>i;k--){
            arr[k]=arr[k-1];
        }
        arr[i]=data;
        
    }
    (size)++;
}

int* deletE(int n,int* arr,int k){
	for(int i=k;i<n;i++){
		arr[i]=arr[i+1];
	}
	return arr;
}

int bsearch(int arr[], int l, int u, int v){
    if(l>u) return -1;
    int mid=(u+l)/2;
    if(arr[mid]==v){
        return mid;
    }
    else if(arr[mid]<v){
        return bsearch(arr,mid+1,u,v);
    }
    else return bsearch(arr,l,mid-1,v);
}

void displayList(int n,int* arr){
	for(int i=0;i<n;i++){
		printf("%d, ",arr[i]);
	}
	printf("\n");
}

int findMin(int n,int* arr){

	printf("%d\n",arr[0]);
}

void findMax(int n, int* arr){

	printf("%d\n",arr[n]);
}


void merge(int arr[], int start, int end) {

    int mid = start + (end - start) / 2;

    int i = start;
    int j = mid + 1;

    int temp[end - start + 1];
    int k = 0;

    while (i <= mid and j <= end) {

        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        } else {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while (j <= end) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    int p = 0;
    for (int x = start; x <= end; x++) {
        arr[x] = temp[p];
        p++;
    }

}

void mergeSort(int arr[], int start, int end) {
    if (start == end) {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, end);
}

  
int main() 
{ 

    int arr[MAX_SIZE]; 
    int n;
    printf("Give the size of array\n");
    scanf("%d",&n);
    printf("type the array\n");
    for (int i = 0; i < n; i++){ 
       scanf("%d",&arr[i]);
    } 

    mergeSort(arr,0,n);
    while(1){

    printf("Choose an operation:\n");	
    printf("1)Insert\n2)Delete\n3)Search\n4)Display\n5)findMin\n6)findMax\n0)Exit\n");
    int data,x,z;
    int operation;    
    scanf("%d",&operation);

    switch(operation){
    	case 1:
    		printf("Enter the value of data to be inserted respectively\n");
    		scanf("%d",&data);
    		insert(n,arr,data);
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
    		if(z == bsearch(arr,0,n,z)){
                printf("Element found.\n");
            }else{
                printf("Element not found.\n");
            }
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