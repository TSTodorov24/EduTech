#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <limits>

// ---------- ENUMS ----------

enum class Category {
    ARITHMETIC,
    ALGEBRA,
    ELEMENTS,
    REACTIONS,
    GRAMMAR,
    VOCABULARY
};

// ---------- DATA STRUCTURES ----------

struct Question {
    string text;
    vector<string> options;
    int correctIndex;
    Category category;
    int points;
};

struct StudentResult {
    string name;
    int score;
    int maxScore;
    double percentage;
    double grade;
    map<Category, int> correctPerCategory;
    map<Category, int> totalPerCategory;
};

// ---------- HELPERS ----------

string categoryToString(Category cat) {
    switch (cat) {
    case Category::ARITHMETIC: return "Arithmetic";
    case Category::ALGEBRA:    return "Algebra";
    case Category::ELEMENTS:   return "Elements";
    case Category::REACTIONS:  return "Reactions";
    case Category::GRAMMAR:    return "Grammar";
    case Category::VOCABULARY: return "Vocabulary";
    default:                   return "Unknown";
    }
}

// Validates integer input and loops until a value in [minVal, maxVal] is entered
int readInt(const string& prompt, int minVal, int maxVal) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= minVal && value <= maxVal) {
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  Invalid input. Enter a number between "
            << minVal << " and " << maxVal << ".\n";
    }
}

// Reads a non-empty line of text from stdin
string readName(const string& prompt) {
    string name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (true) {
        cout << prompt;
        getline(cin, name);
        if (!name.empty()) return name;
        cout << "  Name cannot be empty.\n";
    }
}
