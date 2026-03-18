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

// 20 Elements + 20 Reactions = 40 Chemistry questions
vector<Question> buildChemistryBank() {
    return {
        {"What is the chemical symbol for water?",          {"H2O","CO2","O2","NaCl"},                                  0, Category::ELEMENTS, 1},
        {"What is the symbol for gold?",                    {"Go","Gd","Au","Ag"},                                      2, Category::ELEMENTS, 1},
        {"What is the symbol for sodium?",                  {"So","Sa","Sn","Na"},                                      3, Category::ELEMENTS, 1},
        {"What is the symbol for iron?",                    {"Ir","In","Fe","Io"},                                      2, Category::ELEMENTS, 1},
        {"What is the symbol for oxygen?",                  {"Ox","O2","O","Og"},                                       2, Category::ELEMENTS, 1},
        {"What is the symbol for carbon?",                  {"Ca","Cb","C","Cr"},                                       2, Category::ELEMENTS, 1},
        {"What is the symbol for silver?",                  {"Si","Sl","Ag","Sv"},                                      2, Category::ELEMENTS, 1},
        {"What is the symbol for copper?",                  {"Co","Cp","Cu","Cb"},                                      2, Category::ELEMENTS, 1},
        {"What is the symbol for hydrogen?",                {"Hy","Hd","He","H"},                                       3, Category::ELEMENTS, 1},
        {"What is the symbol for nitrogen?",                {"Ni","Nt","N","Ng"},                                       2, Category::ELEMENTS, 1},
        {"What is the symbol for calcium?",                 {"Cm","Ca","Cl","Ce"},                                      1, Category::ELEMENTS, 1},
        {"What is the symbol for potassium?",               {"Po","Pt","Ps","K"},                                       3, Category::ELEMENTS, 1},
        {"What is the symbol for chlorine?",                {"Ch","Cl","Ce","Cr"},                                      1, Category::ELEMENTS, 1},
        {"What is the symbol for magnesium?",               {"Mn","Me","Mg","Ma"},                                      2, Category::ELEMENTS, 1},
        {"What is the symbol for zinc?",                    {"Zi","Zn","Ze","Zk"},                                      1, Category::ELEMENTS, 1},
        {"What is the symbol for lead?",                    {"Ld","Le","Pb","Pl"},                                      2, Category::ELEMENTS, 1},
        {"What is the symbol for tin?",                     {"Ti","Tn","Sn","Ts"},                                      2, Category::ELEMENTS, 1},
        {"What is the symbol for sulfur?",                  {"Su","Sf","Se","S"},                                       3, Category::ELEMENTS, 1},
        {"What is the symbol for phosphorus?",              {"Ph","Ps","P","Pc"},                                       2, Category::ELEMENTS, 1},
        {"What is the symbol for fluorine?",                {"Fl","Fu","Fr","F"},                                       3, Category::ELEMENTS, 1},

        {"Water boils at what temperature (Celsius)?",      {"80","90","100","110"},                                    2, Category::REACTIONS, 2},
        {"What gas is produced in photosynthesis?",         {"CO2","O2","H2","N2"},                                     1, Category::REACTIONS, 2},
        {"NaCl is the formula for?",                        {"Vinegar","Sugar","Salt","Baking soda"},                   2, Category::REACTIONS, 2},
        {"What is the pH of pure water?",                   {"5","6","7","8"},                                          2, Category::REACTIONS, 2},
        {"CO2 stands for?",                                 {"Carbon monoxide","Carbon dioxide","Calcium oxide","Copper oxide"}, 1, Category::REACTIONS, 2},
        {"Which gas makes up most of Earth's air?",         {"Oxygen","Carbon dioxide","Nitrogen","Hydrogen"},          2, Category::REACTIONS, 2},
        {"Water freezes at what temperature (Celsius)?",    {"0","4","-4","-10"},                                       0, Category::REACTIONS, 2},
        {"What type of reaction releases energy as heat?",  {"Endothermic","Exothermic","Neutral","Catalytic"},         1, Category::REACTIONS, 2},
        {"What is the chemical formula for table sugar?",   {"C6H12O6","C12H22O11","C2H5OH","CH4"},                    1, Category::REACTIONS, 2},
        {"Acids have a pH of?",                             {"Less than 7","Exactly 7","More than 7","Exactly 14"},     0, Category::REACTIONS, 2},
        {"What is produced when an acid reacts with a base?",{"Acid and base","Salt and water","Gas and solid","Only gas"}, 1, Category::REACTIONS, 2},
        {"Which is an example of a physical change?",       {"Burning wood","Rusting iron","Melting ice","Baking bread"}, 2, Category::REACTIONS, 2},
        {"What gas do plants absorb from the air?",         {"Oxygen","Nitrogen","Carbon dioxide","Hydrogen"},          2, Category::REACTIONS, 2},
        {"What is the chemical formula for methane?",       {"CO2","CH4","C2H6","C3H8"},                                1, Category::REACTIONS, 2},
        {"Which metal does NOT rust?",                      {"Iron","Steel","Aluminum","Copper"},                       3, Category::REACTIONS, 2},
        {"What is the chemical formula for ethanol?",       {"CH4","C2H5OH","C3H7OH","C6H12O6"},                       1, Category::REACTIONS, 2},
        {"What type of bond shares electrons equally?",     {"Ionic","Covalent","Metallic","Hydrogen"},                 1, Category::REACTIONS, 2},
        {"Oxidation means loss of?",                        {"Protons","Neutrons","Electrons","Mass"},                  2, Category::REACTIONS, 2},
        {"Which is NOT a state of matter?",                 {"Solid","Liquid","Gas","Energy"},                          3, Category::REACTIONS, 2},
        {"What does a catalyst do in a reaction?",          {"Slows it down","Has no effect","Speeds it up without being consumed","Stops it"}, 2, Category::REACTIONS, 2},
    };
}

