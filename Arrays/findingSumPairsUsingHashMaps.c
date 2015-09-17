/*Given an array A[] and a sum x where a pair of numbers need to found whose sum is x. Using HASHMAP*/

#include<stdio.h>
#define MAXLENGTH 100

void printPairs(int array[], int sum, int len){
	int i;
	int num;
	int HASHMAP[MAXLENGTH] = { 0 };
	for (i = 0; i < len; i++){
		num = sum - array[i];
		if (HASHMAP[num] == 1 && num >= 0)
			printf("The sum is present %d, %d", num, array[i]);
		HASHMAP[array[i]] = 1;
	}
}

int main(){
	int array[] = { 11, -1, 2, 0, 8, 7 };
	int len = sizeof(array) / sizeof(array[0]);
	int sum = 10;
	printPairs(array, sum, len);
}