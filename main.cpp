#include<iostream>
#include<list>
#include<vector>

using namespace std;

int main(void)
{

	list<const char*> YamanoteLine;
	YamanoteLine.push_back("Toukyou");
	YamanoteLine.push_back("Yurakucho");
	YamanoteLine.push_back("Shimbashi");
	YamanoteLine.push_back("Hamamatsucho");
	YamanoteLine.push_back("Tamachi");
	YamanoteLine.push_back("Shinagawa");
	YamanoteLine.push_back("Osaki");
	YamanoteLine.push_back("Gotanda");
	YamanoteLine.push_back("Meguro");
	YamanoteLine.push_back("Ebisu");
	YamanoteLine.push_back("Shibuya");
	YamanoteLine.push_back("Harajuku");
	YamanoteLine.push_back("Yoyogi");
	YamanoteLine.push_back("Shinjuku");
	YamanoteLine.push_back("Shin-Okubo");
	YamanoteLine.push_back("Takadanobaba");
	YamanoteLine.push_back("Mejiro");
	YamanoteLine.push_back("Ikebukuro");
	YamanoteLine.push_back("Otsuka");
	YamanoteLine.push_back("Sugamo");
	YamanoteLine.push_back("Komagome");
	YamanoteLine.push_back("Tabata");
	YamanoteLine.push_back("Nippori");
	YamanoteLine.push_back("Uguisudani");
	YamanoteLine.push_back("Ueno");
	YamanoteLine.push_back("Okachimachi");
	YamanoteLine.push_back("Akihabara");
	YamanoteLine.push_back("Kanda");

	cout << 1970 << endl;

	for (list<const char*>::iterator itr = YamanoteLine.begin(); itr != YamanoteLine.end(); itr++)
	{
			cout << *itr << endl;
	}
	cout << endl;
	cout << 2020 << endl;

	for (list<const char*>::iterator itr = YamanoteLine.begin(); itr != YamanoteLine.end(); itr++)
	{
		if (*itr == "Nippori")
		{
			YamanoteLine.insert(itr, "Nisi-nippori");
			break;
		}
	}

	for (list<const char*>::iterator itr = YamanoteLine.begin(); itr != YamanoteLine.end(); itr++)
	{
		
			cout << *itr<<endl;
	}

	cout << endl;
	cout << 2022 << endl;

	for (list<const char*>::iterator itr = YamanoteLine.begin(); itr != YamanoteLine.end(); itr++)
	{
		if (*itr == "Shinagawa")
		{
			YamanoteLine.insert(itr, "TakanawaGateway");
			break;
		}
	}

	for (list<const char*>::iterator itr = YamanoteLine.begin(); itr != YamanoteLine.end(); itr++)
	{
			cout << *itr<<endl;
	}

	return 0;
}