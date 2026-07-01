#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Question {
private:
    std::string questionText;
    std::vector<std::string> options;
    char correctOption; 

public:

    Question(std::string text, std::vector<std::string> opts, char correct) {
        questionText = text;
        options = opts;
        correctOption = toupper(correct);
    }

    void display() const {
        std::cout << "\n--------------------------------------------------\n";
        std::cout << questionText << "\n";
        char label = 'A';
        for (const auto& option : options) {
            std::cout << "  " << label << ") " << option << "\n";
            label++;
        }
        std::cout << "--------------------------------------------------\n";
    }

    bool checkAnswer(char userAns) const {
        return toupper(userAns) == correctOption;
    }

   
    char getCorrectOption() const {
        return correctOption;
    }
};

class QuizEngine {
private:
    std::vector<Question> questionBank;
    int score;

public:
    QuizEngine() : score(0) {}

    void addQuestion(const Question& q) {
        questionBank.push_back(q);
    }

    void startQuiz() {
        if (questionBank.empty()) {
            std::cout << "The quiz bank is currently empty.\n";
            return;
        }
        score = 0; 
        char userChoice;

        std::cout << "\n==================================================";
        std::cout << "\n           WELCOME TO THE C++ QUIZ GAME           ";
        std::cout << "\n==================================================\n";

        for (size_t i = 0; i < questionBank.size(); ++i) {
            std::cout << "\nQuestion " << (i + 1) << " of " << questionBank.size();
            questionBank[i].display();

            while (true) {
                std::cout << "Enter your answer (A, B, C, or D): ";
                std::cin >> userChoice;
                userChoice = toupper(userChoice);

                if (userChoice == 'A' || userChoice == 'B' || userChoice == 'C' || userChoice == 'D') {
                    break;
                }
                std::cout << "Invalid selection. Please use letters A, B, C, or D.\n";
            }

            if (questionBank[i].checkAnswer(userChoice)) {
                std::cout << ">> Correct! Well done.\n";
                score++;
            } else {
                std::cout << ">> Incorrect. The right choice was " 
                          << questionBank[i].getCorrectOption() << ".\n";
            }
        }

        displayResults();
    }

private:
    void displayResults() const {
        double percentage = (static_cast<double>(score) / questionBank.size()) * 100.0;
        
        std::cout << "\n==================================================";
        std::cout << "\n                  QUIZ COMPLETED                  ";
        std::cout << "\n==================================================\n";
        std::cout << "Your Final Score: " << score << " out of " << questionBank.size() << "\n";
        std::cout << "Success Percentage: " << percentage << "%\n";
        
        if (percentage >= 70.0) {
            std::cout << "Status: Outstanding achievement! You passed.\n";
        } else {
            std::cout << "Status: Keep learning! Practice makes perfect.\n";
        }
        std::cout << "==================================================\n";
    }
};

int main() {
    QuizEngine systemQuiz;

    systemQuiz.addQuestion(Question(
        "Which programming language is known for direct hardware communication and performance?",
        {"Python", "C++", "Java", "JavaScript"}, 'B'
    ));

    systemQuiz.addQuestion(Question(
        "Which concept enables a class to derive features and properties from another class?",
        {"Encapsulation", "Polymorphism", "Inheritance", "Abstraction"}, 'C'
    ));

    systemQuiz.addQuestion(Question(
        "What data structure operates on a First-In, First-Out (FIFO) pipeline mechanism?",
        {"Stack", "Queue", "Binary Tree", "Graph"}, 'B'
    ));

    systemQuiz.addQuestion(Question(
        "Which keyword is utilized to clear allocated heap memory in C++?",
        {"free", "clear", "remove", "delete"}, 'D'
    ));

    systemQuiz.startQuiz();

    return 0;
}