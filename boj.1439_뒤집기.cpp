#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string str;
	cin >> str;
	if (str.length() == 1) {
		cout << 0;
		return 0;
	}
	char flag = str.at(0);
	int hh;
	if (flag == '0')
		hh = 0;
	else
		hh = 1;
	int c[2] = { 0,0 };
	c[hh]++;
	for (int i = 0 ; i < str.length(); i++) {
		if (str.at(i) != flag) {
			flag = str.at(i); 
			if (flag == '0')
				hh = 0;
			else
				hh = 1;
			c[hh]++;
		}
	}
	cout << (c[0] < c[1] ? c[0] : c[1]);
}