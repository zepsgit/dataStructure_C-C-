#include<stdio.h>
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int lo, int hi) {
	int i = lo - 1;//increment of smaller elements

	for (int j = lo; j < hi; j++) {
		if (arr[j] <= arr[hi]) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[hi]);
	return i + 1;
}

void quickSort(int arr[], int lo, int hi) {
	//int pivot = partition(arr, lo, hi);
	if (lo < hi) {
		int pivot = partition(arr, lo, hi);
		
		printf("%d\n", pivot);
		quickSort(arr, lo, pivot - 1);
		quickSort(arr, pivot + 1, hi);
		
	}
}

int main() {
	printf("please enter the number of elements:\n");
	int count;
	int arr[30];
	scanf("%d", &count);

	printf("please enter the elements:\n");

	for (int i = 0; i < count; i++)
		scanf("%d", &arr[i]);

	printf("unsorted array:\n");

	for (int i = 0; i < count; i++)
		printf("%d ", arr[i]);
	printf("\n");
	quickSort(arr, 0, count-1);
	printf("the sorted array is:\n");
	for (int i = 0; i < count; i++)
		printf("%d ", arr[i]);
}