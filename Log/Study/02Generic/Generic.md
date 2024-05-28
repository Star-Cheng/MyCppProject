# C++泛型编程和STL

## 1. 模板

### 1.1 模板的概念

+ 模板就是建立通用的模具, 大大提升复用率
+ 模板不可以直接使用, 他只是一个框架
+ 模板的用用并不是万能的

### 1.2 函数模板

#### 1.2.1 函数模板语法

+ 建立一个通用函数, 其函数返回值和型参类大学可以不具体定义, 用一个虚拟的类型来代替
+ 语法: `template<typename T>`

```C++
#include <iostream>
using namespace std;

// 函数模板
// 交换两个整形
void swapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
// 交换两个浮点型
void swapDouble(float &a, float &b)
{
    float temp = a;
    a = b;
    b = temp;
}
// 函数模板
// template<class T>
template <typename T>
void swapTemplate(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
void test01()
{
    int a = 10;
    int b = 20;
    swapInt(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    float c = 10.1;
    float d = 20.2;
    swapDouble(c, d);
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;

    // 利用函数模板
    // 1. 自动类型推导
    swapTemplate(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    // 2. 指定类型
    swapTemplate<int>(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}
int main()
{
    test01();
    return 0;
}
```

#### 1.2.2 函数模板注意事项

+ 自动类型推导, 必须推导出一致的数据类型T, 才可以使用
+ 模板必须要确定出T的数据类型, 才可以使用

```C++
#include <iostream>
using namespace std;

// 函数模板注意事项
template <class T>
void swapClass(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
// 1. 自动类型推导, 必须推导出一致的数据类型T, 才可以使用
void test01()
{
    int a = 10;
    int b = 20;
    float c = 3.14;
    swapClass(a, b);
    // swapClass(c, b); // error, 推导不出一致数据类型
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}
// 2. 模板必须要确定出T的数据类型, 才可以使用
template <class T>
void func()
{
    cout << "func" << endl;
}
void test02()
{
    func<int>(); // 如果不确定类型, 无法调用func
}
int main()
{
    test01();
    test02();
    return 0;
}
```

#### 1.2.3 函数模板案例

+ 利用函数模板封装一个排序的函数, 可以对不同数据类型数组进行排序
+ 排序规则从大到小, 排序算法为选择排序
+ 分别利用char数组和int数组进行测试

```C++
#include <iostream>
using namespace std;

// 对数组进行排序的函数
// 交换函数
template <class T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
// 选择排序算法
template <class T>
void mySort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[max] < arr[j])
            {
                max = j;
            }
        }
        if (max != i)
        {
            mySwap(arr[max], arr[i]);
        }
    }
}
template <class T>
void printArray(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void test01()
{
    char charArr[] = "hello\0";
    int len_charArr = sizeof(charArr) / sizeof(char);
    mySort(charArr, len_charArr);
    printArray(charArr, len_charArr);
    int intArr[] = {1, 3, 2, 7, 5, 6, 7, 4, 1};
    int len_intArr = sizeof(intArr) / sizeof(int);
    mySort(intArr, len_intArr);
    printArray(intArr, len_intArr);
    float floatArr[] = {1.1, 3.3, 2.2, 7.7, 5.5, 6.6, 7.7, 4.4, 1.1};
    int len_floatArr = sizeof(floatArr) / sizeof(float);
    mySort(floatArr, len_floatArr);
    printArray(floatArr, len_floatArr);
}
int main()
{
    test01();
    return 0;
}
```

#### 1.2.4 普通函数和函数模板的区别

+ 普通函数调用时可以发生自动类型转换(隐式类型转换)
+ 函数模板调用时, 如果利用自动类型推导, 不会发生自动类型转换
+ 如果利用显示类型转换, 可以发生自动类型转换

