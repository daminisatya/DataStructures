/*Finding the missing number in an array*/

#include<stdio.h>

int getMissingNumber(int array[], int len){
	int sum = 0;
	int OriginalSum = ((len + 1) * (len + 2)) / 2;
	for (int i = 0; i < len; i++){
		sum += array[i];
	}
	return (OriginalSum - sum);
}

int getMissingNumberXOR(int array[], int len){
	int sum1 = array[0];
	int sum2 = 1;
	for (int i = 1; i < len; i++)
		sum1 = sum1 ^ array[i];
	for (int i = 2; i <= len + 1; i++)
		sum2 = sum2 ^ i;
	return (sum1 ^ sum2);
}

int main(){
	int array[] = { 1, 2, 3, 5, 6, 7, 8 };
	int len = sizeof(array) / sizeof(array[0]);
	printf("The missing number is %d", getMissingNumber(array, len));
	printf("\nThe missing number is %d using XOR", getMissingNumberXOR(array, len));
}