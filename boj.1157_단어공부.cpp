#include<iostream>
#include<string>

using namespace std;


int main(void)
{
	string s;
	cin >> s;
	
	//65~91, 97~123
	int* arr = new int[124];
	for (int i = 65; i < 124; i++)
		arr[i] = 0;

	for (int i = 0; i < s.length(); i++) {
		arr[s.at(i)]++;
	}
	for (int i = 65; i < 92; i++) {
		arr[i] += arr[i + 32];
	}
	char max1 = 65;
	int count = arr[65];
	char max2 = NULL;
	int count2 = -1;
	for (int i = 66; i < 92; i++) {
		if (arr[i] > count) {
			max1 = i;
			count = arr[i];
		}
		else if (arr[i] == count)
		{
			max2 = i;
			count2 = arr[i];
		}
	}

	if (count == count2)
		cout << '?';
	else
		cout << max1;
}
