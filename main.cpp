#include<iostream>
#include<stdlib.h>

using namespace std;

//単方向リストの構造体の定義
typedef struct CELL {
	char* station;
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
	char* station=nullptr;
	//先頭セルの宣言
	CELL head;
	head.station;
	head.next = nullptr;
	head.prev = nullptr;
	int iterator;
	scanf_s("%s", station,20);
	scanf_s("%d", &iterator);

	CELL* insertCell = getInswrtCellAddress(&head, iterator);

	//最後尾にセルを追加
	create(insertCell, station);

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
void push_back(CELL* currentCell, char* station)
{
	CELL* newSELL = nullptr;

	//新規作成するセル分のメモリを確保する
	newSELL = (CELL*)malloc(sizeof(CELL));

	if (newSELL != NULL)
	{
		strcpy_s(newSELL->station,16, station);
		newSELL->prev = currentCell;
		newSELL->next = nullptr;
	}

	if (currentCell->next) {
		CELL* nextCell = currentCell->next;
		nextCell->prev = newSELL;
	}
}

//データを追加する関数のプロトタイプ宣言
void create(CELL* currentCell, char* station)
{
	CELL* newSELL = nullptr;

	//新規作成するセル分のメモリを確保する
	newSELL = (CELL*)malloc(sizeof(CELL));

	if (newSELL != NULL)
	{
		newSELL->station = station;
		newSELL->prev = currentCell;
		newSELL->next = nullptr;
	}

	if (currentCell->next) {
		CELL* nextCell = currentCell->next;
		nextCell->prev = newSELL;
	}
}

//一覧を表示する関数のプロトタイプ宣言
void index(CELL* endCell) {
	int no = 1;
	while (endCell != nullptr)
	{
		endCell = endCell->next;
		printf("%d", no);
		printf("%p", endCell->prev);
		printf("%5d", endCell->station);
		printf("(%p)", endCell);
		printf("%p/n", endCell->next);
		no++;
	}
}