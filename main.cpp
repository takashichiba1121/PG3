#include<iostream>
#include<stdlib.h>

using namespace std;

//�P�������X�g�̍\���̂̒�`
typedef struct CELL {
	char* station;
	struct CELL* prev;
	struct CELL* next;
}CELL;

//�}���������Z���̃A�h���X���擾
CELL* getInswrtCellAddress(CELL* endCELL, int iterator);
//�f�[�^�𖖔��ɒǉ�����֐��̃v���g�^�C�v�錾
void push_back(CELL* front, char* station);

//�f�[�^���w�肵���Z���ɒǉ�����֐��̃v���g�^�C�v�錾
void create(CELL* front, char* station);

//�ꗗ��\������֐��̃v���g�^�C�v�錾
void index(CELL* front);

int main(void)
{
	char* station=nullptr;
	//�擪�Z���̐錾
	CELL head;
	head.station;
	head.next = nullptr;
	head.prev = nullptr;
	int iterator;
	scanf_s("%s", station,20);
	scanf_s("%d", &iterator);

	CELL* insertCell = getInswrtCellAddress(&head, iterator);

	//�Ō���ɃZ����ǉ�
	create(insertCell, station);

	//���X�g�ꗗ�̕\��
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

//�f�[�^��ǉ�����֐��̃v���g�^�C�v�錾
void push_back(CELL* currentCell, char* station)
{
	CELL* newSELL = nullptr;

	//�V�K�쐬����Z�����̃��������m�ۂ���
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

//�f�[�^��ǉ�����֐��̃v���g�^�C�v�錾
void create(CELL* currentCell, char* station)
{
	CELL* newSELL = nullptr;

	//�V�K�쐬����Z�����̃��������m�ۂ���
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

//�ꗗ��\������֐��̃v���g�^�C�v�錾
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