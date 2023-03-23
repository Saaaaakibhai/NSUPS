
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Student {
private:
    const int id;
    const string department;
    double cgpa;
    int semester;
    static int countStudent;
public:
    Student(int id, string department, double cgpa, int semester) :
        id(id), department(department), cgpa(cgpa), semester(semester)
    {
        countStudent++;
    }

    static int getCount() {
        return countStudent;
    }

    string getDepartment() const {
        return department;
    }

    int getSemester() const {
        return semester;
    }

    bool classMates(const Student& other) const {
        return (department == other.department && semester == other.semester);
    }

    void stackedMates(stack<int>& s, const Student& other) const {
        if (classMates(other)) {
            s.push(other.id);
        }
    }

    void print() const {
        cout << "ID: " << id << ", Department: " << department << ", CGPA: " << cgpa << ", Semester: " << semester << endl;
    }
};

int Student::countStudent = 0;

int main() {
    Student s1(1, "CSE", 3.5, 1);
    Student s2(2, "EEE", 3.2, 2);
    Student s3(3, "CSE", 3.1, 1);
    Student s4(4, "BBA", 2.9, 3);

    cout << "Number of students created: " << Student::getCount() << endl;

    stack<int> classmates;

    s1.stackedMates(classmates, s3);
    s1.stackedMates(classmates, s2);

    while (!classmates.empty()) {
        cout << "Classmate ID: " << classmates.top() << endl;
        classmates.pop();
    }

    return 0;
}
