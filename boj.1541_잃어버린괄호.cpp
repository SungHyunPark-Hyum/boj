#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void)
{
	string str1;
	string str = "+";
	cin >> str1;

	str += str1;
	vector<int> vp;
	vector<int> vm;
	int start;
	int counter = 0;
	int flag = 0;
	for (int i = 0; i < str.length(); i++) {
		if (i == str.length() - 1) {
			string sub;
			sub = str.substr(start, counter);

			if (flag == 0)
				vp.push_back(stoi(sub));
			else
				vm.push_back(stoi(sub));
			break;
		}
		if (str.at(i + 1) == '+' || str.at(i + 1) == '-') {
			string sub;
			sub = str.substr(start, counter);

			if (flag == 0)
				vp.push_back(stoi(sub));
			else
				vm.push_back(stoi(sub));
			counter = 0;
		}
		else if (str.at(i) == '+' || str.at(i) == '-') {
			start = i + 1;
			counter++;
			if (flag == 0) {
				if (str.at(i) == '+') {

				}
				else {
					flag = 1;
				}
			}
			else {
				if (str.at(i) == '+') {

				}
				else {

				}
			}
		}
		else {
			counter++;
		}
	}
	vector<int>::iterator iter;
	int result = 0;
	for (iter = vp.begin(); iter != vp.end(); iter++) {
		result += *iter;
	}

	for (iter = vm.begin(); iter != vm.end(); iter++) {
		result -= *iter;
	}
	cout << result;
}