#include<iostream>

using namespace std;

int main(void)
{
	int n, m1, m2, k;
	cin >> n >> m1;
	int** h1;
	int** h2;

	h1 = new int* [n];
	for (int i = 0; i < n; i++)
		h1[i] = new int[m1];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m1; j++)
			cin >> h1[i][j];

	cin >> m2 >> k;
	h2 = new int* [m2];
	for (int i = 0; i < m2; i++)
		h2[i] = new int[k];

	for (int i = 0; i < m2; i++)
		for (int j = 0; j < k; j++)
			cin >> h2[i][j];

	int** result;
	result = new int* [n];
	for (int i = 0; i < n; i++)
		result[i] = new int[k];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			result[i][j] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int k = 0; k < m2; k++) {
				result[i][j] += h1[i][k] * h2[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++)
			cout << result[i][j] << ' ';
		cout << '\n';
	}

	for (int i = 0; i < n; i++)
		delete result[i];
	delete result;

	for (int i = 0; i < n; i++)
		delete h1[i];
	delete h1;

	for (int i = 0; i < m2; i++)
		delete h2[i];
	delete h2;
}