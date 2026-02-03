#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    double loan_amount = 1000;
    double interest_rate = 0.015;
    double total_interest = 0;
    double principal_paid = 0;
    double current_interest = 0;
    double total_paid = 0;

    int months = 0;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Month #" << right << setw(14) << "Interest" << right << setw(14) << "Principal" << right << setw(14) << "Balance" << right << setw(20) << "Total Interest" << right << setw(14) << "Total Paid" << endl;
    while (loan_amount > 0) {
        current_interest = loan_amount * interest_rate;
        total_interest += current_interest;
        principal_paid = 50 - current_interest;

        if (principal_paid > loan_amount){
            total_paid += loan_amount + current_interest;
            loan_amount -= loan_amount;
            months++;
        } else {
            total_paid += principal_paid + current_interest;
            loan_amount = loan_amount - principal_paid;
            months++;
        }

        // cout << months << "\t" << current_interest << "\t" << principal_paid << "\t" << loan_amount << "\t" << total_interest << "\t" << total_paid << endl;
        cout << right << setw(7) << months << right << setw(14) << current_interest << right << setw(14) << principal_paid << right << setw(14) << loan_amount << right << setw(20) << total_interest << right << setw(14) << total_paid << endl;
    }
    return 0;
}