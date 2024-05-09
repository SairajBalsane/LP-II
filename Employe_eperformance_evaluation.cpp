#include <iostream>
#include <string>

using namespace std;

// Function to evaluate employee performance based on given parameters
string evaluatePerformance(int productivity, int attitude, int teamwork) {
    if (productivity >= 8 && attitude >= 8 && teamwork >= 8) {
        return "Outstanding";
    } else if (productivity >= 6 && attitude >= 6 && teamwork >= 6) {
        return "Satisfactory";
    } else if (productivity >= 4 && attitude >= 4 && teamwork >= 4) {
        return "Needs Improvement";
    } else {
        return "Poor";
    }
}

int main() {
    int productivity, attitude, teamwork;

    // Input employee's productivity, attitude, and teamwork scores
    cout << "Enter productivity score (out of 10): ";
    cin >> productivity;

    cout << "Enter attitude score (out of 10): ";
    cin >> attitude;

    cout << "Enter teamwork score (out of 10): ";
    cin >> teamwork;

    // Evaluate performance
    string performance = evaluatePerformance(productivity, attitude, teamwork);

    // Output performance evaluation
    cout << "Performance Evaluation: " << performance << endl;

    return 0;
}
