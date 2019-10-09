#include<iostream>
#include<algorithm>

using namespace std;


int main(void)
{
	int n, m;
	cin >> n >> m;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	long long left = 0, right = arr[n - 1];
	int start = 0, end = n - 1;
	long long max = 0;
	while (left <= right) {
		long long  mid = (left + right) / 2;
		long long imsi = 0;
		for (int i = end; i >= start; i--) {
			if (arr[i] - mid <= 0) {
				break;
			}
			imsi += arr[i] - mid;
		}
		if (imsi < m)
			right = mid - 1;
		if (imsi >= m) {
			left = mid + 1;
			if(mid >= max)
				max = mid;
		}
	}
	cout << max;

	delete arr;
}