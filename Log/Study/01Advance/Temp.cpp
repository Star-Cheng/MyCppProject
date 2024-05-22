#include <iostream>
using namespace std;

// 继承中的同名成员处理
class Base
{
public:
    Base()
    {
        m_A = 100;
    }
    void func()
    {
        cout << "Base func() = " << m_A << endl;
    }
    // 如果子类中出现和父类同名的成员函数, 子类的同名成员会隐藏掉父类中所有同名成员函数
    void func(int a)
    {
        cout << "Base func(int a) = " << a << endl;
    }
    int m_A;
};
class Son : public Base
{
public:
    Son()
    {
        m_A = 200;
    }
    void func()
    {
        cout << "Son func() = " << m_A << endl;
    }
    int m_A;
};
// 同名成员属性处理
void test01()
{
    Son s1;
    // 直接调用, 调用的是子类中的同名成员
    cout << "Son m_A = " << s1.m_A << endl;
    // 如果通过子类对象访问到父类中同名成员, 需要加作用域
    cout << "Base m_A = " << s1.Base::m_A << endl;
}
// 同名成员函数处理
void test02()
{
    Son s2;
    // 直接调用, 调用的是子类中的同名函数
    s2.func();
    // 如果通过子类对象访问到父类中同名函数, 需要加作用域
    s2.Base::func();
    // 如果想访问到父类中被隐藏的同名成员函数, 需要加作用域
    s2.Base::func(100);
}
main()
{
    test01();
    test02();
    return 0;
}