// #include <iostream>
// using namespace std;
// #include <string>
#include "myArray.hpp"

void PrintArray(MyArray<int> &arr)
{
    for (int i = 0; i < arr.Size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void test01()
{
    MyArray<int> arr1(5);
    MyArray<int> arr2(arr1);
    MyArray<int> arr3(100);
    arr3 = arr1;
}
void test02()
{
    MyArray<int> arr1(5);
    for (int i = 0; i < 5; i++)
    {
        arr1.Push_Back(i + 1);
    }
    arr1.Pop_Back();
    PrintArray(arr1);
    cout << "arr1.Capacity() = " << arr1.Capacity() << endl;
    cout << "arr1.Size() = " << arr1.Size() << endl;
}
// 测试自定义数据类型
class Person
{
public:
    Person(){};
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};
void printPersonArray(MyArray<Person> &arr)
{
    for (int i = 0; i < arr.Size(); i++)
    {
        cout << "姓名：" << arr[i].m_Name << " 年龄：" << arr[i].m_Age << endl;
    }
    cout << endl;
}
void test03()
{
    MyArray<Person> arr1(10);
    Person p1("Tom", 18);
    Person p2("Amy", 19);
    Person p3("Jack", 20);
    Person p4("Taylor", 21);
    Person p5("Jarry", 22);
    // 用尾差法插入到数组中
    arr1.Push_Back(p1);
    arr1.Push_Back(p2);
    arr1.Push_Back(p3);
    arr1.Push_Back(p4);
    arr1.Push_Back(p5);
    // 打印数组
    printPersonArray(arr1);
    // 输出容量
    cout << "arr1.Capacity() = " << arr1.Capacity() << endl;
    // 输出大小
    cout << "arr1.Size() = " << arr1.Size() << endl;
}
int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}