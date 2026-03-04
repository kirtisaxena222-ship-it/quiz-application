#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

struct Question {
    string questionText;
    string options[4];
    int correctAnswer;
};

void startQuiz(vector<Question>& questions) {
    int score = 0;

    for (int i = 0; i < questions.size(); i++) {
        cout << "\nQ" << i + 1 << ": " << questions[i].questionText << endl;

        for (int j = 0; j < 4; j++) {
            cout << j + 1 << ". " << questions[i].options[j] << endl;
        }

        time_t startTime = time(0);

        int answer;
        cout << "Your answer (1-4): ";
        cin >> answer;

        time_t endTime = time(0);
        double timeTaken = difftime(endTime, startTime);

        if (timeTaken > 10) {
            cout << "⏰ Time's up! (More than 10 seconds)\n";
            continue;
        }

        if (answer == questions[i].correctAnswer) {
            cout << "Correct! ✅\n";
            score++;
        } else {
            cout << "Wrong ❌\n";
        }
    }

    cout << "\nFinal Score: " << score << "/" << questions.size() << endl;
}

int main() {

    vector<Question> easyQuestions = {
        {"What is 2 + 2?",
         {"3", "4", "5", "6"},
         2},

        {"Capital of India?",
         {"Mumbai", "Delhi", "Chennai", "Kolkata"},
         2}
    };

    vector<Question> hardQuestions = {
        {"What is the square root of 144?",
         {"10", "11", "12", "13"},
         3},

        {"C++ is developed by?",
         {"James Gosling", "Bjarne Stroustrup", "Dennis Ritchie", "Guido van Rossum"},
         2}
    };

    int choice;
    cout << "==== Quiz Application ====\n";
    cout << "Select Difficulty:\n";
    cout << "1. Easy\n";
    cout << "2. Hard\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        startQuiz(easyQuestions);
    } else if (choice == 2) {
        startQuiz(hardQuestions);
    } else {
        cout << "Invalid choice!\n";
    }

    return 0;
}
