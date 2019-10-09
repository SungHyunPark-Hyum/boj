#include<iostream>
#include<string>

using namespace std;

int* alph(string s) {
	char a = 'a';
	int* arr = new int[26];
	int i = 0;
	for (a; a < 'z' + 1; a++) {
		int index = s.find(a);
		arr[i++] = index;
	}
	return arr;
}

int main(void)
{
	string s;
	cin >> s;
	int* arr = new int[26];
	arr = alph(s);
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}
	delete arr;
}