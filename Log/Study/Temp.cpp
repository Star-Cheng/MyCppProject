#include <iostream>
using namespace std;
#include <string>

// string子串
void test01()
{
    string str = "hello world";
    string substr = str.substr(0, 5);
    cout << "substr = " << substr << endl;
}
// 使用操作
void test02()
{
    string email = "xiaoming@qq.com";
    // 从邮件中获取用户名信息
    int pos = email.find("@");
    string name = email.substr(0, pos);
    cout << "name = " << name << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}