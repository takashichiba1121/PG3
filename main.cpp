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
	//�擪�Z���̐錾
	List* list;
	list = new List();

	Scene scene;
	/*scanf_s("%d", &iterator);

	CELL* insertCell = getInswrtCellAddress(&head, iterator);*/

	////�Ō���ɃZ����ǉ�
	//create(insertCell, station);
	//for (int i = 0; i < 5; i++)
	//{
	//	scanf_s("%s", station, 16);
	//	list->push_back( station);
	//}
	//scanf_s("%s", station, 16);
	//list->create(3,station);
	//printf("\n");
	////���X�g�ꗗ�̕\��
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