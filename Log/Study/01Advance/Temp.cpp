#include <iostream>
using namespace std;

// 虚析构和纯虚析构
class Animal
{
public:
    virtual void speak() = 0;
    Animal()
    {
        cout << "Animal()构造函数" << endl;
    }
    // 利用虚析构可以解决父类指针释放子类对象时不干净的问题
    // virtual ~Animal()
    // {
    //     cout << "Animal()析构函数" << endl;
    // }
    virtual ~Animal() = 0; // 纯虚析构
};
// 纯虚析构需要声明也要实现
// 有了纯虚析构之后, 这个类也属于抽象类, 无法实例化对象
Animal::~Animal()
{
    cout << "Animal()纯虚析构函数" << endl;
}
class Cat : public Animal
{
public:
    Cat(string name)
    {
        m_Name = new string(name);
        cout << "Cat()构造函数" << endl;
    }
    void speak()
    {
        cout << *m_Name << " cat speak" << endl;
    }
    ~Cat()
    {
        if (m_Name != NULL)
        {
            cout << "Cat()析构函数" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }
    string *m_Name;
};
void test01()
{
    Animal *animal = new Cat("Tom");
    animal->speak();
    delete animal;
}
int main()
{
    test01();
    return 0;
}