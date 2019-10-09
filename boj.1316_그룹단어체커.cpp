#include<iostream>
#include<string>
#include<queue>

using namespace std;

int group(string str) {
	char c[124] = { 0, };
	for (int i = 0; i < str.length(); i++) {
		if (c[str.at(i)] == 0) {
			c[str.at(i)] = 1;
		}
		else {
			if (str.at(i - 1) == str.at(i)) {}
			else return 0;
		}
	}
	return 1;
}

int main(void)
{
	int n, counter=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		counter += group(str);
	}
	cout << counter;
}