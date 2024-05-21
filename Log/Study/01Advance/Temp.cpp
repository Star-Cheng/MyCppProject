#include <iostream>
using namespace std;
#include <string>

// 重载递增运算符
// 自定义整型
class MyInteger
{
public:
    friend ostream &operator<<(ostream &cout, const MyInteger &myinst);
    MyInteger()
    {
        m_Num = 0;
    }
    // 重载前置++运算符
    MyInteger &operator++()
    {
        m_Num++;
        return *this;
    }
    // 重载后置++运算符
    MyInteger operator++(int) // int代表占位参数, 可以用于区分前置和后置++运算符
    {
        MyInteger temp = *this;
        m_Num++;
        return temp;
    }

private:
    int m_Num;
};
// // 重载左移运算符
ostream &operator<<(ostream &cout, const MyInteger &my_data)
{
    cout << my_data.m_Num;
    return cout;
}
void test01()
{
    MyInteger myinst;
    cout << ++myinst << endl;
    cout << myinst << endl;
}

void test02()
{
    MyInteger myinst;
    cout << myinst++ << endl;
    cout << myinst << endl;
}
main()
{
    // test01();
    test02();
    return 0;
}