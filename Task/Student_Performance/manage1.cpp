#include <iostream>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    int id;
    int score;
};

class GradeSystem {
private:
    std::vector<Student> students;

public:
    void displayStudents() {
        for (const auto& student : students) {
            std::cout << "Name: " << student.name << ", ID: " << student.id << ", Score: " << student.score << std::endl;
        }
    }

    void addStudent(const std::string& name, int id, int score) {
        Student newStudent = {name, id, score};
        students.push_back(newStudent);
    }

    void updateStudentScore(int id, int newScore) {
        for (auto& student : students) {
            if (student.id == id) {
                student.score = newScore;
                break;
            }
        }
    }

    void sortStudentsByScore() {
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.score > b.score;
        });
    }

    void searchStudent(const std::string& query) {
        for (const auto& student : students) {
            if (student.name == query || std::to_string(student.id) == query) {
                std::cout << "Name: " << student.name << ", ID: " << student.id << ", Score: " << student.score << std::endl;
            }
        }
    }

    void deleteStudent(const std::string& query) {
        students.erase(std::remove_if(students.begin(), students.end(), [&](const Student& student) {
            return student.name == query || std::to_string(student.id) == query;
        }), students.end());
    }
};

int main() {
    GradeSystem gradeSystem;
    int choice;
    do {
        // std::cout << "1. Display students' information" << std::endl;
        std::cout << "1. 显示学生信息" << std::endl;
        // std::cout << "2. Add student information" << std::endl;
        std::cout << "2. 添加学生信息" << std::endl;
        // std::cout << "3. Add student grade" << std::endl;
        std::cout << "3. 添加学生成绩" << std::endl;
        // std::cout << "4. Update student grade" << std::endl;
        std::cout << "4. 更新学生成绩" << std::endl;
        // std::cout << "5. Sort and display students by score" << std::endl;
        std::cout << "5. 按分数对学生进行排序和显示" << std::endl;
        // std::cout << "6. Search for a student" << std::endl;
        std::cout << "6. 搜索学生" << std::endl;
        // std::cout << "7. Delete student information" << std::endl;
        std::cout << "7. 删除学生信息" << std::endl;
        // std::cout << "8. Modify student information" << std::endl;
        std::cout << "8. 修改学生信息" << std::endl;
        // std::cout << "9. Exit" << std::endl;
        std::cout << "9. 退出" << std::endl;
        std::cout << "输入您的选择: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                gradeSystem.displayStudents();
                break;
            case 2:
                // Add student information logic
                break;
            case 3:
                // Add student grade logic
                break;
            case 4:
                // Update student grade logic
                break;
            case 5:
                gradeSystem.sortStudentsByScore();
                gradeSystem.displayStudents();
                break;
            case 6:
                // Search for a student logic
                break;
            case 7:
                // Delete student information logic
                break;
            case 8:
                // Modify student information logic
                break;
            case 9:
                std::cout << "Exiting the system" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 9);

    return 0;
}
