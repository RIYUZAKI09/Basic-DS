#include <bits/stdc++.h> 
using namespace std;
  
void heapify(int arr[], int n, int i) 
{ 
    int highest = i;  
    int l = 2*i + 1; 
    int r = 2*i + 2; 
 
    if (l < n && arr[l] > arr[highest]) 
        highest = l; 
   
    if (r < n && arr[r] > arr[highest]) 
        highest = r; 

    if (highest != i) 
    { 
        swap(arr[i], arr[highest]); 
 
        heapify(arr, n, highest); 
    } 
} 

void heapSort(int arr[], int n) 
{  
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
 
    for (int i=n-1; i>0; i--) 
    { 
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    } 
} 

void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        printf("%d ",arr[i]); 
    printf("\n");
}

int main(int argc, char const *argv[])
{
    printf("Insert the number of elements in the array.\n");
    int n;
    scanf("%d",&n);
    printf("Enter the elements of the array.\n");
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    heapSort(arr,n);
    printf("Sorted array is:\n");
    printArray(arr,n);
    return 0;
}