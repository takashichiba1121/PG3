#include<iostream>
#include<string>
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
void PrintList(List* list);

void CreateList(List* list);

void DitList(List* list);

void DeleteList(List* list);

int fgetsInt();

int main(void)
{
	//先頭セルの宣言
	List* list;
	list = new List();

	Scene scene;
	scene = Scene::Print;
	while (scene != Scene::final)
	{
		cout << "[要素の操作]" << endl;
		cout << "1.要素の表示" << endl;
		cout << "2.要素の挿入" << endl;
		if (list->Size() != 0)
		{
			cout << "3.要素の編集" << endl;
			cout << "4.要素の削除" << endl;
		}
		cout << endl;
		cout << "-----------------------------" << endl;
		cout << "操作を選択してください" << endl;
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
			CreateList(list);
			break;
		case Scene::Dit:
			DitList(list);
			break;
		case Scene::Delete:
			DeleteList(list);
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
void PrintList(List* list)
{
	while (true) {
		cout << "[要素の表示]" << endl;
		cout << "1.要素の一覧表示" << endl;
		cout << "2.順番を指定して要素を表示" << endl;
		cout << "9.要素操作に戻る" << endl;
		cout << endl;
		cout << "操作を選択してください" << endl;
		int number = 0;
		if (scanf_s("%d", &number) == 0)
		{
			std::cout << "エラー" << endl;
			cout << "文字が入力されました" << endl;
		}
		else if (number == 1)
		{
			cout << "[要素の一覧表示]" << endl;
			cout << "要素の一覧:{" << endl;
			list->index();
			cout << "}" << endl;
			cout << endl;
			cout << "要素数:";
			cout << list->Size() << endl;
			cout << endl;
			cout << "-----------------------------" << endl;
			cout << "1.要素の表示に戻る" << endl;
			cout << "2.要素の操作に戻る" << endl;
			if (scanf_s("%d", &number) == 0)
			{
				std::cout << "エラー" << "\n";
				cout << "文字が入力されました" << endl;
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
				cout << "指定していない数字が入りました" << endl;
			}
		}
		else if (number == 2)
		{
			if (list->Size() > 0)
			{
				int itr = 0;
				cout << "[順番を指定して要素を表示]" << endl;
				do
				{
					cout << "表示したい要素の番号を指定してください" << endl;

					if (scanf_s("%d", &itr) == 0)
					{
						std::cout << "エラー" << endl;
						cout << "文字が入力されました" << endl;
					}
					if (itr>list->Size()-1)
					{
						cout << "要素数以上の番号が入力されました" << endl;
					}
				} while (list->Size() < itr);

				list->print(itr);

				cout << "-----------------------------" << endl;
				cout << "1.要素の表示に戻る" << endl;
				cout << "2.要素の操作に戻る" << endl;

				if (scanf_s("%d", &number) == 0)
				{
					std::cout << "エラー" << "endl";
					cout << "文字が入力されました" << endl;
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
					cout << "指定していない数字が入力されました" << endl;
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
			cout << "文字が入力されました" << endl;
		}
	}
}

void CreateList(List* list)
{
	std::cout << "[リストの挿入]" << endl;
	if (list->Size() > 0)
	{
		std::cout << "要素を追加する場所を指定してください。最後尾に追加する場合は何も入力しないでください" << endl;
		int itr = fgetsInt();

		cout << "追加する値を入れてください" << endl;
		char newVal[16];
		scanf_s("%s", newVal, 16);

		int debug = list->Size();
		if (itr < 0)
		{
			list->push_back(newVal);
			std::cout << "最後尾に入力されます。" << endl;
			std::cout << "要素" << newVal << "が最後尾に挿入されました" << endl;
		}
		else
		{
			if (itr>=list->Size())
			{
				std::cout << itr << "が要素数以上なので最後尾に入ります" << endl;
				std::cout << "要素" << newVal << "が最後尾に挿入されました" << endl;
			}
			else
			{
				std::cout << "要素" << newVal << "が" << itr << "番に挿入されました" << endl;
			}
			list->create(itr, newVal);
		}
	}
	else
	{
		cout << "要素が0なので位置の入力はなし" << endl;
		cout << "挿入する値を入れてください" << endl;
		char newVal[16];
		scanf_s("%s", newVal, 16);
		list->push_back(newVal);
		std::cout << "要素\"" << newVal << "\"挿入されました" << endl;
	}
}

void DitList(List* list)
{
	cout << "[要素の編集]" << endl;
	cout << "編集したい要素の番号を入力してください" << endl;
	int itr = 0;
	if (scanf_s("%d", &itr)==0)
	{
		std::cout << "エラー" << "\n";
		cout << "文字が入力されました" << endl;
	}
	else if (itr > list->Size()-1 || itr < 0)
	{
		cout << itr << "番目は見つかりませんでした" << endl;
	}
	else
	{
		cout << itr << "番目の変更する値を入力してください" << endl;
		char newVal[16];
		scanf_s("%s", newVal, 16);
		list->Dit(itr, newVal);
		std::cout << itr << "番目の要素が\"" << newVal << "\"に変更されました" << endl;

	}
}

void DeleteList(List* list)
{
	cout << "[要素の要素]" << endl;
	cout << "削除したい要素の番号を指定してください。" << endl;
	int itr=0;
	if (scanf_s("%d", &itr) == 0)
	{
		std::cout << "エラー" << "\n";
		cout << "文字が入力されました" << endl;
	}
	else if(itr>list->Size()-1)
	{
		cout << itr << "番目は見つかりませんでした" << endl;
	}
	else
	{
		list->Delete(itr);
	}
}

int fgetsInt()
{
	int num;
	std::string insertNum;
	while (std::getchar() != '\n');

	std::getline(std::cin, insertNum);
	if (insertNum == "")
	{
		num = -1;
	}
	else
	{
		if (insertNum == "0")
		{
			num = 0;
		}
		else
		{
			num = std::atoi(insertNum.c_str());
			if (num == 0)
			{
				num = -1;
			}
		}
	}
	return num;
}