#include <iostream>

using namespace std;

class BicycleSpeedometer {
    public:
        void set_distance_traveled(double distance1) {
            distance_traveled = distance1;
        }

        double get_distance_traveled() {
            return distance_traveled;
        }

        void set_time_taken(double time) {
            time_taken = time;
        }

        double average_speed(double distance, double time) {
            double time_in_hours = time / 60.0;
            avg_speed = distance / time_in_hours;
            return avg_speed;
        }

        void display(double distance, double time) {
            double speed = average_speed(distance, time);
            cout << "Average speed: " << speed << " miles per hour" << endl;
        }

    private:
        double distance_traveled;
        double time_taken;
        double avg_speed;

};

int main() {

    BicycleSpeedometer speedometer;

    double distance, time;

    cout << "Enter the distance traveled in miles: ";
    cin >> distance;

    cout << "Enter the time taken in minutes: ";
    cin >> time;

    speedometer.set_distance_traveled(distance);
    speedometer.set_time_taken(time);

    speedometer.display(distance, time);
    return 0;
};
