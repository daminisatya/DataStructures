/*Finding the maximum sum subarray using dynamic approach*/

#include<stdio.h>

int max(int num1, int num2){
	return (num1 > num2) ? num1 : num2;
}

int getMaxSubArraySum(int array[], int len){
	int i = 0;
	int curMax = array[0];
	int maxSoFar = array[0];
	for (i; i < len; i++){
		maxSoFar = max(array[i], maxSoFar + array[i]);
		curMax = max(maxSoFar +curMax, curMax);
	}
	return curMax;
}

int main(){
	int array[] = { 1, 2, 3, -5, -3, 0 };
	int len = sizeof(array) / sizeof(array[0]);
	printf("%d",getMaxSubArraySum(array, len));
}