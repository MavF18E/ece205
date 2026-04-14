#include <iostream>

using namespace std;

class PrimeNumber {
    private:
        int prime;

        bool isPrime(int n) {
            if (n <= 1) return false;
            for (int i = 2; i <= n / 2; i++) {
                if (n % i == 0) {
                    return false;
                }
            }
            return true;
        }

        int nextPrime(int n) {
            n++;
            while (!isPrime(n)) {
                n++;
            }
            return n;
        }

        int previousPrime(int n) {
            --n;
            while (!isPrime(n)) {
                n--;
            }
            return n;
        }

    public:
        PrimeNumber() {
            prime = 1;
        }

        PrimeNumber(int p) {
            prime = p;
        }

        int getPrime() const {
            return prime;
        }

        PrimeNumber operator++(int) {
            PrimeNumber temp;
            prime = nextPrime(prime);
            return temp;
        }

        PrimeNumber operator--(int) {
            PrimeNumber temp;
            prime = previousPrime(prime);
            return temp;
        }
};

int main() {
    PrimeNumber p1;
    PrimeNumber p2(13);

    cout << "Default prime number: " << p1.getPrime() << endl;
    cout << "Initial p2: " << p2.getPrime() << endl;

    p2++;
    cout << "After postfix p2++: " << p2.getPrime() << endl;

    p2 = PrimeNumber(13); // Reset p2 to 13 for testing previous prime
    p2--;
    cout << "After postfix p2--: " << p2.getPrime() << endl;
    return 0;
}