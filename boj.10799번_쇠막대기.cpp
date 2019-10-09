#include<iostream>
#include<stack>
#include<string>

using namespace std;

class Pipe
{
private :
	int len;
	string str;
	stack<char> st;
	int sum;
public : 
	Pipe(string str) : str(str), sum(0)
	{
		len = str.length();
	}
	void func()
	{
		for (int i = 0; i < len; i++)
		{
			if (str[i] == '(')
			{
				st.push(str[i]);
			}
			else if(str[i] == ')')
			{
				st.pop();
				if (str[i - 1] == '(')
				{
					sum += st.size();
				}
				else if (str[i - 1] == ')')
				{
					sum++;
				}
			}
		}
	}
	void showAns()
	{
		cout << sum;
	}
};

int main(void)
{
	string str;
	cin >> str;
	Pipe pipe(str);
	pipe.func();
	pipe.showAns();
}