// 20 Grammar + 20 Vocabulary = 40 English questions
vector<Question> buildEnglishBank() {
    return {
        {"Which sentence is correct?",                          {"She go home","She goes home","She going home","She gone home"},        1, Category::GRAMMAR, 1},
        {"What is the plural of 'child'?",                      {"Childs","Childes","Children","Childrens"},                            2, Category::GRAMMAR, 1},
        {"Which is a verb?",                                    {"Beautiful","Quickly","Run","Happiness"},                              2, Category::GRAMMAR, 1},
        {"What is the past tense of 'eat'?",                    {"Eated","Ate","Eaten","Eats"},                                         1, Category::GRAMMAR, 1},
        {"Which word is an adjective?",                         {"Slowly","Bright","Jump","Happiness"},                                 1, Category::GRAMMAR, 1},
        {"What is the plural of 'mouse'?",                      {"Mouses","Mice","Mousies","Mouse"},                                    1, Category::GRAMMAR, 1},
        {"Which is the correct comparative of 'tall'?",         {"More tall","Taller","Tallier","Most tall"},                           1, Category::GRAMMAR, 1},
        {"What is the past tense of 'go'?",                     {"Goed","Goes","Gone","Went"},                                          3, Category::GRAMMAR, 1},
        {"Which is a conjunction?",                             {"But","Quickly","Blue","Laugh"},                                       0, Category::GRAMMAR, 1},
        {"What is the superlative of 'good'?",                  {"Gooder","Better","Goodest","Best"},                                   3, Category::GRAMMAR, 1},
        {"Which sentence uses the present perfect?",            {"I eat lunch","I ate lunch","I have eaten lunch","I was eating lunch"}, 2, Category::GRAMMAR, 1},
        {"What is the plural of 'tooth'?",                      {"Tooths","Teeths","Teeth","Toothes"},                                  2, Category::GRAMMAR, 1},
        {"Which is a preposition?",                             {"Under","Beautiful","Quickly","Shout"},                                0, Category::GRAMMAR, 1},
        {"What is the past tense of 'write'?",                  {"Writed","Written","Wrote","Writes"},                                  2, Category::GRAMMAR, 1},
        {"Which word is an adverb?",                            {"Happy","Happily","Happiness","Happier"},                              1, Category::GRAMMAR, 1},
        {"What is the plural of 'cactus'?",                     {"Cactuses","Cacties","Cacti","Cactuss"},                               2, Category::GRAMMAR, 1},
        {"Identify the noun: 'The dog barks loudly.'",          {"The","Barks","Dog","Loudly"},                                         2, Category::GRAMMAR, 1},
        {"Which is the correct passive voice?",                 {"The cat ate the fish","The fish was eaten by the cat","The fish ate the cat","The cat was eaten"}, 1, Category::GRAMMAR, 1},
        {"What type of sentence is: 'What time is it?'",        {"Declarative","Imperative","Interrogative","Exclamatory"},             2, Category::GRAMMAR, 1},
        {"What is the past tense of 'run'?",                    {"Runned","Runs","Ran","Run"},                                          2, Category::GRAMMAR, 1},

        {"What does 'enormous' mean?",                          {"Tiny","Fast","Very large","Very dark"},                               2, Category::VOCABULARY, 2},
        {"What is a synonym for 'happy'?",                      {"Sad","Angry","Joyful","Tired"},                                       2, Category::VOCABULARY, 2},
        {"What does 'transparent' mean?",                       {"Solid","You can see through it","Very heavy","Colorful"},             1, Category::VOCABULARY, 2},
        {"Which word means 'to begin'?",                        {"Finish","Pause","Start","Stop"},                                      2, Category::VOCABULARY, 2},
        {"What is an antonym of 'ancient'?",                    {"Old","Historic","Modern","Tall"},                                     2, Category::VOCABULARY, 2},
        {"What does 'benevolent' mean?",                        {"Evil","Kind and generous","Angry","Confused"},                        1, Category::VOCABULARY, 2},
        {"Which word means 'to make better'?",                  {"Worsen","Improve","Ignore","Destroy"},                                1, Category::VOCABULARY, 2},
        {"What does 'arid' describe?",                          {"Very cold","Very wet","Very dry","Very windy"},                       2, Category::VOCABULARY, 2},
        {"What is a synonym for 'brave'?",                      {"Scared","Courageous","Weak","Lazy"},                                  1, Category::VOCABULARY, 2},
        {"What does 'nocturnal' mean?",                         {"Active during the day","Active at night","Living in water","Living underground"}, 1, Category::VOCABULARY, 2},
        {"What is an antonym of 'expand'?",                     {"Grow","Increase","Contract","Multiply"},                              2, Category::VOCABULARY, 2},
        {"What does 'vivid' mean?",                             {"Dull","Unclear","Bright and striking","Quiet"},                       2, Category::VOCABULARY, 2},
        {"Which word means 'a feeling of great joy'?",          {"Sorrow","Elation","Anger","Fear"},                                    1, Category::VOCABULARY, 2},
        {"What does 'ambiguous' mean?",                         {"Clear and obvious","Having more than one meaning","Very loud","Extremely small"}, 1, Category::VOCABULARY, 2},
        {"What is a synonym for 'old'?",                        {"Young","New","Ancient","Fast"},                                       2, Category::VOCABULARY, 2},
        {"What does 'scarce' mean?",                            {"Plentiful","In short supply","Very large","Extremely common"},        1, Category::VOCABULARY, 2},
        {"Which word means 'to copy someone'?",                 {"Ignore","Imitate","Create","Destroy"},                                1, Category::VOCABULARY, 2},
        {"What does 'eloquent' mean?",                          {"Speaking poorly","Speaking fluently and persuasively","Speaking quietly","Speaking angrily"}, 1, Category::VOCABULARY, 2},
        {"What is an antonym of 'victory'?",                    {"Win","Success","Defeat","Achievement"},                               2, Category::VOCABULARY, 2},
        {"What does 'monotonous' mean?",                        {"Exciting and varied","Dull and repetitive","Loud and clear","Bright and colorful"}, 1, Category::VOCABULARY, 2},
    };
}
// Combines all three banks for mixed mode
vector<Question> buildFullBank() {
    vector<Question> full;
    auto math = buildMathBank();
    auto chem = buildChemistryBank();
    auto english = buildEnglishBank();
    full.insert(full.end(), math.begin(), math.end());
    full.insert(full.end(), chem.begin(), chem.end());
    full.insert(full.end(), english.begin(), english.end());
    return full;
}

