#include<iostream>

using namespace std;

int** arr;
int* result;

int puzzle(int v1, int v2, int v3, int v4) {
	int flag = arr[v1][v3];
	if (v1 == v2 || v3 == v4)
		return flag;
	for (int i = v1; i <= v2; i++)
		for (int j = v3; j <= v4; j++) {
			if (arr[i][j] != flag)
				return -2;
		}
	return flag;
}

void divide(int v1, int v2, int v3, int v4) {
	int p = puzzle(v1, v2, v3, v4);
	if (p == -1) {
		result[0]++;;
	}
	else if (p == 0) {
		result[1]++;
	}
	else if (p == 1) {
		result[2]++;
	}
	//ÂÉ°³±â
	else {
		int mo = (v2 - v1) / 3 + 1;
		divide(v1, v1 + mo - 1, v3, v3 + mo -1);
		divide(v1 + mo, v1 + mo * 2 - 1, v3, v3 + mo - 1);
		divide(v1 + mo * 2, v1 + mo * 3 - 1, v3, v3 + mo - 1);
		divide(v1, v1 + mo - 1, v3 + mo, v3 + mo * 2 -1);
		divide(v1 + mo, v1 + mo * 2 -1, v3 + mo, v3 + mo * 2 - 1);
		divide(v1 + mo * 2, v1 + mo * 3 - 1, v3 + mo, v3 + mo * 2 - 1);
		divide(v1, v1 + mo - 1, v3 + mo * 2, v3 + mo * 3 - 1);
		divide(v1 + mo, v1 + mo * 2 - 1, v3 + mo * 2, v3 + mo * 3 - 1);
		divide(v1 + mo * 2, v1 + mo * 3 - 1, v3 + mo * 2, v3 + mo * 3 - 1);
	}
}

int main(void)
{
	int n;
	cin >> n;

	result = new int[3];
	for (int i = 0; i < 3; i++)
		result[i] = 0;

	arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	divide(0, n - 1, 0, n - 1);

	for (int i = 0; i < 3; i++) {
		cout << result[i];
		if(i != 2)
			cout << endl;
	}

	delete(result);
	for (int i = 0; i < n; i++)
		delete arr[i];
	delete arr;
}