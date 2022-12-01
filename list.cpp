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
	create(Get(),val);
}

//データを追加する関数のプロトタイプ宣言
void List::create(int itr, char* val)
{
	CELL* currentCell = getInswrtCellAddress(itr);

	CELL* newCELL = nullptr;

	//新規作成するセル分のメモリを確保する
	newCELL = (CELL*)malloc(sizeof(CELL));

	if (newCELL != NULL)
	{
		strcpy_s(newCELL->val, 16,val);
		newCELL->prev = currentCell;
		newCELL->next = currentCell->next;
	}

	if (currentCell->next) {
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCELL;
		if (newCELL != NULL)
		{
			newCELL->next->prev = newCELL;
		}
	}

	currentCell->next = newCELL;
}

void List::Dit(int itr, char* val)
{
	CELL* currentCell = getInswrtCellAddress(itr);

	strcpy_s(currentCell->val, 16, val);
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
	CELL* head = &this->head;
	while (num<itr)
	{
		num++;
		head = head->next;
	}
	printf("%s\n",head->val);
}
int List::Get() {
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
	CELL* currentCell = getInswrtCellAddress(itr);

	currentCell->prev->next=currentCell->next;

	currentCell->next->prev =currentCell->prev;

	free(currentCell);
}