// ---------- GRADING ----------

// Bulgarian 6-point scale: percentage thresholds -> grade
double calculateGrade(double percentage) {
    if (percentage >= 90.0) return 6.00;
    if (percentage >= 75.0) return 5.00;
    if (percentage >= 60.0) return 4.00;
    if (percentage >= 45.0) return 3.00;
    return 2.00;
}

string gradeLabel(double grade) {
    if (grade >= 5.50) return "Excellent (6)";
    if (grade >= 4.50) return "Very Good (5)";
    if (grade >= 3.50) return "Good (4)";
    if (grade >= 2.50) return "Average (3)";
    return "Fail (2)";
}

// ---------- TEST GENERATION ----------

// Selects N unique questions distributed evenly across categories
// Uses per-category shuffle so each run produces a different set
vector<Question> generateTest(
    const vector<Question>& bank,
    const vector<Category>& cats,
    int totalQuestions,
    mt19937& rng)
{
    map<Category, vector<Question>> byCategory;
    for (const auto& q : bank) {
        for (Category c : cats) {
            if (q.category == c) {
                byCategory[c].push_back(q);
                break;
            }
        }
    }

    for (auto& [cat, pool] : byCategory) {
        shuffle(pool.begin(), pool.end(), rng);
    }

    vector<Question> test;
    int perCategory = totalQuestions / static_cast<int>(cats.size());
    int remainder = totalQuestions % static_cast<int>(cats.size());

    for (size_t i = 0; i < cats.size(); i++) {
        int take = perCategory + (static_cast<int>(i) < remainder ? 1 : 0);
        auto& pool = byCategory[cats[i]];
        take = min(take, static_cast<int>(pool.size()));
        for (int j = 0; j < take; j++) {
            test.push_back(pool[j]);
        }
    }

    shuffle(test.begin(), test.end(), rng);
    return test;
}

