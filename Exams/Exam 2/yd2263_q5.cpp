/* Name: Yun-Ping Du
 * NetID: yd2263
 */

#include <iostream>
#include <vector>
using namespace std;

int get_highest_grade(const vector<int>& student_grade);
vector<int> get_highest_students(const vector<int>& student_id, const vector<int>& student_grade, int highest);

int main() {
    vector<int> student_id;
    vector<int> student_grade;

    cout << "Please enter a non-empty sequence of lines.\n"
         << "Each line should have a student ID and their grade (0-100), separated by a space.\n"
         << "To indicate the end of the input, enter -1 as a student ID:\n";

    while (true) {
        int id;

        cin >> id;

        if (id == -1) {
            break;
        } else {
            int grade;

            cin >> grade;
            student_id.push_back(id);
            student_grade.push_back(grade);
        }
    }

    int highest = get_highest_grade(student_grade);
    vector<int> highest_students = get_highest_students(student_id, student_grade, highest);

    cout << "The highest grade is " << highest << ".\n"
         << "The students with grade " << highest << " are: ";

    for (int i = 0; i < highest_students.size(); i++) {
        if (i == highest_students.size() - 1) {
            cout << highest_students[i] << '.';
        } else {
            cout << highest_students[i] << ' ';
        }
    }

    return 0;
}

int get_highest_grade(const vector<int>& student_grade) {
    int highest = -1;

    for (int grade: student_grade) {
        if (grade > highest) {
            highest = grade;
        }
    }

    return highest;
}

vector<int> get_highest_students(const vector<int>& student_id, const vector<int>& student_grade, int highest) {
    vector<int> highest_students;

    for (int i = 0; i < student_id.size(); i++) {
        if (student_grade[i] == highest) {
            highest_students.push_back(student_id[i]);
        }
    }

    return highest_students;
}
