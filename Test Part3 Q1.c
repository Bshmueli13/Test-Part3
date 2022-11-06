#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#pragma warning(disable : 4996)

int main()
{
	char UserLine[100], LineLeft[100], LineRight[100];
	int LineLength, split, i, r;
	scanf("%s", UserLine);
	LineLength = strlen(UserLine);
	split = LineLength / 2;


	for (i = 0; i < split; i++)
	{
		LineLeft[i] = UserLine[i];
	}
	LineLeft[i] = '\0';

	for (i = split, r = 0; i <= LineLength; i++, r++)
	{
		LineRight[r] = UserLine[i];
	}
	printf("left %s\n", LineLeft);
	printf("right %s\n", LineRight);
	return 0;
}


