/*Given an array A[] and a number x such that a pair exists in the array whose sum is equal to x*/

#include<stdio.h>
#include<stdbool.h>

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partitionNumber(int array[], int low, int high){
	int pivot = array[high];
	int i = low - 1;
	int j;
	for (j = low; j < high - 1; j++){
		if (array[j] <= pivot){
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &pivot);
	return i + 1;
}

void quickSort(int array[], int low, int high){
	if (low < high){
		int pivot = partitionNumber(array, low, high);
		quickSort(array, low, pivot - 1);
		quickSort(array, pivot + 1, high);
	}
}

bool isPresentPair(int array[], int sum, int len){
	quickSort(array, 0, len - 1);
	int low = 0;
	int high = len - 1;
	while (low < high){
		if (array[low] + array[high] == sum)
			return true;
		else if (array[low] + array[high] < sum)
			low++;
		else high--;
	}
	return false;
}

int main(){
	int array[] = { 11, -2, 0, 8, 7, 3, 1, 0, 1 };
	int sum = 6;
	int len = sizeof(array) / sizeof(array[0]);
	if (isPresentPair(array, sum, len))
		printf("Array contains the elements");
	else printf("Array doesnt contain any pair");
}