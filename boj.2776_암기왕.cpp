#include<iostream>
#include <algorithm>

using namespace std;

int binarySearch(int* arr, int note, int n) {
	int start = 0;
	int end = n;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] == note)
			return 1;
		else if (arr[mid] > note){
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return 0;
}

int main(void)
{
	int t, n, m;
	cin >> m;
	for (int j = 0; j < m; j++) {
		cin >> t;
		int* rem = new int[t];
		for (int i = 0; i < t; i++)
			cin >> rem[i];
		cin >> n;
		int* note = new int[n];
		for (int i = 0; i < n; i++)
			cin >> note[i];

		sort(rem, rem + t);

		for (int i = 0; i < n; i++) {
			cout << binarySearch(rem, note[i], n-1) << '\n';
		}
		delete rem;
		delete note;
	}
}