// ---------- QUESTION DISPLAY ----------

bool askQuestion(const Question& q, int questionNumber) {
    cout << "\n  Q" << questionNumber
        << ". [" << categoryToString(q.category)
        << " | " << q.points << " pt]  "
        << q.text << "\n\n";

    for (size_t i = 0; i < q.options.size(); i++) {
        cout << "     " << (i + 1) << ". " << q.options[i] << "\n";
    }
    cout << "\n";

    int answer = readInt("  Your answer (1-4): ", 1, 4);
    bool correct = (answer - 1) == q.correctIndex;

    if (correct) {
        cout << "  [CORRECT]  +" << q.points << " point(s)\n";
    }
    else {
        cout << "  [WRONG]    Correct answer: "
            << q.options[q.correctIndex] << "\n";
    }
    return correct;
}


// ---------- RUN TEST ----------

StudentResult runTest(mt19937& rng) {
    string name = readName("\n  Enter your name: ");

    displaySubjectMenu();
    int subjectChoice = readInt("  Choose subject (1-4): ", 1, 4);

    vector<Category> selectedCategories;
    vector<Question> pool;

    switch (subjectChoice) {
    case 1:
        selectedCategories = { Category::ARITHMETIC, Category::ALGEBRA };
        pool = buildMathBank();
        break;
    case 2:
        selectedCategories = { Category::ELEMENTS, Category::REACTIONS };
        pool = buildChemistryBank();
        break;
    case 3:
        selectedCategories = { Category::GRAMMAR, Category::VOCABULARY };
        pool = buildEnglishBank();
        break;
    case 4:
        selectedCategories = {
            Category::ARITHMETIC, Category::ALGEBRA,
            Category::ELEMENTS,   Category::REACTIONS,
            Category::GRAMMAR,    Category::VOCABULARY
        };
        pool = buildFullBank();
        break;
    }

    // Single subject: 20 questions (10 per category)
    // Mixed: 24 questions (4 per category)
    int testSize = (subjectChoice == 4) ? 24 : 20;
    vector<Question> test = generateTest(pool, selectedCategories, testSize, rng);

    cout << "\n  Test: " << test.size() << " questions\n";
    displaySeparator();

    StudentResult result;
    result.name = name;
    result.score = 0;
    result.maxScore = 0;

    for (Category c : selectedCategories) {
        result.correctPerCategory[c] = 0;
        result.totalPerCategory[c] = 0;
    }

    for (size_t i = 0; i < test.size(); i++) {
        const Question& q = test[i];
        result.maxScore += q.points;
        result.totalPerCategory[q.category]++;

        bool correct = askQuestion(q, static_cast<int>(i + 1));
        if (correct) {
            result.score += q.points;
            result.correctPerCategory[q.category]++;
        }
        cout << "  Score: " << result.score << "/" << result.maxScore << "\n";
    }

    result.percentage = result.maxScore > 0
        ? (static_cast<double>(result.score) / result.maxScore) * 100.0
        : 0.0;
    result.grade = calculateGrade(result.percentage);

    displaySeparator();
    cout << "\n  RESULT FOR: " << result.name << "\n";
    displaySeparator();
    cout << "  Score      : " << result.score << " / " << result.maxScore << "\n";
    cout << "  Percentage : " << fixed << setprecision(1)
        << result.percentage << "%\n";
    cout << "  Grade      : " << gradeLabel(result.grade) << "\n";
    displaySeparator();

    cout << "\n  Category breakdown:\n";
    for (const auto& [cat, total] : result.totalPerCategory) {
        if (total == 0) continue;
        int    correct = result.correctPerCategory.at(cat);
        double pct = (static_cast<double>(correct) / total) * 100.0;
        cout << "  - " << setw(14) << left << categoryToString(cat)
            << ": " << correct << "/" << total
            << "  (" << fixed << setprecision(0) << pct << "%)\n";
    }

    return result;
}