```C++
#include <iostream>
using namespace std;

// 普通函数与模板函数的区别
// 1. 普通函数调用时可以发生自动类型转换(隐式类型转换)
// 2. 函数模板调用时, 如果利用自动类型推导, 不会发生自动类型转换
// 3. 如果利用显示类型转换, 可以发生自动类型转换
// 普通函数
int myAdd(int a, int b)
{
    return a + b;
}
// 函数模板
template <class T>
T myAdd2(T a, T b)
{
    return a + b;
}
void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    cout << myAdd(a, b) << endl;
    cout << myAdd(a, c) << endl; // 隐式类型转换, 将char类型转换为int类型

    // 1. 自动类型推导
    // 自动类型推导, 不会发生隐式类型转换
    // cout << myAdd2(a, c) << endl; // error, a和c的类型不同, 不可以发生类型转换

    // 2. 显示类型转换
    // 显示制定类型, 会发生隐式类型转换
    cout << myAdd2<int>(a, c) << endl;
    cout << myAdd2<char>(a, c) << endl;
}
int main()
{
    test01();
    return 0;
}
```

#### 1.2.5 普通函数和函数模板的调用规则

+ 调用规则
    1. 如果函数模板和普通函数都可以实现, 有限调用普通函数
    2. 可以通过空模板参数列表来强制调用函数模板
    3. 函数模板也可以发生重载
    4. 如果函数模板可以产生更好的匹配, 优先调用函数模板

```C++
#include <iostream>
using namespace std;

// 普通函数和函数模板的调用规则
void myprint(int a, int b)
{
    cout << "普通函数" << endl;
}
template <class T>
void myprint(T a, T b)
{
    cout << "函数模板" << endl;
}

template <class T>
void myprint(T a, T b, T c)
{
    cout << "函数重载模板" << endl;
}

void test01()
{
    // 1. 如果函数模板和普通函数都可以实现, 有限调用普通函数
    myprint(10, 20);
    // 2. 可以通过空模板参数列表来强制调用函数模板
    myprint<>(10, 20);
    // 3. 函数模板也可以发生重载
    myprint(1, 2, 3);
    // 4. 如果函数模板可以产生更好的匹配, 优先调用函数模板
    myprint('a', 'b');
}
int main()
{
    test01();
    return 0;
}
```

#### 1.2.6 模板的局限性

+ 局限性: 模板的通用性并不是万能的

```C++
#include <iostream>
using namespace std;

// 模板的局限性
// 模板并不是万能的, 有些特定数据类型, 需要用具体化方式来实现
// 对比两个函数是否相等
class Person
{
public:
    string m_name;
    int m_age;
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
};
template <class T>
bool myCompare(T &a, T &b)
{
    if (a == b)
        return true;
    else
        return false;
}
// 利用具体化的Person版本实现代码, 具体化会优先调用
template <>
bool myCompare(Person &p1, Person &p2)
{
    if (p1.m_name == p2.m_name && p1.m_age == p2.m_age)
        return true;
    else
        return false;
}
void test01()
{
    int a = 10;
    int b = 20;
    bool ret = myCompare(a, b);
    if (ret)
        cout << "a == b" << endl;
    else
        cout << "a != b" << endl;
}
void test02()
{
    Person p1("Tom", 18);
    Person p2("Amy", 20);
    bool ret = myCompare(p1, p2);
    if (ret)
        cout << "p1 == p2" << endl;
    else
        cout << "p1 != p2" << endl;
}
int main()
{
    test01();
    test02();
    return 0;
}
```

### 1.3 类模板

#### 1.3.1 类模板语法

+ 类模板作用: 建立一个通用类, 类中的成员数据类型可以不具体制定, 用一个虚拟的类型来代表

```C++
#include <iostream>
using namespace std;
#include <string>

// 类模板
template <class NameType, class AgeType>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void showPerson()
    {
        cout << "name: " << this->m_Name << ", age: " << this->m_Age << endl;
    }
    NameType m_Name;
    AgeType m_Age;
};
void test01()
{
    Person<string, int> p("monkey sun", 100);
    p.showPerson();
}
int main()
{
    test01();
    return 0;
}
```

#### 1.3.2 类模板和函数模板的区别

+ 类模板和函数模板的区别主要有两点
    1. 类模板没有自动类型推导功能
    2. 类模板在模板参数列表中可以有默认参数

