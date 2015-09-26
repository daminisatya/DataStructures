/* Q2
Given a file with odd number of lines, print out the median line of the file (middle line), You can use fread(), fseek() but no getline()
All lines are of variable lengths and are not constant.
*/

#include <stdio.h>
#include <string.h>

int numberOfLinesInFile()
{
	FILE* f = fopen("test.txt", "r");
	int ch, numberOfLines = 0;
	do 
	{
		ch = fgetc(f);
		if(ch == '\n')
			numberOfLines++;
	} while (ch != EOF);

	fclose(f);
	return numberOfLines;
}

int medianLine(int n)
{
	return (n+1)/2; // Given as odd only.
}

void printMedianLine(int median)
{
	char line[256];
	FILE* f = fopen("test.txt", "r");
	int ch, numberOfLines = 0;
	while(fgets (line, 256, f) != NULL)
	{
		numberOfLines++;
		if(numberOfLines == median)
			printf("%s\n", line);
	}
	fclose(f);
}

int main()
{
	int lines = numberOfLinesInFile();
	int mline = medianLine(lines);
	printMedianLine(mline);
	return 0;
}