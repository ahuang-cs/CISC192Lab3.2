#include "grade_analyzer.hpp"
#include <iostream>

using namespace std;

int main() {
    double score1 = 0.0;
    double score2 = 0.0;
    double score3 = 0.0;

    cout << "Grade Analyzer" << endl;
    cout << endl;

    cout << "Enter score 1: ";
    cin >> score1;

    while (!isValidScore(score1)) {
        cout << "Invalid score. Enter a score from 0 to 100: ";
        cin >> score1;
    }

    cout << "Enter score 2: ";
    cin >> score2;

    while (!isValidScore(score2)) {
        cout << "Invalid score. Enter a score from 0 to 100: ";
        cin >> score2;
    }

    cout << "Enter score 3: ";
    cin >> score3;

    while (!isValidScore(score3)) {
        cout << "Invalid score. Enter a score from 0 to 100: ";
        cin >> score3;
    }

    double total = calculateTotal(score1, score2, score3);
    double average = calculateAverage(total, SCORE_COUNT);
    char letterGrade = determineLetterGrade(average);
    bool passing = isPassing(average);

    printGradeReport(total, average, letterGrade, passing);

    return 0;
}
