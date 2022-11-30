#include"list.h"
#include<iostream>
#include<stdlib.h>

List::List()
{
	head.next = nullptr;
	head.prev = nullptr;
}

CELL* List::getInswrtCellAddress(int iterator) {
	CELL* endCELL = &head;
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

//�f�[�^��ǉ�����֐��̃v���g�^�C�v�錾
void List::push_back(char* station)
{
	CELL* head=&this->head;
	while (head->next != nullptr) {
		head = head->next;
	}
	CELL* newSELL = nullptr;

	//�V�K�쐬����Z�����̃��������m�ۂ���
	newSELL = (CELL*)malloc(sizeof(CELL));

	if (newSELL != NULL)
	{
		strcpy_s(newSELL->station, 16, station);
		newSELL->prev = head;
		newSELL->next = nullptr;
	}

	//�Ō�(�ŐV)�̃Z���̃A�h���X�̈�ڂ̏����͈������玝���Ă���
	//���X�g�̂����ŏ��̃Z���̃A�h���X���Y������
	head->next = newSELL;
}

//�f�[�^��ǉ�����֐��̃v���g�^�C�v�錾
void List::create(int itr, char* station)
{
	CELL* currentCell = getInswrtCellAddress(itr);

	CELL* newCELL = nullptr;

	//�V�K�쐬����Z�����̃��������m�ۂ���
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

//�ꗗ��\������֐��̃v���g�^�C�v�錾
void List::index() {
	int no = 1;
	CELL* endCell = &head;
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
	/*	printf("%d\n", no);
		printf("%p\n", endCell->prev);*/
		printf("%s\n", endCell->station);
		//printf("(%p)\n", endCell);
		/*printf("%p\n", endCell->next);
		printf("\n");
		no++;*/
	}
}
void List::print(int itr)
{
	int num = 0;
	CELL* head = &this->head;
	while (num<=itr)
	{
		num++;
		head = head->next;
	}
	printf("%s\n",head->station);
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

int fgets()
{
	char buffer[256];
	size_t length;

	printf("Input: ");
	if (fgets(buffer, 256, stdin) == NULL) {
		return 1;
	}
	length = strlen(buffer);
	if (length > 0 && buffer[length - 1] == '\n') {
		buffer[--length] = '\0';
	}
	int num = std::atoi(buffer);
	printf("Output: %s\n", buffer);
	printf("Length: %zu\n", length);
	printf("num:%d\n", num);
	return 0;
}