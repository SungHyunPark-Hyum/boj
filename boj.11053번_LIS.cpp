#include<iostream>

//nlong(n) 방법 나중에 생각해 볼것!

using namespace std;

int Max2(int a, int b) {
	return a > b ? a : b;
}

int main(void)
{
	int n;
	cin >> n;
	int* arr = new int[n + 1];
	int* dp = new int[n + 1];


	dp[0] = 1;

	int max = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		int tmp = 0;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (tmp < dp[j])
					tmp = dp[j];
			}
		}
		dp[i] = tmp + 1;
		if (dp[i] > max)
			max = dp[i];
	}
	cout << max;
	delete[] arr;
	delete[] dp;
}