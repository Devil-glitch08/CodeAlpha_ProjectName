#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

float getGradePoint(const string& grade) {
    if (grade == "O") return 10.0;
    else if (grade == "A+") return 9.0;
    else if (grade == "A") return 8.0;
    else if (grade == "B+") return 7.0;
    else if (grade == "B") return 6.0;
    else if (grade == "C") return 5.0;
    else if (grade == "D") return 4.0;
    else return 0.0;  // F grade
}

int main() {
    int numSubjects;
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    vector<string> subjects(numSubjects);
    vector<string> grades(numSubjects);
    vector<int> credits(numSubjects);
    vector<float> gradePoints(numSubjects);

    // Input subject names, grade points, and credit points
    for (int i = 0; i < numSubjects; i++) {
        cout << "Enter the name of subject " << i + 1 << ": ";
        cin >> subjects[i];

        cout << "Enter the grade (O, A+, A, B+, B, C, D, F) for " << subjects[i] << ": ";
        cin >> grades[i];

        gradePoints[i] = getGradePoint(grades[i]);

        cout << "Enter the credit for " << subjects[i] << ": ";
        cin >> credits[i];
    }

    // Display the table with subjects, grade points, grades, and credits
    cout << "\n-------------------------------------------\n";
    cout << setw(20) << left << "Subject"
         << setw(10) << "Grade"
         << setw(15) << "Grade Points"
         << setw(10) << "Credits" << endl;
    cout << "-------------------------------------------\n";
    
    for (int i = 0; i < numSubjects; i++) {
        cout << setw(20) << left << subjects[i]
             << setw(10) << grades[i]
             << setw(15) << gradePoints[i]
             << setw(10) << credits[i] << endl;
    }

    // Calculate CGPA
    float totalWeightedGradePoints = 0;
    int totalCredits = 0;
    for (int i = 0; i < numSubjects; i++) {
        totalWeightedGradePoints += gradePoints[i] * credits[i];
        totalCredits += credits[i];
    }

    float cgpa = totalWeightedGradePoints / totalCredits;
    cout << "\nYour CGPA is: " << cgpa << endl;

    return 0;
}
