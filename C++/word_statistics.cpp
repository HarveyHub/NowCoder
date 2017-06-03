#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct WordIndex
{
	char value;
	vector<int> index;
};

int main()
{
	vector<WordIndex> result;
	ifstream fin("word_statistics.txt");
	string line;
	int length;
	bool flag;
	WordIndex newWord;
	while(fin >> line)
	{
		length = line.size();
		// cout << "line's length: " << length << endl;
		for(int i = 0; i <length; i++)
		{
			
			flag = false;
			for(auto iter = result.begin(); iter != result.end(); iter++)
			{	
				if(iter->value == line[i])
				{
					iter->index.push_back(i);	
					flag = true;
				}
			}
			if(!flag)
			{
				newWord.value = line[i];
				newWord.index.push_back(i);
				result.push_back(newWord);
				newWord.index.clear();
			}
			
		}
		
		for(auto r_iter = result.begin(); r_iter != result.end(); r_iter++)
		{
			// cout << iter->value << "\t" << iter->
			if(r_iter->index.size() > 1)
			{
				for(auto i_iter = r_iter->index.begin(); i_iter != r_iter->index.end(); i_iter++)
				{
					if(i_iter+1 != r_iter->index.end())
						cout << r_iter->value << ":" << *i_iter << ",";
					else
						cout << r_iter->value << ":" << *i_iter << endl;
				}
			}
				
		}
		cout << endl;
		result.clear();
		
	}
}