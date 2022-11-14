#include<iostream>
#include<stdlib.h>

using namespace std;

//�P�������X�g�̍\���̂̒�`
typedef struct CELL {
	int returnDate;
	int loanDate;
	char name[20];
	struct CELL* next;
}CELL;

//�f�[�^��ǉ�����֐��̃v���g�^�C�v�錾
void create(CELL* front,int loanDate,int returnDate, const char* name);
//�ꗗ��\������֐��̃v���g�^�C�v�錾
void index(CELL* front);

int main(void)
{
	char name[]="YamadaTarou";
	int loanDate;
	int returnDate;
	//�擪�Z���̐錾
	CELL front;
	front.next = nullptr;

	while (true) {
		scanf_s("%s", name,20);
		scanf_s("%d", &loanDate);
		scanf_s("%d", &returnDate);


		//�Ō���ɃZ����ǉ�
		create(&front, loanDate, returnDate, name);

		//���X�g�ꗗ�̕\��
		index(&front);
	}


	return 0;
}

//�f�[�^��ǉ�����֐��̃v���g�^�C�v�錾
void create(CELL* front, int loanDate, int returnDate, const char* name)
{
	CELL* newSELL = nullptr;

	//�V�K�쐬����Z�����̃��������m�ۂ���
	newSELL = (CELL*)malloc(sizeof(CELL));

	if (newSELL!=NULL)
	{
		strcpy_s(newSELL->name, 8, name);
		newSELL->loanDate = loanDate;
		newSELL->returnDate = returnDate;
		newSELL->next = nullptr;
	}

	//�Ō�(�ŐV)�̃Z���̃A�h���X�̈�ڂ̏����͈������玝���Ă���
	//���X�g�̂����ŏ��̃Z���̃A�h���X���Y������
	while (front->next != nullptr) {
		front = front->next;
	}
	front->next = newSELL;
}

//�ꗗ��\������֐��̃v���g�^�C�v�錾
void index(CELL* front) {
	while (front->next != nullptr)
	{
		front = front->next;
		printf("����/%s\n", front->name);
		printf("�ݏo��/%d\n", front->loanDate);
		printf("�ԋp��/%d\n", front->returnDate);
	}
}