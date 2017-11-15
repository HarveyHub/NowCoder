#include <iostream>
using namespace std;

int main()
{
    unsigned y, m, d;
    while(cin >> y >> m >> d){
        switch(m - 1){
            case 11:
                d += 30;
            case 10:
                d += 31;
            case 9:
                d += 30;
            case 8:
                d += 31;
            case 7:
                d += 31;
            case 6:
                d += 30;
            case 5:
                d += 31;
            case 4:
                d += 30;
            case 3:
                d += 31;
            case 2:
                if((y % 4 == 0 && y % 100 != 0) ||y%400==0){
                    d += 29;
                }
                else{
                    d += 28;
                }
            case 1:
                d += 31;
                break;
            default:
                d += 0;
        }
        cout << d << endl;
    }
    return 0;
}