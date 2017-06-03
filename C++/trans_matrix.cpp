#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	int N, num;
	vector<vector<int>> matrix;
	vector<int> row;
	while(fin >> N)
	{
		matrix.clear();
		for(int i = 0; i < N; i++)
		{
			row.clear();
			for(int j = 0; j < N; j++)
			{
				fin >> num;
				row.push_back(num);
			}
			matrix.push_back(row);
		}
		
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}
		
		cout << endl;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				
				cout << matrix[j][i] << "\t";
			}
			cout << endl;
		}
	}
	
}