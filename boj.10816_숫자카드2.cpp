#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int m;
	cin >> m;
	int* arr = new int[m];
	for (int i = 0; i < m; i++)
		cin >> arr[i];

	for (int i = 0; i < m; i++)
	{
		int result = upper_bound(v.begin(), v.end(), arr[i]) - lower_bound(v.begin(), v.end(), arr[i]);
		cout << result << ' ';
	}

	delete arr;
}