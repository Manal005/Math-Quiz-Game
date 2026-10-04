#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enLevel
{
    Easy = 1,
    Med = 2,
    Hard = 3,
    MixLevel = 4
};

enum enType
{
    Add = 1,
    Sub = 2,
    Div = 3,
    Mul = 4,
    MixType = 5
};

struct Quiz
{
    int questionCount = 1;
    enLevel level = MixLevel;
    enType type = MixType;
    int correctAnswers = 0;
    int wrongAnswers = 0;
};

// ---------------------------------------------
// Random Number
// ---------------------------------------------

int RandomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

// ---------------------------------------------
// Get Level
// ---------------------------------------------

enLevel GetLevel(int level)
{
    switch (level)
    {
    case 1:
        return Easy;

    case 2:
        return Med;

    case 3:
        return Hard;

    case 4:
        return MixLevel;

    default:
        return Easy;
    }
}

// ---------------------------------------------
// Get Type
// ---------------------------------------------

enType GetType(int type)
{
    switch (type)
    {
    case 1:
        return Add;

    case 2:
        return Sub;

    case 3:
        return Div;

    case 4:
        return Mul;

    case 5:
        return MixType;

    default:
        return MixType;
    }
}

// ---------------------------------------------
// Generate Level Randomly
// ---------------------------------------------

enLevel GetRandomLevel()
{
    return GetLevel(RandomNumber(1, 3));
}

// ---------------------------------------------
// Get Operation
// ---------------------------------------------

char GetRandomOperation()
{
    int operation = RandomNumber(1, 4);

    switch (operation)
    {
    case 1:
        return '+';

    case 2:
        return '-';

    case 3:
        return '*';

    case 4:
        return '/';
    }

    return '+';
}

// ---------------------------------------------
// Get Operation According To Type
// ---------------------------------------------

char GetOperation(enType type)
{
    switch (type)
    {
    case Add:
        return '+';

    case Sub:
        return '-';

    case Div:
        return '/';

    case Mul:
        return '*';

    case MixType:
        return GetRandomOperation();
    }

    return '+';
}

// ---------------------------------------------
// Generate Number According To Level
// ---------------------------------------------

int NumberByLevel(enLevel level)
{
    switch (level)
    {
    case Easy:
        return RandomNumber(1, 10);

    case Med:
        return RandomNumber(11, 60);

    case Hard:
        return RandomNumber(61, 100);

    default:
        return RandomNumber(1, 10);
    }
}

// ---------------------------------------------
// Calculate Answer
// ---------------------------------------------

int CalculateAnswer(int number1, int number2, char operation)
{
    switch (operation)
    {
    case '+':
        return number1 + number2;

    case '-':
        return number1 - number2;

    case '*':
        return number1 * number2;

    case '/':
        return number1 / number2;
    }

    return 0;
}

// ---------------------------------------------
// Generate Numbers
// ---------------------------------------------

void GenerateNumbers(
    enLevel level,
    char operation,
    int& number1,
    int& number2)
{
    number1 = NumberByLevel(level);
    number2 = NumberByLevel(level);

    // Make division result an integer
    if (operation == '/')
    {
        number2 = RandomNumber(1, 10);
        number1 = number2 * RandomNumber(1, 10);
    }
}

// ---------------------------------------------
// Print Level
// ---------------------------------------------

string PrintLevel(enLevel level)
{
    switch (level)
    {
    case Easy:
        return "Easy";

    case Med:
        return "Medium";

    case Hard:
        return "Hard";

    case MixLevel:
        return "Mix";
    }

    return "Unknown";
}

// ---------------------------------------------
// Print Type
// ---------------------------------------------

string PrintType(enType type)
{
    switch (type)
    {
    case Add:
        return "Addition";

    case Sub:
        return "Subtraction";

    case Div:
        return "Division";

    case Mul:
        return "Multiplication";

    case MixType:
        return "Mix";
    }

    return "Unknown";
}

// ---------------------------------------------
// Ask One Question
// ---------------------------------------------