```C++
#include <iostream>
using namespace std;
#include <string>

// 类模板和类模板的区别
template <class NameType, class AgeType = int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    };
    void showPerson()
    {
        cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
    };
    NameType m_Name;
    AgeType m_Age;
};
// 1. 类模板没有自动类型推导功能
void test01()
{
    // Person p1("Tom", 10); // 推导失败, 无法自动类型推导
    Person<string, int> p1("Tom", 18); // 只能使用显示指定类型
    p1.showPerson();
}
// 2. 类模板在模板参数列表中可以添加默认参数
void test02()
{
    Person<string> p2("Amy", 18); // 因为默认age为整形, 所以这里可以省略
    p2.showPerson();
}
int main()
{
    test01();
    test02();
    return 0;
}
```

#### 1.3.3 类模板中成员函数调用时机

+ 类模板中成员函数和普通类模板中成员函数调用时机的区别
    1. 普通类中的成员函数一开始就可以创建
    2. 类模板中的成员函数在调用时才创建

```C++
#include <iostream>
using namespace std;
#include <string>

// 类模板中成员函数的创建时机
class Person1
{
public:
    void showPerson1()
    {
        cout << "Person1 show" << endl;
    }
};
class Person2
{
public:
    void showPerson2()
    {
        cout << "Person2 show" << endl;
    }
};
template <class T>
class Person
{
public:
    T obj;
    // 类模板中成员函数
    void func1()
    {
        obj.showPerson1();
    }
    void func2()
    {
        obj.showPerson2();
    }
};
void test01()
{
    Person<Person1> p1;
    p1.func1();
    Person<Person2> p2;
    p2.func2();
}
int main()
{
    test01();
    return 0;
}
```

#### 1.3.4 类模板对象做函数参数

+ 类模板实例化出的对象, 向函数传递参数的方式
    1. 指定传入的类型: 直接显示对象的数据类型
    2. 参数模板化: 将对象中的参数变为模板进行传递
    3. 整个类型模板化: 将整个对象类型模板化进行传递

```C++
#include <iostream>
using namespace std;
#include <string>

// 类模板的对象做函数的参数
template <class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    void showPerson()
    {
        cout << "name: " << this->m_name << " age: " << this->m_age << endl;
    }
    T1 m_name;
    T2 m_age;
};
// 1. 指定传入的类型
void printPerson1(Person<string, int> &p)
{
    p.showPerson();
}
void test01()
{
    Person<string, int> p("Tom", 20);
    printPerson1(p);
}
// 2. 参数模板化:
template <class T1, class T2>
void printPerson2(Person<T1, T2> &p)
{
    p.showPerson();
    cout << "T1的类型: " << typeid(T1).name() << endl;
    cout << "T2的类型: " << typeid(T2).name() << endl;
}

void test02()
{
    Person<string, int> p("Amy", 18);
    printPerson2(p);
}
// 3. 整个类型模板化
template <class T>
void printPerson3(T &p)
{
    p.showPerson();
    cout << "T的类型: " << typeid(T).name() << endl;
}
void test03()
{
    Person<string, int> P("Jack", 20);
    printPerson3(P);
}
int main()
{
    test01();
    test02();
    test03();
    return 0;
}
```

#### 1.3.5 类模板与继承

+ 当子类继承的父类是一个类模板时, 子类在声明的时候, 要指定出父类中T的类型
+ 如果不指定, 编译器无法给子类分配内存
+ 如果想灵活指定出父类中T的类型, 子类也需要变为类模板

```C++
#include <iostream>
using namespace std;
#include <string>

// 类模板与继承
template <class T>
class Base
{
public:
    T m;
};
// 当子类继承的父类是一个类模板时, 子类在声明的时候, 要指定出父类中T的类型
// class Son : public Base // erorr, 必须要知道父类中的T类型, 才能继承给子类
class Son : public Base<int>
{
};
template <class T1, class T2>
class Son2 : public Base<T2>
{
public:
    Son2()
    {
        cout << "T1的类型为: " << typeid(T1).name() << endl;
        cout << "T2的类型为: " << typeid(T2).name() << endl;
    }
    T1 obj;
};
void test01()
{
    Son s;
    s.m = 10;
    cout << s.m << endl;
}
void test02()
{
    Son2<string, int> s2;
    s2.obj = "hello";
    cout << s2.obj << endl;
}
int main()
{
    test01();
    test02();
    return 0;
}
```

