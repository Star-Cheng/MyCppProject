#include <iostream>
#include <string>

using namespace std;

const int TABLE_SIZE = 10; // 散列表大小，可根据需求进行调整

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

public:
    HashTable() {
        table = new Employee*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
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
    }

    Employee* searchEmployee(const string& key) {
        int index = hashFunction(key);
        int count = 0;
        while (table[index] != nullptr && count < TABLE_SIZE) {
            if (table[index]->name == key) {
                return table[index];
            }
            index = (index + 1) % TABLE_SIZE;
            count++;
        }
        return nullptr; // 未找到职工信息
    }
};

int main() {
    HashTable ht;
    ht.insertEmployee(Employee("admin", "Manager", "Finance"));
    ht.insertEmployee(Employee("ming", "Engineer", "IT"));
    ht.insertEmployee(Employee("alex", "Salesperson", "Marketing"));

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

    return 0;
}
