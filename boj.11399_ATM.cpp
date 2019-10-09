#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int sum = arr[0];
	if(n>1)
		for (int i = 1; i < n; i++) {
			arr[i] += arr[i - 1];
			sum += arr[i];
		}
	cout << sum;

	delete arr;
}