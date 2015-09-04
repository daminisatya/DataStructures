/*Linear search*/

#include<stdio.h>

int isPresent(int arr[], int num){
	for (int i = 0; i < 5; i++) {
		if (num == arr[i])
			return i + 1;
	}
		return -1;
}

int main(){
	int arr[5] = { 1, 2, 4, 5, 6 };
	int num = 5;
	printf(" The number is found at %d",isPresent(arr, num));
}
