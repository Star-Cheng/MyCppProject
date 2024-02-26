#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 20; // 散列表大小，可根据需求进行调整

class Employee {
public:
    string name;
    string position;
    string department;

    Employee(string n, string p, string d) : name(n), position(p), department(d) {}
};

class HashTable {
private:
    Employee** table;
    int count; // 记录散列表中已存储的职工信息数量

public:
    HashTable() {
        table = new Employee*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
        count = 0;
    }

    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != nullptr) {
                delete table[i];
            }
        }
        delete[] table;
    }

    int hashFunction(const string& key) const {
        int sum = 0;
        for (char c : key) {
            sum += c;
        }
        return sum % TABLE_SIZE;
    }

    void insertEmployee(const Employee& emp) {
        int index = hashFunction(emp.name);
        while (table[index] != nullptr) { // 处理冲突的方法：线性探测法
            index = (index + 1) % TABLE_SIZE;
        }
        table[index] = new Employee(emp);
        count++;
    }

    Employee* searchEmployee(const string& key) {
        int index = hashFunction(key);
        int i = 0;
        while (table[index] != nullptr && i < TABLE_SIZE) {
            if (table[index]->name == key) {
                return table[index];
            }
            index = (index + 1) % TABLE_SIZE;
            i++;
        }
        return nullptr; // 未找到职工信息
    }

    bool removeEmployee(const string& key) {
        int index = hashFunction(key);
        int i = 0;
        while (table[index] != nullptr && i < TABLE_SIZE) {
            if (table[index]->name == key) {
                delete table[index];
                table[index] = nullptr;
                count--;
                return true;
            }
            index = (index + 1) % TABLE_SIZE;
            i++;
        }
        return false; // 未找到该职工信息，无法删除
    }

    bool updateEmployee(const string& key) {
        Employee* emp = searchEmployee(key);
        if (emp != nullptr) {
            cout << "请输入该职工的新职位：";
            string position;
            cin >> position;
            cout << "请输入该职工的新部门：";
            string department;
            cin >> department;
            emp->position = position;
            emp->department = department;
            return true;
        } else {
            return false; // 未找到该职工信息，无法更新
        }
    }

    void printAllEmployees() {
        if (count == 0) {
            cout << "当前散列表中没有职工信息。" << endl;
            return;
        }
        cout << "所有职工信息如下：" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != nullptr) {
                cout << "姓名：" << table[i]->name << "，职位：" << table[i]->position << "，部门：" << table[i]->department << endl;
            }
        }
    }

    void printEmployeesByDepartment(const string& department) {
        vector<Employee> vec;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != nullptr && table[i]->department == department) {
                vec.push_back(*table[i]);
            }
        }
        if (vec.empty()) {
            cout << "未找到该部门的职工信息。" << endl;
            return;
        }
        cout << "部门为" << department << "的职工信息如下：" << endl;
        for (const auto& emp : vec) {
            cout << "姓名：" << emp.name << "，职位：" << emp.position << endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.insertEmployee(Employee("admin", "Manager", "Finance"));
    ht.insertEmployee(Employee("ming", "Engineer", "IT"));
    ht.insertEmployee(Employee("alex", "Salesperson", "Marketing"));

    while (true) {
        cout << "请选择要进行的操作（1-添加职工信息，2-查找职工信息，3-删除职工信息，4-修改职工信息，5-输出所有职工信息，6-按部门分类输出职工信息，0-退出）：";
        int choose;
        cin >> choose;
        if (choose == 0) {
            break;
        }
        switch (choose) {
        case 1: {
            cout << "请输入职工姓名、职位和部门，以空格分隔：";
            string name, position, department;
            cin >> name >> position >> department;
            ht.insertEmployee(Employee(name, position, department));
            cout << "成功添加职工信息。" << endl;
            break;
        }
        case 2: {
            cout << "请输入要检索的职工姓名：";
            string name;
            cin >> name;
            Employee* emp = ht.searchEmployee(name);
            if (emp != nullptr) {
                cout << "职工姓名：" << emp->name << endl;
                cout << "职位：" << emp->position << endl;
                cout << "部门：" << emp->department << endl;
            } else {
                cout << "未找到该职工信息。" << endl;
            }
            break;
        }
        case 3: {
            cout << "请输入要删除的职工姓名：";
            string name;
            cin >> name;
            if (ht.removeEmployee(name)) {
                cout << "成功删除职工信息。" << endl;
            } else {
                cout << "未找到该职工信息，无法删除。" << endl;
            }
            break;
        }
        case 4: {
            cout << "请输入要修改的职工姓名：";
            string name;
            cin >> name;
            if (ht.updateEmployee(name)) {
                cout << "成功更新职工信息。" << endl;
            } else {
                cout << "未找到该职工信息，无法更新。" << endl;
            }
            break;
        }
        case 5: {
            ht.printAllEmployees();
            break;
        }
        case 6: {
            cout << "请输入要检索的部门名称：";
            string department;
            cin >> department;
            ht.printEmployeesByDepartment(department);
            break;
        }
        default: {
            cout << "无效的输入，请重新选择。" << endl;
            break;
        }
        }
    }

    return 0;
}
