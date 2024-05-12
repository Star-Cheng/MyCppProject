#include <iostream>
using namespace std;
#include <string.h>
#include <time.h>
struct Student
{
    string name;
    int age;
    float score;
};
struct teacher
{
    int id; // 工号
    string name;
    int age;
    Student stu;
};
struct teachers
{
    string name;
    int s_len = 3;
    Student stu[3]; // 一个老师可以带多个学生
};
void printStudent1(Student s)
{
    s.name = "张三";
    cout << "姓名：" << s.name << " "
         << "年龄：" << s.age << " "
         << "成绩：" << s.score << endl;
}
// 将函数中的形参改为指针, 可以减少内存, 而且不会复制新的副本出来
void printStudent2(Student *p)
{
    p->name = "张三";
    cout << "姓名：" << p->name << " "
         << "年龄：" << p->age << " "
         << "成绩：" << p->score << endl;
}
void printStudent3(const Student *p)
{
    // p->name = "张三";  // 加入const一旦有修改操作就会报错
    cout << "姓名：" << p->name << " "
         << "年龄：" << p->age << " "
         << "成绩：" << p->score << endl;
}
void printInfo(teachers tArray[], int t_len)
{
    for (int i = 0; i < t_len; i++)
    {
        cout << "老师姓名:" << tArray[i].name << endl;
        for (int j = 0; j < tArray[i].s_len; j++)
        {
            cout << "学生姓名：" << tArray[i].stu[j].name << " "
                 << "学生年龄：" << tArray[i].stu[j].age << " "
                 << "学生成绩：" << tArray[i].stu[j].score << endl;
        }
    }
}
struct hero
{
    string name;
    int age;
    string sex;
};

void sort_age(hero hero_arr[], int hero_len)
{
    for (int i = 0; i < hero_len - 1; i++)
    {
        for (int j = 0; j < hero_len - i - 1; j++)
        {
            if (hero_arr[j].age > hero_arr[j + 1].age)
            {
                hero temp = hero_arr[j];
                hero_arr[j] = hero_arr[j + 1];
                hero_arr[j + 1] = temp;
            }
        }
    }
}
void printHero(hero hero_arr[], int hero_len)
{
    for (int i = 0; i < hero_len; i++)
    {
        cout << hero_arr[i].name << " "
             << hero_arr[i].age << " "
             << hero_arr[i].sex << endl;
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    // 8.1 结构体的概念
    // 结构体属于用户自定义的数据类型
    Student s1 = {"张三", 18, 100}; // 在C++中struct关键字可以省略
    cout << "姓名：" << s1.name << endl;
    cout << "年龄：" << s1.age << endl;
    cout << "成绩：" << s1.score << endl;
    cout << "hello world" << endl;
    // 8.2 结构体数组
    Student s2[3] = {
        {"张三", 18, 100},
        {"李四", 19, 99},
        {"王五", 20, 98}};
    for (int i = 0; i < 3; i++)
    {
        cout << "姓名：" << s2[i].name << " "
             << "年龄：" << s2[i].age << " "
             << "成绩：" << s2[i].score << endl;
    }
    // 8.3 结构体指针
    Student *p = &s2[1];
    cout << "姓名：" << p->name << endl;
    cout << "年龄：" << p->age << endl;
    cout << "成绩：" << p->score << endl;
    // 8.4 结构体嵌套
    teacher t1 = {1001, "张老师", 28, {"李四", 19, 99}};
    cout << "老师姓名：" << t1.name << " "
         << "老师年龄：" << t1.age << " "
         << "老师的学生姓名：" << t1.stu.name << " "
         << "老师的学生年龄：" << t1.stu.age << endl;
    // 8.6 结构体做函数参数
    printStudent1(s2[1]);
    cout << "姓名：" << p->name << " "
         << "年龄：" << p->age << " "
         << "成绩：" << p->score << endl;
    printStudent2(&s2[1]);
    cout << "姓名：" << p->name << " "
         << "年龄：" << p->age << " "
         << "成绩：" << p->score << endl;
    s2[1].name = "李四";
    printStudent3(&s2[1]);
    cout << "姓名：" << p->name << " "
         << "年龄：" << p->age << " "
         << "成绩：" << p->score << endl;
    // 8.7 结构体中const使用场景
    Student s3 = {"张三", 18, 100};
    // 8.8 结构体案例
    teachers tArray[3];
    for (int i = 0; i < 3; i++)
    {
        tArray[i].name = "Teacher_" + to_string(i + 1);
        for (int j = 0; j < tArray->s_len; j++)
        {
            int ranom = rand() % 100;
            tArray[i].stu[j].name = "\tStudent_" + to_string(j + 1);
            tArray[i].stu[j].age = 18 + j;
            tArray[i].stu[j].score = ranom;
        }
    }
    printInfo(tArray, 3);
    hero heroArray[5] =
        {
            {"hero_1", 21, "man"},
            {"hero_2", 20, "man"},
            {"hero_3", 23, "man"},
            {"hero_4", 21, "man"},
            {"hero_5", 18, "woman"},
        };
    sort_age(heroArray, 5);
    printHero(heroArray, 5);
    return 0;
}