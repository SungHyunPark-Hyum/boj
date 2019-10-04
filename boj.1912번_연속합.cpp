//#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

//������ p119
//maxAt(i) = max(0, maxAt(i - 1)) + A[i];
//printf, scanf -> 8ms
//cin, cout     -> 20ms
//linear�ϰ� �о�� �Ǳ� ������ scanf�� �� ���� ������ ��
//-> ���ʿ��ϰ� for���� 2�� ����(vector�� iterator�� �����ϱ� ���Ե� ������..)

int Max2(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int main(void)
{
	int n;
	cin >> n;
	//scanf_s("%d", &n,sizeof(n));
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		//scanf_s("%d", &a, sizeof(a));
		v.push_back(a);
	}

	int max = v.at(0);
	int sum = 0;
	vector<int>::iterator itr;
	for (itr = v.begin(); itr != v.end(); itr++) {
		if (sum < 0)
			sum = 0;
		sum += *itr;
		max = Max2(sum, max);
	}
	cout << max;
	//printf("%d", max);
}