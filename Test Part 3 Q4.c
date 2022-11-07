#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>
#pragma warning (disable : 4996)

struct Loto
{
	int LotoNum;
	char LotoDate[100];
	struct Loto* Next;
	struct Loto* Prev;
};

struct Loto* Head = NULL;
struct Loto* Tail = NULL;

void AddLotoDraw(int loto_num, char loto_date[100]) {
	struct Loto* CurrentLoto = NULL;
	struct Loto* PrevLoto = NULL;

	CurrentLoto = (struct Loto*)malloc(sizeof(struct Loto));
	CurrentLoto->LotoNum = loto_num;
	strcpy(CurrentLoto->LotoDate, loto_date);

	if (Head == NULL)
	{
		Head = CurrentLoto;
		Tail = CurrentLoto;
		CurrentLoto->Next = NULL;
		CurrentLoto->Prev = NULL;
		PrevLoto = CurrentLoto;
	}
	else
	{
		CurrentLoto->Next = NULL;
		CurrentLoto->Prev = PrevLoto;
		Tail = CurrentLoto;
		PrevLoto = CurrentLoto;
	}
}

void LotoLoadFile() {
	FILE* f = fopen("C:\\Users\\User\\source\\repos\\ConsoleApplication4\\ConsoleApplication4\\Lotto.csv", "r");
	if (!f)
	{
		//error
	}
	else
	{
		char str[1000];
		fgets(str, 1000, f);
		while (fgets(str, 1000, f))
		{
			char LottoryNum[50];
			char LottoryDate[50];
			char* Token;

			Token = strtok(str, ",");
			strcpy(LottoryNum, Token);
			Token = strtok(NULL, ",");
			strcpy(LottoryDate, Token);
			AddLotoDraw(atoi(LottoryNum), LottoryDate);
		}
	}
}

void SerchLoto(int loto_num)
{
	struct Loto* currentItem1 = Head;
	struct Loto* serch = Head;

	while (serch != NULL)
	{
		serch = currentItem1;
		

		if (serch->LotoNum == loto_num)
		{
			printf("the raffle:\n loto number: %d\n loto date: %s\n", serch->LotoNum, serch->LotoDate);
			return;
		}

		serch = serch->Next;

	}
	printf("Lotto Draw wasnt found");
	return;
}

void FreeList() {
	struct Loto* currentItem1 = Head;
	struct Loto* FreeItem = Head;

	while (currentItem1 != NULL)
	{
		FreeItem = currentItem1;
		currentItem1 = currentItem1->Next;
		free(FreeItem);
	}
}

int main()
{
	char UserResponse = 0;
	int a;

	while (UserResponse != 'Q' || 'q') {
		printf("*MENU*\n~ Type the Option For Execution ~\nN.Which lottery number are you interested in?\nQ.Quit\ntype here:");
		UserResponse = getch();
		printf("\n\n\n");
		Sleep(1000);
		switch (UserResponse)
		{
		case 'N':
			Sleep(1000);
			LotoLoadFile();
			printf("\n\nFile is loadded.\n\n");
			Sleep(1000);
			printf("\n\nPlease choose a lotto number:\n\n");
			scanf("%d", &a);
			SerchLoto(a);
			printf("\n\n");
			Sleep(1000);
			break;
		case 'Q':
			FreeList();
			printf("\n\nThank you have a good day!\n\n");
			Sleep(1000);
			return;
		default:
			printf("invalid key");
			printf("\n\n");
			break;
		}
	}
	return 0;
}


