#include<iostream>
#include<string>

using namespace std;

class sum {
private :
	int result;
	string s;
public :
	sum(string s) {
		this->s = s;
		result = 0;
	}
	int calc() {
		for (int i = 0; i < s.length(); i++) {
			string s1 = s.substr(i, 1);
			result += stoi(s1);
		}
		return result;
	}
};

int main(void)
{
	int n;
	cin >> n;

	string s;
	cin >> s;

	sum *ss = new sum(s);
	cout << ss->calc();
	delete ss;
}