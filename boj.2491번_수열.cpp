//�ѹ��� �������� ���ҿ� ������ ��� �˻��� �� �ְ� ¥�� �Ϳ� �����Ͽ�
//������ �ð��� �� �����ɸ�.
//��簡ó�� for���ȿ� ������ ������ �ְ� 2�� ������ ���� �ð������� �ξ� �̵�.
//(�ѹ��� �����ϴ� ������, �ٸ��ѹ��� �����ϴ� ������ �˻�)

#include<iostream>

using namespace std;

int Max2(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int flaging(int i1, int i2) {
	if (i2 > i1)
		return 1;
	else if (i2 < i1)
		return -1;
	else
		return 0;
}

int main(void)
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];


	if (n == 1) {
		int max = 1;
		cout << max;
	}
	else {
		int max = 2;
		int flag = flaging(arr[0], arr[1]);
		int before, now;
		int counter = 2;
		int seq_zero = 1;

		for (int i = 1; i < n-1; i++) {
			before = flaging(arr[i - 1], arr[i]);
			now = flaging(arr[i], arr[i + 1]);

			if ((flag == now) || (now == 0)) {
				if (flag == 0)
					flag = now;
				if ((before == 0) && (now == 0)) {
					seq_zero++;
				}
				else
					seq_zero = 1;
				counter++;
			}
			else {
				flag = now;
				max = Max2(counter, max);
				counter = 2;
				if (before == 0) {
					counter += seq_zero;
					seq_zero = 1;
				}
			}
		}
		max = Max2(counter, max);
		cout << max;
	}

	delete[] arr;
	return 0;
}