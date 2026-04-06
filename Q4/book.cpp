#include <iostream>
#include <vector>

using namespace std;

/**
 * Define a class called Book which is an abstract data type for searching a book from a history bookstore. 
 * You will search the book by category, publishing year, and ISBN. The book category should be a string, 
 * publishing year and ISBN should be an integer type. The book will only be available in the store if the 
 * book was published after the year 1950 and the category is “history” for any ISBN value. Display the output if the book is available or not. 
 * You will take the input from the console. 

    Include all the following specifications: 

    1)	Make all member variables private.
    2)	a constructor to set the book selecting parameters as an argument.  
    3)	A non-member output (display) function that outputs the availability. 
    4)	Other member/non-member functions if you need them. 

 */

class Book {
    private:
        string category;
        int publishing_year;
        int ISBN;

    public:
        Book(string c, int p, int i) {
            category = c;
            publishing_year = p;
            ISBN = i;
        }

        bool isAvailable() {
            if (category == "history" && publishing_year > 1950) {
                return true;
            }
            return false;
        }
};

void printAvailable(bool available) {
    if (available) {
        cout << "The book is available in the store." << endl;
    } else {
        cout << "The book is not available in the store." << endl;
    }
}

int main() {
    string category;
    int publishing_year;
    int ISBN;

    cout << "Enter book category: ";
    cin >> category;
    cout << "Enter publishing year: ";
    cin >> publishing_year;
    cout << "Enter ISBN: ";
    cin >> ISBN;

    Book book(category, publishing_year, ISBN);

    printAvailable(book.isAvailable());

    return 0;
}