// ---------- STATISTICS ----------

void displayStatistics(const vector<StudentResult>& results) {
    if (results.empty()) {
        cout << "\n  No test results yet.\n";
        return;
    }

    cout << "\n  STATISTICS\n";
    displaySeparator();

    const StudentResult* best = &results[0];
    const StudentResult* worst = &results[0];
    double totalPct = 0.0;

    for (const auto& r : results) {
        if (r.percentage > best->percentage)  best = &r;
        if (r.percentage < worst->percentage) worst = &r;
        totalPct += r.percentage;
    }

    double avgPct = totalPct / static_cast<double>(results.size());

    cout << "  Students tested : " << results.size() << "\n";
    cout << "  Average score   : " << fixed << setprecision(1)
        << avgPct << "% [" << gradeLabel(calculateGrade(avgPct)) << "]\n";
    cout << "  Best result     : " << best->name
        << "  " << fixed << setprecision(1) << best->percentage << "%\n";
    cout << "  Worst result    : " << worst->name
        << "  " << fixed << setprecision(1) << worst->percentage << "%\n";

    // Aggregate per-category performance across all sessions
    map<Category, int> catCorrect, catTotal;
    for (const auto& r : results) {
        for (const auto& [cat, cnt] : r.correctPerCategory) catCorrect[cat] += cnt;
        for (const auto& [cat, cnt] : r.totalPerCategory)   catTotal[cat] += cnt;
    }

    if (!catTotal.empty()) {
        cout << "\n  Category success rates:\n";
        displaySeparator();

        Category bestCat = catTotal.begin()->first;
        Category worstCat = catTotal.begin()->first;

        for (const auto& [cat, total] : catTotal) {
            if (total == 0) continue;
            double pct = (static_cast<double>(catCorrect[cat]) / total) * 100.0;
            cout << "  - " << setw(14) << left << categoryToString(cat)
                << ": " << fixed << setprecision(1) << pct << "%\n";

            double bestPct = catTotal[bestCat] > 0
                ? (static_cast<double>(catCorrect[bestCat]) / catTotal[bestCat]) * 100.0 : 0.0;
            double worstPct = catTotal[worstCat] > 0
                ? (static_cast<double>(catCorrect[worstCat]) / catTotal[worstCat]) * 100.0 : 100.0;

            if (pct > bestPct)  bestCat = cat;
            if (pct < worstPct) worstCat = cat;
        }

        cout << "\n  Best category  : " << categoryToString(bestCat) << "\n";
        cout << "  Worst category : " << categoryToString(worstCat) << "\n";
    }

    cout << "\n  All results:\n";
    displaySeparator();
    cout << "  " << setw(22) << left << "Name"
        << setw(10) << "Score"
        << setw(8) << "Pct"
        << "Grade\n";
    displaySeparator();
    for (const auto& r : results) {
        cout << "  " << setw(22) << left << r.name
            << setw(10) << (to_string(r.score) + "/" + to_string(r.maxScore))
            << setw(8) << (to_string(static_cast<int>(r.percentage)) + "%")
            << gradeLabel(r.grade) << "\n";
    }
}

// ---------- STUDY MATERIAL ----------

