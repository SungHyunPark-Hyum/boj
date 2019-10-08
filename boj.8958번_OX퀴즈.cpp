#include<iostream>
#include<stack>
#include<string>

using namespace std;

class Quiz
{
private :
	string str;
	int sum, counter;
public :
	Quiz(const string str) : str(str), sum(0), counter(0)
	{

	}
	void getAns()
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == 'O')
			{
				counter++;
				sum += counter;
			}
			else
			{
				counter = 0;
			}
		}
		cout << sum << endl;
	}
};

int main(void)
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string str;
		cin >> str;
		Quiz quiz(str);
		quiz.getAns();
	}
}