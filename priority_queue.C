#include<bits/stdc++.h>
using namespace std;
int size = 0;

void heapify(int A[], int size, int i) 
{ 
    int highest = i;  
    int l = 2*i + 1; 
    int r = 2*i + 2; 
 
    if (l < size && A[l] > A[highest]) 
        highest = l; 
   
    if (r < size && A[r] > A[highest]) 
        highest = r; 

    if (highest != i) 
    { 
        swap(A[i], A[highest]); 
 
        heapify(A, size, highest); 
    } 
} 

void MakeHeap(int* A,int size){
	for(int i = size/2-1;i>=0;i--){
		heapify(A,size,i);
	}
}

void insertQ(int* A,int k){
	if(size == 0){
		A[0] = k;
		size++;
	}else{
		A[size] = k;
		size++;
	}
	MakeHeap(A,size);
	
}

void deleteQ(int* A){
	A[0] = A[size-1];
	size--;
	MakeHeap(A,size);
}

void DisplayHeap(int* A,int size){
	for(int i =0;i<size;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int A[1000];
		printf("\t\t\t\t\tProgram to simulate priority queues:\n\n");
	while(true){

		printf("Enter your choice:\n");
		printf("1) Insert into priority queue\n");
		printf("2) Delete from priority queue\n");
		printf("3) Display priority queue\n");
		printf("4) Exit\n");
		int k;
		scanf("%d",&k);
		switch(k){
			case 1:
			{
				printf("Enter the number to be inserted:\n");
				int z;
				scanf("%d",&z);
				insertQ(A,z);
				printf("\n");
				break;
			}

			case 2:
			{
				deleteQ(A);
				break;
			}

			case 3:
			{
				printf("Priority queue is:\n");
				DisplayHeap(A,size);
				break;
			}

			case 4:
			{
				return 0;
				break;
			}

			default:
			{
				break;
			}
		}
		printf("\n\t\t\t\t**************************************************\n");
	}

	return 0;
}