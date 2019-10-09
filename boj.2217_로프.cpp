#include<iostream>
#include<algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main(void)
{
	int n, w;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++) {
		arr[i] *= (i+1);
	}

	int max = arr[0];
	if(n>1)
		for (int i = 1; i < n; i++) {
			if (max < arr[i])
				max = arr[i];
		}
	cout << max;
}