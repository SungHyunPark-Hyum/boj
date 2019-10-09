#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n, greater<int>());

	long long result = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < i)
			break;
		result += arr[i] - i;
	}
	cout << result;

	delete arr;
}