#include<iostream>

using namespace std;

int max2(int a, int b) {
	return a > b ? a : b;
}

int max3(int a, int b, int c) {
	int max = a > b ? a : b;
	return max > c ? max : c;
}

int main(void)
{
	int n;
	cin >> n;
	int* arr = new int[n];
	int* result = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	result[0] = arr[0];
	if (n > 1)
		result[1] = result[0] + arr[1];
	if(n>2)
		result[2] = max3(result[0] + arr[2], result[1], arr[1] + arr[2]);
	if(n>3)
		for (int i = 3; i < n; i++) {
			result[i] = max3(result[i-2]+arr[i], result[i-3] +arr[i-1] + arr[i], result[i-1]);
		}
	cout << result[n - 1];
}