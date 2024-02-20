#include <iostream>
#include <mysql.h>
#include <string>
#include <vector>

using namespace std;

MYSQL library; // Database handle

class Employee {
public:
    int id;
    string name;
    string gender;
    string department;
    string level;

    Employee(int _id, const string& _name, const string& _gender, const string& _department, const string& _level)
        : id(_id), name(_name), gender(_gender), department(_department), level(_level) {}

    virtual double calculateSalary() const = 0; // Virtual function for calculating salary
};

class Manager : public Employee {
public:
    double fixedSalary;

    Manager(int _id, const string& _name, const string& _gender, const string& _department, const string& _level, double _fixedSalary)
        : Employee(_id, _name, _gender, _department, _level), fixedSalary(_fixedSalary) {}

    double calculateSalary() const override {
        return fixedSalary;
    }
};

class TechnicalStaff : public Employee {
public:
    int hoursWorked;
    double hourlyRate;

    TechnicalStaff(int _id, const string& _name, const string& _gender, const string& _department, const string& _level, int _hoursWorked, double _hourlyRate)
        : Employee(_id, _name, _gender, _department, _level), hoursWorked(_hoursWorked), hourlyRate(_hourlyRate) {}

    double calculateSalary() const override {
        return hoursWorked * hourlyRate;
    }
};

class Salesperson : public Employee {
public:
    double salesAmount;
    double commissionRate;

    Salesperson(int _id, const string& _name, const string& _gender, const string& _department, const string& _level, double _salesAmount, double _commissionRate)
        : Employee(_id, _name, _gender, _department, _level), salesAmount(_salesAmount), commissionRate(_commissionRate) {}

    double calculateSalary() const override {
        return salesAmount * commissionRate;
    }
};

class SalesManager : public Manager {
public:
    double salesAmount;
    double commissionRate;

    SalesManager(int _id, const string& _name, const string& _gender, const string& _department, const string& _level, double _fixedSalary, double _salesAmount, double _commissionRate)
        : Manager(_id, _name, _gender, _department, _level, _fixedSalary), salesAmount(_salesAmount), commissionRate(_commissionRate) {}

    double calculateSalary() const override {
        return fixedSalary + salesAmount * commissionRate;
    }
};

class EmployeeManagementSystem {
private:
    MYSQL* connection;
    vector<Employee*> employees;

public:
    EmployeeManagementSystem() {
        connection = connectDB();
    }

    ~EmployeeManagementSystem() {
        for (Employee* emp : employees) {
            delete emp;
        }
        mysql_close(connection);
    }

    MYSQL* connectDB() {
        MYSQL* conn = mysql_init(&library);
        // ... (same as your existing connectDB function)
        return conn;
    }

    // Add employee based on user input
    void AddEmployee() {
        int id;
        string name, gender, department, level;
        double fixedSalary, hourlyRate, salesAmount, commissionRate;
        int hoursWorked;

        cout << "Enter employee ID: ";
        cin >> id;

        cout << "Enter employee name: ";
        cin >> name;

        cout << "Enter employee gender: ";
        cin >> gender;

        cout << "Enter employee department: ";
        cin >> department;

        cout << "Enter employee level (Manager/TechnicalStaff/Salesperson/SalesManager): ";
        cin >> level;

        if (level == "Manager") {
            cout << "Enter manager's fixed salary: ";
            cin >> fixedSalary;
            employees.push_back(new Manager(id, name, gender, department, level, fixedSalary));
        } else if (level == "TechnicalStaff") {
            cout << "Enter hours worked: ";
            cin >> hoursWorked;

            cout << "Enter hourly rate: ";
            cin >> hourlyRate;

            employees.push_back(new TechnicalStaff(id, name, gender, department, level, hoursWorked, hourlyRate));
        } else if (level == "Salesperson") {
            cout << "Enter sales amount: ";
            cin >> salesAmount;

            cout << "Enter commission rate: ";
            cin >> commissionRate;

            employees.push_back(new Salesperson(id, name, gender, department, level, salesAmount, commissionRate));
        } else if (level == "SalesManager") {
            cout << "Enter manager's fixed salary: ";
            cin >> fixedSalary;

            cout << "Enter sales amount: ";
            cin >> salesAmount;

            cout << "Enter commission rate: ";
            cin >> commissionRate;

            employees.push_back(new SalesManager(id, name, gender, department, level, fixedSalary, salesAmount, commissionRate));
        } else {
            cout << "Invalid level entered." << endl;
        }
    }

    // Display information of all employees
    void DisplayEmployees() const {
        cout << "-------------------------------------------------------" << endl;
        cout << "ID\tName\tGender\tDepartment\tLevel\tSalary" << endl;
        cout << "-------------------------------------------------------" << endl;

        for (const Employee* emp : employees) {
            cout << emp->id << "\t" << emp->name << "\t" << emp->gender << "\t" << emp->department << "\t"
                 << emp->level << "\t" << emp->calculateSalary() << endl;
        }

        cout << "-------------------------------------------------------" << endl;
    }

