#include <iostream>
using namespace std;
#include <map>

// map自定义数据类型排序
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
void printMap(const map<Person, int, MyCompare> &m)
{
    for (map<Person, int, MyCompare>::const_iterator it = m.begin(); it != m.end(); it++)
        cout << "value = " << it->second << ", name = " << it->first.m_Name << ", age = " << it->first.m_Age << endl;
    cout << endl;
}
void test01()
{
    map<Person, int, MyCompare> m1;
    Person p1("ming", 19);
    Person p2("xing", 18);
    Person p3("wang", 20);
    m1.insert(make_pair(p1, 1));
    m1.insert(make_pair(p2, 2));
    m1.insert(make_pair(p3, 3));
    printMap(m1);
}
int main()
{
    test01();
    return 0;
}