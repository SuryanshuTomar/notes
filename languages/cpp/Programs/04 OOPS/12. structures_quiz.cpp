#include <iostream>
#include <vector>

using namespace std;

struct Question
{
private:
    string questionText;
    vector<string> options;
    int correctAnswerIndex;

public:
    void addQuestion(const string &questionText, const vector<string> &options, int correctAnswerIndex)
    {
        this->questionText = questionText;
        this->options = options;
        this->correctAnswerIndex = correctAnswerIndex;
    }

    void deleteQuestions()
    {
        questionText.clear();
        options.clear();
        correctAnswerIndex = -1; // Invalid index
    }

    void showQuestion() const
    {
        cout << "Question: " << questionText << endl;
        cout << "Options:" << endl;
        for (size_t i = 0; i < options.size(); ++i)
        {
            cout << i + 1 << ". " << options[i] << endl;
        }
    }

    bool checkAnswer(int answerIndex) const
    {
        return answerIndex == correctAnswerIndex;
    }

    string getCorrectAnswer() const
    {
        if (correctAnswerIndex >= 0 && correctAnswerIndex < options.size())
        {
            return options[correctAnswerIndex];
        }
        return "Invalid answer index";
    }
};

struct Quiz
{
private:
    // Quiz() = default;            // Private constructor to prevent instantiation
    // Quiz(const Quiz &) = delete; // Disable copy constructor

public:
    vector<Question> questions;

    // Function to add a question to the quiz
    void addQuestion(const string &questionText, const vector<string> &options, int correctAnswerIndex)
    {
        Question question;
        question.addQuestion(questionText, options, correctAnswerIndex);
        questions.push_back(question);
    }

    void resetQuiz()
    {
        questions.clear(); // Clear all questions in the quiz
    }

    // start the quiz
    void startQuiz() const
    {
        cout << "Starting the quiz..." << endl;
        for (const auto &question : questions)
        {
            question.showQuestion();
            int answerIndex;
            cout << "Enter your answer : ";
            cin >> answerIndex;
            if (question.checkAnswer(answerIndex - 1))
            {
                cout << "Correct!" << endl;
            }
            else
            {
                cout << "Incorrect. The correct answer was: " << question.getCorrectAnswer() << endl << endl;
            }
        }
        cout << "Quiz completed!" << endl;
    }
};


int main(){
    Quiz quiz;
    // Adding questions to the quiz
    quiz.addQuestion("What's your favorite animal?", {"Dog", "Cat", "Rabbit"}, 2);
    quiz.addQuestion("What is your favorite show?", {"Drake & Josh", "BTR", "iCarly"}, 1);
    quiz.addQuestion("What is your favorite color?", {"blue", "green", "red"}, 1);

    // Start the quiz
    quiz.startQuiz();
    
    // Uncomment the following lines to see how to delete questions
    // quiz.questions[0].deleteQuestions();
    // quiz.questions[1].deleteQuestions();
    // quiz.questions[2].deleteQuestions();
    
    // Uncomment the following lines to see how to add questions
    // quiz.addQuestion("What is your favorite food?", {"Pizza", "Burger", "Pasta"}, 0);
    
    // Reset the quiz if needed
    // quiz.resetQuiz();

    return 0;
}