    // Edit information of an employee
    void EditEmployee() {
        int id;
        cout << "Enter employee ID to edit: ";
        cin >> id;

        auto it = find_if(employees.begin(), employees.end(), [id](const Employee* emp) { return emp->id == id; });

        if (it != employees.end()) {
            Employee* emp = *it;

            cout << "Enter new employee name: ";
            cin >> emp->name;

            // Update other attributes based on employee type (Manager, TechnicalStaff, Salesperson, SalesManager)
            if (Manager* manager = dynamic_cast<Manager*>(emp)) {
                cout << "Enter new manager's fixed salary: ";
                cin >> manager->fixedSalary;
            } else if (TechnicalStaff* techStaff = dynamic_cast<TechnicalStaff*>(emp)) {
                cout << "Enter new hours worked: ";
                cin >> techStaff->hoursWorked;

                cout << "Enter new hourly rate: ";
                cin >> techStaff->hourlyRate;
            } else if (Salesperson* salesperson = dynamic_cast<Salesperson*>(emp)) {
                cout << "Enter new sales amount: ";
                cin >> salesperson->salesAmount;

                cout << "Enter new commission rate: ";
                cin >> salesperson->commissionRate;
            } else if (SalesManager* salesManager = dynamic_cast<SalesManager*>(emp)) {
                cout << "Enter new manager's fixed salary: ";
                cin >> salesManager->fixedSalary;

                cout << "Enter new sales amount: ";
                cin >> salesManager->salesAmount;

                cout << "Enter new commission rate: ";
                cin >> salesManager->commissionRate;
            }
            cout << "Employee information updated successfully!" << endl;
        } else {
            cout << "No employee found with ID " << id << endl;
        }
    }

    // Delete an employee
    void DeleteEmployee() {
        int id;
        cout << "Enter employee ID to delete: ";
        cin >> id;

        auto it = find_if(employees.begin(), employees.end(), [id](const Employee* emp) { return emp->id == id; });

        if (it != employees.end()) {
            delete *it;
            employees.erase(it);
            cout << "Employee deleted successfully!" << endl;
        } else {
            cout << "No employee found with ID " << id << endl;
        }
    }

    // Calculate and display statistics
    void Statistics() const {
        // You can implement various statistics based on your requirements
        // Example: Total number of employees
        cout << "Total number of employees: " << employees.size() << endl;
    }

    // Save employee data to a file
    void SaveData() const {
        ofstream outputFile("employee_data.txt");
        if (!outputFile.is_open()) {
            cerr << "Error opening file for writing." << endl;
            return;
        }

        for (const Employee* emp : employees) {
            outputFile << emp->id << " " << emp->name << " " << emp->gender << " " << emp->department << " " << emp->level;
            if (const Manager* manager = dynamic_cast<const Manager*>(emp)) {
                outputFile << " " << manager->fixedSalary;
            } else if (const TechnicalStaff* techStaff = dynamic_cast<const TechnicalStaff*>(emp)) {
                outputFile << " " << techStaff->hoursWorked << " " << techStaff->hourlyRate;
            } else if (const Salesperson* salesperson = dynamic_cast<const Salesperson*>(emp)) {
                outputFile << " " << salesperson->salesAmount << " " << salesperson->commissionRate;
            } else if (const SalesManager* salesManager = dynamic_cast<const SalesManager*>(emp)) {
                outputFile << " " << salesManager->fixedSalary << " " << salesManager->salesAmount << " " << salesManager->commissionRate;
            }
            outputFile << endl;
        }

        outputFile.close();
        cout << "Employee data saved successfully!" << endl;
    }

    // Read employee data from a file
    void LoadData() {
        ifstream inputFile("employee_data.txt");
        if (!inputFile.is_open()) {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        int id;
        string name, gender, department, level;
        double fixedSalary, hourlyRate, salesAmount, commissionRate;
        int hoursWorked;

        while (inputFile >> id >> name >> gender >> department >> level) {
            if (level == "Manager") {
                inputFile >> fixedSalary;
                employees.push_back(new Manager(id, name, gender, department, level, fixedSalary));
            } else if (level == "TechnicalStaff") {
                inputFile >> hoursWorked >> hourlyRate;
                employees.push_back(new TechnicalStaff(id, name, gender, department, level, hoursWorked, hourlyRate));
            } else if (level == "Salesperson") {
                inputFile >> salesAmount >> commissionRate;
                employees.push_back(new Salesperson(id, name, gender, department, level, salesAmount, commissionRate));
            } else if (level == "SalesManager") {
                inputFile >> fixedSalary >> salesAmount >> commissionRate;
                employees.push_back(new SalesManager(id, name, gender, department, level, fixedSalary, salesAmount, commissionRate));
            } else {
                cerr << "Invalid employee level read from file." << endl;
                break;
            }
        }

        inputFile.close();
        cout << "Employee data loaded successfully!" << endl;
    }
};

void ShowMenu() {
    cout << "***************************************" << endl;
    cout << "|--------0、退出系统---------------------|" << endl;
    cout << "|--------1、添加雇员--------------------|" << endl;
    cout << "|--------2、显示所有雇员------------------|" << endl;
    cout << "|--------3、编辑雇员信息------------------|" << endl;
    cout << "|--------4、删除雇员----------------------|" << endl;
    cout << "|--------5、统计信息----------------------|" << endl;
    cout << "|--------6、保存雇员数据------------------|" << endl;
    cout << "|--------7、读取雇员数据------------------|" << endl;
    cout << "---------------------------------------" << endl;
}

int main() {
    int choice;
    EmployeeManagementSystem system;

    while (true) {
        ShowMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Exiting system. Goodbye!" << endl;
            return 0;
        case 1:
            system.AddEmployee();
            break;
        case 2:
            system.DisplayEmployees();
            break;
        case 3:
            system.EditEmployee();
            break;
        case 4:
            system.DeleteEmployee();
            break;
        case 5:
            system.Statistics();
            break;
        case 6:
            system.SaveData();
            break;
        case 7:
            system.LoadData();
            break;
        default:
            cout << "Invalid choice. Please enter a number between 0 and 7." << endl;
            break;
        }
    }

    return 0;
}