#### 1.3.6 类模板成员函数类外实现

```C++
#include <iostream>
using namespace std;
#include <string>

// 类模板成员函数类外实现
template <class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age);
    void showPerson();
    T1 m_Name;
    T2 m_Age;
};
// 构造函数的类外实现
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->m_Name = name;
    this->m_Age = age;
}
// 成员函数类外实现
template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << "name: " << this->m_Name << ", age: " << this->m_Age << endl;
}
void test01()
{
    Person<string, int> p("Tom", 20);
    p.showPerson();
}
int main()
{
    test01();
    return 0;
}
```

#### 类模板分文件编写

+ 类模板中成员函数创建时期在调用阶段, 导致分文件编写时链接不到
    1. 解决方式1: 直接包含.cpp源文件
    2. 解决方式2. 将声明和实现写到同一个文件中, 并更改后缀名为.hpp, hpp是约定的名称, 并不算强制

Person.hpp

```C++
#pragma once
#include <iostream>
using namespace std;
#include <string>

// 类模板分文件编写以及解决
template <class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age);
    void showPerson();
    T1 m_Name;
    T2 m_Age;
};
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->m_Name = name;
    this->m_Age = age;
}
template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << "name: " << this->m_Name << ", age: " << this->m_Age << endl;
}
```

Person.cpp

```C++
#include "Person.hpp"
void test01()
{
    Person<string, int> p("Tom", 20);
    p.showPerson();
}
int main()
{
    test01();
    return 0;
}
```

#### 1.3.8 类模板与友元

+ 全局函数类内实现: 直接在类内声明友元即可
+ 全局函数类外实现: 需要提前让编译器知道全局函数的存在

```C++
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
```

#### 1.3.9 类模版案例

MyArray.hpp

```C++
#pragma
#include <iostream>
using namespace std;
#include <string>

template <class T>
class MyArray
{
public:
    MyArray(int capacity)
    {
        cout << "MyArray有参构造调用" << endl;
        this->m_capacity = capacity;
        this->m_size = 0;
        this->pAddress = new T[this->m_capacity];
    }
    // 拷贝构造
    MyArray(const MyArray &arr)
    {
        cout << "MyArray拷贝构造调用" << endl;
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->pAddress = new T[arr.m_capacity];
        // 拷贝数组元素
        for (int i = 0; i < this->m_size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    // operator=防止浅拷贝
    MyArray &operator=(const MyArray &arr)
    {
        cout << "MyArray operator=调用" << endl;
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_size = 0;
            this->m_capacity = 0;
        }
        // 深拷贝
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->pAddress = new T[arr.m_capacity];
        // 拷贝数组元素
        for (int i = 0; i < this->m_size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }
    // 尾差法
    void Push_Back(const T &val)
    {
        if (this->m_size == this->m_capacity)
        {
            return;
        }
        this->pAddress[this->m_size] = val;
        this->m_size++;
    }
    // 尾删法
    void Pop_Back()
    {
        // 让用户访问不到最后一个元素, 逻辑上删除
        if (this->m_size == 0)
        {
            return;
        }
        this->m_size--;
    }
    // 通过下标访问元素
    T &operator[](int index)
    {
        return this->pAddress[index];
    }
    // 返回数组容量
    int Capacity()
    {
        return this->m_capacity;
    }
    // 返回数组大小
    int Size()
    {
        return this->m_size;
    }
    // 析构函数
    ~MyArray()
    {
        cout << "MyArray析构调用" << endl;
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

private:
    T *pAddress;    // 指针指向堆区开辟的真是数组
    int m_capacity; // 数组容量
    int m_size;     // 数组大小
};
```

MyArray.cpp

```C++
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
```

## 2 STL初识

