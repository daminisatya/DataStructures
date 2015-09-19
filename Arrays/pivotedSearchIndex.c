/*Search for the element in the pivoted array*/

#include<stdio.h>

int binarySearch(int array[], int low, int high, int num){
	if (low > high)
		return -1;
	int mid = (low + high) / 2;
	if (num == array[mid])
		return mid;
	if (num > array[mid])
		return binarySearch(array, mid + 1, high, num);
	else
		return binarySearch(array, low, mid - 1, num);
}

int pivotedIndex(int array[], int low, int high){
	if (high < low)
		return -1;
	if (high == low)
		return low;
	int mid = (low + high) / 2;
	if (mid < high && array[mid] > array[mid + 1])
		return mid;
	if (mid > low && array[mid] < array[mid - 1])
		return mid - 1;
	if (array[low] > array[mid])
		return pivotedIndex(array, low, mid - 1);
	else return pivotedIndex(array, mid + 1, high);
}

int pivotedBinarySearch(int array[], int len, int num){
	int pivot = pivotedIndex(array, 0, len - 1);
	if (pivot == -1)
		return binarySearch(array, 0, len - 1, num);
	if (num == array[pivot])
		return pivot;
	if (num >= array[0])
		return binarySearch(array, 0, pivot - 1, num);
	else
		return binarySearch(array, pivot + 1, len - 1, num);
}

int main(){
	int array[] = { 3, 4, 5, 1, 2 };
	int size = sizeof(array) / sizeof(array[0]);
	int num = 5;
	printf("%d", pivotedBinarySearch(array, size, num));
}







