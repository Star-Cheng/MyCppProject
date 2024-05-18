# C++核心编程

## 1. 内存分区模型

+ 代码区: 存放代码, 特点: 共享, 可读
+ 全局区: 全局变量、静态变量、全局const常量和字符串常量存放于此, 该区域的数据在程序结束之后由操作系统释放
+ 栈区: 有编译器自动分配释放, 存放函数的参数值, 局部变量, 不要返回局部变量的地址
+ 堆区: 有程序员分配释放, 若程序员不是放， 程序结束时由操作系统回收, 利用new开辟堆区空间, 利用delete释放堆区空间

## 2. 引用

### 2.1 引用的基本使用

1. 作用: 给变量起别名
2. 语法: 数据类型 &别名 = 原名

```C++
#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int &b = a;
    cout << a << endl;
    cout << b << endl;
    b = 20;
    cout << a << endl;
    cout << b << endl;
    return 0;
}
```

### 2.2 引用的注意事项

 1. 引用必须要初始化: int &b; // 错误
 2. 引用在初始化后, 不可以改变

### 2.3 引用做函数参数

1. 作用: 函数传参时, 可以利用引用的技术让形参修饰实参
2. 优点: 可以简化指针修改实参

```C++
#include <iostream>
using namespace std;
// 交换函数
// 1. 值传递
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
// 2. 地址传递
void swap_add(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// 3. 引用传递
void swap_ref(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a = 10;
    int b = 20;
    swap(a, b); // 值传递, 形参不会修饰实参
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    swap_add(&a, &b); // 地址传递, 形参会修饰实参
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    swap_ref(a, b); // 引用传递, 形参会修饰实参
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    return 0;
}
```

### 2.4 引用做函数返回值

1. 作用: 减少函数返回值个数, 减少函数调用
2. 注意: 不要返回局部变量引用
3. 函数调用作为左值

```C++
#include <iostream>
using namespace std;
// 1. 不要返回局部变量的引用
int &test01()
{
    int a = 10;
    return a; // error
}
// 2. 函数的调用可以作为左值
int &test02()
{
    static int a = 10;
    return a;
}
int main()
{
    // int &ref = test01();
    // cout << ref << endl;  // error

    int &ref2 = test02();
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;
    test02() = 1000;  // 如果函数的返回值是引用, 这个函数调用可以作为左
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;
    return 0;
}
```

### 2.5 引用的本质

1. 本质引用的本质在C++内部实现是一个指针常量

```C++
#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int &ref = a;
    // 自动转换为 int * const ref = &a;
    ref = 20;
    cout << "a: " << a << endl;
    cout << "ref: " << ref << endl;
}
```

### 2.6 常量引用

1. 作用: 常量引用主要用来修饰形参, 防止误操作

```C++
#include <iostream>
using namespace std;
void showValue(int &a)
{
    cout << "a = " << a << endl;
    a = 1000;
}
void showValue2(const int &a)
{
    cout << "a = " << a << endl;
    // a = 1000;  // 加入const之后值变为可读, 不可以修改
}
int main()
{
    int a = 10;
    int &ref = a;         // 引用必须引一块合法的内存空间
    const int &ref2 = 10; // 加上const: int temp=10; const int & ref2=temp;
    // ref2 = 10;  // 加入const之后值变为可读, 不可以修改
    showValue2(a);
    cout << "a = " << a << endl;
    showValue(a);
    cout << "a = " << a << endl;
}
```

## 3. 函数提高

### 3.1 函数默认参数

#### 3.1.1 默认参数注意事项

1. 如果某个位置已经有了默认参数, 那么从这个位置往后, 从左到右必须要有默认值
2. 函数声明和函数实现只能有一个有默认参数

### 3.2 函数占位参数

```C++
void func(int a, int = 10) // 占位参数也可以有默认参数
{
    cout << "this is func" << endl;
}
```

### 3.3 函数重载

#### 3.3.1 函数重载概述

1. 作用: 函数名可以相同, 提高复用性
2. 重载条件: 函数名相同, 参数不同, 函数体相同
3. 注意事项: 函数的返回值不可以作为函数重载条件

```C++
#include <iostream>
using namespace std;
// 函数重载的满足条件
// 1. 同一个作用域下
// 2. 函数名称相同
// 3. 函数的参数类型不同, 或者个数不同, 或者顺序不同

void func()
{
    cout << "Hello World" << endl;
}
void func(int a, double b)
{
    cout << "int double World!!!" << endl;
}
void func(double a, int b)
{
    cout << "double int World!!!" << endl;
}

int main()
{
    func();
    func(10, 3.14);
    func(10., 3);
}
```

