#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

int main()
{
	map<char, int> alphabet;
	unordered_map<char, int> ur_alphabet;
	for(int i = 'z'; i >= 'a'; i--)
	{
		// alphabet.insert(make_pair(char(i), i));
		alphabet[char(i)] = i;
		ur_alphabet[char(toupper(i))] = i;
	}
		
	// cout << alphabet.size() << endl;
	// for(auto begin = alphabet.begin(); begin != alphabet.end(); begin++)
	// {
		
		// cout << begin->first << "\t" << begin->second << endl;
	// }
	for(auto begin = ur_alphabet.begin(); begin != ur_alphabet.end(); begin++)
	{
		
		cout << begin->first << "\t" << begin->second << endl;
	}
}