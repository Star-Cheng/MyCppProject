#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    // 4. 程序流程结构
    // 4.1 选择结构
    // 4.1.1. if语句
    // 注意事项, if语句后面不要加分号";"
    int score = 655;
    // cout << "请输入你的成绩: ";
    // cin >> score;
    if (score > 500)
    {
        cout << "一本大学"
             << "\n";
        if (score > 600 && score < 650)
        {
            cout << "211大学"
                 << "\n";
        }
        else if (score > 650)
        {
            cout << "985大学"
                 << "\n";
        }
    }
    else if (score < 500 && score > 300)
    {
        cout << "二本大学"
             << "\n";
    }
    else
    {
        cout << "大专院校"
             << "\n";
    }
    // 判断三只小猪的体重
    int a, b, c, t;
    a = 200;
    b = 300;
    c = 100;
    // cout << "The weight of pig A: ";
    // cin >> a;
    // cout << "The weight of pig B: ";
    // cin >> b;
    // cout << "The weight of pig C: ";
    // cin >> c;
    t = a;
    if (a > b)
    {
        t = a;
        if (a > c)
        {
            t = a;
            cout << "小猪A最重,重" << t << "\n";
        }
        else
        {
            t = c;
            cout << "小猪C最重,重" << t << "\n";
        }
    }
    else
    {
        t = b;
        if (b > c)
        {
            t = b;
            cout << "小猪B最重,重" << t << "\n";
        }
        else
        {
            t = c;
            cout << "小猪C最重,重" << t << "\n";
        }
    }
    // t = max(max(a,b),c);
    cout << "The heaviest of pig is: " << t << "\n";

    // 4.1.2 三目运算符
    int a1 = 10;
    int b1 = 20;
    int c1 = 0;
    c1 = (a1 > b1 ? a1 : b1);
    cout << "c1 = " << c1 << "\n";
    // 在C++中三目运算符返回的是变量，可以继续赋值
    (a1 > b1 ? a1 : b1) = 100;
    cout << "a1 = " << a1 << "\n";
    cout << "b1 = " << b1 << "\n";

    // 4.1.3 swtich语句
    int month;
    month = 4;
    switch (month)
    {
    case 1:
    case 2:
    case 3:
        cout << "春季"
             << "\n";
        break;
    case 4:
    case 5:
    case 6:
        cout << "夏季"
             << "\n";
        break;
    case 7:
    case 8:
    case 9:
        cout << "秋季"
             << "\n";
        break;
    case 10:
    case 11:
    case 12:
        cout << "冬季"
             << "\n";
        break;
    default:
        cout << "输入错误"
             << "\n";
        break;
    }
    // if和switch区别
    // switch缺点, 判断时候只能是整形或者字符型, 不可以是一个区间
    // switch优点, 结构清晰, 执行效率高

    // 4.2 循环结构
    // 4.2.1 while循环
    // 猜数字游戏
    // 1.系统生成随机数
    srand((unsigned int)time(0));
    int num = rand() % 100 + 1;
    cout << "num = " << num << "\n";
    bool flag = true;
    while (flag)
    {
        int val;
        cout << "猜一个数字: "
             << "";
        cin >> val;
        if (val == num)
        {
            cout << "恭喜你猜对了"
                 << "\n";
            flag = false;
        }
        else if (val > num)
        {
            cout << "猜大了"
                 << "\n";
        }
        else
        {
            cout << "猜小了"
                 << "\n";
        }
    }

    // 4.2.2 do...while循环
    int i = 0;
    do
    {
        cout << "i = " << i << "\n";
        i++;
    } while (i < 10);
    // while 和 do...while区别, do...while循环至少执行一次
    // 4.2.3 for循环
    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            cout << "i = " << i << "\n";
            break;
        }
        continue;
        cout << "i = " << i << "\n";
    }
    
    // 4.3 跳转语句
    cout << "1. xxxxx" << endl;
    cout << "2. xxxxx" << endl;
    goto label;
    cout << "3. xxxxx" << endl;
    label:
    cout << "4. xxxxx" << endl;
    cout << "5. xxxxx" << endl;
    return 0;
}