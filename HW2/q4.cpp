#include <iostream>
#include <cmath>

using namespace std;

void getRandomFinalist();

int main() {
    srand(time(0));
    getRandomFinalist();
    return 0;
}

void getRandomFinalist() {
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    int n4 = 0;

    cout << n1 << endl;
    
    n1 = (rand() % 25) + 1;
    cout << n1 << endl;
    n2 = (rand() % 25) + 1;
    while (n1 == n2){
        n2 = rand() % 25 + 1;
    }
    n3 = rand() % 25 + 1;
    while (n3 == n1 || n2 == n3){
        n3 = rand() % 25 + 1;
    }
    n4 = rand() % 25 + 1;
    while (n1 == n4 || n2 == n4 || n3 == n4){
        n4 = rand() % 25 + 1;
    }

    cout << "And the finalist winners are numbers: " << n1 << ", " << n2 << ", " << n3 << ", " << n4; 

}

