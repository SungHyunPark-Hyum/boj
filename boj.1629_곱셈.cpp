#include<iostream>

using namespace std;

//LL power(LL A, LL B, LL C) {
//	if (B == 0)
//		return 1;
//	if (B == 1)
//		return A % C;
//	LL tmp = power(A, B / 2, C);
//	if (B % 2 == 0)
//		return (tmp * tmp) % C;
//	else
//		return (((tmp * tmp) % C) * A) % C;
//}

long long pow(long long a, long long b, long long c) {
	long long ans = 1;
	while (b > 0) {
		if (b % 2) {
			ans *= a;
			ans %= c;
		}
		a *= a;
		a %= c;
		b /= 2;
	}
	return ans;
}

int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;

	cout << pow(a, b, c);
}