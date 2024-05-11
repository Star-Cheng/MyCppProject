#include <iostream>
using namespace std;
// 1. define定义常量
#define Day 7

int main()
{
    // 2. const修饰变量
    const int month = 12;
    cout << "hello world"
            "\n";
    cout << "a week has " << Day << " day" << endl;
    cout << "a year has " << month << " month" << endl;
    return 0;
}
