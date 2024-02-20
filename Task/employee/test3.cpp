#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// 抽象类 Employee
class Employee {
public:
    virtual int getId() const = 0;  // Virtual function to get employee ID
    virtual double getSalary() const = 0;  // 纯虚函数
    virtual void setSalary(double newSalary) = 0;  // Virtual function to set employee salary
    // Other member functions...

    virtual void calculateSalary() = 0;
    virtual void display() = 0;
    virtual void save(ofstream& ofs) = 0;
    virtual void read(ifstream& ifs) = 0;
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
    int getId() const override {
        return id;
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
    double getSalary() const override {
        // 实现经理的薪资计算
        // 返回适当的经理薪资
    }

    void setSalary(double newSalary) override {
        fixedSalary = newSalary;
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
    // (2) 查询功能
    void searchEmployee(int employeeId) {
        for (Employee* employee : employees) {
            if (employee->getId() == employeeId) {
                cout << "Employee Found:" << endl;
                employee->display();
                return;
            }
        }
        cout << "Employee with ID " << employeeId << " not found." << endl;
    }

    // (4) 编辑功能
    void editEmployee(int employeeId, double newSalary) {
        for (Employee* employee : employees) {
            if (employee->getId() == employeeId) {
                // Assuming salary can be edited for all types of employees
                // You may need to add more logic based on your requirements
                employee->setSalary(newSalary);
                cout << "Employee information updated:" << endl;
                employee->display();
                return;
            }
        }
        cout << "Employee with ID " << employeeId << " not found." << endl;
    }

    // (5) 删除功能
    void deleteEmployee(int employeeId) {
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if ((*it)->getId() == employeeId) {
                delete *it;  // Free memory before removing the pointer from the vector
                employees.erase(it);
                cout << "Employee with ID " << employeeId << " deleted." << endl;
                return;
            }
        }
        cout << "Employee with ID " << employeeId << " not found." << endl;
    }

    // (6) 统计功能
    void statistics() {
        // You can implement various statistics based on your requirements
        double totalSalary = 0.0;
        for (const auto& employee : employees) {
            totalSalary += employee->getSalary();
        }
        cout << "Total salary of all employees: $" << totalSalary << endl;
    }
};

int main() {
    EmployeeManagementSystem ems;

    // 添加功能
    ems.addEmployee(new Manager(1, "John", "Male", "HR", "Senior", 5000));
    ems.addEmployee(new Manager(1, "admin", "Female", "IT", "Senior", 5000));
    ems.addEmployee(new Manager(1, "John", "Male", "HR", "Senior", 5000));
    ems.addEmployee(new Manager(2, "Alice", "Female", "IT", "Junior", 4500));
    ems.addEmployee(new Manager(3, "Bob", "Male", "Finance", "Manager", 6000));
    ems.addEmployee(new Manager(4, "Catherine", "Female", "Marketing", "Senior", 5500));
    ems.addEmployee(new Manager(5, "David", "Male", "IT", "Senior", 5000));
    ems.addEmployee(new Manager(6, "Eva", "Female", "HR", "Junior", 4800));
    ems.addEmployee(new Manager(7, "Frank", "Male", "Finance", "Manager", 5800));


    // 查询功能
    ems.searchEmployee(1);

    // 编辑功能
    ems.editEmployee(1, 6000.0);

    // 显示功能
    ems.displayAllEmployees();

    // 统计功能
    ems.statistics();

    // 删除功能
    ems.deleteEmployee(1);

    // 保存功能
    ems.saveToFile("employees.txt");

    // 读取功能
    ems.readFromFile("employees.txt");

    return 0;
}
