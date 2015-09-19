/*Merging the two arrays*/

#include<stdio.h>


void moveToEnd(int array[], int size){
	int i, j = size - 1;
	for (i = size; i >= 0; i--){
		if (array[i] != -1){
			array[j] = array[i];
			j--;
		}
	}
}

void merge(int array[], int array2[], int m, int n){
	int i = n;
	int j = 0;
	int k = 0;
	while (k < m + n){
		if (((i < m + n) && array[i] <= array2[j]) || j == n){
			array[k] = array[i];
			k++;
			i++;
		}
		else{
			array[k] = array2[j];
			k++;
			j++;
		}
	}
}

void printArray(int array[], int size){
	for (int i = 0; i < size; i++){
		printf("%d\n", array[i]);
	}
}

int main(){
	int array[] = { 2, -1, 7, -1, -1, 10, -1 };
	int array2[] = { 5, 8, 12, 14 };
	int size2 = sizeof(array2) / sizeof(array2[0]);
	int size = (sizeof(array) / sizeof(array[0]) - size2);
	moveToEnd(array, size);
	merge(array, array2, size, size2);
	printArray(array, size + size2);
}