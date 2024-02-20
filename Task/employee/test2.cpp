#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
public:
    int studentId;
    string name;
    string gender;
    string address;
    string contactNumber;
    double chineseScore;
    double mathScore;
    double englishScore;
    double examAverage;
    int examRank;
    double peerEvaluation;
    double moralScore;
    double teacherEvaluation;
    double totalScore;
    int totalRank;

    Student(int _studentId, const string& _name, const string& _gender, const string& _address, const string& _contactNumber)
        : studentId(_studentId), name(_name), gender(_gender), address(_address), contactNumber(_contactNumber),
          chineseScore(0), mathScore(0), englishScore(0), examAverage(0), examRank(0),
          peerEvaluation(0), moralScore(0), teacherEvaluation(0), totalScore(0), totalRank(0) {}

    void calculateExamAverage() {
        examAverage = (chineseScore + mathScore + englishScore) / 3;
    }

    void calculateTotalScore() {
        totalScore = examAverage * 0.6 + peerEvaluation * 0.1 + moralScore * 0.1 + teacherEvaluation * 0.2;
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
    // Add student and sort by student ID
    void AddStudent() {
        int studentId;
        string name, gender, address, contactNumber;

        cout << "Enter student ID: ";
        cin >> studentId;

        cout << "Enter student name: ";
        cin >> name;

        cout << "Enter student gender: ";
        cin >> gender;

        cout << "Enter student address: ";
        cin.ignore(); // Ignore newline character left in the buffer
        getline(cin, address);

        cout << "Enter student contact number: ";
        cin >> contactNumber;

        students.emplace_back(studentId, name, gender, address, contactNumber);

        // Sort students by ID
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.studentId < b.studentId;
        });

        cout << "Student added successfully!" << endl;
    }

    // Display student information
    void DisplayStudents() const {
        cout << "-------------------------------------------------------" << endl;
        cout << "ID\tName\tGender\tAddress\t\tContact Number" << endl;
        cout << "-------------------------------------------------------" << endl;

        for (const Student& student : students) {
            cout << student.studentId << "\t" << student.name << "\t" << student.gender << "\t"
                 << student.address << "\t" << student.contactNumber << endl;
        }

        cout << "-------------------------------------------------------" << endl;
    }

    // Edit student information
    void EditStudent() {
        int studentId;
        cout << "Enter student ID to edit: ";
        cin >> studentId;

        auto it = find_if(students.begin(), students.end(), [studentId](const Student& student) {
            return student.studentId == studentId;
        });

        if (it != students.end()) {
            Student& student = *it;

            cout << "Enter new student name: ";
            cin >> student.name;

            // Other attributes can be edited similarly

            cout << "Student information updated successfully!" << endl;
        } else {
            cout << "No student found with ID " << studentId << endl;
        }
    }

    // Delete student
    void DeleteStudent() {
        int studentId;
        cout << "Enter student ID to delete: ";
        cin >> studentId;

        auto it = find_if(students.begin(), students.end(), [studentId](const Student& student) {
            return student.studentId == studentId;
        });

        if (it != students.end()) {
            students.erase(it);
            cout << "Student deleted successfully!" << endl;
        } else {
            cout << "No student found with ID " << studentId << endl;
        }
    }

    // Calculate exam average and rank
    void CalculateExamData() {
        for (Student& student : students) {
            student.calculateExamAverage();
        }

        // Sort students by exam average
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.examAverage > b.examAverage; // Sort in descending order
        });

        // Assign exam ranks
        for (int i = 0; i < students.size(); ++i) {
            students[i].examRank = i + 1;
        }

        cout << "Exam data calculated successfully!" << endl;
    }

    // Input and calculate evaluation data
    void InputEvaluationData() {
        for (Student& student : students) {
            cout << "Enter peer evaluation score for student " << student.studentId << ": ";
            cin >> student.peerEvaluation;

            cout << "Enter moral score for student " << student.studentId << ": ";
            cin >> student.moralScore;

            cout << "Enter teacher evaluation score for student " << student.studentId << ": ";
            cin >> student.teacherEvaluation;

            student.calculateTotalScore();
        }

        // Sort students by total score
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.totalScore > b.totalScore; // Sort in descending order
        });

        // Assign total ranks
        for (int i = 0; i < students.size(); ++i) {
            students[i].totalRank = i + 1;
        }

        cout << "Evaluation data calculated successfully!" << endl;
    }

    // Display student information
    void DisplayStudentInfo() const {
        cout << "-------------------------------------------------------" << endl;
        cout << "ID\tName\tExam Avg\tExam Rank\tPeer Eval\tMoral Score\tTeacher Eval\tTotal Score\tTotal Rank" << endl;
        cout << "-------------------------------------------------------" << endl;

        for (const Student& student : students) {
            cout << student.studentId << "\t" << student.name << "\t" << student.examAverage << "\t"
                 << student.examRank << "\t" << student.peerEvaluation << "\t" << student.moralScore << "\t"
                 << student.teacherEvaluation << "\t" << student.totalScore << "\t" << student.totalRank << endl;
        }

        cout << "-------------------------------------------------------" << endl;
    }

    // Save student data to a file
    void SaveData() const {
        ofstream outputFile("student_data.txt");
        if (!outputFile.is_open()) {
            cerr << "Error opening file for writing." << endl;
            return;
        }

        for (const Student& student : students) {
            outputFile << student.studentId << " " << student.name << " " << student.gender << " "
                       << student.address << " " << student.contactNumber << " "
                       << student.chineseScore << " " << student.mathScore << " " << student.englishScore << " "
                       << student.examAverage << " " << student.examRank << " "
                       << student.peerEvaluation << " " << student.moralScore << " " << student.teacherEvaluation << " "
                       << student.totalScore << " " << student.totalRank << endl;
        }

        outputFile.close();
        cout << "Student data saved successfully!" << endl;
    }

    // Load student data from a file
    void LoadData() {
        ifstream inputFile("student_data.txt");
        if (!inputFile.is_open()) {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        int studentId;
        string name, gender, address, contactNumber;
        double chineseScore, mathScore, englishScore;
        double examAverage;
        int examRank;
        double peerEvaluation, moralScore, teacherEvaluation;
        double totalScore;
        int totalRank;

        while (inputFile >> studentId >> name >> gender >> address >> contactNumber
               >> chineseScore >> mathScore >> englishScore
               >> examAverage >> examRank
               >> peerEvaluation >> moralScore >> teacherEvaluation
               >> totalScore >> totalRank) {
            students.emplace_back(studentId, name, gender, address, contactNumber);
            Student& student = students.back();
            student.chineseScore = chineseScore;
            student.mathScore = mathScore;
            student.englishScore = englishScore;
            student.examAverage = examAverage;
            student.examRank = examRank;
            student.peerEvaluation = peerEvaluation;
            student.moralScore = moralScore;
            student.teacherEvaluation = teacherEvaluation;
            student.totalScore = totalScore;
            student.totalRank = totalRank;
        }

        inputFile.close();
        cout << "Student data loaded successfully!" << endl;
    }
};

