/*selection sort*/

#include<stdio.h>

void swap(int *a, int *b){
	int temp = *b;
	*b = *a;
	*a = temp;
}

void selectionSort(int arr[], int len){
	int minEle;
	int i;
	int j;
	for (i = 0; i < len - 1; i++){
		minEle = i;
		for (j = i + 1; j < len; j++){
			if (arr[j] < arr[minEle])
				minEle = j;
		}
		swap(&arr[i], &arr[minEle]);
	}
}

void printArray(int arr[], int len){
	for (int i = 0; i < len; i++)
		printf("%d\n", arr[i]);
}

int main(){
	int arr[] = { 64, 25, 12, 22, 11 };
	int size = sizeof(arr) / sizeof(arr[0]);
	selectionSort(arr, size);
	printArray(arr, size);
}