#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;

// Function to convert grade to grade point
float getGradePoint(const string& grade) {
    map<string, float> gradeMap = {
        {"A+", 4.0}, {"A", 4.0}, {"A-", 3.7},
        {"B+", 3.3}, {"B", 3.0}, {"B-", 2.7},
        {"C+", 2.3}, {"C", 2.0}, {"C-", 1.7},
        {"D+", 1.3}, {"D", 1.0}, {"F", 0.0}
    };

    auto it = gradeMap.find(grade);
    if (it != gradeMap.end()) {
        return it->second;
    } else {
        return -1; // Invalid grade
    }
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    float totalCredits = 0, totalGradePoints = 0;
    string grade;
    float creditHours;

    cout << fixed << setprecision(2);

    for (int i = 1; i <= numCourses; ++i) {
        cout << "\nCourse " << i << ":\n";
        
        while (true) {
            cout << "Enter grade (e.g., A, B+, C-): ";
            cin >> grade;
            if (getGradePoint(grade) != -1) break;
            else cout << "Invalid grade. Please try again.\n";
        }

        cout << "Enter credit hours: ";
        cin >> creditHours;

        float gradePoint = getGradePoint(grade);
        float courseGradePoints = gradePoint * creditHours;

        totalCredits += creditHours;
        totalGradePoints += courseGradePoints;

        cout << "Grade = " << grade
             << ", Credit Hours = " << creditHours
             << ", Grade Points = " << courseGradePoints << endl;
    }

    if (totalCredits == 0) {
        cout << "\nNo credits entered. Cannot calculate CGPA.\n";
    } else {
        float cgpa = totalGradePoints / totalCredits;
        cout << "\n--- Summary ---\n";
        cout << "Total Credits: " << totalCredits << endl;
        cout << "Total Grade Points: " << totalGradePoints << endl;
        cout << "Final CGPA: " << cgpa << endl;
    }

    return 0;
}