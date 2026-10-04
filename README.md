# Math Quiz Game

A simple **C++ console-based Math Quiz Game** that generates random arithmetic questions based on the user's selected difficulty level and operation type.

The project was developed to practice fundamental C++ programming concepts such as **functions, enums, structures, loops, conditionals, references, random number generation, and input validation**.

## Features

* Choose the number of questions.
* Choose the difficulty level:

  * Easy
  * Medium
  * Hard
  * Mixed
* Choose the arithmetic operation:

  * Addition
  * Subtraction
  * Division
  * Multiplication
  * Mixed
* Randomly generated questions.
* Mixed difficulty can generate a different level for each question.
* Division questions are generated with integer results.
* Automatically checks the user's answers.
* Displays the correct answer when the user gives a wrong answer.
* Tracks correct and wrong answers.
* Calculates the final score as a percentage.
* Displays a final pass/fail result.
* Validates the user's menu choices and number of questions.
* Allows the user to restart the quiz.

## How It Works

When the program starts, the user is asked to choose:

1. The number of questions.
2. The difficulty level.
3. The arithmetic operation.

The program then generates questions according to the selected settings.

For each question:

1. A difficulty level is selected.
2. An arithmetic operation is selected.
3. Two random numbers are generated.
4. The question is displayed.
5. The user enters an answer.
6. The program checks the answer.
7. The correct or wrong answer counter is updated.

If **Mixed Level** is selected, a new difficulty level is randomly selected for every question.

If **Mixed Operation** is selected, a new arithmetic operation is randomly selected for every question.

At the end of the quiz, the program displays the total number of questions, selected settings, correct and wrong answers, and the final score.

## Example

```text
How many questions do you want to answer? 5

Enter questions level:
[1] Easy
[2] Medium
[3] Hard
[4] Mix
Your choice: 4

Enter questions type:
[1] Addition
[2] Subtraction
[3] Division
[4] Multiplication
[5] Mix
Your choice: 5
```

Example question:

```text
Question [1/5]

8
* 4
____________
```

If the answer is correct:

```text
Right answer :)
```

If the answer is incorrect:

```text
Wrong answer :(
Correct answer is: 32
```

At the end:

```text
________________________________________
Final Result: PASS :)
________________________________________

Number of questions : 5
Questions level : Mix
Questions type : Mix
Correct answers : 4
Wrong answers : 1
Score : 80%
```

## Concepts Used

This project demonstrates several fundamental C++ concepts:

* `struct`
* `enum`
* Functions
* Function parameters
* References
* `switch` statements
* `if / else`
* `for` loops
* `do-while` loops
* Random number generation
* `rand()` and `srand()`
* `cin` and `cout`
* Strings and characters
* Input validation
* Basic program decomposition
* Modular function design

## Project Structure

```text
Math-Quiz-Game/
│
├── main.cpp
└── README.md
```

## Requirements

* A C++ compiler
* C++11 or later
* Windows for the current console color and screen-clearing features

## How to Run

### Using g++

Compile the program:

```bash
g++ main.cpp -o MathQuiz
```

Run the program:

```bash
MathQuiz
```

### Using an IDE

The project can also be opened and run using common C++ IDEs such as:

* Visual Studio
* Code::Blocks
* CLion
* VS Code with a C++ compiler


## Purpose

This project was created as part of my **C++ learning journey** to practice writing a complete interactive program and applying fundamental programming concepts in a practical project.


