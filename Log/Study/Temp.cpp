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