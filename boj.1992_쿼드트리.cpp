#include<iostream>
#include<cstdio>

using namespace std;

int** arr;

int puzzle(int v1, int v2, int v3, int v4) {
	int flag = arr[v1][v3];
	if (v1 == v2 || v3 == v4)
		return flag;
	for (int i = v1; i <= v2; i++)
		for (int j = v3; j <= v4; j++) {
			if (arr[i][j] != flag)
				return -1;
		}
	return flag;
}

void divide(int v1, int v2, int v3, int v4) {
	int p = puzzle(v1, v2, v3, v4);
	if (p == 0) {
		cout << 0;
	}
	else if (p == 1) {
		cout << 1;
	}
	//�ɰ���
	else {
		cout << '(';
		divide(v1, (v1 + v2) / 2, v3, (v3 + v4) / 2);
		divide(v1, (v1 + v2) / 2, (v3 + v4) / 2 + 1, v4);
		divide((v1 + v2) / 2 + 1, v2, v3, (v3 + v4) / 2);
		divide((v1 + v2) / 2 + 1, v2, (v3 + v4) / 2 + 1, v4);
		cout << ')';
	}
}

int main(void)
{
	//���0, ������1
	int n;
	cin >> n;
	arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%1d", &arr[i][j]);
		}
	}

	divide(0, n-1, 0, n - 1);
}