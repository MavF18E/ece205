#include <iostream>
#include <vector>
using namespace std;

class Pizza {
    private:
        int type;       // 1 = deep dish, 2 = hand tossed, 3 = pan
        int size;       // 1 = small, 2 = medium, 3 = large
        int toppings;   // number of toppings

    public:
        // Constants for type
        static const int DEEP_DISH = 1;
        static const int HAND_TOSSED = 2;
        static const int PAN = 3;

        // Constants for size
        static const int SMALL = 1;
        static const int MEDIUM = 2;
        static const int LARGE = 3;

        // Default constructor
        Pizza() {
            type = HAND_TOSSED;
            size = SMALL;
            toppings = 0;
        }

        // Parameterized constructor
        Pizza(int t, int s, int top)
        {
            type = t; size = s; toppings = top;

        }

        // Mutators (setters)
        void setType(int t)
        {
            type = t;
        }

        void setSize(int s)
        {
            size = s;
        }

        void setToppings(int t)
        {
            toppings = t;
        }

        // Accessors (getters)
        int getType()
        {
            return type;
        }

        int getSize()
        {
            return size;
        }

        int getToppings()
        {
            return toppings;
        }
        double computePrice() const;
        void outputDescription() const;

};



class order {
    vector <Pizza> Pizzas;
    public:
        void add_pizza(const Pizza& p)
        {
            Pizzas.push_back(p);
        }
        void add_pizza(int type, int size, int toppings)
        {
            Pizza p(type, size, toppings);
            Pizzas.push_back(p);
        }

        void outputOrder() const
        {
            double totalPrice = 0.0;
            if (Pizzas.empty()){
                cout << "No pizzas in the order." << endl;
                return;
            }
            for (size_t i = 0; i < Pizzas.size(); i++)
            {
                cout << "Pizza #" << i + 1 << ": ";
                Pizzas[i].outputDescription();
                cout << "Price: $" << Pizzas[i].computePrice() << endl << endl;
                totalPrice += Pizzas[i].computePrice();
            }
            cout << "Total Order Price: $" << totalPrice << endl;
            cout << "--------------------------" << endl;
        }
};

double Pizza::computePrice() const {
    double basePrice = 0.0;
    if (size == SMALL)
        basePrice = 10.0;
    else if (size == MEDIUM)
        basePrice = 12.0;
    else if (size == LARGE)
        basePrice = 14.0;

    return basePrice + toppings * 2.0;
}

void Pizza::outputDescription() const {
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

int main() {
    // Create pizza objects
    Pizza pizza1(1, 1, 1);
    Pizza pizza2(2, 2, 2);
    

    // Output details for pizza1
    cout << "---- Pizza 1 ----\n";
    pizza1.outputDescription();
    cout << "Price: $" << pizza1.computePrice() << endl;

    cout << endl;

    // Output details for pizza2
    cout << "---- Pizza 2 ----\n";
    pizza2.outputDescription();
    cout << "Price: $" << pizza2.computePrice() << endl;

    cout << endl;
    order order1;
    order1.add_pizza(pizza1);
    order1.add_pizza(pizza2);

    order order2;
    order2.add_pizza(pizza1);
    order2.add_pizza(pizza2);
    order2.add_pizza(pizza1);

    cout << "---- Order 1 ----\n";
    order1.outputOrder();

    cout << "---- Order 2 ----\n";
    order2.outputOrder();

    return 0;
}