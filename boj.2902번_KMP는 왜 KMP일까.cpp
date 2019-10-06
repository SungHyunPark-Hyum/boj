#include<iostream>
#include<string>

using namespace std;

class KMP
{
private :
	string longstr;
	string shortstr;
public :
	KMP(string str) : longstr(str)
	{}
	void Changer()
	{
		shortstr = longstr[0];
		for (int i = 1; i < longstr.length(); i++)
		{
			if (longstr[i - 1] == '-')
				shortstr.push_back(longstr[i]);
		}
		cout << shortstr;
	}
};

int main(void)
{
	string str;
	cin >> str;
	KMP kmp(str);
	kmp.Changer();
}