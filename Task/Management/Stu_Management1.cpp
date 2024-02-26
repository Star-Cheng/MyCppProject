#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int id;
    string gender;
    int age;
    string className;
    float score;
};

class GradeManagementSystem {
private:
    vector<Student> students;

public:
    void addStudent() {
        Student student;
        cout << "Enter student name: ";
        cin >> student.name;

        cout << "Enter student ID: ";
        cin >> student.id;

        // Check for unique ID
        if (find_if(students.begin(), students.end(), [id = student.id](const Student& s) { return s.id == id; }) != students.end()) {
            cout << "Error: Student with the same ID already exists!" << endl;
            return;
        }

        cout << "Enter student gender: ";
        cin >> student.gender;

        cout << "Enter student age: ";
        cin >> student.age;

        cout << "Enter student class name: ";
        cin >> student.className;

        cout << "Enter student score: ";
        cin >> student.score;

        students.push_back(student);
        cout << "Student added successfully!" << endl;
    }

    void displayStudents() const {
        cout << "---------------------------------------------" << endl;
        cout << "ID\tName\tGender\tAge\tClass\tScore" << endl;
        cout << "---------------------------------------------" << endl;

        for (const auto& student : students) {
            cout << student.id << "\t" << student.name << "\t" << student.gender << "\t"
                 << student.age << "\t" << student.className << "\t" << student.score << endl;
        }

        cout << "---------------------------------------------" << endl;
    }

    void saveToFile() const {
        ofstream outFile("students.txt");
        if (!outFile.is_open()) {
            cout << "Error: Unable to open file for writing." << endl;
            return;
        }

        for (const auto& student : students) {
            outFile << student.id << " " << student.name << " " << student.gender << " "
                    << student.age << " " << student.className << " " << student.score << endl;
        }

        outFile.close();
        cout << "Data saved to file successfully!" << endl;
    }

    void loadFromFile() {
        students.clear(); // Clear existing data

        ifstream inFile("students.txt");
        if (!inFile.is_open()) {
            cout << "Error: Unable to open file for reading." << endl;
            return;
        }

        Student student;
        while (inFile >> student.id >> student.name >> student.gender >> student.age >> student.className >> student.score) {
            students.push_back(student);
        }

        inFile.close();
        cout << "Data loaded from file successfully!" << endl;
    }

    void sortStudentsById() {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.id < b.id;
        });

        cout << "Students sorted by ID." << endl;
    }

    void sortStudentsByScore() {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.score > b.score;
        });

        cout << "Students sorted by score." << endl;
    }

    // Implement other functions as needed

};

void showMenu() {
    cout << "1. Add Student\n";
    cout << "2. Display Students\n";
    cout << "3. Save to File\n";
    cout << "4. Load from File\n";
    cout << "5. Sort Students by ID\n";
    cout << "6. Sort Students by Score\n";
    cout << "0. Exit\n";
}

int main() {
    GradeManagementSystem system;

    int choice;
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addStudent();
                break;
            case 2:
                system.displayStudents();
                break;
            case 3:
                system.saveToFile();
                break;
            case 4:
                system.loadFromFile();
                break;
            case 5:
                system.sortStudentsById();
                break;
            case 6:
                system.sortStudentsByScore();
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
