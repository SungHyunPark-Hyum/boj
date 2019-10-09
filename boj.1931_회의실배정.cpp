#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main(void)
{
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(pair<int, int>(a, b));
	}

	sort(v.begin(), v.end(), compare);
	
	vector<pair<int, int>>::iterator iter;
	int end = v.begin()->second;
	int counter = 1;
	for (iter = v.begin()+1; iter != v.end(); iter++) {
		if (iter->first >= end) {
			counter++;
			end = iter->second;
		}
	}
	cout << counter;
}

// 시간초과 코드
//int main(void)
//{
//	int n;
//	cin >> n;
//	set<pair<int, int>> s;
//	for (int i = 0; i < n; i++) {
//		int a, b;
//		cin >> a >> b;
//		s.insert({ a, b });
//	}
//
//	set<pair<int, int>>::iterator iter;
//	int max = 0;
//	for (iter = s.begin(); iter != s.end(); iter++) {
//		int counter = 1;
//		int start = iter->first;
//		int end = iter->second;
//		set<pair<int, int>>::iterator spin;
//		for (spin = iter; spin != s.end(); spin++) {
//			if (spin->first >= end) {
//				int end1 = spin->second;
//				while (spin->first >= end1)
//					spin++;
//				counter++;
//				end = spin->second;
//			}
//		}
//		if (counter > max)
//			max = counter;
//	}
//
//	cout << max;
//}
