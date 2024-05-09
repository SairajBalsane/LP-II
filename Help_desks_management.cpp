#include <iostream>
#include <string>

using namespace std;

// Function to handle software issues
void handleSoftwareIssue() {
    cout << "Please check if the software is up to date.\n";
    cout << "If the issue persists, please contact the software support team.\n";
}

// Function to handle hardware issues
void handleHardwareIssue() {
    cout << "Please check if all cables are properly connected.\n";
    cout << "If the issue persists, please contact the hardware support team.\n";
}

// Function to handle network issues
void handleNetworkIssue() {
    cout << "Please check if your internet connection is working.\n";
    cout << "If the issue persists, please contact the network support team.\n";
}

int main() {
    string issueType;

    cout << "Welcome to the Help Desk Management System.\n";
    cout << "Please select the type of issue you are experiencing:\n";
    cout << "1. Software issue\n";
    cout << "2. Hardware issue\n";
    cout << "3. Network issue\n";

    // Get user input
    getline(cin, issueType);

    if (issueType == "1") {
        handleSoftwareIssue();
    } else if (issueType == "2") {
        handleHardwareIssue();
    } else if (issueType == "3") {
        handleNetworkIssue();
    } else {
        cout << "Invalid input. Please select a valid option.\n";
    }

    return 0;
}
