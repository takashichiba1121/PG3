#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include<functional>

int main(void)
{
	int input;
	//入力
	printf("奇数だったら1を\n偶数だったら0を\n入力してください\n");
	scanf_s("%d", &input);

	//コールバック関数1(ラムダ式版)
	std::function<void(int)> answer = [](int input) {

		const int oddNumber = 1;
		const int evenNumber = 2;
		srand(time(NULL));
		int random = rand();

		if (input == oddNumber)
		{
			if (random % 2 == 0)
			{
				printf("不正解\n");
			}
			else if (random % 2 == 1)
			{
				printf("正解\n");
			}
		}
		else if (input == evenNumber)
		{
			if (random % 2 == 0)
			{
				printf("正解\n");
			}
			else if (random % 2 == 1)
			{
				printf("不正解\n");
			}
		}
	};


	std::function<void(std::function<void(int)>,int)>setTimeout = [=](std::function<void(int)> answer,int time) {
		Sleep(time * 1000);
		answer(input);

	};

	//入力の値が1か0だったら判定へそれ以外だったらエラー文だして終了
	if (input == 1 || input == 0) {
		setTimeout(answer,3);
	}
	else {
		printf("1か0を入力してください");
	}

	system("pause");
	return 0;
}