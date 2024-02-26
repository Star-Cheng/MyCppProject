#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Student {
    string name;
    int id;
    float score;

    Student(string n, int i, float s) : name(n), id(i), score(s) {}
};

class GradeManagementSystem {
private:
    vector<Student> students;

public:
    void AddStudent() {
        string name;
        int id;
        float score;

        cout << "Enter student name: ";
        cin >> name;

        cout << "Enter student ID: ";
        cin >> id;

        cout << "Enter student score: ";
        cin >> score;

        students.push_back(Student(name, id, score));
        cout << "Student added successfully!" << endl;
    }

    void DisplayStudents() {
        cout << "--------------------------" << endl;
        cout << "ID\tName\tScore" << endl;
        cout << "--------------------------" << endl;

        for (const auto& student : students) {
            cout << student.id << "\t" << student.name << "\t" << student.score << endl;
        }

        cout << "--------------------------" << endl;
    }

    void SearchStudent() {
        int id;
        cout << "Enter student ID to search: ";
        cin >> id;

        auto it = find_if(students.begin(), students.end(), [id](const Student& s) {
            return s.id == id;
        });

        if (it != students.end()) {
            cout << "Student found:" << endl;
            cout << "ID\tName\tScore" << endl;
            cout << "--------------------------" << endl;
            cout << it->id << "\t" << it->name << "\t" << it->score << endl;
            cout << "--------------------------" << endl;
        } else {
            cout << "Student not found!" << endl;
        }
    }

    void DeleteStudent() {
        int id;
        cout << "Enter student ID to delete: ";
        cin >> id;

        auto it = find_if(students.begin(), students.end(), [id](const Student& s) {
            return s.id == id;
        });

        if (it != students.end()) {
            students.erase(it);
            cout << "Student deleted successfully!" << endl;
        } else {
            cout << "Student not found!" << endl;
        }
    }
};

void ShowMenu() {
    cout << "***************************************" << endl;
    cout << "|--------0、退出系统---------------------|" << endl;
    cout << "|--------1、添加学生--------------------|" << endl;
    cout << "|--------2、显示所有学生------------------|" << endl;
    cout << "|--------3、查询学生--------------------|" << endl;
    cout << "|--------4、删除学生--------------------|" << endl;
    cout << "---------------------------------------" << endl;
}

int main() {
    int choice;
    GradeManagementSystem system;

    while (true) {
        ShowMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Exiting system. Goodbye!" << endl;
                return 0;
            case 1:
                system.AddStudent();
                break;
            case 2:
                system.DisplayStudents();
                break;
            case 3:
                system.SearchStudent();
                break;
            case 4:
                system.DeleteStudent();
                break;
            default:
                cout << "Invalid choice. Please enter a number between 0 and 4." << endl;
                break;
        }
    }

    return 0;
}
