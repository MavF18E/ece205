#include <iostream>

using namespace std;

int main() {

    cout << "How many hours have you worked this week?" << endl;
    double hours_worked;
    cin >> hours_worked;

    cout << "How many dependents do you have?" << endl;
    int dependents;
    cin >> dependents;

    double gross_pay;
    double net_pay;
    double ss;
    double federal_tax;
    double state_tax;
    double beth_local;
    int union_dues;
    int health_insurance;

    if (hours_worked <= 40) {
        gross_pay = hours_worked * 36.75;
    }
    else {
        gross_pay = (40 * 36.75) + ((hours_worked - 40) * 36.75 * 1.5);
    }

    if (dependents >= 2) {
        ss = gross_pay * 0.06;
        federal_tax = gross_pay * 0.15;
        state_tax = gross_pay * 0.04;
        beth_local = gross_pay * 0.01;
        union_dues = 20;
        health_insurance = 40;
        net_pay = gross_pay - (ss + federal_tax + state_tax + beth_local + union_dues + health_insurance);
    }
    else{
        ss = gross_pay * 0.06;
        federal_tax = gross_pay * 0.15;
        state_tax = gross_pay * 0.04;
        beth_local = gross_pay * 0.01;
        union_dues = 20;
        health_insurance = 0;
        net_pay = gross_pay - (ss + federal_tax + state_tax + beth_local + union_dues + health_insurance);
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Gross Pay: $" << gross_pay << endl;
    cout << "Social Security Deduction: $" << ss << endl;
    cout << "Federal Tax Income Deduction: $" << federal_tax << endl;
    cout << "State Tax Deduction: $" << state_tax << endl;
    cout << "Bethlehem Local Tax Deduction: $" << beth_local << endl;
    cout << "Union Dues Deduction: $" << union_dues << endl;
    cout << "Health Insurance Deduction: $" << health_insurance << endl;
    cout << "Net Pay: $" << net_pay << endl;

    return 0;
}