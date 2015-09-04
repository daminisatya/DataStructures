/*Binary search recursive*/

#include<stdio.h>

int binarySearch(int arr[], int low, int high, int num){
	if (high >= low){
		int mid = low + (high - low) / 2;
		if (arr[mid] == num) return mid;
		if (arr[mid] > num) return binarySearch(arr, low, mid - 1, num);
		if (arr[mid] < num) return binarySearch(arr, mid + 1, high, num);
	}
}

int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = 2;
	int result = binarySearch(arr, 0, size, num);
	(result == -1) ? printf("The number is not found") : printf("The number of found at %d", result + 1);
}