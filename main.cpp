#include<iostream>
#include<list>
#include<vector>

using namespace std;

vector<char> GetVectorChar(const char* str)
{
	vector<char> VectorStr;

	int i = 0;
	while (str[i] != '\0') {
		VectorStr.push_back(str[i]);
		i++;
	}

	return VectorStr;
}

int main(void)
{
	list<vector<char>> YamanoteLine;
	YamanoteLine.push_back(GetVectorChar("Toukyou"));
	YamanoteLine.push_back(GetVectorChar("Yurakucho"));
	YamanoteLine.push_back(GetVectorChar("Shimbashi"));
	YamanoteLine.push_back(GetVectorChar("Hamamatsucho"));
	YamanoteLine.push_back(GetVectorChar("Tamachi"));
	YamanoteLine.push_back(GetVectorChar("Shinagawa"));
	YamanoteLine.push_back(GetVectorChar("Osaki"));
	YamanoteLine.push_back(GetVectorChar("Gotanda"));
	YamanoteLine.push_back(GetVectorChar("Meguro"));
	YamanoteLine.push_back(GetVectorChar("Ebisu"));
	YamanoteLine.push_back(GetVectorChar("Shibuya"));
	YamanoteLine.push_back(GetVectorChar("Harajuku"));
	YamanoteLine.push_back(GetVectorChar("Yoyogi"));
	YamanoteLine.push_back(GetVectorChar("Shinjuku"));
	YamanoteLine.push_back(GetVectorChar("Shin-Okubo"));
	YamanoteLine.push_back(GetVectorChar("Takadanobaba"));
	YamanoteLine.push_back(GetVectorChar("Mejiro"));
	YamanoteLine.push_back(GetVectorChar("Ikebukuro"));
	YamanoteLine.push_back(GetVectorChar("Otsuka"));
	YamanoteLine.push_back(GetVectorChar("Sugamo"));
	YamanoteLine.push_back(GetVectorChar("Komagome"));
	YamanoteLine.push_back(GetVectorChar("Tabata"));
	YamanoteLine.push_back(GetVectorChar("Nippori"));
	YamanoteLine.push_back(GetVectorChar("Uguisudani"));
	YamanoteLine.push_back(GetVectorChar("Ueno"));
	YamanoteLine.push_back(GetVectorChar("Okachimachi"));
	YamanoteLine.push_back(GetVectorChar("Akihabara"));
	YamanoteLine.push_back(GetVectorChar("Kanda"));

	cout << 1970 << endl;

	for (list<vector<char>>::iterator itr=YamanoteLine.begin(); itr != YamanoteLine.end();itr++)
	{
		vector<char> str = *itr;

		for (vector<char>::iterator it_f = str.begin(); it_f != str.end();it_f++) {
			cout << *it_f;
		}
		cout << endl;
	}
	cout << endl;
	cout << 2020 << endl;

	for (list<vector<char>>::iterator itr = YamanoteLine.begin(); itr != YamanoteLine.end(); itr++)
	{
		if (*itr == GetVectorChar("Nippori"))
		{
			YamanoteLine.insert(itr,GetVectorChar("Nisi-nippori"));
			break;
		}
	}

	for (list<vector<char>>::iterator itr = YamanoteLine.begin(); itr != YamanoteLine.end(); itr++)
	{
		vector<char> str = *itr;

		for (vector<char>::iterator it_f = str.begin(); it_f != str.end(); it_f++) {
			cout << *it_f;
		}
		cout << endl;
	}

	cout << endl;
	cout << 2022 << endl;

	for (list<vector<char>>::iterator itr = YamanoteLine.begin(); itr != YamanoteLine.end(); itr++)
	{
		if (*itr == GetVectorChar("Shinagawa"))
		{
			YamanoteLine.insert(itr, GetVectorChar("TakanawaGateway"));
			break;
		}
	}

	for (list<vector<char>>::iterator itr = YamanoteLine.begin(); itr != YamanoteLine.end(); itr++)
	{
		vector<char> str = *itr;

		for (vector<char>::iterator it_f = str.begin(); it_f != str.end(); it_f++) {
			cout << *it_f;
		}
		cout << endl;
	}

	return 0;
}