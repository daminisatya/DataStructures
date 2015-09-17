/*Finding the number occurring odd number of times*/

#include<stdio.h>

int getOddOccurances(int array[], int len){
	int num = array[0];
	int i;
	for (i = 0; i < len; i++)
		num = num ^ array[i];
	return num;
}

int main(){
	int array[] = { 1, 3, 4, 3, 4, 3};
	int len = sizeof(array) / sizeof(array[0]);
	printf("%d",getOddOccurances(array, len));
}