#include<iostream>
#include<algorithm>

using namespace std;

int binSearch(int* arr, int n, int target) {
	int start = 0;
	int end = n;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] == target)
			return 1;
		else {
			if (arr[mid] > target)
				end = mid - 1;
			else
				start = mid + 1;
		}
	}
	return 0;
}

int main(void)
{
	int n, m;
	cin >> n;
	int* card = new int[n];
	for (int i = 0; i < n; i++)
		cin >> card[i];

	cin >> m;
	int* exist = new int[m];
	for (int i = 0; i < m; i++)
		cin >> exist[i];

	sort(card, card + n);

	for (int i = 0; i < m; i++)
		cout << binSearch(card, n, exist[i]) << ' ';

	delete card;
	delete exist;
}