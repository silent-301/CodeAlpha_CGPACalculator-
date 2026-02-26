#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Course {
    string name;
    double gradePoints;
    double creditHours;
};

class CGPACalculator {
private:
    vector<Course> courses;

public:
    void addCourse() {
        Course c;
        cout << "\nEnter Course Name: ";
        cin.ignore();
        getline(cin, c.name);

        cout << "Enter Grade Points (e.g., 4.0 for A, 3.0 for B): ";
        cin >> c.gradePoints;

        cout << "Enter Credit Hours: ";
        cin >> c.creditHours;

        courses.push_back(c);
        cout << "[SUCCESS] Course added." << endl;
    }

    void calculateAndDisplay() {
        if (courses.empty()) {
            cout << "\n[ERROR] No courses added yet!" << endl;
            return;
        }

        double totalGradePoints = 0;
        double totalCreditHours = 0;

        cout << "\n" << string(50, '=') << endl;
        cout << left << setw(20) << "Course Name" 
             << setw(15) << "Grade Points" 
             << "Credit Hours" << endl;
        cout << string(50, '-') << endl;

        for (const auto& c : courses) {
            cout << left << setw(20) << c.name 
                 << setw(15) << fixed << setprecision(2) << c.gradePoints 
                 << c.creditHours << endl;
            
            totalGradePoints += c.gradePoints;
            totalCreditHours += c.creditHours;
        }

        double cgpa =totalGradePoints /totalCreditHours ;

        cout << string(50, '=') << endl;
        cout << "Total Credit Hours: " << totalCreditHours << endl;
        cout << "Total Grade Points: " << totalGradePoints << endl;
        cout << "Final CGPA:         " << fixed << setprecision(2) << cgpa << endl;
        cout << string(50, '=') << endl;
    }
};

int main() {
    CGPACalculator calc;
    int choice;

    do {
        cout << "\n*** CGPA CALCULATOR MENU ***" << endl;
        cout << "1. Add a Course" << endl;
        cout << "2. Calculate and Display Report" << endl;
        cout << "3. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                calc.addCourse();
                break;
            case 2:
                calc.calculateAndDisplay();
                break;
            case 3:
                cout << "Exiting. Good luck with your studies!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);

    return 0;
}