#include<iostream>

using namespace std;

int** arr;
int* cnt;

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
		cnt[0]++;
	}
	else if (p == 1) {
		cnt[1]++;
	}
	//ÂÉ°³±â
	else {
		divide(v1, (v1 + v2) / 2, v3, (v3 + v4) / 2);
		divide(v1, (v1 + v2) / 2, (v3 + v4) / 2 + 1, v4);
		divide((v1 + v2) / 2 + 1, v2, v3, (v3 + v4) / 2);
		divide((v1 + v2) / 2 + 1, v2, (v3 + v4) / 2 + 1, v4);
	}
}

int main(void)
{
	int n;
	cin >> n;
	arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}

	cnt = new int[2];
	cnt[0] = cnt[1] = 0;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}


	divide(0, n-1, 0, n-1);
	cout << cnt[0] << endl << cnt[1];
}