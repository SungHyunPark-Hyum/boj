#include<iostream>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int counter = n-1;
	int sum = 0;
	while (k != 0) {
		if (arr[counter] <= k) {
			k -= arr[counter];
			sum ++;
		}
		else
			counter--;
	}
	cout << sum;
}