#### 3.3.2 函数重载的注意事项

1. 引用作为函数重载条件
2. 函数重载碰到默认参数

```C++
#include <iostream>
using namespace std;
// 函数重在的注意事项
// 1. 引用作为重载的条件
void func(int &a)
{
    cout << "func(int &a)" << endl;
}
void func(const int &a)
{
    cout << "func(const int &a" << endl;
}
// 2. 函数重载碰到默认参数
void func2(int a, int b = 10)
{
    cout << "func2(int a, int b =10)" << endl;
}
void func2(int a)
{
    cout << "func2(int a)" << endl;
}

int main()
{
    int a = 10;
    func(a);  // 调用func(int &a)
    func(10); // 调用func(const int &a)
    // func2(10);  // error, 函数重载碰到默认参数
}
```

## 4. 类和对象

### 4.1 封装

#### 4.1.1 封装的意义

1. 将属性和行为作为一个整体
2. 将属性和行为加以权限控制
    1. public : 公有权限, 成员在类内可以访问, 类外可以访问
    2. private : 私有权限, 类内可以访问, 类外不可以访问, 儿子不可以访问父亲的私有的内容
    3. protected : 保护权限, 类内可以访问, 类外不可以访问, 儿子也可以访问父亲保护的内容

```C++
#include <iostream>
using namespace std;
// 设计一个圆类, 求圆的周长
const double pi = 3.14;
// class代表设计一个类
class Circle
{
    // 访问权限
public: // 公共权限
    // 类中的属性和行为统一称为成员
    // 属性: 成员属性、成员变量
    double radius; // 半径
    // 行为: 成员函数、成员方法
    double getArea()
    {
        return pi * radius * radius;
    }
    double getPerimeter()
    {
        return 2 * pi * radius;
    }
};
int main()
{
    // 通过圆类, 创建具体的圆
    Circle c1;
    c1.radius = 10;
    cout << "圆的面积是:" << c1.getArea() << endl;
    cout << "圆的周长是:" << c1.getPerimeter() << endl;
    return 0;
}
```

```C++
#include <iostream>
using namespace std;
#include <string>
// class代表设计一个类
class Person
{
public: // 公共权限
    string name;

protected: // 保护权限
    string car;

private: // 私有权限
    int password;

public:
    void func()
    {
        name = "xingming";
        car = "xiaomi su7";
        password = 123456;
        cout << "name: " << name << endl;
        cout << "car: " << car << endl;
        cout << "password: " << password << endl;
    }
};
int main()
{
    Person p1;
    p1.name = "xiaoming";
    // p1.car = "xiaomi su7";  // 保护权限内容, 在类外访问不到
    // p1.password = 123456;  // 私有权限内容, 在类外访问不到
    p1.func();
    return 0;
}
```

#### 4.1.2 struct和class的区别

1. struct默认权限为公共
2. class默认权限为私有

```C++
#include <iostream>
using namespace std;
#include <string>
class c1
{
    int m_a; // 默认权限是私有
};
struct c2
{
    int m_a; // 默认权限是公共
};
int main()
{
    // struct和class的区别
    // 1. struct默认权限为公共
    // 2. class默认权限为私有
    c1 c1;
    c2 c2;
    // c1.m_a = 10;  // 错误
    c2.m_a = 10; // 正确
    return 0;
}
```

#### 4.1.3 成员属性设置为私有

1. 将所有成员属性设置私有, 可以自己控制读写权限
2. 对于写权限, 我们可以检测数据的有效性

```C++
#include <iostream>
using namespace std;
#include <string>
// 成员属性设置为私有
// 1. 可以自己控制读写权限
// 2. 对于写可以检测数据有效性
class Person
{
private:
    string m_Name;  // 可读可写
    int m_Age = 18; // 只读
    string m_ido;   // 只写
public:
    void setName(string name)
    {
        m_Name = name;
    }
    string getName()
    {
        return m_Name;
    }
    int getAge()
    {
        return m_Age;
    }
    void setido(string ido)
    {
        m_ido = ido;
    }
};
int main()
{
    Person p;
    p.setName("xiaoming");
    p.setido("xiaohong");
    cout << "name: " << p.getName() << endl;
    cout << "age: " << p.getAge() << endl;
}
```
