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
public://�X�^�e�B�b�N�����o�ϐ�
	static std::list<ResponsibleParty> responsiblePartyList;
public://�X�^�e�B�b�N�����o�֐�
	void create();

	void Update(int id);

	void Delete(int id);

};

