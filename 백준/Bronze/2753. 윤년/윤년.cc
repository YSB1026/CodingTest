//윤년은 연도가 4의 배수이면서, 100의 배수가 아닐 때 또는 400의 배수일 때이다.
#include <iostream>
using namespace std;

int main(){
    int year;
    cin >> year;
    
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0)? 1 : (year%400==0) ? 1 : 0;

    cout << isLeapYear;
    
    return 0;
}