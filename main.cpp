#include<iostream>
#include<stdlib.h>

using namespace std;

//単方向リストの構造体の定義
typedef struct CELL {
	int returnDate;
	int loanDate;
	char name[20];
	struct CELL* next;
}CELL;

//データを追加する関数のプロトタイプ宣言
void create(CELL* front,int loanDate,int returnDate, const char* name);
//一覧を表示する関数のプロトタイプ宣言
void index(CELL* front);

int main(void)
{
	char name[]="YamadaTarou";
	int loanDate;
	int returnDate;
	//先頭セルの宣言
	CELL front;
	front.next = nullptr;

	while (true) {
		scanf_s("%s", name,20);
		scanf_s("%d", &loanDate);
		scanf_s("%d", &returnDate);


		//最後尾にセルを追加
		create(&front, loanDate, returnDate, name);

		//リスト一覧の表示
		index(&front);
	}


	return 0;
}

//データを追加する関数のプロトタイプ宣言
void create(CELL* front, int loanDate, int returnDate, const char* name)
{
	CELL* newSELL = nullptr;

	//新規作成するセル分のメモリを確保する
	newSELL = (CELL*)malloc(sizeof(CELL));

	if (newSELL!=NULL)
	{
		strcpy_s(newSELL->name, 8, name);
		newSELL->loanDate = loanDate;
		newSELL->returnDate = returnDate;
		newSELL->next = nullptr;
	}

	//最後(最新)のセルのアドレスの一つ目の処理は引数から持ってきた
	//リストのうち最初のセルのアドレスが該当する
	while (front->next != nullptr) {
		front = front->next;
	}
	front->next = newSELL;
}

//一覧を表示する関数のプロトタイプ宣言
void index(CELL* front) {
	while (front->next != nullptr)
	{
		front = front->next;
		printf("氏名/%s\n", front->name);
		printf("貸出日/%d\n", front->loanDate);
		printf("返却日/%d\n", front->returnDate);
	}
}