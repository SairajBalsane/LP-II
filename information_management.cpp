#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Define a structure to represent a piece of information
struct Information {
    string category;
    string data;
};

// Define a structure to represent a rule
struct Rule {
    string condition;
    string result;
};

class ExpertSystem {
private:
    unordered_map<string, vector<string>> knowledgeBase;

public:
    void addInformation(const Information& info) {
        knowledgeBase[info.category].push_back(info.data);
    }

    void addRule(const Rule& rule) {
        // For simplicity, we won't implement rule-based inference in this example
        // Instead, we'll just store the rules in the knowledge base
        knowledgeBase["Rule"].push_back(rule.condition + " -> " + rule.result);
    }

    void query(const string& category) {
        if (knowledgeBase.find(category) != knowledgeBase.end()) {
            cout << "Information in category '" << category << "':" << endl;
            for (const auto& info : knowledgeBase[category]) {
                cout << "- " << info << endl;
            }
        } else {
            cout << "No information found in category '" << category << "'" << endl;
        }
    }
};

int main() {
    ExpertSystem expertSystem;

    // Adding sample information
    Information info1 = {"Books", "Harry Potter and the Sorcerer's Stone"};
    Information info2 = {"Books", "The Great Gatsby"};
    Information info3 = {"Movies", "Inception"};
    Information info4 = {"Movies", "The Shawshank Redemption"};

    expertSystem.addInformation(info1);
    expertSystem.addInformation(info2);
    expertSystem.addInformation(info3);
    expertSystem.addInformation(info4);

    // Adding sample rules
    Rule rule1 = {"Books", "Read more books to gain knowledge."};
    Rule rule2 = {"Movies", "Watch more movies to entertain yourself."};

    expertSystem.addRule(rule1);
    expertSystem.addRule(rule2);

    // Querying information
    expertSystem.query("Books");
    expertSystem.query("Movies");

    return 0;
}
