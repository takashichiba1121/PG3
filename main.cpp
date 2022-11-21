#include<iostream>
#include<stdlib.h>

using namespace std;

//単方向リストの構造体の定義
typedef struct CELL {
	int val;
	struct CELL* prev;
	struct CELL* next;
}CELL;

//挿入したいセルのアドレスを取得
CELL* getInswrtCellAddress(CELL* endCELL, int iterator);
//データを追加する関数のプロトタイプ宣言
void create(CELL* front, int val);
//一覧を表示する関数のプロトタイプ宣言
void index(CELL* front);

int main(void)
{
	int val;
	//先頭セルの宣言
	CELL head;
	head.val = 0;
	head.next = nullptr;
	head.prev = nullptr;
	int iterator;

	while (true) {
		scanf_s("%d", &val);
		scanf_s("%d", &iterator);

		CELL* insertCell = getInswrtCellAddress(&head, iterator);

		//最後尾にセルを追加
		create(insertCell, val);

		//リスト一覧の表示
		index(&head);
	}


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
void create(CELL* currentCell, int val)
{
	CELL* newSELL = nullptr;

	//新規作成するセル分のメモリを確保する
	newSELL = (CELL*)malloc(sizeof(CELL));

	newSELL->val = val;
	newSELL->prev = currentCell;
	newSELL->next = nullptr;

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
		printf("%5d", endCell->val);
		printf("(%p)", endCell);
		printf("%p/n", endCell->next);
		no++;
	}
}