### 2.1 STL的诞生

+ 为了可重复利用, STL诞生
+ 为了建立数据结构和算法的一套标准, STL诞生

### 2.2 STL基本概念

1. STL(Standard Template Library, 标准模版库)
2. STL从广义上分为: 容器(container), 算法(alworithm), 迭代器(iterator)
3. 容器和算法之间通过迭代器进行无缝连接
4. STL几乎所有代码都采用了模版类或者模版函数

### 2.3 STL六大组件

+ 容器(container), 算法(alworithm), 迭代器(iterator), 仿函数(function object), 适配器(adapter), 序列容器(sequence container)
    1. 容器: 各种数据结构, 如: vector, list, deque, set, map
    2. 算法: 各种常用算法, 如: sort, find, for_each, count, accumulate
    3. 迭代器: 扮演类容器与算法之间的胶水作用
    4. 仿函数: 行为类似函数, 可作为算法的某种策略
    5. 适配器: 一种用来修饰容器或者仿函数或迭代器接口的东西
    6. 序列容器: 负责空间的配置与管理

### 2.4 STL中容器, 算法, 迭代器

1. 容器
    1. 序列式容器: 强调值的排序, 序列式容器中的每个元素均有固定的位置
    2. 关联式容器: 二叉树结构, 各元素之间没有严格的物理上的顺序关系

2. 算法
    1. 质变算法: 运算过程中会改变区间内的元素内容
    2. 非质变算法: 指运算过程中不会改变区间内的元素内容

3. 迭代器: 迭代器使用非常类似于指针
    1. 输入迭代器: 只能进行输入, 不能进行输出
    2. 输出迭代器: 只能进行输出, 不能进行输入
    3. 前向迭代器: 既可以进行输入, 也可以进行输出, 但是只能单向移动
    4. 双向迭代器: 既可以进行输入, 也可以进行输出, 同时可以双向移动
    5. 随机访问迭代器: 既可以进行输入, 也可以进行输出, 同时可以双向移动, 而且可以任意访问任意位置的元素

### 2.5 容器算法迭代器初识

#### 2.5.1 Vector存放内置数据类型

+ 容器: vector
+ 算法: for_each
+ 迭代器: vector《int》::iterator

```C++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void myPring(int value)
{
    cout << value << endl;
}
// vector容器存放内置数据类型
void test01()
{
    vector<int> v; // 创建一个vector容器, 当成数组使用
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    // 通过迭代器访问容器中的数据
    vector<int>::iterator itBegin = v.begin(); // 起始迭代器, 指向容器中第一个元素的前面
    vector<int>::iterator itEnd = v.end();     // 结束迭代器, 指向容器中最后一个元素的下一个位置
    // 第一种遍历
    while (itBegin != itEnd)
    {
        cout << *itBegin << endl;
        itBegin++;
    }
    // 第二种遍历
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    // 第三种遍历, 利用STL提供的遍历算法
    for_each(v.begin(), v.end(), myPring);
}
int main()
{
    test01();
    return 0;
}
```

#### 2.5.2 Vector存放自定义数据类型

```C++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// Vector存放自定义数据类型
class Person
{
public:
    string m_Name;
    int m_Age;
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
};
void test01()
{
    vector<Person> v;
    Person p1("孙悟空", 100);
    Person p2("猪八戒", 80);
    Person p3("唐僧", 30);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << (*it).m_Name << " 年龄：" << (*it).m_Age << endl;
        cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age << endl;
    }
}

int main()
{
    test01();
    return 0;
}
```

#### 2.5.4 Vector容器嵌套容器

```C++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// Vector容器嵌套容器
void test01()
{
    vector<vector<int>> v;
    // 小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    // 向小容器中添加元素
    for (int i = 0; i < 4; i++)
    {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }
    // 将小容器添加到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    // 通过大容器, 把所有数据遍历一遍
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        // (*it) ---- 容器vector<int>
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << *vit << " ";
        }
        cout << endl;
    }
}

int main()
{
    test01();
    return 0;
}
```

### 3.1 string容器

#### 3.1.1 string基本概念
