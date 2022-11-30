#include<iostream>
#include<stdlib.h>
#include"list.h"
enum class Scene
{
	Print = 1,
	Create,
	Dit,
	Delete,
	final
};
//要素の表示
bool PrintList(List* list);

int main(void)
{
	char station[16];
	//先頭セルの宣言
	List* list;
	list = new List();

	Scene scene;
	scene = Scene::Print;

	int number = 0;
	while (scene != Scene::final)
	{
		cout << "[要素の操作]" << endl;
		cout << "1.要素の表示" << endl;
		cout << "2.要素の挿入" << endl;
		if (list->Get() != 0)
		{
			cout << "3.要素の編集" << endl;
			cout << "4.要素の削除" << endl;
		}
		cout << endl;
		cout << "-----------------------------" << endl;
		cout << "操作を選択してください(上の番号以外および文字を入れた場合は即実行終了します)" << endl;
		if (scanf_s("%d", &scene) == 0)
		{
			std::cout << "エラー" << "\n";
			scene = Scene::final;
		}
		switch (scene)
		{
			break;
		case Scene::Print:
			PrintList(list);
			break;
		case Scene::Create:
			break;
		case Scene::Dit:
			break;
		case Scene::Delete:
			break;
		default:
			scene = Scene::final;
			std::cout << "エラー" << "\n";
			break;
		}
	}
	delete list;
	return 0;
}
bool PrintList(List* list)
{
	while (true) {
		cout << "[要素の表示]" << endl;
		cout << "1.要素の一覧表示" << endl;
		cout << "2.順番を指定して要素を表示" << endl;
		cout << "9.要素操作に戻る" << endl;
		cout << endl;
		cout << "操作を選択してください(上の番号以外および文字を入れた場合は即実行終了します)" << endl;
		int number = 0;
		if (scanf_s("%d", &number) == 0)
		{
			std::cout << "エラー" << "\n";
			return false;
		}
		else if (number == 1)
		{
			cout << "[要素の一覧表示]" << endl;
			cout << "要素の一覧:{" << endl;
			list->index();
			cout << "}" << endl;
			cout << endl;
			cout << "要素数:";
			cout << list->Get() << endl;
			cout << endl;
			cout << "-----------------------------" << endl;
			cout << "1.要素の表示に戻る" << endl;
			cout << "2.要素の操作に戻る" << endl;
			if (scanf_s("%d", &number) == 0)
			{
				std::cout << "エラー" << "\n";
				return false;
			}
			if (number==1)
			{

			}
			else if (number==2)
			{
				break;
			}
			else
			{
				std::cout << "エラー" << "\n";
				return false;
			}
		}
		else if (number == 2)
		{
			if (list->Get()>0)
			{
				int itr = 0;
				cout << "[順番を指定して要素を表示]" << endl;
				do
				{
					cout << "表示したい要素の番号を指定してください" << endl;

					if (scanf_s("%d", &itr) == 0)
					{
						std::cout << "エラー" << "\n";
						return false;
					}
					if (list->Get() < itr)
					{
						cout << "要素数以上の番号が入力されました" << endl;
					}
				} while (list->Get() < itr);

				list->print(itr);

				cout << "-----------------------------" << endl;
				cout << "1.要素の表示に戻る" << endl;
				cout << "2.要素の操作に戻る" << endl;

				if (scanf_s("%d", &number) == 0)
				{
					std::cout << "エラー" << "\n";
					return false;
				}
				if (number == 1)
				{

				}
				else if (number == 2)
				{
					break;
				}
				else
				{
					std::cout << "エラー" << "\n";
					return false;
				}
			}
			else
			{
				cout << endl;
				cout << "要素数が0です。" << endl;
				cout << endl;
			}
		}
		else if (number == 9)
		{
			break;
		}
		else
		{
			std::cout << "エラー" << "\n";
			return false;
		}
	}
	return true;
}