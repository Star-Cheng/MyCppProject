#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// 抽象类 Employee
class Employee {
public:
    virtual void calculateSalary() = 0;  // 纯虚函数，需要在派生类中实现
    virtual void display() = 0;  // 纯虚函数，需要在派生类中实现
    virtual void save(ofstream& ofs) = 0;  // 纯虚函数，需要在派生类中实现
    virtual void read(ifstream& ifs) = 0;  // 纯虚函数，需要在派生类中实现
};

// 派生类 Manager
class Manager : public Employee {
private:
    int id;
    string name;
    string gender;
    string department;
    string level;
    double fixedSalary;

public:
    Manager(int id, string name, string gender, string department, string level, double fixedSalary)
        : id(id), name(name), gender(gender), department(department), level(level), fixedSalary(fixedSalary) {}

    void calculateSalary() override {
        // 经理拿固定月薪
        cout << "Manager's monthly salary: " << fixedSalary << endl;
    }

    void display() override {
        cout << "ID: " << id << ", Name: " << name << ", Gender: " << gender << ", Department: " << department << ", Level: " << level << endl;
    }

    void save(ofstream& ofs) override {
        ofs << "Manager " << id << " " << name << " " << gender << " " << department << " " << level << " " << fixedSalary << endl;
    }

    void read(ifstream& ifs) override {
        ifs >> id >> name >> gender >> department >> level >> fixedSalary;
    }
};

// 其他类的实现与Manager类似，这里省略

// 公司员工管理系统类
class EmployeeManagementSystem {
private:
    vector<Employee*> employees;

public:
    void addEmployee(Employee* employee) {
        employees.push_back(employee);
    }

    void displayAllEmployees() {
        for (Employee* employee : employees) {
            employee->display();
        }
    }

    void saveToFile(const string& filename) {
        ofstream ofs(filename);
        for (Employee* employee : employees) {
            employee->save(ofs);
        }
        ofs.close();
    }

    void readFromFile(const string& filename) {
        ifstream ifs(filename);
        // 根据文件内容读取并创建对应的员工对象，这里省略
        ifs.close();
    }
    
};

int main() {
    EmployeeManagementSystem ems;

    // 添加功能
    ems.addEmployee(new Manager(1, "John", "Male", "HR", "Senior", 5000.0));
    // 添加其他类型的员工，这里省略

    // 显示功能
    ems.displayAllEmployees();

    // 保存功能
    ems.saveToFile("employees.txt");

    // 读取功能
    ems.readFromFile("employees.txt");

    return 0;
}
