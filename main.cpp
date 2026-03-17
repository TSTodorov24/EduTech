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

// ---------- UI ----------

void displayBanner() {
    cout << "\n";
    cout << "   ______    _     _______         _     \n";
    cout << "  |  ____|  | |   |__   __|       | |    \n";
    cout << "  | |__   __| |_   _| | ___  ___  | |__  \n";
    cout << "  |  __| / _` | | | | |/ _ \\/ __| |  _ \\ \n";
    cout << "  | |___| (_| | |_| | |  __/ (__  | | | |\n";
    cout << "  |______\\__,_|\\__,_|_|\\___|\\___| |_| |_|\n";
    cout << "\n";
}

void displaySeparator() {
    cout << "  -------------------------------------------------\n";
}

void displayMainMenu() {
    displayBanner();
    cout << "  MAIN MENU\n";
    displaySeparator();
    cout << "  1. Start Test\n";
    cout << "  2. View Statistics\n";
    cout << "  3. Study Material\n";
    cout << "  4. Fun Facts\n";
    cout << "  5. Exit\n";
    displaySeparator();
}

void displaySubjectMenu() {
    cout << "\n  SELECT SUBJECT\n";
    displaySeparator();
    cout << "  1. Mathematics\n";
    cout << "  2. Chemistry\n";
    cout << "  3. English\n";
    cout << "  4. Mixed (all subjects)\n";
    displaySeparator();
}

// ---------- QUESTION BANK (40 per subject) ----------

// 20 Arithmetic + 20 Algebra = 40 Math questions
vector<Question> buildMathBank() {
    return {
        {"What is 7 + 8?",                              {"13","14","15","16"},              2, Category::ARITHMETIC, 1},
        {"What is 15 - 6?",                             {"7","8","9","10"},                 2, Category::ARITHMETIC, 1},
        {"What is 4 x 6?",                              {"20","22","24","26"},              2, Category::ARITHMETIC, 1},
        {"What is 36 / 4?",                             {"7","8","9","10"},                 2, Category::ARITHMETIC, 1},
        {"What is 100 - 37?",                           {"53","63","73","83"},              1, Category::ARITHMETIC, 1},
        {"What is 12 x 12?",                            {"132","144","156","168"},          1, Category::ARITHMETIC, 1},
        {"What is 9 + 9?",                              {"16","17","18","19"},              2, Category::ARITHMETIC, 1},
        {"What is 81 / 9?",                             {"7","8","9","10"},                 2, Category::ARITHMETIC, 1},
        {"What is 25 + 75?",                            {"90","95","100","105"},            2, Category::ARITHMETIC, 1},
        {"What is 13 x 4?",                             {"48","50","52","54"},              2, Category::ARITHMETIC, 1},
        {"What is 200 - 56?",                           {"134","144","154","164"},          1, Category::ARITHMETIC, 1},
        {"What is 7 x 8?",                              {"48","54","56","64"},              2, Category::ARITHMETIC, 1},
        {"What is 144 / 12?",                           {"10","11","12","13"},              2, Category::ARITHMETIC, 1},
        {"What is 64 + 36?",                            {"90","95","100","110"},            2, Category::ARITHMETIC, 1},
        {"What is 11 x 11?",                            {"110","111","121","131"},          2, Category::ARITHMETIC, 1},
        {"What is 1000 - 250?",                         {"650","700","750","800"},          2, Category::ARITHMETIC, 1},
        {"What is 6 x 7?",                              {"36","40","42","48"},              2, Category::ARITHMETIC, 1},
        {"What is 56 / 8?",                             {"5","6","7","8"},                  2, Category::ARITHMETIC, 1},
        {"What is 99 + 11?",                            {"108","109","110","111"},          2, Category::ARITHMETIC, 1},
        {"What is 3 x 15?",                             {"40","42","45","48"},              2, Category::ARITHMETIC, 1},

        {"If x + 5 = 12, what is x?",                   {"5","6","7","8"},                  2, Category::ALGEBRA, 2},
        {"What is the value of 2x when x = 4?",         {"4","6","8","10"},                 2, Category::ALGEBRA, 2},
        {"Solve: 3x = 21",                              {"5","6","7","8"},                  2, Category::ALGEBRA, 2},
        {"What is x if 2x - 3 = 7?",                   {"4","5","6","7"},                  1, Category::ALGEBRA, 2},
        {"Which is a prime number?",                    {"9","15","17","21"},               2, Category::ALGEBRA, 2},
        {"What is 2 to the power of 5?",                {"16","24","32","64"},              2, Category::ALGEBRA, 2},
        {"What is the square root of 64?",              {"6","7","8","9"},                  2, Category::ALGEBRA, 2},
        {"Solve: x / 4 = 5",                            {"10","15","20","25"},              2, Category::ALGEBRA, 2},
        {"What is 3 squared?",                          {"6","8","9","12"},                 2, Category::ALGEBRA, 2},
        {"If 5x = 35, what is x?",                      {"5","6","7","8"},                  2, Category::ALGEBRA, 2},
        {"What is the value of x^0 for any x != 0?",   {"0","1","x","Undefined"},          1, Category::ALGEBRA, 2},
        {"Solve: 2x + 4 = 14",                          {"3","4","5","6"},                  2, Category::ALGEBRA, 2},
        {"What is 4 to the power of 3?",                {"48","54","64","72"},              2, Category::ALGEBRA, 2},
        {"Which number is NOT prime?",                  {"11","13","17","21"},              3, Category::ALGEBRA, 2},
        {"If y = 3x and x = 4, what is y?",            {"9","10","12","15"},               2, Category::ALGEBRA, 2},
        {"What is the LCM of 4 and 6?",                 {"8","10","12","14"},               2, Category::ALGEBRA, 2},
        {"What is the GCD of 18 and 24?",               {"4","6","8","12"},                 1, Category::ALGEBRA, 2},
        {"Solve: x - 7 = 13",                           {"17","19","20","23"},              2, Category::ALGEBRA, 2},
        {"What is 5 to the power of 2?",                {"10","15","20","25"},              3, Category::ALGEBRA, 2},
        {"If 3x - 6 = 9, what is x?",                  {"3","4","5","6"},                  2, Category::ALGEBRA, 2},
    };
}
