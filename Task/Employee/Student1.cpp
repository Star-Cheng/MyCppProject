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
    // 增加职工信息
    system.addEmployee("001", "张三", "技术部", "工程师", 8000);
    system.addEmployee("002", "李四", "市场部", "销售员", 6000);
    system.addEmployee("003", "王五", "技术部", "经理", 10000);
    system.addEmployee("004", "赵六", "财务部", "会计", 7000);

    // 显示所有职工信息
    system.displayAllEmployees();

    // 按部门名称分类显示该部门所有职工信息
    system.displayEmployeesByDepartment("技术部");

    // 按部门显示各部门职工工资总额
    system.displayTotalSalaryByDepartment();

    // 删除职工信息
    system.deleteEmployee("002");

    // 调整工资
    system.adjustSalaryByTitle("工程师", 9000);

    return 0;
}
