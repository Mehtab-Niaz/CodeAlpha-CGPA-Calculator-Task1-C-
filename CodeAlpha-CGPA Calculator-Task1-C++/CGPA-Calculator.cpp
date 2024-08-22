#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

// Function to convert grade to grade points
double gradeToPoint(const string& grade) {
    map<string, double> gradeMap = {
        {"A", 4.0}, {"A-", 3.7}, {"B+", 3.3}, {"B", 3.0}, {"B-", 2.7},
        {"C+", 2.3}, {"C", 2.0}, {"C-", 1.7}, {"D+", 1.3}, {"D", 1.0}, {"F", 0.0}
    };

    return gradeMap[grade];
}

// Function to calculate GPA for a single semester
double calculateGPA(const vector<double>& gradePoints, const vector<int>& credits) {
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (size_t i = 0; i < gradePoints.size(); ++i) {
        totalGradePoints += gradePoints[i] * credits[i];
        totalCredits += credits[i];
    }

    return totalGradePoints / totalCredits;
}

// Function to calculate CGPA
double calculateCGPA(const vector<vector<double>>& allGradePoints, const vector<vector<int>>& allCredits) {
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (size_t i = 0; i < allGradePoints.size(); ++i) {
        for (size_t j = 0; j < allGradePoints[i].size(); ++j) {
            totalGradePoints += allGradePoints[i][j] * allCredits[i][j];
            totalCredits += allCredits[i][j];
        }
    }

    return totalGradePoints / totalCredits;
}

int main() {
    string studentName;
    cout << "Enter the student's name: ";
    getline(cin, studentName);

    int numSemesters;
    cout << "Enter the number of semesters: ";
    cin >> numSemesters;

    vector<vector<double>> allGradePoints(numSemesters);
    vector<vector<int>> allCredits(numSemesters);

    for (int i = 0; i < numSemesters; ++i) {
        int numCourses;
        cout << "\nEnter the number of courses for semester " << i + 1 << ": ";
        cin >> numCourses;

        allGradePoints[i].resize(numCourses);
        allCredits[i].resize(numCourses);

        for (int j = 0; j < numCourses; ++j) {
            string grade;
            cout << "Enter grade for course " << j + 1 << ": ";
            cin >> grade;
            allGradePoints[i][j] = gradeToPoint(grade);

            cout << "Enter credits for course " << j + 1 << ": ";
            cin >> allCredits[i][j];
        }

        double semesterGPA = calculateGPA(allGradePoints[i], allCredits[i]);
        cout << fixed << setprecision(2);
        cout << "GPA for semester " << i + 1 << ": " << semesterGPA << endl;
    }

    double cgpa = calculateCGPA(allGradePoints, allCredits);
    cout << "\nCumulative GPA (CGPA) for " << studentName << ": " << cgpa << endl;

    return 0;
}
