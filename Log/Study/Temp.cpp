#include <iostream>
using namespace std;
#include <string>
#include <set>

// set容器排序, 存放自定义数据类型
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};
class MyCompare
{
public:
    bool operator()(const Person &p1, const Person &p2) const
    {
        return p1.m_Age > p2.m_Age;
    }
};
void printSet(const set<Person, MyCompare> &s)
{
    for (set<Person, MyCompare>::const_iterator it = s.begin(); it != s.end(); it++)
        cout << "name: " << it->m_Name << ", age: " << it->m_Age << endl;
    cout << endl;
}
void test01()
{
    set<Person, MyCompare> s;
    Person p1("ming", 18);
    Person p2("xing", 19);
    Person p3("hong", 20);
    Person p4("wang", 21);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    printSet(s);
}
int main()
{
    test01();
    return 0;
}