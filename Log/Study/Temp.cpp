#include <iostream>
using namespace std;
#include <list>

class Person
{
public:
    string m_Name;
    int m_Age;
    int m_Height;
    Person(string name, int age, int height)
    {
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }
};
void printPerson(const list<Person> &l)
{
    for (list<Person>::const_iterator it = l.begin(); it != l.end(); it++)
        cout << "name: " << (*it).m_Name << " age: " << (*it).m_Age << " height: " << (*it).m_Height << endl;
}
// 指定排序规则
bool comparePerson(const Person &p1, const Person &p2)
{
    if (p1.m_Age == p2.m_Age)
        return p1.m_Height > p2.m_Height;
    else
        return p1.m_Age < p2.m_Age;
}
void test01()
{
    list<Person> l1;
    Person p1("ming", 18, 185);
    Person p2("hong", 19, 170);
    Person p3("wang", 20, 175);
    Person p4("qing", 20, 165);
    Person p5("long", 19, 165);
    Person p6("zhao", 20, 190);
    l1.push_back(p1);
    l1.push_back(p2);
    l1.push_back(p3);
    l1.push_back(p4);
    l1.push_back(p5);
    cout << "排序前:" << endl;
    printPerson(l1);
    cout << "排序后:" << endl;
    l1.sort(comparePerson);
    printPerson(l1);
}
int main()
{
    test01();
    return 0;
}