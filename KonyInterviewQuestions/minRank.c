/* Q1:
    Find the minimum rank of a 6 digit number given as input, the minimum rank is defined as the minimum index at which the given 
    number occurs in its permutations.
    eg. 123 can be done as (123, 132, 213, 231, 312, 321) index is 1, min rank of 123 is 1 similarly
    241 can be (124,142,214,241,412,421) index is 4, min rank of 241 is 4
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strArray[100000];
int count = 0;

int compare (const void * a, const void * b )
{
    return strcmp(*(char **)a, *(char **)b);
}

void sort(char *strArray, int size)
{
    qsort (strArray, size, sizeof (char*), compare);
}

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int left, int right)
{
    int i;
    if (left == right)
    {
        strArray[count]=a;
        count++;
    }
    else
    {
        for (i = left; i <= right; i++)
        {
            swap((a+left), (a+i));
            permute(a, left+1, right);
            swap((a+left), (a+i)); //backtrack
        }
    }
}

int main()
{
    char *input;
    scanf("%s",input);
    int n = strlen(input);
    permute(input, 0, n-1);
    int noOfElementsInArray = sizeof(strArray)/sizeof(strArray[0]);
    sort(strArray, noOfElementsInArray);
    int minRank = 0;
    for(minRank; minRank < noOfElementsInArray; minRank++)
        if(strcmp(strArray[minRank], input)==0)
            printf("%d\n",minRank+1);
    return 0;
}