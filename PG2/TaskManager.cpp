#include "TaskManager.h"

std::list<Task> TaskManager::taskList;

void TaskManager::create(int id)
{
	Task newTask;

	for (ResponsibleParty x : ResponsiblePartyManager::responsiblePartyList)
	{
		if (x.id == id)
		{
			newTask.responsibleParty = x;
			break;
		}
	}

	newTask.id = taskList.size() + 1;

	std::cout << "�^�X�N�̃^�C�g���̐ݒ�";
	scanf_s("%s", &newTask.title, 16);

	std::cout << "�^�X�N�̓��e�̐ݒ�";
	scanf_s("%s", &newTask.content, 16);

	std::cout << "�D��x����͂��Ă�������";
	std::cout << "0.����";
	std::cout << "1.���";
	std::cout << "2.����";
	scanf_s("%d", &newTask.priority);

	std::cout << "�^�X�N�̊����̐ݒ�(8���̐����œ��͂��Ă�����������ɔN�����ɕϊ����܂�)";
	scanf_s("%d", &newTask.timeLimit);

	newTask.status = Status::InComplete;

	taskList.push_back(newTask);
}

void TaskManager::Update(int id)
{
	std::cout << "1.�S���҂̕ύX" << "%n";
	std::cout << "2.�^�C�g���̕ύX" << "%n";
	std::cout << "3.���e�̕ύX" << "%n";
	std::cout << "4.�D��x�̕ύX" << "%n";
	std::cout << "5.�����̕ύX" << "%n";
	std::cout << "6.�X�e�[�^�X�̕ύX" << "%n";
	int selection;
	do
	{
		if (scanf_s("%d", &selection) == 0)
		{
			std::cout << "�G���[";
			std::cout << "���������͂���܂���";
		}
	} while (selection <= 0 || selection >= 7);


	for (const Task& x : taskList)
	{
		if (x.id == id)
		{
			if (selection == 1)
			{

				break;
			}
			else if (selection == 2)
			{
				scanf_s("%s", &x.title, 16);
				break;
			}
			else if (selection == 3)
			{
				scanf_s("%s", &x.content, 16);
				break;
			}
			else if (selection == 4)
			{

				scanf_s("%d", &x.priority, 16);
				break;
			}
			else if (selection == 5)
			{
				scanf_s("%d", &x.timeLimit, 16);
				break;
			}
			else if (selection == 6)
			{
				scanf_s("%d", &x.status, 16);
				break;
			}
		}
	}
}

void TaskManager::Delete(int id)
{
}
