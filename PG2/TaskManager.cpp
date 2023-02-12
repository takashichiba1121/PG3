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

	std::cout << "タスクのタイトルの設定";
	scanf_s("%s", &newTask.title, 16);

	std::cout << "タスクの内容の設定";
	scanf_s("%s", &newTask.content, 16);

	std::cout << "優先度を入力してください";
	std::cout << "0.普通";
	std::cout << "1.低め";
	std::cout << "2.高い";
	scanf_s("%d", &newTask.priority);

	std::cout << "タスクの期限の設定(8桁の数字で入力してください勝手に年月日に変換します)";
	scanf_s("%d", &newTask.timeLimit);

	newTask.status = Status::InComplete;

	taskList.push_back(newTask);
}

void TaskManager::Update(int id)
{
	std::cout << "1.担当者の変更" << "%n";
	std::cout << "2.タイトルの変更" << "%n";
	std::cout << "3.内容の変更" << "%n";
	std::cout << "4.優先度の変更" << "%n";
	std::cout << "5.期限の変更" << "%n";
	std::cout << "6.ステータスの変更" << "%n";
	int selection;
	do
	{
		if (scanf_s("%d", &selection) == 0)
		{
			std::cout << "エラー";
			std::cout << "文字が入力されました";
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