void ShowMenu() {
    cout << "***************************************" << endl;
    cout << "|--------0、退出系统---------------------|" << endl;
    cout << "|--------1、添加学生--------------------|" << endl;
    cout << "|--------2、浏览学生信息------------------|" << endl;
    cout << "|--------3、编辑学生信息------------------|" << endl;
    cout << "|--------4、删除学生信息------------------|" << endl;
    cout << "|--------5、计算考试数据------------------|" << endl;
    cout << "|--------6、输入测评数据------------------|" << endl;
    cout << "|--------7、显示学生综合信息--------------|" << endl;
    cout << "|--------8、保存学生数据------------------|" << endl;
    cout << "|--------9、从文件读取学生数据------------|" << endl;
    cout << "---------------------------------------" << endl;
}

int main() {
    int choice;
    StudentManagementSystem system;

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
            system.EditStudent();
            break;
        case 4:
            system.DeleteStudent();
            break;
        case 5:
            system.CalculateExamData();
            break;
        case 6:
            system.InputEvaluationData();
            break;
        case 7:
            system.DisplayStudentInfo();
            break;
        case 8:
            system.SaveData();
            break;
        case 9:
            system.LoadData();
            break;
        default:
            cout << "Invalid choice. Please enter a number between 0 and 9." << endl;
            break;
        }
    }

    return 0;
}
