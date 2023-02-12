#pragma once
#include"ResponsiblePartyManager.h"
enum class Priority
{
	Normal,
	Lower,
	Higher,
};
enum class Status
{
	Completion,
	InComplete,
};
struct Task
{
	int id;
	ResponsibleParty responsibleParty;
	std::string title;
	std::string content;
	Priority priority;
	int timeLimit;
	Status status;
	
};
class TaskManager
{
	static std::list<Task> taskList;

	void create(int id);

	void Update(int id);

	void Delete(int id);
};

