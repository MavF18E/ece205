#include <iostream>

using namespace std;

/**
 * 3. (25 pts) Write a program that will take start and end times as 
 * 2 integers in 24-hour format military time notation (i.e. range is 
 * 0000 to 2359). After user input, the program will calculate and return 
 * the amount of minutes between the start and end times as a function where 
 * the parameters are passed-by-value. Be careful of time intervals where 
 * the start time is before midnight and the end time is the following day 
 * (e.g. start at 2300 and end at 0600).
 */
double compute_minutes(int start_time, int end_time);

int main() {
    cout << "Input: Start time in 24-hour format (hhmm) = ";
    int start_time;
    cin >> start_time;
    cout << "Input: End time in 24-hour format (hhmm) = ";
    int end_time;
    cin >> end_time;

    double minutes_between = compute_minutes(start_time, end_time);
    cout << "Minutes between: " << minutes_between << endl;

    return 0;

}

double compute_minutes(int start_time, int end_time) {
    int start_hours = start_time / 100;
    int start_minutes = start_time % 100;
    int end_hours = end_time / 100;
    int end_minutes = end_time % 100;

    int total_start_minutes = start_hours * 60 + start_minutes;
    int total_end_minutes = end_hours * 60 + end_minutes;

    if (total_end_minutes < total_start_minutes) {
        total_end_minutes += 24 * 60; // Add 24 hours in minutes
    }

    return total_end_minutes - total_start_minutes;
}