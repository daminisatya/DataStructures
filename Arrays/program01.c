/*Given an array and an element check for the pair which sums up to the given element*/

#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

void swap(int arr[], int pos1, int pos2){
	arr[pos1] = arr[pos1] + arr[pos2];
	arr[pos2] = arr[pos1] - arr[pos2];
	arr[pos1] = arr[pos1] - arr[pos2];
	return;
}

int getPivotPosition(int arr[], int start, int last){
	int i = start - 1;
	int j;
	int x = arr[last];
	for (j = start; j <= last - 1; j++){
		if (arr[j] <= x){
			i++;
			swap(arr, i, j);
		}
	}
	swap(arr, i + 1, last);
	return i + 1;
}

void quickSort(int arr[], int start, int last){
	int pivot = 0;
	if (start < last){
		pivot = getPivotPosition(arr, start, last);
		quickSort(arr, start, pivot - 1);
		quickSort(arr, pivot + 1, last);
	}
	return;
}

bool hasTwoSumElements(int arr[], int num, int last){
	int left, right;
	quickSort(arr, 0, last - 1);

	left = 0;
	right = last - 1;
	while (left < right){
		if ((arr[left] + arr[right]) == num)
			return true;
		else if ((arr[left] + arr[right]) > num)
			right--;
		else if ((arr[left] + arr[right]) < num)
			left++;
	}
	return false;
}

int main(){
	int arrayElements[5] = { 5, 2, 1, 0, 6 };
	int num = 3;
	if (hasTwoSumElements(arrayElements, num, 5))
		printf("\nThe Array has two elements which sums up to %d", num);
	else
		printf("\nThe Array do not have two elements");
}
