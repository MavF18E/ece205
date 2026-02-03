#include <iostream>

using namespace std;

int main() {
    cout << "Input a length of time (in seconds) to convert: " << endl;

    int total_seconds;

    cin >> total_seconds;

    int hours = total_seconds / 3600;
    int minutes = (total_seconds % 3600) / 60;
    int seconds = total_seconds % 60;

    double total_hours = total_seconds / 3600.0;
    double total_minutes = total_seconds / 60.0;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);



    cout << total_seconds << " seconds is equivalent to " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds." << endl;
    cout << total_seconds << " seconds is also equivalent to " << total_hours << " hours." << endl;
    cout << total_seconds << " seconds is also equivalent to " << total_minutes << " minutes." << endl;

    return 0;
}