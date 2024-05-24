#include <iostream>
using namespace std;

// 多态
class Animal
{
public:
    // void speak()
    virtual void speak()
    {
        cout << "Animal speak" << endl;
    }
};
class Cat : public Animal
{
public:
    void speak()
    {
        cout << "Cat speak" << endl;
    }
};
class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Dog speak" << endl;
    }
};
// 地址早绑定, 再编译阶段就确定了函数地址
// 如果想执行让猫说话, 那么这个函数地址就不能提前绑定, 需要在运行阶段进行绑定
// 动态多态满足条件
// 1. 有继承关系
// 2. 子类要重写父类的虚函数
// 动态多态使用: 父类的指针或者引用 指向子类对象
void doSpeak(Animal &a)
{
    a.speak();
}
void test01()
{
    Cat c;
    doSpeak(c);
    Dog d;
    doSpeak(d);
}
main()
{
    test01();
    return 0;
}