#include<iostream>
#include<stdlib.h>

using namespace std;

//�P�������X�g�̍\���̂̒�`
typedef struct CELL {
	int val;
	struct CELL* prev;
	struct CELL* next;
}CELL;

//�}���������Z���̃A�h���X���擾
CELL* getInswrtCellAddress(CELL* endCELL, int iterator);
//�f�[�^��ǉ�����֐��̃v���g�^�C�v�錾
void create(CELL* front, int val);
//�ꗗ��\������֐��̃v���g�^�C�v�錾
void index(CELL* front);

int main(void)
{
	int val;
	//�擪�Z���̐錾
	CELL head;
	head.val = 0;
	head.next = nullptr;
	head.prev = nullptr;
	int iterator;

	while (true) {
		scanf_s("%d", &val);
		scanf_s("%d", &iterator);

		CELL* insertCell = getInswrtCellAddress(&head, iterator);

		//�Ō���ɃZ����ǉ�
		create(insertCell, val);

		//���X�g�ꗗ�̕\��
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

//�f�[�^��ǉ�����֐��̃v���g�^�C�v�錾
void create(CELL* currentCell, int val)
{
	CELL* newSELL = nullptr;

	//�V�K�쐬����Z�����̃��������m�ۂ���
	newSELL = (CELL*)malloc(sizeof(CELL));

	newSELL->val = val;
	newSELL->prev = currentCell;
	newSELL->next = nullptr;

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
		printf("%5d", endCell->val);
		printf("(%p)", endCell);
		printf("%p/n", endCell->next);
		no++;
	}
}