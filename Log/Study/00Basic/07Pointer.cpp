#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble(int *arr, int len_arr)
{
    for (int i = 0; i < len_arr - 1; i++)
    {
        for (int j = 0; j < len_arr - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
    // 指针所占内存空间
    int a = 10;
    int *p = &a;
    cout << "sizeof(p) = " << sizeof(p) << endl;
    // 7.4 空指针
    // 1. 空指针用于给指针变量进行初始化
    // 2. 空指针是不可以进行访问的
    int *p1 = nullptr;
    // 7.5 野指针
    int *p2 = (int *)0x12345678;
    cout << "p2 = " << p2 << endl;
    // 7.6 const修饰指针
    // 1. 常量指针
    const int *p3 = &a; // 指针指向的内容不能被修改,但指针的指向可以改变
    // 2. 指针常量
    int *const p4 = &a; // 指针指向的内容可以修改,但指针的指向不能改变
    // 3. 常量指针常量
    const int *const p5 = &a; // 指针指向的内容不能被修改,指针的指向也不能改变
    // 7.7 指针和数组
    int arr[] = {3, 1, 2};
    int *p6 = arr;
    for (int i = 0; i < 3; i++)
    {
        cout << *p6 << endl;
        p6++;
    }
    // 7.8 指针和函数
    // 地址传递
    int a1 = 10, b1 = 20;
    swap(&a1, &b1);
    cout << "a1 = " << a1 << ", b1 = " << b1 << endl;
    // 指针、函数、数组
    int len_arr = sizeof(arr) / sizeof(arr[0]);
    bubble(arr, len_arr);
    for (int i = 0; i < len_arr; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}