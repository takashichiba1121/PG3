#include<iostream>
#include<stdlib.h>
#include"list.h"
enum class Scene
{
	Menu,
	Print,
	Dit,
	Create,
	Delete,
	final
};

int main(void)
{
	char station[16];
	//先頭セルの宣言
	List* list;
	list = new List();

	Scene scene;
	/*scanf_s("%d", &iterator);

	CELL* insertCell = getInswrtCellAddress(&head, iterator);*/

	////最後尾にセルを追加
	//create(insertCell, station);
	//for (int i = 0; i < 5; i++)
	//{
	//	scanf_s("%s", station, 16);
	//	list->push_back( station);
	//}
	//scanf_s("%s", station, 16);
	//list->create(3,station);
	//printf("\n");
	////リスト一覧の表示
	//list->index();
	while (true)
	{
		switch (scene)
		{
		case Scene::Menu:

			break;
		case Scene::Print:
			break;
		case Scene::Dit:
			break;
		case Scene::Create:
			break;
		case Scene::Delete:
			break;
		case Scene::final:
			break;
		}
	}

	delete list;
	return 0;
}