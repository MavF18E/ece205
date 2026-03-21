#include <iostream>
#include <cmath>

using namespace std;

void sort(int a[], int numberUsed);

void swapValues(int& v1, int& v2);

int indexOfSmallest(const int a[], int startIndex, int numberUsed);

void fillArray(int a[], int size, double temp);

void returnBins(int nums[], int size);

int main() {
    int size;
    cout << "Input the size of your array: ";
    cin >> size;

    int nums[size];
    double temp;
    fillArray(nums, size, temp);

    sort(nums, size);

    returnBins(nums, size);

    return 0;
}

void sort(int a[], int numberUsed) {
    int indexOfNextSmallest;
    for (int i = 0; i < numberUsed - 1; i++) {
        indexOfNextSmallest = indexOfSmallest(a, i, numberUsed);
        swapValues(a[i], a[indexOfNextSmallest]);
    }
}

void swapValues(int& v1, int& v2) {
    int temp = v1;
    v1 = v2;
    v2 = temp;
}

int indexOfSmallest(const int a[], int startIndex, int numberUsed) {
    int min = a[startIndex], indexOfMin = startIndex;
    for (int i = startIndex + 1; i < numberUsed; i++) {
        if (a[i] < min) {
            min = a[i];
            indexOfMin = i;
        }
    }
    return indexOfMin;
}

void fillArray(int nums[], int size, double temp) {
    for (int i = 0; i < size; i++) {
        cout << "Input integer " << i + 1 << ": ";
        cin >> temp;

        if (temp < 0) {
            cout << "Negative numbers are not allowed. Please enter a non-negative integer: \n";
            i--;
        }
        else if (temp != floor(temp)) {
            cout << "Non-integer values are not allowed. Please enter an integer: \n";
            i--;
        } 
        else {
            int rand = static_cast<int>(temp);
            nums[i] = rand;
        }

    }
}

void returnBins(int nums[], int size) {
    int numOfBins = nums[size - 1] / 10 + 1;

    for (int i = 0; i < numOfBins; i++) {
        cout << "Bin " << i+1 << ": ";
        for (int j = 0; j < size; j++) {
            if (nums[j] >= i * 10 && nums[j] < (i + 1) * 10) {
                cout << nums[j] << " ";
            }
        }
        cout << endl;
    }
}