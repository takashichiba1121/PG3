#include"list.h"
#include<iostream>
#include<stdlib.h>

List::List()
{
	strcpy_s(head.val, 16, "aaa");
	head.next = nullptr;
	head.prev = nullptr;
}

CELL *List::getInswrtCellAddress(int iterator) {
	CELL* endCELL = &head;
	for (int i = 0; i < iterator; i++)
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
void List::push_back(char* val)
{
	create(Size(),val);
}

//データを追加する関数のプロトタイプ宣言
void List::create(int itr, char* val)
{
	CELL* iteratorCell = getInswrtCellAddress(itr);

	CELL* newCELL = nullptr;

	//新規作成するセル分のメモリを確保する
	newCELL = (CELL*)malloc(sizeof(CELL));

	if (newCELL != NULL)
	{
		strcpy_s(newCELL->val, 16,val);
		newCELL->prev = iteratorCell;
		newCELL->next = iteratorCell->next;
	}

	if (iteratorCell->next) {
		CELL* nextCell = iteratorCell->next;
		nextCell->prev = newCELL;
		if (newCELL != NULL)
		{
			newCELL->next->prev = newCELL;
		}
	}

	iteratorCell->next = newCELL;
}

void List::Dit(int itr, char* val)
{
	CELL* iteratorCell = getInswrtCellAddress(itr+1);

	strcpy_s(iteratorCell->val, 16, val);
}

//一覧を表示する関数のプロトタイプ宣言
void List::index() {
	int no = 0;
	CELL* endCell = &head;
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
	/*	printf("%d\n", no);
		printf("%p\n", endCell->prev);*/
		printf("%d:\"%s\",\n",no, endCell->val);
		//printf("(%p)\n", endCell);
		/*printf("%p\n", endCell->next);
		printf("\n");*/
		no++;
	}
}
void List::print(int itr)
{
	int num = 0;
	CELL* iteratorCell = getInswrtCellAddress(itr + 1);
	printf("%s\n", iteratorCell->val);
}
int List::Size() {
	int num = 0;
	CELL* head = &this->head;
	while (head->next!=nullptr)
	{
		num++;
		head = head->next;
	}
	return num;
}

void List::Delete(int itr)
{
	CELL* iteratorCell = getInswrtCellAddress(itr+1);

	if (iteratorCell->next == nullptr)
	{
		iteratorCell->prev->next = nullptr;
	}
	else
	{
		iteratorCell->prev->next = iteratorCell->next;

		iteratorCell->next->prev = iteratorCell->prev;
	}

	cout <<itr << "番目の要素\""<<iteratorCell->val <<"\"を削除しました" << endl;

	free(iteratorCell);
}
