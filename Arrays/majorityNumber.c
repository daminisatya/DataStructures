/*The Majority element which appears more than n/2 times using MOORE VOTING ALGORITHM*/

#include<stdio.h>
#include<stdbool.h>

int findMaxNumber(int array[], int len){
	int majIndex = 0;
	int count = 1;
	int i;
	for (i = 0; i < len; i++){
		if (array[majIndex] == array[i])
			count++;
		else count--;
		if (count == 0){
			majIndex = i;
			count = 1;
		}
	}
	return array[majIndex];
}

bool isMajority(int max, int array[], int len){
	int count = 0;
	for (int i = 0; i < len; i++){
		if (max == array[i])
			count++;
	}
	if (count > len / 2)
		return true;
	else return false;
}

void isPresentMaxNum(int array[], int len){
	int maxNum = findMaxNumber(array, len);
	if (isMajority(maxNum, array, len))
		printf("The number %d is a majority number", maxNum);
	else
		printf("The number is not a majority number");
}

int main(){
	int array[] = { 1, 3, 2, 5, 3, 5, 5, 5, 5, 5 };
	int len = sizeof(array) / sizeof(array[0]);
	isPresentMaxNum(array, len);
}
