#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void SieveOfEratosthenes(int n);

int main() {
    int n;
    cout << "Enter a number to see the primes lower than it: ";
    cin >> n;
    cout << endl;
    SieveOfEratosthenes(n);
    return 0;
}

void SieveOfEratosthenes(int n) {
    vector<bool> primes(n, 1);
    primes[0] = primes[1] = false;
    for (int i = 2; i < sqrt(n); i++) {
        if (primes[i]) {
            for (int j = i * i; j < n; j += i) {
                primes[j] = false;
            }
        }
    }
    cout << "The prime numbers lower than " << n << " are: " << endl;
    for (int i = 2; i < n; i++) {
        if (primes[i]) {
            cout << i << endl;
        }
    }
}