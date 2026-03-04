#include <iostream>

using namespace std;

/**
 * 4. (25 pts) Write a program using several functions (up to your judgment, 
 * but at least 3) to take user input for a weight in pounds (lb) and ounces (oz) 
 * and output the equivalent value in kilograms and grams (e.g. 2lb 3oz would be 
 * converted to 0kg 992g). Include a loop that lets the user convert as many weights 
 * as possible until they quit (up to you how to design this). There are 2.2046 pounds 
 * in 1kg, 1000g in 1kg, and 16oz in 1lb. The conversion function must be of type void 
 * and take the kilogram and gram arguments as pass-by-reference, while the rest of the 
 * arguments are up to you.
 */

void input(double& pounds, double& ounces);
void conversion (double pounds, double ounces, double& kilograms, double& grams);
void output(double kilograms, double grams);
int main() {

    double pounds, ounces, kilograms, grams;
    char user_choice;
    do {
        input(pounds, ounces);
        conversion(pounds, ounces, kilograms, grams);
        output(kilograms, grams);
        cout << "Do you want to convert another weight? (y/n) ";
        cin >> user_choice;
    } while (user_choice == 'y' || user_choice == 'Y');
    return 0;
}

void input (double& pounds, double& ounces) {
    cout << "Enter weight in pounds and ounces (e.g. 2 3 for 2lb 3oz): ";
    cin >> pounds >> ounces;
}
void conversion (double pounds, double ounces, double& kilograms, double& grams) {
    double total_pounds = pounds + ounces / 16.0;
    kilograms = total_pounds / 2.2046;
    grams = static_cast<int>((kilograms - static_cast<int>(kilograms)) * 1000);
    kilograms = static_cast<int>(kilograms);
}
void output(double kilograms, double grams) {
    cout << "Equivalent weight: " << kilograms << " kg " << grams << " g" << endl;
}