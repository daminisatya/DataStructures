/*Finding the largest sum within a single array using KADANE ALGORITHM*/

#include<stdio.h>

int maxSubArraySum(int array[], int len){
	int i = 0;
	int maxSoFar = 0;
	int maxPresent = 0;
	for (i; i < len; i++){
		maxPresent += array[i];
		if (maxPresent < 0)
			maxPresent = 0;
		if (maxSoFar < maxPresent)
			maxSoFar = maxPresent;
	}
	return maxSoFar;
}

int main(){
	int array[] = { 1, 2, 3, -4, 5, 0, -1 };
	int len = sizeof(array) / sizeof(array[0]);
	int maxSum = maxSubArraySum(array, len);
	printf("The maximum sum of subarray is %d", maxSum);
}