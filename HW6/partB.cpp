#include <iostream>
#include <vector>

using namespace std;

vector<char> deleteRepeatedChars(vector<char> myVector);
vector<char> selectionSort(vector<char> myVector);


int main() {
    vector<char> myVector;
    char input;

    cout << "Please enter a char, enter 0 to quit: " << endl;
    cin >> input;

    while (input != '0') {
        myVector.push_back(input);
        cout << "Please enter a char, enter 0 to quit: " << endl;
        cin >> input;
    }

    myVector = deleteRepeatedChars(myVector);
    cout << "Test\n";
    myVector = selectionSort(myVector);
    cout << "Array with repeated char's removed and inversed:\n";
    for (int i = 0; i < myVector.size(); i++) {
        cout << myVector[i] << endl;
    }
    return 0;
}

vector<char> deleteRepeatedChars(vector<char> myVector) {
    for (int i = 0; i < myVector.size(); i++) {
        for (int j = i + 1; j < myVector.size(); j++) {
            if (myVector[i] == myVector[j]) {
                for (int k = j; k < myVector.size() - 1; k++) {
                    myVector[k] = myVector[k + 1];
                }
                myVector.resize(myVector.size() - 1);
                j--;
            }
        }
    }
    return myVector;
}

vector<char> selectionSort(vector<char> myVector) {
    int indexOfNextSmallest;
    for (int i = 0; i < myVector.size() - 1; i++) {
        indexOfNextSmallest = i;
        for (int j = i + 1; j < myVector.size(); j++) {
            if (myVector[j] > myVector[indexOfNextSmallest]) {
                indexOfNextSmallest = j;
            }
        }
        char temp = myVector[i];
        myVector[i] = myVector[indexOfNextSmallest];
        myVector[indexOfNextSmallest] = temp;
    }
    return myVector;
}