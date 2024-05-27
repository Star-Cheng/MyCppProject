#include <iostream>
using namespace std;
#include <string>

// 提前让编译器知道Person类存在
template <class T1, class T2>
class Person;
// 类外实现
template <class T1, class T2>
void showPerson(Person<T1, T2> p)
{
    cout << "name: " << p.m_Name << ", age: " << p.m_Age << endl;
};

template <class T1, class T2>
class Person
{
public:
    // 全局函数类内实现
    // friend void showPerson(Person<T1, T2> p)
    // {
    //     cout << "name: " << p.m_Name << ", age: " << p.m_Age << endl;
    // };
    // 全局函数类外实现
    // 加空模版参数列表
    // 如果全局函数是类外, 需要让编译器提前知道这个函数的存在
    friend void showPerson<>(Person<T1, T2> p);
    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    };

private:
    T1 m_Name;
    T2 m_Age;
};
void test01()
{
    Person<string, int> p("Tom", 18);
    showPerson(p);
}
int main()
{
    test01();
    return 0;
}