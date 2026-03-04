#include <iostream>
#include <cmath>

using namespace std;

/**
 * 2. (25 pts) The area of an arbitrary triangle can be computed using the formula below, 
 * where a, b, and c are the lengths of the sides and s is the semi-perimeter (half of the 
 * sum of all sides). Write a void function that uses 5 parameters: 3 pass-by-value parameters 
 * that provide the lengths of the edges and 2 pass-by-reference parameters that compute the area 
 * and perimeter (not semi-perimeter). Make your function robust, noting that not all values for combinations 
 * of 3 sides will produce a triangle. Your function should produce correct results for legal data 
 * and zeros for illegal combinations. You can use the sqrt function from the cmath library as needed.
 */

void compute_triangle (double a, double b, double c, double& area, double& perimeter);

int main() {
    double a, b, c, area, perimeter;
    cout << "Enter the lengths of the three sides of the triangle: " << endl;
    cout << "Side a: ";
    cin >> a ;
    cout << "\nSide b: ";
    cin >> b ;
    cout << "\nSide c: ";
    cin >> c;
    compute_triangle(a, b, c, area, perimeter);
    return 0;
}

void compute_triangle (double a, double b, double c, double& area, double& perimeter) {
    if (a + b > c && a + c > b && b + c > a) {
        perimeter = a + b + c;
        double s = perimeter / 2;
        area = sqrt(s * (s - a) * (s - b) * (s - c));
        cout << "The area of the triangle is: " << area << endl;
        cout << "The perimeter of the triangle is: " << perimeter << endl;
    }
    else {
        cout << "Illegal combination." << endl;
        cout << "Area: " << 0 << endl;
        cout << "Perimeter: " << 0 << endl;
    }
}