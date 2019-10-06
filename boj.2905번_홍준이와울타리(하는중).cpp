#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

int sum = 0;
int counting = 0;

struct segArr {
	int min;
	int start, end;
};

bool cmp(const segArr& a, const segArr& b) {
	if (a.min < b.min)
		return true;
	else if (a.min == b.min)
		return a.start < b.start;
	else
		return false;
}

//ĥ������ ���� �κ��� ����ϰ�, ĥ�� Ƚ���� ���������ִ� �Լ�
void counter(int start, int end, int* arr, int paint, int* arrPainted) {
	for (int i = start; i <= end; i++) {
		sum += (arr[i] - paint);
		arrPainted[i] = 1;
	}
	counting++;
}

void checkPainted(int& start, int& end, int* arrPainted) {
	while (arrPainted[start] != 1) {
		start++;
	}
	while (arrPainted[end] != 1) {
		end--;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, x;
	cin >> n >> x;
	int* arr = new int[n];
	int* arrPainted = new int[n];
	segArr* arrSorted = new segArr[n - x];

	for (int i = 0; i < n; i++) {
		arrPainted[i] = 0;
		cin >> arr[i];
	}

	sort(arrSorted, arrSorted + (n - x));

	deque<segArr> d;

	for (int i = 0; i < n; i++) {
		d.push_back(arrSorted[i]);
	}

	//ť���� �Ǿտ� �ִ� ���� ĥ�Ѵ�.
	//checkPainted�� �Ѵ�.
	//counter�� ������.
	//���� ���� �ִ� x�� pop_front�� �� ���̴�.
	//(�Ǿհ��� ������ pop_front, �ٸ��ٸ� stop)
	while (!d.empty()) {
		segArr tmp = d.front();
		d.pop_front();
		int min, start, end;
		min = tmp.min;
		start = tmp.start;
		end = tmp.end;
		checkPainted(start, end, arrPainted);
		counter(start, end, arr, min, arrPainted);

		int timer = 0;
		while (timer < x) {
			if (min == d.front().min)
				d.pop_front();
			else
				break;
			timer++;
		}
	}

	cout << sum << "\n" << counting;

	delete[] arr;
	delete[] arrPainted;
}