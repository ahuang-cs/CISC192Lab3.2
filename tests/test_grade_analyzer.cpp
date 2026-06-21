#include "grade_analyzer.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

bool nearlyEqual(double actual, double expected, double tolerance = 0.0001) {
    return fabs(actual - expected) <= tolerance;
}

void testCalculateTotal() {
    assert(nearlyEqual(calculateTotal(90.0, 80.0, 70.0), 240.0));
    assert(nearlyEqual(calculateTotal(100.0, 100.0, 100.0), 300.0));
    assert(nearlyEqual(calculateTotal(0.0, 0.0, 0.0), 0.0));
}

void testCalculateAverage() {
    assert(nearlyEqual(calculateAverage(240.0, 3), 80.0));
    assert(nearlyEqual(calculateAverage(300.0, 3), 100.0));
    assert(nearlyEqual(calculateAverage(0.0, 3), 0.0));
    assert(nearlyEqual(calculateAverage(100.0, 0), 0.0));
    assert(nearlyEqual(calculateAverage(100.0, -5), 0.0));
}

void testDetermineLetterGrade() {
    assert(determineLetterGrade(100.0) == 'A');
    assert(determineLetterGrade(90.0) == 'A');
    assert(determineLetterGrade(89.9) == 'B');
    assert(determineLetterGrade(80.0) == 'B');
    assert(determineLetterGrade(79.9) == 'C');
    assert(determineLetterGrade(70.0) == 'C');
    assert(determineLetterGrade(69.9) == 'D');
    assert(determineLetterGrade(60.0) == 'D');
    assert(determineLetterGrade(59.9) == 'F');
}

void testIsPassing() {
    assert(isPassing(100.0));
    assert(isPassing(70.0));
    assert(!isPassing(69.9));
    assert(!isPassing(0.0));
}

void testIsValidScore() {
    assert(isValidScore(0.0));
    assert(isValidScore(50.0));
    assert(isValidScore(100.0));
    assert(!isValidScore(-0.1));
    assert(!isValidScore(100.1));
}

int main() {
    testCalculateTotal();
    testCalculateAverage();
    testDetermineLetterGrade();
    testIsPassing();
    testIsValidScore();

    cout << "All Lab 3.2 grade analyzer tests passed!" << endl;
    return 0;
}
