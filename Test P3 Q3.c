#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <psapi.h>
#include <time.h>
#pragma warning(disable:4996)



int Add222(int num) {
    printf("%d\n", num);
    return 100 != num ? (Add222(num + 1)) : printf("count complete");
}

int main()
{
    Add222(1);
    return 0;
}