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
//�v�f�̕\��
bool PrintList(List* list);

int main(void)
{
	char station[16];
	//�擪�Z���̐錾
	List* list;
	list = new List();

	Scene scene;
	scene = Scene::Print;

	int number = 0;
	while (scene != Scene::final)
	{
		cout << "[�v�f�̑���]" << endl;
		cout << "1.�v�f�̕\��" << endl;
		cout << "2.�v�f�̑}��" << endl;
		if (list->Get() != 0)
		{
			cout << "3.�v�f�̕ҏW" << endl;
			cout << "4.�v�f�̍폜" << endl;
		}
		cout << endl;
		cout << "-----------------------------" << endl;
		cout << "�����I�����Ă�������(��̔ԍ��ȊO����ѕ�������ꂽ�ꍇ�͑����s�I�����܂�)" << endl;
		if (scanf_s("%d", &scene) == 0)
		{
			std::cout << "�G���[" << "\n";
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
			std::cout << "�G���[" << "\n";
			break;
		}
	}
	delete list;
	return 0;
}
bool PrintList(List* list)
{
	while (true) {
		cout << "[�v�f�̕\��]" << endl;
		cout << "1.�v�f�̈ꗗ�\��" << endl;
		cout << "2.���Ԃ��w�肵�ėv�f��\��" << endl;
		cout << "9.�v�f����ɖ߂�" << endl;
		cout << endl;
		cout << "�����I�����Ă�������(��̔ԍ��ȊO����ѕ�������ꂽ�ꍇ�͑����s�I�����܂�)" << endl;
		int number = 0;
		if (scanf_s("%d", &number) == 0)
		{
			std::cout << "�G���[" << "\n";
			return false;
		}
		else if (number == 1)
		{
			cout << "[�v�f�̈ꗗ�\��]" << endl;
			cout << "�v�f�̈ꗗ:{" << endl;
			list->index();
			cout << "}" << endl;
			cout << endl;
			cout << "�v�f��:";
			cout << list->Get() << endl;
			cout << endl;
			cout << "-----------------------------" << endl;
			cout << "1.�v�f�̕\���ɖ߂�" << endl;
			cout << "2.�v�f�̑���ɖ߂�" << endl;
			if (scanf_s("%d", &number) == 0)
			{
				std::cout << "�G���[" << "\n";
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
				std::cout << "�G���[" << "\n";
				return false;
			}
		}
		else if (number == 2)
		{
			if (list->Get()>0)
			{
				int itr = 0;
				cout << "[���Ԃ��w�肵�ėv�f��\��]" << endl;
				do
				{
					cout << "�\���������v�f�̔ԍ����w�肵�Ă�������" << endl;

					if (scanf_s("%d", &itr) == 0)
					{
						std::cout << "�G���[" << "\n";
						return false;
					}
					if (list->Get() < itr)
					{
						cout << "�v�f���ȏ�̔ԍ������͂���܂���" << endl;
					}
				} while (list->Get() < itr);

				list->print(itr);

				cout << "-----------------------------" << endl;
				cout << "1.�v�f�̕\���ɖ߂�" << endl;
				cout << "2.�v�f�̑���ɖ߂�" << endl;

				if (scanf_s("%d", &number) == 0)
				{
					std::cout << "�G���[" << "\n";
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
					std::cout << "�G���[" << "\n";
					return false;
				}
			}
			else
			{
				cout << endl;
				cout << "�v�f����0�ł��B" << endl;
				cout << endl;
			}
		}
		else if (number == 9)
		{
			break;
		}
		else
		{
			std::cout << "�G���[" << "\n";
			return false;
		}
	}
	return true;
}