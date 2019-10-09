#include<iostream>

using namespace std;

int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;

	int d = c - b;
	if (d <= 0) {
		cout << -1;
		return 0;
	}

	int counter = a / d;
	cout << counter + 1;
}