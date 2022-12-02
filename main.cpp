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
//�v�f�̕\��
void PrintList(List* list);

void CreateList(List* list);

void DitList(List* list);

void DeleteList(List* list);

int fgetsInt();

int main(void)
{
	//�擪�Z���̐錾
	List* list;
	list = new List();

	Scene scene;
	scene = Scene::Print;
	while (scene != Scene::final)
	{
		cout << "[�v�f�̑���]" << endl;
		cout << "1.�v�f�̕\��" << endl;
		cout << "2.�v�f�̑}��" << endl;
		if (list->Size() != 0)
		{
			cout << "3.�v�f�̕ҏW" << endl;
			cout << "4.�v�f�̍폜" << endl;
		}
		cout << endl;
		cout << "-----------------------------" << endl;
		cout << "�����I�����Ă�������" << endl;
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
			std::cout << "�G���[" << "\n";
			break;
		}
	}
	delete list;
	return 0;
}
void PrintList(List* list)
{
	while (true) {
		cout << "[�v�f�̕\��]" << endl;
		cout << "1.�v�f�̈ꗗ�\��" << endl;
		cout << "2.���Ԃ��w�肵�ėv�f��\��" << endl;
		cout << "9.�v�f����ɖ߂�" << endl;
		cout << endl;
		cout << "�����I�����Ă�������" << endl;
		int number = 0;
		if (scanf_s("%d", &number) == 0)
		{
			std::cout << "�G���[" << endl;
			cout << "���������͂���܂���" << endl;
		}
		else if (number == 1)
		{
			cout << "[�v�f�̈ꗗ�\��]" << endl;
			cout << "�v�f�̈ꗗ:{" << endl;
			list->index();
			cout << "}" << endl;
			cout << endl;
			cout << "�v�f��:";
			cout << list->Size() << endl;
			cout << endl;
			cout << "-----------------------------" << endl;
			cout << "1.�v�f�̕\���ɖ߂�" << endl;
			cout << "2.�v�f�̑���ɖ߂�" << endl;
			if (scanf_s("%d", &number) == 0)
			{
				std::cout << "�G���[" << "\n";
				cout << "���������͂���܂���" << endl;
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
				cout << "�w�肵�Ă��Ȃ�����������܂���" << endl;
			}
		}
		else if (number == 2)
		{
			if (list->Size() > 0)
			{
				int itr = 0;
				cout << "[���Ԃ��w�肵�ėv�f��\��]" << endl;
				do
				{
					cout << "�\���������v�f�̔ԍ����w�肵�Ă�������" << endl;

					if (scanf_s("%d", &itr) == 0)
					{
						std::cout << "�G���[" << endl;
						cout << "���������͂���܂���" << endl;
					}
					if (itr>list->Size()-1)
					{
						cout << "�v�f���ȏ�̔ԍ������͂���܂���" << endl;
					}
				} while (list->Size() < itr);

				list->print(itr);

				cout << "-----------------------------" << endl;
				cout << "1.�v�f�̕\���ɖ߂�" << endl;
				cout << "2.�v�f�̑���ɖ߂�" << endl;

				if (scanf_s("%d", &number) == 0)
				{
					std::cout << "�G���[" << "endl";
					cout << "���������͂���܂���" << endl;
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
					cout << "�w�肵�Ă��Ȃ����������͂���܂���" << endl;
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
			cout << "���������͂���܂���" << endl;
		}
	}
}

void CreateList(List* list)
{
	std::cout << "[���X�g�̑}��]" << endl;
	if (list->Size() > 0)
	{
		std::cout << "�v�f��ǉ�����ꏊ���w�肵�Ă��������B�Ō���ɒǉ�����ꍇ�͉������͂��Ȃ��ł�������" << endl;
		int itr = fgetsInt();

		cout << "�ǉ�����l�����Ă�������" << endl;
		char newVal[16];
		scanf_s("%s", newVal, 16);

		int debug = list->Size();
		if (itr < 0)
		{
			list->push_back(newVal);
			std::cout << "�Ō���ɓ��͂���܂��B" << endl;
			std::cout << "�v�f" << newVal << "���Ō���ɑ}������܂���" << endl;
		}
		else
		{
			if (itr>=list->Size())
			{
				std::cout << itr << "���v�f���ȏ�Ȃ̂ōŌ���ɓ���܂�" << endl;
				std::cout << "�v�f" << newVal << "���Ō���ɑ}������܂���" << endl;
			}
			else
			{
				std::cout << "�v�f" << newVal << "��" << itr << "�Ԃɑ}������܂���" << endl;
			}
			list->create(itr, newVal);
		}
	}
	else
	{
		cout << "�v�f��0�Ȃ̂ňʒu�̓��͂͂Ȃ�" << endl;
		cout << "�}������l�����Ă�������" << endl;
		char newVal[16];
		scanf_s("%s", newVal, 16);
		list->push_back(newVal);
		std::cout << "�v�f\"" << newVal << "\"�}������܂���" << endl;
	}
}

void DitList(List* list)
{
	cout << "[�v�f�̕ҏW]" << endl;
	cout << "�ҏW�������v�f�̔ԍ�����͂��Ă�������" << endl;
	int itr = 0;
	if (scanf_s("%d", &itr)==0)
	{
		std::cout << "�G���[" << "\n";
		cout << "���������͂���܂���" << endl;
	}
	else if (itr > list->Size()-1 || itr < 0)
	{
		cout << itr << "�Ԗڂ͌�����܂���ł���" << endl;
	}
	else
	{
		cout << itr << "�Ԗڂ̕ύX����l����͂��Ă�������" << endl;
		char newVal[16];
		scanf_s("%s", newVal, 16);
		list->Dit(itr, newVal);
		std::cout << itr << "�Ԗڂ̗v�f��\"" << newVal << "\"�ɕύX����܂���" << endl;

	}
}

void DeleteList(List* list)
{
	cout << "[�v�f�̗v�f]" << endl;
	cout << "�폜�������v�f�̔ԍ����w�肵�Ă��������B" << endl;
	int itr=0;
	if (scanf_s("%d", &itr) == 0)
	{
		std::cout << "�G���[" << "\n";
		cout << "���������͂���܂���" << endl;
	}
	else if(itr>list->Size()-1)
	{
		cout << itr << "�Ԗڂ͌�����܂���ł���" << endl;
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