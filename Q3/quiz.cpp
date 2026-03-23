#include <iostream>
#include <cmath>

using namespace std;

int findMax(int a[], int size);
int findMin(int a[], int size);
double calculateAverage(int a[], int size);
double computeStdDev(int a[], int size, double average);

int main() {
    int scores[5];
    double temp;
    cout << "Input 5 scores (between 0 and 100): " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Score " << (i + 1) << ": ";
        cin >> temp;
        
        if (temp < 0 || temp > 100) {
            cout << "Invalid score. Please enter a score between 0 and 100." << endl;
            i--; // Decrement i to repeat the input for the current index
            continue;
        }
        else if (temp != floor(temp)) {
            cout << "Non-integer values are not allowed. Please enter an integer: \n";
            i--;
            continue;
        } 
        scores[i] = temp;
    }


    int maxScore = findMax(scores, 5);
    int minScore = findMin(scores, 5);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    double averageScore = calculateAverage(scores, 5);
    double stdDev = computeStdDev(scores, 5, averageScore);
    cout << "Max Score: " << maxScore << endl;
    cout << "Min Score: " << minScore << endl;
    cout << "Average Score: " << averageScore << endl;
    cout << "Standard Deviation: " << stdDev << endl;
}

int findMax(int a[], int size) {
    int max = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int findMin(int a[], int size) {
    int min = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

double calculateAverage(int a[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += a[i];
    }
    return static_cast<double>(sum) / size;
}

double computeStdDev(int a[], int size, double average) {
    double sumOfSquares = 0.0;
    for (int i = 0; i < size; i++) {
        sumOfSquares += (a[i] - average) * (a[i] - average);
    }
    return sqrt(sumOfSquares / size);
}
