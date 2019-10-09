#include<iostream>
#include<set>

using namespace std;

int coin(set<int> s, int n, int k)
{
	int* arr = new int[k+1];
	for (int i = 0; i < k + 1; i++)
		arr[i] = 0;
	set<int>::iterator iter;

	for (iter = s.begin(); iter != s.end(); iter++) {
		arr[*iter]++;
		for (int i = *iter; i < k + 1; i++) {
			if (*iter > i)
				break;
			arr[i] += arr[i - *iter];
		}
	}
	return arr[k];
}

int main(void)
{
	int n, k;
	cin >> n >> k;
	
	set<int> s;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		s.insert(c);
	}
	int result = coin(s, n, k);
	cout << result;
}