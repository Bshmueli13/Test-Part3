#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#pragma warning(disable : 4996)

void splitLeft(char UserLine[100]) 
{
    char LineLeft[100], LineRight[100];
    int LineLength, split;
    int i, r;

    LineLength = strlen(UserLine);
    split = LineLength / 2;

    for (i = 0; i < split; i++) {
        LineLeft[i] = UserLine[i];
    }
    LineLeft[i] = '\0';

    for (i = split, r = 0; i <= LineLength; i++, r++) {
        LineRight[r] = UserLine[i];
    }

    printf("LineLeft %s\n", LineLeft);
    if (LineLeft[0] != '\0')
    {
        splitLeft(LineLeft);
    }
}

int main() {
    splitLeft("Who Dares Wins");
    splitLeft("12345678");
    return 0;
}