void showMathMaterial() {
    cout << "\n  ===  MATHEMATICS  ===\n\n";

    cout << "  ARITHMETIC\n";
    displaySeparator();
    cout << "  Arithmetic is the foundation of all mathematics. It covers\n";
    cout << "  the four basic operations applied to numbers.\n\n";

    cout << "  Addition (+)\n";
    cout << "  Combines two or more numbers into a total called the sum.\n";
    cout << "  Order does not matter: a + b = b + a  (commutative property)\n";
    cout << "  Adding zero changes nothing: a + 0 = a  (identity element)\n";
    cout << "  Example: 47 + 36 = 83\n\n";

    cout << "  Subtraction (-)\n";
    cout << "  Finds the difference between two numbers.\n";
    cout << "  Order matters: a - b is not the same as b - a\n";
    cout << "  Subtracting a negative equals addition: a - (-b) = a + b\n";
    cout << "  Example: 100 - 37 = 63\n\n";

    cout << "  Multiplication (x)\n";
    cout << "  Repeated addition of the same number.\n";
    cout << "  4 x 6 means 4 added 6 times: 4+4+4+4+4+4 = 24\n";
    cout << "  Anything multiplied by 0 equals 0. Anything x 1 = itself.\n";
    cout << "  Example: 12 x 12 = 144\n\n";

    cout << "  Division (/)\n";
    cout << "  Splits a number into equal parts.\n";
    cout << "  36 / 4 = 9 means: how many groups of 4 fit into 36?\n";
    cout << "  Division by zero is undefined and not allowed in mathematics.\n";
    cout << "  Remainder: 17 / 5 = 3 remainder 2\n\n";

    cout << "  Order of Operations (PEMDAS / BODMAS)\n";
    cout << "  Parentheses -> Exponents -> Multiply/Divide -> Add/Subtract\n";
    cout << "  Always left to right for same-priority operations.\n";
    cout << "  Example: 2 + 3 x 4 = 2 + 12 = 14  (NOT 20)\n\n";

    cout << "  ALGEBRA\n";
    displaySeparator();
    cout << "  Algebra uses letters (variables) to represent unknown values,\n";
    cout << "  allowing us to write and solve general rules and equations.\n\n";

    cout << "  Variables and Expressions\n";
    cout << "  x, y, z are the most common variable names.\n";
    cout << "  An expression like 3x + 2 means: multiply x by 3, then add 2.\n";
    cout << "  Expressions do NOT contain an equals sign; equations do.\n\n";

    cout << "  Solving Linear Equations\n";
    cout << "  Goal: isolate the variable on one side of the equals sign.\n";
    cout << "  Key rule: whatever you do to one side, do to the other.\n";
    cout << "  Example:  2x + 4 = 14\n";
    cout << "    Step 1: subtract 4 from both sides -> 2x = 10\n";
    cout << "    Step 2: divide both sides by 2    -> x = 5\n\n";

    cout << "  Powers and Roots\n";
    cout << "  x^n means x multiplied by itself n times.\n";
    cout << "  2^5 = 2x2x2x2x2 = 32   |   3^3 = 27   |   4^3 = 64\n";
    cout << "  Square root: the number which, squared, gives the original.\n";
    cout << "  sqrt(64) = 8 because 8 x 8 = 64\n";
    cout << "  Any non-zero number to the power of 0 equals 1: x^0 = 1\n\n";

    cout << "  Prime Numbers\n";
    cout << "  A prime number has exactly two factors: 1 and itself.\n";
    cout << "  Primes: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 ...\n";
    cout << "  1 is NOT prime (only one factor). 2 is the only even prime.\n";
    cout << "  To test: divide by all primes up to its square root.\n\n";

    cout << "  LCM and GCD\n";
    cout << "  LCM (Least Common Multiple): smallest number divisible by both.\n";
    cout << "  LCM(4, 6) = 12   (multiples of 4: 4,8,12 | of 6: 6,12)\n";
    cout << "  GCD (Greatest Common Divisor): largest divisor shared by both.\n";
    cout << "  GCD(18, 24) = 6  (factors of 18: 1,2,3,6,9,18 | of 24: 1,2,3,4,6...)\n";
}

