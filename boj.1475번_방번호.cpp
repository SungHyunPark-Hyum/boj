#include<iostream>

using namespace std;

class Number
{
private :
	int arr[9] = { 0 };
	int num;
	int lnum;
public :
	Number(int n) : num(n)
	{
	}
	void getAns()
	{
		if (num == 0)
		{
			cout << 1;
			return;
		}

		while (num != 0)
		{
			lnum = num % 10;

			if ((lnum == 6) || (lnum == 9))
			{
				(arr[6])++;
			}
			else
			{
				(arr[lnum])++;
			}

			num = num / 10;
		}

		if ((arr[6] % 2) == 0)
			arr[6] = arr[6] / 2;
		else
			arr[6] = arr[6] / 2 + 1;

		int max = arr[0];
		for (int i = 0; i < 9; i++)
		{
			if (arr[i] > max)
				max = arr[i];
		}
		cout << max;
	}
};

int main(void)
{
	int n;
	cin >> n;
	Number number(n);
	number.getAns();
}