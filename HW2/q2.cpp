#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

void createOutputFile();

int main() {
    createOutputFile();
    return 0;
}

void createOutputFile() {
    ifstream in;
    ofstream out;

    int n1, n2, n3, n4, n5;

    in.open("C:/Users/Aden/ECE205/ece205/HW2/scores.txt");

    in >> n1;
    in >> n2;
    in >> n3;
    in >> n4;
    in >> n5;

    double avg = (n1 + n2 + n3 + n4 + n5) / 5;

    double diff_n1 = avg - n1;
    double diff_n2 = avg - n2;
    double diff_n3 = avg - n3;
    double diff_n4 = avg - n4;
    double diff_n5 = avg - n5;

    double std_dev= sqrt((pow(diff_n1, 2) + pow(diff_n2, 2) + pow(diff_n3, 2) + pow(diff_n4, 2) + pow(diff_n5, 2)) / 5);

    out.open("C:/Users/Aden/ECE205/ece205/HW2/output.txt");

    out.setf(ios::fixed);
    out.setf(ios::showpoint);
    out.precision(2);

    out << "Average of test scores: " << avg << endl;
    out << "Standard deviation of test scores: " << std_dev << endl;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Average of test scores: " << avg << endl;
    cout << "Standard deviation of test scores: " << std_dev << endl;
    
    in.close();
    out.close();
}