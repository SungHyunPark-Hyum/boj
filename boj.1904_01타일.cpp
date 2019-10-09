#include<iostream>

using namespace std;

int* dp;

int main(void)
{
	int n;
	cin >> n;
	dp = new int[n + 1];
	dp[0] = 1;
	dp[1] = 1;
	if (n > 1)
		dp[2] = 2;
	
	if (n > 2)
		for (int i = 3; i <= n; i++)
			dp[i] = (dp[i - 2] * 2 + dp[i - 3]) % 15746;

	cout << dp[n];

	delete dp;
}