void Question(Quiz& quiz)
{
    enLevel currentLevel = quiz.level;

    // If level is Mix, choose a new level for every question
    if (quiz.level == MixLevel)
    {
        currentLevel = GetRandomLevel();
    }

    char operation = GetOperation(quiz.type);

    int number1;
    int number2;

    GenerateNumbers(
        currentLevel,
        operation,
        number1,
        number2
    );

    int correctAnswer =
        CalculateAnswer(number1, number2, operation);

    int userAnswer;

    cout << "\n";
    cout << number1 << '\n';
    cout << operation << " " << number2 << '\n';
    cout << "____________\n";

    cin >> userAnswer;

    if (userAnswer == correctAnswer)
    {
        quiz.correctAnswers++;

        system("color 2F");

        cout << "\nRight answer :)\n";
    }
    else
    {
        quiz.wrongAnswers++;

        system("color 4F");

        cout << '\a';
        cout << "\nWrong answer :(\n";
        cout << "Correct answer is: "
             << correctAnswer << '\n';
    }
}

// ---------------------------------------------
// Start Test
// ---------------------------------------------

void Test(Quiz& quiz)
{
    for (int i = 0; i < quiz.questionCount; i++)
    {
        cout << "\n\nQuestion ["
             << i + 1
             << "/"
             << quiz.questionCount
             << "]\n";

        Question(quiz);
    }
}

// ---------------------------------------------
// Final Result
// ---------------------------------------------

void FinalResult(const Quiz& quiz)
{
    int score =
        (quiz.correctAnswers * 100)
        / quiz.questionCount;

    cout << "\n";
    cout << "________________________________________\n";

    if (score >= 50)
    {
        cout << "Final Result: PASS :)\n";
    }
    else
    {
        cout << "Final Result: FAIL :(\n";
    }

    cout << "________________________________________\n";

    cout << "\nNumber of questions : "
         << quiz.questionCount;

    cout << "\nQuestions level : "
         << PrintLevel(quiz.level);

    cout << "\nQuestions type : "
         << PrintType(quiz.type);

    cout << "\nCorrect answers : "
         << quiz.correctAnswers;

    cout << "\nWrong answers : "
         << quiz.wrongAnswers;

    cout << "\nScore : "
         << score
         << "%";

    cout << "\n";
}

// ---------------------------------------------
// Get Number Of Questions
// ---------------------------------------------

int GetQuestionCount()
{
    int count;

    do
    {
        cout << "How many questions do you want to answer? ";
        cin >> count;

        if (count <= 0)
        {
            cout << "Please enter a positive number.\n";
        }

    } while (count <= 0);

    return count;
}

// ---------------------------------------------
// Get Level Choice
// ---------------------------------------------

int GetLevelChoice()
{
    int choice;

    do
    {
        cout << "\nEnter questions level:\n";
        cout << "[1] Easy\n";
        cout << "[2] Medium\n";
        cout << "[3] Hard\n";
        cout << "[4] Mix\n";
        cout << "Your choice: ";

        cin >> choice;

        if (choice < 1 || choice > 4)
        {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice < 1 || choice > 4);

    return choice;
}

// ---------------------------------------------
// Get Type Choice
// ---------------------------------------------

int GetTypeChoice()
{
    int choice;

    do
    {
        cout << "\nEnter questions type:\n";
        cout << "[1] Addition\n";
        cout << "[2] Subtraction\n";
        cout << "[3] Division\n";
        cout << "[4] Multiplication\n";
        cout << "[5] Mix\n";
        cout << "Your choice: ";

        cin >> choice;

        if (choice < 1 || choice > 5)
        {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice < 1 || choice > 5);

    return choice;
}

// ---------------------------------------------
// Start Game
// ---------------------------------------------

void Start()
{
    char playAgain;

    do
    {
        system("color 0F");
        system("cls");

        Quiz quiz;

        int levelChoice;
        int typeChoice;

        quiz.questionCount = GetQuestionCount();

        levelChoice = GetLevelChoice();

        typeChoice = GetTypeChoice();

        quiz.level = GetLevel(levelChoice);
        quiz.type = GetType(typeChoice);

        Test(quiz);

        FinalResult(quiz);

        cout << "\n\n";
        cout << "________________________________________\n";
        cout << "Do you want to play again? (y/n): ";

        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');
}

// ---------------------------------------------
// Main
// ---------------------------------------------

int main()
{
    srand((unsigned)time(NULL));

    Start();

    return 0;
}