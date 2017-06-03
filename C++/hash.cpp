#include <iostream>
using namespace std;

unsigned myhash(const char*arKey, unsigned nKeyLength)
{
	unsigned hash = 0;
	for (; nKeyLength > 0; nKeyLength -=1) {
		hash = ((hash << 5) - hash) + *arKey++;
	}
	return hash;
}

int main()
{
	cout << myhash("Ey", 2) << endl;
	return 0;
}