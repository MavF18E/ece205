#include <iostream>
#include <cmath>

using namespace std;

void getHatSize(double w, double h);
void getJacketSize(double w, double h, double a);
void getWaistSize(double w, double a);

int main() {
    double weight, height, age;

    cout << "Enter your height (in inches): " << endl;
    cin >> height;

    cout << "Enter your weight (in pounds): " << endl;
    cin >> weight;

    cout << "Enter your age: " << endl;
    cin >> age;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    getHatSize(weight, height);
    getJacketSize(weight, height, age);
    getWaistSize(weight, age);

    return 0;
}

void getHatSize(double w, double h) {
    double hatSize = (2.9 * w) / h;

    cout << "Your hat size is: " << hatSize << endl;
}

void getJacketSize(double w, double h, double a) {
    double jacketSize = (h * w) / 288;
    while (a > 30) {
        jacketSize += 0.125;
        a -= 10;
    }

    cout << "Your jacket size is: " << jacketSize << endl;
}

void getWaistSize(double w, double a) {
    double waistSize = w / 5.7;
    while (a > 28) {
        waistSize += 0.1;
        a -= 2;
    }

    cout << "Your waist size is: " << waistSize << endl;
}