void showChemistryMaterial() {
    cout << "\n  ===  CHEMISTRY  ===\n\n";

    cout << "  ELEMENTS AND THE PERIODIC TABLE\n";
    displaySeparator();
    cout << "  An element is a pure substance made of only one type of atom.\n";
    cout << "  Elements cannot be broken down by chemical reactions.\n";
    cout << "  There are 118 known elements, arranged in the Periodic Table\n";
    cout << "  by increasing atomic number (number of protons).\n\n";

    cout << "  Key Element Symbols\n";
    cout << "  Many symbols come from Latin names:\n";
    cout << "  H  = Hydrogen  (lightest, most abundant element in the universe)\n";
    cout << "  O  = Oxygen    (essential for respiration and combustion)\n";
    cout << "  C  = Carbon    (basis of all organic life on Earth)\n";
    cout << "  N  = Nitrogen  (makes up ~78% of Earth's atmosphere)\n";
    cout << "  Na = Sodium    (Latin: Natrium) - reactive alkali metal\n";
    cout << "  Fe = Iron      (Latin: Ferrum)  - most used metal in industry\n";
    cout << "  Au = Gold      (Latin: Aurum)   - noble metal, does not corrode\n";
    cout << "  Ag = Silver    (Latin: Argentum)- best electrical conductor\n";
    cout << "  Cu = Copper    (Latin: Cuprum)  - excellent heat conductor\n";
    cout << "  K  = Potassium (Latin: Kalium)  - essential for nerve function\n";
    cout << "  Pb = Lead      (Latin: Plumbum) - very dense, used in shielding\n";
    cout << "  Sn = Tin       (Latin: Stannum) - used in food cans and soldering\n\n";

    cout << "  Atomic Structure\n";
    cout << "  Nucleus: contains protons (+) and neutrons (no charge)\n";
    cout << "  Shells: contain electrons (-) orbiting the nucleus\n";
    cout << "  Atomic number = number of protons (defines the element)\n";
    cout << "  Mass number   = protons + neutrons\n";
    cout << "  Isotopes: same element, different number of neutrons\n\n";

    cout << "  COMPOUNDS AND REACTIONS\n";
    displaySeparator();
    cout << "  A compound forms when two or more elements bond chemically.\n";
    cout << "  Unlike mixtures, compounds have fixed compositions.\n\n";

    cout << "  Common Compounds\n";
    cout << "  H2O        = Water          (2 hydrogen + 1 oxygen atoms)\n";
    cout << "  CO2        = Carbon dioxide (greenhouse gas, plant food)\n";
    cout << "  NaCl       = Table salt     (sodium + chlorine)\n";
    cout << "  CH4        = Methane        (natural gas, simplest hydrocarbon)\n";
    cout << "  C2H5OH     = Ethanol        (alcohol in beverages)\n";
    cout << "  C12H22O11  = Sucrose        (common table sugar)\n\n";

    cout << "  pH Scale (0-14)\n";
    cout << "  pH < 7  : Acidic   - lemon juice (2), vinegar (3), coffee (5)\n";
    cout << "  pH = 7  : Neutral  - pure water\n";
    cout << "  pH > 7  : Alkaline - baking soda (9), bleach (13), NaOH (14)\n";
    cout << "  Each step on the pH scale is a factor of 10 difference.\n\n";

    cout << "  Types of Reactions\n";
    cout << "  Exothermic : releases energy (heat/light). Burning, explosions.\n";
    cout << "  Endothermic: absorbs energy from surroundings. Photosynthesis.\n";
    cout << "  Neutralisation: Acid + Base -> Salt + Water\n";
    cout << "  Oxidation  : loss of electrons (OIL - Oxidation Is Loss)\n";
    cout << "  Reduction  : gain of electrons (RIG - Reduction Is Gain)\n\n";

    cout << "  Photosynthesis Equation\n";
    cout << "  6CO2 + 6H2O + light energy -> C6H12O6 + 6O2\n";
    cout << "  Plants absorb CO2 and water; they release glucose and oxygen.\n\n";

    cout << "  States of Matter\n";
    cout << "  Solid  : fixed shape, fixed volume. Particles tightly packed.\n";
    cout << "  Liquid : fixed volume, takes shape of container.\n";
    cout << "  Gas    : no fixed shape or volume. Particles move freely.\n";
    cout << "  Physical change (melting, boiling): composition unchanged.\n";
    cout << "  Chemical change (burning, rusting): new substances are formed.\n";
    cout << "  Catalysts speed up reactions without being consumed themselves.\n";
}

