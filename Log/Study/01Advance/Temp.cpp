#include <iostream>
using namespace std;
#include <string>

// 常函数
class Person
{
public:
    // this指针的本质是指针常量: 指针的指向是不可修改的
    // const Person *const this;
    // 在成员函数后加const, 修饰的是this指向, 让指针指向的值也不能修改
    Person() {}
    void showPerson() const
    {
        // this->m_Age = 100; // error
        // this = NULL;       // error
        this->m_Salary = 8000;
        cout << "m_Salary = " << m_Salary << endl;
    }
    void func() {}
    int m_Age;
    mutable int m_Salary;
};
void test01()
{
    Person p;
    p.showPerson();
}
// 常对象
void test02()
{
    const Person p;
    // p.m_Age = 100;
    // p.m_Salary = 8000;
    p.showPerson(); // 常对象可以调用常成员函数
    // p.func();       // 常对象不可以调用普通成员函数
}
int main()
{
    test01();
    test02();
    return 0;
}