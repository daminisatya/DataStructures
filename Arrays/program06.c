/*bubble sort*/

#include<stdio.h>

void swap(int *a, int *b){
	int temp = *b;
	*b = *a;
	*a = temp;
}

void bubbleSort(int arr[], int size){
	int i, j;
	for (i = 0; i <  size - 1; i++){
		for (j = 0; j < size - i - 1; j++){
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

void printArray(int arr[], int size){
	for (int i = 0; i < size; i++)
		printf("%d\n", arr[i]);
}

int main(){
	int arr[] = { 64, 34, 25, 12, 22, 11, 9};
	int size = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, size);
	printArray(arr, size);
}