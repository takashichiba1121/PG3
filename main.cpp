#include<iostream>
#include<stdlib.h>

using namespace std;

//単方向リストの構造体の定義
typedef struct CELL {
	char station[16];
	struct CELL* prev;
	struct CELL* next;
}CELL;

//挿入したいセルのアドレスを取得
CELL* getInswrtCellAddress(CELL* endCELL, int iterator);
//データを末尾に追加する関数のプロトタイプ宣言
void push_back(CELL* front, char* station);

//データを指定したセルに追加する関数のプロトタイプ宣言
void create(CELL* front, char* station);

//一覧を表示する関数のプロトタイプ宣言
void index(CELL* front);

int main(void)
{
	char station[16];
	//先頭セルの宣言
	CELL head;
	strcpy_s(head.station, 16, "toukyou");
	head.next = nullptr;
	head.prev = nullptr;
	int iterator;
	/*scanf_s("%d", &iterator);

	CELL* insertCell = getInswrtCellAddress(&head, iterator);*/

	////最後尾にセルを追加
	//create(insertCell, station);
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%s", station, 16);
		push_back(&head, station);
	}
	CELL* insertCell = getInswrtCellAddress(&head, 3);
	scanf_s("%s", station, 16);
	create(insertCell,station);
	//リスト一覧の表示
	index(&head);

	return 0;
}

CELL* getInswrtCellAddress(CELL* endCELL, int iterator) {
	for (int i = -0; i < iterator; i++)
	{
		if (endCELL->next) {
			endCELL = endCELL->next;
		}
		else {
			break;
		}
	}
	return endCELL;
}

//データを追加する関数のプロトタイプ宣言
void push_back(CELL* head, char* station)
{
	while (head->next != nullptr) {
		head = head->next;
	}
	CELL* newSELL = nullptr;

	//新規作成するセル分のメモリを確保する
	newSELL = (CELL*)malloc(sizeof(CELL));

	if (newSELL != NULL)
	{
		strcpy_s(newSELL->station, 16, station);
		newSELL->prev = head;
		newSELL->next = nullptr;
	}

	//最後(最新)のセルのアドレスの一つ目の処理は引数から持ってきた
	//リストのうち最初のセルのアドレスが該当する
	head->next = newSELL;
}

//データを追加する関数のプロトタイプ宣言
void create(CELL* currentCell, char* station)
{
	CELL* newCELL = nullptr;

	//新規作成するセル分のメモリを確保する
	newCELL = (CELL*)malloc(sizeof(CELL));

	if (newCELL != NULL)
	{
		strcpy_s(newCELL->station, 16, station);
		newCELL->prev = currentCell;
		newCELL->next = currentCell->next;
	}

	if (currentCell->next) {
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCELL;
	}

	currentCell->next = newCELL;
}

//一覧を表示する関数のプロトタイプ宣言
void index(CELL* endCell) {
	int no = 1;
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
		printf("%d\n", no);
		printf("%p\n", endCell->prev);
		printf("%s\n", endCell->station);
		printf("(%p)\n", endCell);
		printf("%p\n", endCell->next);
		printf("\n");
		no++;
	}
}