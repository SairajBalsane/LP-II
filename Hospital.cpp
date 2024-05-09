#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// Define a structure for a hospital
struct Hospital {
    string name;
    string location;
    bool hasEmergency;
    bool hasSurgery;
    bool hasPediatrics;
    bool hasCardiology;
    // Add more attributes as needed
};

// Knowledge base of hospitals
vector<Hospital> hospitals = {
    {"General Hospital", "City A", true, true, true, true},
    {"Community Hospital", "City B", true, false, true, false},
    {"Children's Hospital", "City C", true, false, true, false},
    // Add more hospitals as needed
};

// Function to query hospitals based on user requirements
void findHospitals(bool emergency, bool surgery, bool pediatrics, bool cardiology) {
    cout << "Matching hospitals based on your requirements:" << endl;
    for (const auto& hospital : hospitals) {
        if ((!emergency || hospital.hasEmergency) &&
            (!surgery || hospital.hasSurgery) &&
            (!pediatrics || hospital.hasPediatrics) &&
            (!cardiology || hospital.hasCardiology)) {
            cout << hospital.name << " - Location: " << hospital.location << endl;
        }
    }
}

int main() {
    // Example query: User requires emergency services and pediatrics
    bool emergencyNeeded = true;
    bool surgeryNeeded = false;
    bool pediatricsNeeded = true;
    bool cardiologyNeeded = false;

    // Find hospitals based on user requirements
    findHospitals(emergencyNeeded, surgeryNeeded, pediatricsNeeded, cardiologyNeeded);

    return 0;
}
