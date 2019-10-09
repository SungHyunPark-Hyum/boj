#include<iostream>
#include<string>

using namespace std;

class Chess
{
private :
	char** chessboard;
	int counter;
	int row;
	int column;
public :
	Chess(int row, int column) : counter(0), row(row), column(column)
	{
		chessboard = new char*[row];
		for (int i = 0; i < row; i++)
			chessboard[i] = new char[column];
		this->row = 0;
	}
	void getChessBoard(string str)
	{
		for (int j = 0; j < column; j++)
		{
			chessboard[row][j] = str[j];
		}
		row++;
	}
	void checkChessBoard()
	{
		for (int j = 0; j < row; j+=2)
		{
			for (int i = 0; i < column; i+=2)
			{
				if (chessboard[j][i] == 'F')
					counter++;
			}
		}
		for (int j = 1; j < row; j += 2)
		{
			for (int i = 1; i < column; i += 2)
			{
				if (chessboard[j][i] == 'F')
					counter++;
			}
		}
		cout << counter;

		for (int i = 0; i < row; i++)
			delete[] chessboard[i];
		delete[] chessboard;
	}
};

int main(void)
{
	Chess chess(9, 9);
	for (int i = 0; i < 8; i++)
	{
		string str;
		cin >> str;
		chess.getChessBoard(str);
	}
	chess.checkChessBoard();
}