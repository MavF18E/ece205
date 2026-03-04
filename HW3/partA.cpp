#include <iostream>

using namespace std;

/** 1. (25 pts) 
 * Write a program that converts from 24-hour notation to 12-hour notation. The input is given as two integers, entered 
 * sequentially by the user. There should be at least 3 functions: one for input, one for the conversion, and one for output. 
 * The AM/PM information should be recorded as a single char (‘A’ for AM and ‘P’ for PM). The conversion function will have a 
 * call-by-reference formal parameter of type char to record where it’s AM or PM (but it may also have other parameters as well). 
 * Include a loop that lets the user repeat this computation for new input values until the user wants to end the program (you can do 
 * this with a negative integer input or using some other solution). 
 * */

void input(int& hours, int& minutes);
void conversion(int& hours, int& minutes, char& am_pm);
void output(int hours, int minutes, char am_pm);

int main() {
    int hours, minutes;
    char am_pm;
    char user_choice;
    do {
        input(hours, minutes);
        conversion(hours, minutes, am_pm);
        output(hours, minutes, am_pm);
        cout << "Do you want to convert another time? (y/n) ";
        cin >> user_choice;
    } while (user_choice == 'y' || user_choice == 'Y');
    return 0;
}

void input(int& hours, int& minutes) {
    cout << "Input: Start time in 24-hour format (hhmm) = ";
    int start_time;
    cin >> start_time;
    hours = start_time / 100;
    minutes = start_time % 100;
}

void conversion(int& hours, int& minutes, char& am_pm) {
    if (hours > 12) {
        hours -= 12;
        am_pm = 'P';
    }
    else if (hours == 12) {
        am_pm = 'P';
    }
    else {
        am_pm = 'A';
    }
}

void output(int hours, int minutes, char am_pm) {
    cout << "Start time in 12-hour format = ";
    if (minutes < 10) {
        cout << hours << ":0" << minutes << " " << am_pm << "M" << endl;
    }
    else {
        cout << hours << ":" << minutes << " " << am_pm << "M" << endl;
    }
}