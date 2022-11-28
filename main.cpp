#include<iostream>
#include<stdlib.h>

using namespace std;

//�P�������X�g�̍\���̂̒�`
typedef struct CELL {
	char station[16];
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
	char station[16];
	//�擪�Z���̐錾
	CELL head;
	strcpy_s(head.station, 16, "toukyou");
	head.next = nullptr;
	head.prev = nullptr;
	int iterator;
	/*scanf_s("%d", &iterator);

	CELL* insertCell = getInswrtCellAddress(&head, iterator);*/

	////�Ō���ɃZ����ǉ�
	//create(insertCell, station);
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%s", station, 16);
		push_back(&head, station);
	}
	CELL* insertCell = getInswrtCellAddress(&head, 3);
	scanf_s("%s", station, 16);
	create(insertCell,station);
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
void push_back(CELL* head, char* station)
{
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
void create(CELL* currentCell, char* station)
{
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