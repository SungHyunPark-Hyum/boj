#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int* arrA = new int[n];
	int* arrB = new int[n];
	int* arrC = new int[n];
	int* arrD = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arrA[i] >> arrB[i] >> arrC[i] >> arrD[i];

	long long* arrAB = new long long[n * n];
	long long* arrCD = new long long[n * n];
	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			arrAB[i * n + j] = arrA[i] + arrB[j];
			arrCD[i * n + j] = arrC[i] + arrD[j];
		}

	delete arrA;
	delete arrB;
	delete arrC;
	delete arrD;

	sort(arrCD, arrCD + n * n);

	long long count = 0;
	for (int i = 0; i < n * n; i++) {
		long long* low = lower_bound(arrCD, arrCD + n * n, -arrAB[i]);
		long long* high = upper_bound(arrCD, arrCD + n * n, -arrAB[i]);
		while (low != high) {
			count++;
			low++;
		}
	}

	cout << count;
	delete arrAB;
	delete arrCD;
}