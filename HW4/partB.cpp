#include <iostream>

using namespace std;

void sort(double a[], int numberUsed);

void swapValues(double& v1, double& v2);

int indexOfSmallest(const double a[], int startIndex, int numberUsed);

void inputDegreeOfDifficulty(double& degreeOfDifficulty);

void inputScores(double scores[], int size);

double calculateScore(double scores[], int size, double degreeOfDifficulty);

int main() {
    double degreeOfDifficulty;
    inputDegreeOfDifficulty(degreeOfDifficulty);

    double scores[7];
    cout << "Input the 7 scores (between 0 and 10): " << endl;
    inputScores(scores, 7);

    sort(scores, 7);

    double adjustedScores[5];
    for (int i = 1; i < 6; i++) {
        adjustedScores[i-1] = scores[i];
    }

    double totalScore = calculateScore(adjustedScores, 5, degreeOfDifficulty);

    cout << "Total score: " << totalScore << endl;

    return 0;
}

void sort(double a[], int numberUsed) {
    int indexOfNextSmallest;
    for (int i = 0; i < numberUsed - 1; i++) {
        indexOfNextSmallest = indexOfSmallest(a, i, numberUsed);
        swapValues(a[i], a[indexOfNextSmallest]);
    }
}

void swapValues(double& v1, double& v2) {
    double temp = v1;
    v1 = v2;
    v2 = temp;
}

int indexOfSmallest(const double a[], int startIndex, int numberUsed) {
    double min = a[startIndex], indexOfMin = startIndex;
    for (int i = startIndex + 1; i < numberUsed; i++) {
        if (a[i] < min) {
            min = a[i];
            indexOfMin = i;
        }
    }
    return indexOfMin;
}

void inputDegreeOfDifficulty(double& degreeOfDifficulty) {
    cout << "Input the degree of difficulty (1.2 to 3.8): ";
    cin >> degreeOfDifficulty;

    while (degreeOfDifficulty < 1.2 || degreeOfDifficulty > 3.8) {
        cout << "Invalid input. Degree of difficulty must be between 1.2 and 3.8." << endl;
        cout << "Input the degree of difficulty (1.2 to 3.8): ";
        cin >> degreeOfDifficulty;
    }
}

void inputScores(double scores[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Input score " << i + 1 << ": ";
        cin >> scores[i];

        if (scores[i] < 0 || scores[i] > 10) {
            cout << "Invalid input. Scores must be between 0 and 10." << endl;
            i--;
        }
    }
}

double calculateScore(double scores[], int size, double degreeOfDifficulty) {
    double totalScore = 0;
    for (int i = 0; i < size; i++) {
        totalScore += scores[i];
    }
    totalScore *= degreeOfDifficulty;
    totalScore *= 0.6;

    return totalScore;
}