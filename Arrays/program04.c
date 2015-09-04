/*binary search iterative*/

#include<stdio.h>

int binarySearch(int arr[], int low, int high, int num){
	while (high >= low){
		int mid = low + (high - low) / 2;
		if (arr[mid] == num) return mid;
		if (arr[mid] > num) high = mid - 1;
		if (arr[mid] < num) low = mid + 1;
	}
	return -1;
}

int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = 4;
	int result = binarySearch(arr, 0, size, num);
	(result == -1) ? printf("The number not found") : printf("Number found at %d", result + 1);
}