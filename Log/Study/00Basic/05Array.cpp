#include <iostream>
using namespace std;

int main()
{
    // 5. 数组
    // 5.2 一维数组
    // 5.2.1 一维数组定义方式
    // 1. 数据类型 数组名[数组长度]
    int arr1[5];
    arr1[0] = 10;
    arr1[1] = 20;
    arr1[2] = 30;
    arr1[3] = 40;
    arr1[4] = 50;
    cout << arr1[0] << endl;
    // 2. 数据类型 数组名[数组长度] = {初始化值1, 初始化值2, ...}
    int arr2[5] = {1, 2, 3};
    for (int i = 0; i < 5; i++)
    {
        cout << arr2[i] << endl;
    }
    // 3. 数据类型 数组名[] = {初始化值1, 初始化值2, ...}
    int arr3[] = {1, 2, 3};
    cout << arr3[2] << endl;

    // 5.2.2 一维数组数组名
    // 1. 通过数组名统计数组占用大小
    cout << "整个数组占用内存空间: " << sizeof(arr3) << endl;
    // 2. 通过数组名查看数组首地址
    cout << "数组的首地址为: " << arr2 << endl;
    cout << "数组中第一个元素的首地址为: " << &arr2[0] << endl;
    // 3. 数组逆置
    int pig[5] = {1, 2, 3, 4, 5};
    int start = 0;
    int end = sizeof(pig) / sizeof(int) - 1;
    for (int i = start; i < 5; i++)
    {
        if (start < end)
        {
            int temp = pig[start];
            pig[start] = pig[end];
            pig[end] = temp;
            start++;
            end--;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << pig[i] << endl;
    }
    // 4. 冒泡排序
    int arr4[5] = {2, 1, 5, 3, 1};
    int len_arr = sizeof(arr4) / sizeof(int);
    cout << "冒泡排序前: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr4[i] << endl;
    }
    for (int i = 0; i < 5 - 1; i++)
    {
        for (int j = 0; j < 5 - i - 1; j++)
        {
            if (arr4[j] > arr4[j + 1])
            {
                int t = arr4[j];
                arr4[j] = arr4[j + 1];
                arr4[j + 1] = t;
            }
        }
    }

    cout << "冒泡排序后: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr4[i] << endl;
    }

    // 5.3 二维数组
    // 5.3.1 二维数组定义方式
    // 1. 数据类型 数组名[行数][列数]
    // 2. 数据类型 数组名[行数][列数] = {{初始化值1, 初始化值2}, {初始化值1, 初始化值2}}
    // 3. 数据类型 数组名[行数][列数] = {初始化值1, 初始化值2, ...}
    // 4. 数据类型 数组名[][列数] = {初始化值1, 初始化值2, ...}

    // 5.3.2 二维数组数组名
    // 1. 查看占用内存空间大小
    int arr5[2][3] = {{1, 2, 3}, {4, 5, 6}};
    cout << "整个数组占用内存空间: " << sizeof(arr5) << endl;
    cout << "数组的第一行占用内存为: " << sizeof(arr5[0]) << endl;
    cout << "数组中第一个元素占用内存为: " << sizeof(arr5[0][0]) << endl;
    cout << "二维数组行数为: " << sizeof(arr5) / sizeof(arr5[0]) << endl;
    cout << "二维数组列数为: " << sizeof(arr5[0]) / sizeof(arr5[0][0]) << endl;
    // 2. 查看二维数组的首地址
    cout << "二维数组的首地址为: " << arr5 << endl;
    cout << "二维数组第一行地址为: " << &arr5[0] << endl;
    cout << "二维数组第二行地址为: " << &arr5[1] << endl;
    cout << "二维数组中第一个元素的首地址为: " << &arr5[0][0] << endl;
    cout << "二维数组中第二个元素的首地址为: " << &arr5[0][1] << endl;

    return 0;
}