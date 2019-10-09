#include<iostream>

using namespace std;

int min2(int a, int b) {
	if (a < 0) {
		if (b < 0)
			return -1;
		else
			return b;
	}
	if (b < 0)
		return a;
	
	return a < b ? a : b;
}

int main(void)
{
	int n;
	cin >> n;
	int* arr = new int[5001];

	for (int i = 1; i < 6; i++) {
		if (i == 3 || i == 5)
			arr[i] = 1;
		else
			arr[i] = -1;
	}

	if(n > 5)
		for (int i = 6; i <= n; i++) {
			arr[i] = min2(arr[i - 3], arr[i - 5]) + 1;
			if (arr[i] == 0)
				arr[i] = -1;
		}
	cout << arr[n];

	delete arr;
}