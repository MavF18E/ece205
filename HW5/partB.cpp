#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Pizza {
    public:

    // Constants for type
    static const int DEEP_DISH = 1;
    static const int HAND_TOSSED = 2;
    static const int PAN = 3;
    static const int SMALL = 1;
    static const int MEDIUM = 2;
    static const int LARGE = 3;

    Pizza() {
        type = DEEP_DISH;
        size = SMALL;
        toppings = 0;
    }

    Pizza(int type1, int size1, int toppings1) {
        type = type1;
        size = size1;
        toppings = toppings1;
    }
    
    void get_input();
    double compute_price();
    void output_description();

    private:

    int type;
    int size;
    int toppings;

};

void Pizza::get_input() {
    cout << "Enter type of pizza (deep dish = 1, hand tossed = 2, pan = 3): ";
    cin >> type;

    cout << "Enter size of pizza (small = 1, medium = 2, large = 3): ";
    cin >> size;

    cout << "Enter number of toppings: ";
    cin >> toppings;
}

double Pizza::compute_price() {
    double basePrice = 0;
    if ((size == SMALL)) {
        basePrice = 10;
    }
    else if ((size == MEDIUM)) {
        basePrice = 12;
    }
    else if ((size == LARGE)) {
        basePrice = 14;
    }

    return basePrice + toppings * 2;
}

void Pizza::output_description() {
    if (type == DEEP_DISH) {
        cout << "Pizza type is deep dish" << endl;
    } else if (type == HAND_TOSSED) {
        cout << "Pizza type is hand tossed" << endl;
    } else if (type == PAN) {
        cout << "Pizza type is pan" << endl;
    }
    if (size == SMALL) {
        cout << "Pizza size is small" << endl;
    } else if (size == MEDIUM) {
        cout << "Pizza size is medium" << endl;
    } else if (size == LARGE) {
        cout << "Pizza size is large" << endl;
    }
    cout << "Number of toppings: " << toppings << endl;
}

// ----------- main function --------------

int main() {
    Pizza p1 (1,2,2);
    Pizza p2 (2,3,3);
    Pizza p3 (3,1,1);

    cout << "Sample Pizza Variations: " << endl;

    p1.output_description();
    cout << "Price of pizza is: $" << p1.compute_price() << endl;
    cout << endl;
    p2.output_description();
    cout << "Price of pizza is: $" << p2.compute_price() << endl;
    cout << endl;
    p3.output_description();
    cout << "Price of pizza is: $" << p3.compute_price() << endl;
    cout << endl;



    do {
        cout << "Do you want to order a pizza? (y/n): ";
        char answer;
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            p1.get_input();
            cout <<"-----Pizza-----" << endl;
            p1.output_description();
            cout << "Price of pizza is: $" << p1.compute_price() << endl;
            cout << endl;
        } else if (answer == 'n' || answer == 'N') {
            break;
        } else {
            cout << "Invalid input. Please enter y or n." << endl;
        }
    } while (true);


    return 0;
}