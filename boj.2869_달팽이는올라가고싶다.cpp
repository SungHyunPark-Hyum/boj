#include<iostream>
#include<algorithm>

using namespace std;

bool possible(int day, int one, int a, int v) {
	int result = v - day * one;
	if (result - a <= 0)
		return true;
	return false;
}

int main(void)
{
	int a, b, v;
	cin >> a >> b >> v;
	int min = v;
	int one = a - b;

	int left = 1, right = v / (a - b);
	if (a == v) {
		cout << 1;
		return 0;
	}
	while (left <= right) {
		int mid = (left + right) / 2;
		if (possible(mid, one, a, v)) {
			right = mid - 1;
			if (min > mid)
				min = mid;
		}
		else
			left = mid + 1;
	}
	cout << min+1;
}