#pragma once
#include<iostream>
#include<string>
#include<stdlib.h>
#include<list>
struct ResponsibleParty
{
	int id;
	std::string name;
	std::string classification;
};
class ResponsiblePartyManager
{
public://スタティックメンバ変数
	static std::list<ResponsibleParty> responsiblePartyList;
public://スタティックメンバ関数
	void create();

	void Update(int id);

	void Delete(int id);

};

