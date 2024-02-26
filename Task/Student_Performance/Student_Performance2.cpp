#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 学生类
class Student {
public:
    string name;
    string id;
    float score;

    // 构造函数
    Student(string n, string i, float s) : name(n), id(i), score(s) {}

    // 显示学生信息
    void display() const {
        cout << "姓名: " << name << "\t学号: " << id << "\t成绩: " << score << endl;
    }
};


// 学生成绩管理系统类
class GradeManagementSystem {
private:
    vector<Student> students;

public:
    // 浏览学生信息
    void displayAllStudents() {
        for (const auto& student : students) {
            student.display();
        }
    }

    // 输入学生信息
    void addStudent() {
        string name, id;
        float score;

        cout << "请输入学生姓名: ";
        cin >> name;
        cout << "请输入学生学号: ";
        cin >> id;
        cout << "请输入学生成绩: ";
        cin >> score;

        students.push_back(Student(name, id, score));
        cout << "学生信息添加成功！" << endl;
    }

    // 修改学生成绩
    void modifyStudent() {
        string id;
        cout << "请输入要修改成绩的学生学号: ";
        cin >> id;

        auto it = find_if(students.begin(), students.end(), [id](const Student& student) {
            return student.id == id;
        });

        if (it != students.end()) {
            cout << "请输入新的成绩: ";
            cin >> it->score;
            cout << "成绩修改成功！" << endl;
        } else {
            cout << "未找到该学生学号，无法修改成绩。" << endl;
        }
    }

    // 排序学生成绩
    void sortStudents() {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.score > b.score;
        });

        cout << "学生成绩排序完成！" << endl;
    }

    // 查找学生成绩
    void searchStudent() {
        string keyword;
        cout << "请输入学生姓名或学号进行查找: ";
        cin >> keyword;

        auto it = find_if(students.begin(), students.end(), [keyword](const Student& student) {
            return student.name == keyword || student.id == keyword;
        });

        if (it != students.end()) {
            it->display();
        } else {
            cout << "未找到符合条件的学生信息。" << endl;
        }
    }

    // 删除学生成绩
    void deleteStudent() {
        string keyword;
        cout << "请输入要删除成绩的学生姓名或学号: ";
        cin >> keyword;

        auto it = remove_if(students.begin(), students.end(), [keyword](const Student& student) {
            return student.name == keyword || student.id == keyword;
        });

        if (it != students.end()) {
            students.erase(it, students.end());
            cout << "学生成绩删除成功！" << endl;
        } else {
            cout << "未找到符合条件的学生信息，无法删除成绩。" << endl;
        }
    }
};

int main() {
    GradeManagementSystem system;

    while (true) {
        cout << "\n学生成绩管理系统\n";
        cout << "1.浏览学生信息\n";
        cout << "2.输入学生信息\n";
        cout << "3.增加学生成绩模块\n";
        cout << "4.修改学生成绩模块\n";
        cout << "5.排序统计成绩模块\n";
        cout << "6.查找学生成绩模块\n";
        cout << "7.删除学生成绩模块\n";
        cout << "8.退出模块\n";
        cout << "请选择操作（1-8）: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                system.displayAllStudents();
                break;
            case 2:
                system.addStudent();
                break;
            case 3:
                system.addStudent();
                break;
            case 4:
                system.displayAllStudents();
                system.modifyStudent();
                break;
            case 5:
                system.sortStudents();
                break;
            case 6:
                system.searchStudent();
                break;
            case 7:
                system.deleteStudent();
                break;
            case 8:
                cout << "退出学生成绩管理系统。" << endl;
                return 0;
            default:
                cout << "无效的选项，请重新选择。" << endl;
        }
    }

    return 0;
}
