#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string str;
	getline(cin, str);
	if (str == " ") {
		cout << 0;
		return 0;
	}
	int x = 0;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (str.at(i) == ' ')
			x++;
	}
	if (len > 1) {
		if (str.at(0) == ' ')
			x--;
		if (str.at(len - 1) == ' ')
			x--;
	}
	cout << x+1;
}