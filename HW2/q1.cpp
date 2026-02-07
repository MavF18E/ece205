#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

/** Write a program that calculates the gravitational attractive force between two bodies with
masses 𝑚1 and 𝑚2 separated by a distance 𝑑 as follows:
𝐹 =
𝐺∗𝑚1∗𝑚2
𝑑2
,
where 𝐺 = 6.673 × 10−8
cm3
/(g*sec2
). Use the built-in pow(x,y) function from the cmath library to obtain
the square of the distance. Masses will be given in units of kg (1 kg = 1000g). The use of the formula
above will produce a result measured in dynes, where 1 dyne = 1 cm3
/(g*sec2
). Define the gravitational
constant above as a constant. Design the program such that a user can repeat the code as many times as
they want (this will make it necessary to get some user input to repeat or not). */

double gravitational_calc(double m1, double m2, double d, double G);

int main() {
    double mass1, mass2, distance;
    const double G=6.67E-8;
    double force;

    cout.setf(ios::scientific);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Enter the mass of body 1 (in kg):" << endl;
    cin >> mass1;

    cout << "Enter the mass of body 2 (in kg):" << endl;
    cin >> mass2;

    cout << "Enter the distance between the two bodies: " << endl;
    cin >> distance;

    cout << "The gravitational attractive force between the two bodies is: " << gravitational_calc(mass1, mass2, distance, G) << " dynes" << endl;

}

double gravitational_calc(double m1, double m2, double d, double G) {
    double modified_m1 = m1 * 1000;
    double modified_m2 = m2 * 1000;
    double F = (modified_m1 * modified_m2 * G) / pow(d, 2);
    return F;
}