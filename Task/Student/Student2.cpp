#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// 职工记录结构体
struct Employee {
    string no; // 职工编号
    string name; // 职工姓名
    string depname; // 部门名称
    string title; // 职称
    int salary; // 工资
};

// 人事信息管理系统类
class HRSystem {
private:
    map<string, vector<Employee>> employees; // 保存职工信息，按部门分类

public:
    // 增加职工信息
    void addEmployee(string no, string name, string depname, string title, int salary) {
        Employee emp = {no, name, depname, title, salary};
        employees[depname].push_back(emp);
    }

    // 显示所有职工信息
    void displayAllEmployees() {
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            for (int i = 0; i < it->second.size(); ++i) {
                cout << "部门：" << it->first << " 职工编号：" << it->second[i].no << " 姓名：" << it->second[i].name << " 职称：" << it->second[i].title << " 工资：" << it->second[i].salary << endl;
            }
        }
    }

    // 按部门名称分类显示该部门所有职工信息
    void displayEmployeesByDepartment(string depname) {
        for (int i = 0; i < employees[depname].size(); ++i) {
            cout << "部门：" << depname << " 职工编号：" << employees[depname][i].no << " 姓名：" << employees[depname][i].name << " 职称：" << employees[depname][i].title << " 工资：" << employees[depname][i].salary << endl;
        }
    }

    // 按部门显示各部门职工工资总额
    void displayTotalSalaryByDepartment() {
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            int totalSalary = 0;
            for (int i = 0; i < it->second.size(); ++i) {
                totalSalary += it->second[i].salary;
            }
            cout << "部门：" << it->first << " 总工资：" << totalSalary << endl;
        }
    }

    // 删除职工信息
    void deleteEmployee(string no) {
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            for (int i = 0; i < it->second.size(); ++i) {
                if (it->second[i].no == no) {
                    it->second.erase(it->second.begin() + i);
                    cout << "已删除职工编号为" << no << "的记录" << endl;
                    return;
                }
            }
        }
        cout << "未找到职工编号为" << no << "的记录" << endl;
    }

    // 按职称调整工资
    void adjustSalaryByTitle(string title, int newSalary) {
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            for (int i = 0; i < it->second.size(); ++i) {
                if (it->second[i].title == title) {
                    it->second[i].salary = newSalary;
                }
            }
        }
    }
};

int main() {
    HRSystem system;

    while (true) {
        cout << "主菜单:" << endl;
        cout << "1:增加职工信息 " << endl;
        cout << "2:显示所有职工信息 " << endl;
        cout << "3:按部门查找职工信息 " << endl;
        cout << "4:按部门显示总工资 " << endl;
        cout << "5:删除职工信息 " << endl;
        cout << "6:调整工资" << endl;
        cout << "0:退出" << endl;

        int choice;
        cout << "请输入数字选择操作: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // 获取用户输入的职工信息
                string emp_no, emp_name, dep_name, title;
                int salary;
                cout << "请输入职工编号: ";
                cin >> emp_no;
                cout << "请输入职工姓名: ";
                cin >> emp_name;
                cout << "请输入部门名称: ";
                cin >> dep_name;
                cout << "请输入职称: ";
                cin >> title;
                cout << "请输入工资: ";
                cin >> salary;

                system.addEmployee(emp_no, emp_name, dep_name, title, salary);
                break;
            }
            case 2:
                system.displayAllEmployees();
                break;
            case 3: {
                string department;
                cout << "请输入部门名称: ";
                cin >> department;
                system.displayEmployeesByDepartment(department);
                break;
            }
            case 4:
                system.displayTotalSalaryByDepartment();
                break;
            case 5: {
                string emp_no;
                cout << "请输入要删除的职工编号: ";
                cin >> emp_no;
                system.deleteEmployee(emp_no);
                break;
            }
            case 6: {
                string title;
                int new_salary;
                cout << "请输入要调整工资的职称: ";
                cin >> title;
                cout << "请输入新的工资: ";
                cin >> new_salary;
                system.adjustSalaryByTitle(title, new_salary);
                break;
            }
            case 0:
                cout << "感谢使用，再见！" << endl;
                return 0;
            default:
                cout << "无效的选择，请重新输入。" << endl;
        }
    }
}
