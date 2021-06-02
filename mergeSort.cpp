#include<bits/stdc++.h>

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

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter size of array.\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements of the array.\n");
	for(int i =0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	mergeSort(arr,0,n);
	printf("Array after sorting is: \n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}