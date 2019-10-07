#include<iostream>
#include<string>

using namespace std;

class CMD
{
private :
	int counter;
	int slen;
	string s1;
	string s2;
public :
	CMD(string str) : s1(str)
	{
		counter = 0;
		slen = s1.length();
	}
	void Checker(string second)
	{
		s2 = second;
		for (int i = 0; i < slen; i++)
		{
			if (s1[i] != s2[i])
				s1[i] = '?';
		}
	}
	void showAns()
	{
		cout << s1;
	}
};

int main(void)
{
	int t;
	cin >> t;

	string s1;
	cin >> s1;
	CMD cmd(s1);

	for (int i = 1; i < t; i++)
	{
		string str;
		cin >> str;
		cmd.Checker(str);
	}
	cmd.showAns();
}