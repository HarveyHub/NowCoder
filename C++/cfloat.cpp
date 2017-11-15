#include <iostream>
#include <cfloat>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	const int COUT_WIDTH = 25;  
    cout<<setiosflags(ios::left);  
    //float  
    cout<<setw(COUT_WIDTH)<<"sizeof(float):"<<sizeof(float)<<endl;  
    cout<<setw(COUT_WIDTH)<<"float Min:"<<FLT_MIN<<endl;  
    cout<<setw(COUT_WIDTH)<<"float Max:"<<FLT_MAX<<endl<<endl;  
	
	float a = 6.1207, b = 6.1203;
	cout << fabs(a-b)/fabs(a+b)/FLT_MIN << endl;
	
	return 0;
}

