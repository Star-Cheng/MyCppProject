#include <iostream>
#include <mysql.h>
#include <string>
#include <fstream>

using namespace std;

MYSQL library; // 数据库句柄

struct Student {
    string name;
    int id;
    string gender;
    int age;
    string className;
};

class GradeManagementSystem {
private:
    MYSQL* connection;

public:
    GradeManagementSystem() {
        connection = connectDB();
    }

    ~GradeManagementSystem() {
        mysql_close(connection);
    }

    MYSQL* connectDB() {
		MYSQL* conn = mysql_init(&library);
        if (conn == NULL) {
            cout << "mysql_init failed!" << endl;
            exit(1);
        }

        // 请根据你的数据库配置修改以下参数
        const char* host = "127.0.0.1";
        const char* user = "root";
        const char* password = "python";
        const char* database = "jingdong";
        int port = 3306;

        if (mysql_real_connect(conn, host, user, password, database, port, NULL, 0) == NULL) {
            cout << "mysql_real_connect failed: " << mysql_error(conn) << endl;
            exit(1);
        }

        cout << "Database connected successfully!" << endl;

        return conn;
    }

    void AddStudent() {
        Student student;
        cout << "Enter student name: ";
        cin >> student.name;

        cout << "Enter student ID: ";
        cin >> student.id;

        cout << "Enter student gender: ";
        cin >> student.gender;

        cout << "Enter student age: ";
        cin >> student.age;

        cout << "Enter student class name: ";
        cin >> student.className;

        string query = "INSERT INTO students (name, id, gender, age, class_name) VALUES ('" + student.name + "', " +
                       to_string(student.id) + ", '" + student.gender + "', " + to_string(student.age) + ", '" + student.className + "')";

        if (mysql_query(connection, query.c_str()) != 0) {
            cout << "Failed to add student: " << mysql_error(connection) << endl;
        } else {
            cout << "Student added successfully!" << endl;
        }
    }

    void DisplayStudents() {
        string query = "SELECT * FROM students";
        if (mysql_query(connection, query.c_str()) != 0) {
            cout << "Failed to display students: " << mysql_error(connection) << endl;
            return;
        }

        MYSQL_RES* result = mysql_store_result(connection);
        if (result == NULL) {
            cout << "mysql_store_result failed!" << endl;
            return;
        }

        int numFields = mysql_num_fields(result);
        MYSQL_ROW row;

        cout << "-------------------------------------------------------" << endl;
        cout << "ID\tName\tGender\tAge\tClass" << endl;
        cout << "-------------------------------------------------------" << endl;

        while ((row = mysql_fetch_row(result))) {
            for (int i = 0; i < numFields; i++) {
                cout << row[i] << "\t";
            }
            cout << endl;
        }

        cout << "-------------------------------------------------------" << endl;

        mysql_free_result(result);
    }
	void EditStudent() {
		int id;
		cout << "Enter student ID to edit: ";
		cin >> id;

		// 查询学生信息
		string query = "SELECT * FROM students WHERE id=" + to_string(id);
		if (mysql_query(connection, query.c_str()) != 0) {
			cout << "Failed to edit student: " << mysql_error(connection) << endl;
			return;
		}

		MYSQL_RES* result = mysql_store_result(connection);
		if (result == NULL) {
			cout << "mysql_store_result failed!" << endl;
			return;
		}

		MYSQL_ROW row = mysql_fetch_row(result);
		if (row == NULL) {
			cout << "No student found with ID " << id << endl;
			mysql_free_result(result);
			return;
		}

		// 修改学生信息
		Student student;
		cout << "Enter new student name: ";
		cin >> student.name;

		cout << "Enter new student gender: ";
		cin >> student.gender;

		cout << "Enter new student age: ";
		cin >> student.age;

		cout << "Enter new student class name: ";
		cin >> student.className;

		string updateQuery = "UPDATE students SET name='" + student.name + "', gender='" + student.gender +
			"', age=" + to_string(student.age) + ", class='" + student.className + "' WHERE id=" + to_string(id);

		if (mysql_query(connection, updateQuery.c_str()) != 0) {
			cout << "Failed to edit student: " << mysql_error(connection) << endl;
		}
		else {
			cout << "Student information updated successfully!" << endl;
		}

		mysql_free_result(result);
	}

	void DeleteStudent() {
		int id;
		cout << "Enter student ID to delete: ";
		cin >> id;

		string deleteQuery = "DELETE FROM students WHERE id=" + to_string(id);
		if (mysql_query(connection, deleteQuery.c_str()) != 0) {
			cout << "Failed to delete student: " << mysql_error(connection) << endl;
		}
		else {
			cout << "Student deleted successfully!" << endl;
		}
	}

	void Statistics() {
		// 实现统计功能，根据多种参数进行统计，例如学生人数、总分、单科的平均分
		// ...

		// 示例：统计学生人数
		string countQuery = "SELECT COUNT(*) FROM students";
		if (mysql_query(connection, countQuery.c_str()) != 0) {
			cout << "Failed to get student count: " << mysql_error(connection) << endl;
			return;
		}

		MYSQL_RES* result = mysql_store_result(connection);
		if (result == NULL) {
			cout << "mysql_store_result failed!" << endl;
			return;
		}

		MYSQL_ROW row = mysql_fetch_row(result);
		cout << "Total number of students: " << row[0] << endl;

		mysql_free_result(result);
	}
};

void ShowMenu() {
    cout << "***************************************" << endl;
    cout << "|--------0、退出系统---------------------|" << endl;
    cout << "|--------1、添加学生--------------------|" << endl;
	cout << "2、显示所有学生------------------|" << endl;
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
			system.EditStudent();
			break;
		case 4:
			system.DeleteStudent();
			break;
		case 5:
			system.Statistics();
			break;
		default:
			cout << "Invalid choice. Please enter a number between 0 and 9." << endl;
			break;
		}
	}
	return 0;
}

