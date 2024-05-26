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
