#include "ResponsiblePartyManager.h"

std::list<ResponsibleParty> ResponsiblePartyManager::responsiblePartyList;

void ResponsiblePartyManager::create()
{
	ResponsibleParty newResponsibleParty;


	newResponsibleParty.id = responsiblePartyList.size() + 1;

	std::cout <<"担当者の名前の設定";
	scanf_s("%s", &newResponsibleParty.name, 16);

	std::cout << "担当者のクラスの設定";
	scanf_s("%s", &newResponsibleParty.classification, 16);

	responsiblePartyList.push_back(newResponsibleParty);
}

void ResponsiblePartyManager::Update(int id)
{
	/*for (const ResponsibleParty& x:responsiblePartyList)
	{
		std::cout << x.id;
		std::cout << x.name;
		std::cout << x.classification;
		std::cout << "\n";

	}*/
	std::cout << "1.氏名の変更" << "%n";
	std::cout << "2.クラスの変更" << "%n";
	int selection;
	do
	{
		if (scanf_s("%d", &selection) == 0)
		{
			std::cout << "エラー";
			std::cout << "文字が入力されました";
		}
	} while (selection == 1 || selection == 2);


	for (const ResponsibleParty& x : responsiblePartyList)
	{
		if (x.id == id)
		{
			if (selection == 1)
			{
				scanf_s("%s",&x.name,16);
				break;
			}
			else if (selection == 2)
			{
				scanf_s("%s", &x.classification, 16);
				break;
			}
		}
	}
}

void ResponsiblePartyManager::Delete(int id)
{
	std::list<ResponsibleParty>::iterator itr;

	for (const ResponsibleParty& x : responsiblePartyList)
	{
		itr++;
		if (x.id == id)
		{
			responsiblePartyList.erase(itr);
			break;
		}
	}
}
