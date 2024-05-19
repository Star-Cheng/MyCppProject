#include <iostream>
using namespace std;
#include <string>
// 深拷贝与浅拷贝
class Person
{
public:
    Person()
    {
        cout << "Person默认构造函数" << endl;
    }
    Person(int age, int height)
    {
        m_Age = age;
        m_Height = new int(height);
        cout << "Person有参构造函数" << endl;
    }
    Person(const Person &p)
    {
        m_Age = p.m_Age;
        m_Height = p.m_Height;           // 浅拷贝, 编译器默认的操作
        m_Height = new int(*p.m_Height); // 在堆区开辟数据做拷贝操作
        cout << "Person拷贝构造函数" << endl;
    }
    ~Person()
    {
        // 析构代码, 将堆区开辟数据做释放操作
        if (m_Height != NULL)
        {
            delete m_Height;
            m_Height = NULL;
        }
        cout << "Person析构函数" << endl;
    }
    int m_Age;
    int *m_Height;
};
void test01()
{
    Person p1(18, 185);
    cout << "p1.m_Age = " << p1.m_Age << " p1.m_Height = " << *p1.m_Height << endl;
    Person p2(p1);
    cout << "p2.m_Age = " << p2.m_Age << " p2.m_Height = " << *p2.m_Height << endl;
}
int main()
{
    test01();
    return 0;
}