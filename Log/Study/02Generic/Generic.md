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