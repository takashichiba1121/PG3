#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include<functional>

int main(void)
{
	int input;
	//����
	printf("���������1��\n������������0��\n���͂��Ă�������\n");
	scanf_s("%d", &input);

	//�R�[���o�b�N�֐�1(�����_����)
	std::function<void(int)> answer = [](int input) {

		const int oddNumber = 1;
		const int evenNumber = 2;
		srand(time(NULL));
		int random = rand();

		if (input == oddNumber)
		{
			if (random % 2 == 0)
			{
				printf("�s����\n");
			}
			else if (random % 2 == 1)
			{
				printf("����\n");
			}
		}
		else if (input == evenNumber)
		{
			if (random % 2 == 0)
			{
				printf("����\n");
			}
			else if (random % 2 == 1)
			{
				printf("�s����\n");
			}
		}
	};


	std::function<void(std::function<void(int)>,int)>setTimeout = [=](std::function<void(int)> answer,int time) {
		Sleep(time * 1000);
		answer(input);

	};

	//���͂̒l��1��0�������画��ւ���ȊO��������G���[�������ďI��
	if (input == 1 || input == 0) {
		setTimeout(answer,3);
	}
	else {
		printf("1��0����͂��Ă�������");
	}

	system("pause");
	return 0;
}