// #include <iostream>
// #include <mysql_driver.h>
// #include <mysql_connection.h>
// #include <cppconn/prepared_statement.h>

// struct Student {
//     std::string name;
//     int id;
//     int score;
// };

// class GradeSystem {
// private:
//     std::vector<Student> students;
//     sql::mysql::MySQL_Driver* driver;
//     sql::Connection* con;

// public:
//     GradeSystem() {
//         // Initialize MySQL Connector/C++
//         driver = sql::mysql::get_mysql_driver_instance();
//         // Connect to your MySQL server (modify the connection parameters accordingly)
//         con = driver->connect("tcp://127.0.0.1:3306", "username", "password");
//         con->setSchema("your_database_name");
//     }

//     ~GradeSystem() {
//         delete con;
//     }

//     // ... (other member functions)

//     void addStudent(const std::string& name, int id, int score) {
//         Student newStudent = {name, id, score};
//         students.push_back(newStudent);

//         // Insert the new student into the MySQL database
//         try {
//             sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO students (name, id, score) VALUES (?, ?, ?)");
//             pstmt->setString(1, name);
//             pstmt->setInt(2, id);
//             pstmt->setInt(3, score);
//             pstmt->executeUpdate();
//             delete pstmt;
//         } catch (sql::SQLException& e) {
//             std::cout << "MySQL error: " << e.what() << std::endl;
//         }
//     }

//     // ... (other member functions)
// };

// int main() {
//     // ... (other code)

//     GradeSystem gradeSystem;

//     // ... (other code)

//     switch (choice) {
//         case 1:
//             gradeSystem.displayStudents();
//             break;
//         case 2:
//             {
//                 std::string name;
//                 int id, score;
//                 std::cout << "Enter student name: ";
//                 std::cin >> name;
//                 std::cout << "Enter student ID: ";
//                 std::cin >> id;
//                 std::cout << "Enter student score: ";
//                 std::cin >> score;
//                 gradeSystem.addStudent(name, id, score);
//                 break;
//             }
//         // ... (other cases)

//         default:
//             std::cout << "Invalid choice. Please try again." << std::endl;
//     }

//     // ... (other code)

//     return 0;
// }
