#include <iostream>
using namespace std;
int main()
{
    // 2.1 整形大小比较: shor < int <= long < long long
    cout << "hello world"
            "\n";
    // 1. 短整型（-32768--32767）
    short num1 = 32767;
    cout << num1 << "\n";
    // 2. 整形（-2147483648--2147483647）
    int num2 = 2147483647;
    cout << num2 << "\n";
    // 3. 长整型（-2147483648--2147483647）
    long num3 = 2147483647;
    cout << num3 << "\n";
    // 4. 长长整型（-9223372036854775808--9223372036854775807）
    long long num4 = 9223372036854775807;
    cout << num4 << "\n";

    // 2.2 sizeof关键字
    cout << "short:" << sizeof(short) << "B" << '\n';
    cout << "int:" << sizeof(int) << "B" << '\n';
    cout << "long:" << sizeof(long) << "B" << '\n';
    cout << "long long:" << sizeof(long long) << "B" << '\n';

    // 2.3 实型(浮点型)
    // 1. 单精度(-3.40282347E+38~3.40282347E+38)
    float f1 = 3.14f;
    cout << f1 << "\n";
    // 2. 双精度(-1.7976931348623157E+308~1.7976931348623157E+308)
    double d1 = 3.14;
    cout << d1 << "\n";
    // 统计float和double占用的字节
    cout << "float:" << sizeof(f1) << "B" << '\n';
    cout << "double:" << sizeof(d1) << "B" << '\n';
    // 科学计数法
    float f2 = 3e-2;
    cout << "科学计数法3e-2=" << f2 << "\n";

    // 2.4 字符类型
    // 1. 字符型变量的创建方式
    char ch = 'a';
    cout << ch << "\n";
    // 2. 字符型变量所占内存大小
    cout << "char:" << sizeof(ch) << "B" << '\n';
    // 3. 字符型变量常见错误
    char ch2 = 'b'; // 创建字符型变量时候,要用单引号:''
    cout << ch2 << "\n";
    // char ch3 = 'abc'  // 创建字符型变量的时候,单引号内只能用一个字符
    // 4. 字符型变量对应ASCII编码
    // a - 97
    // A - 65
    cout << "a的ASCII编码为:" << (int)ch << "\n";
    cout << "A的ASCII编码为:" << (int)'A' << "\n";

    // 2.5 转义字符
    // 作用: 用于表示一些不能显示出来的ASCII字符
    // 换行符: \n
    // 反斜杠: \\ : 可以整齐的输出数据
    // 制表符: \t
    cout << "换行符:\n"
         << '\n';
    cout << "反斜杠:\\" << '\n';
    cout << "制表符:aaa\thello world" << '\n';
    cout << "制表符:aa\thello world" << '\n';
    cout << "制表符:a\thello world" << '\n';

    // 2.6 字符串型
    // 1. C风格字符串
    // 注意事项1: char字符串名[]
    // 注意事项2: 等号后面要用双引号: "hello world"
    char str1[] = "hello world";
    cout << "C风格字符串:\t" << str1 << "\n";
    // 2. C++风格字符串
    // 注意事项3: 包含头文件: #include <string>
    string str2 = "hello world";
    cout << "C++风格字符串:\t" << str2 << "\n";

    // 2.7 布尔类型
    // 1.创建bool数据类型
    bool b1 = true;
    cout << "bool类型:\t" << b1 << "\n";
    b1 = false;
    cout << "bool类型:\t" << b1 << "\n";
    // 2. 查看bool类型所占内存大小
    cout << "bool所占内存大小:" << sizeof(b1) << "B" << '\n';

    // 2.8 数据输入
    // 1. 整形
    int a = 0;
    cout << "请给整型变量a赋值: " << "\n";
    cin >> a;
    cout << "a的值为:" << a << "\n";
    // 2. 浮点型
    float b = 0;
    cout << "请给浮点型变量b赋值: " << "\n";
    cin >> b;
    cout << "b的值为:" << b << "\n";
    // 3. 字符型
    char c = 'a';
    cout << "请给字符型变量c赋值: " << "\n";
    cin >> c;
    cout << "c的值为:" << c << "\n";
    // 4. 字符串型
    string d = "";
    cout << "请给字符串型变量d赋值: " << "\n";
    cin >> d;
    cout << "d的值为:" << d << "\n";
    // 5. 布尔型
    bool e = false;
    cout << "请给布尔型变量e赋值: " << "\n";
    cin >> e;
    cout << "e的值为:" << e << "\n";
    return 0;
}