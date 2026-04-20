#include <iostream>
#include <vector>

using namespace std;

int findMax(vector<int> myVector);
void sort(int a[], int numberUsed);
void swapValues(int& v1, int& v2);
int indexOfSmallest(const int a[], int startIndex, int numberUsed);
void fillBins(int nums[], int size, vector<vector<int>>& histogram);
void returnBins(const vector<vector<int>>& histogram);

int main() {
    vector<int> myVector;
    int number;

    cout << "Please enter a non-negative integer: " << endl;
    cin >> number;

    while (number >= 0) {
        myVector.push_back(number);
        cout << "Please enter a non-negative integer: " << endl;
        cin >> number;
    }

    int max = findMax(myVector);

    vector<vector<int>> histogram(max / 10 + 1, vector<int>(myVector.size(), -1));

    sort(myVector.data(), myVector.size());
    
    fillBins(myVector.data(), myVector.size(), histogram);

    returnBins(histogram);

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

int findMax(vector<int> myVector) {
    int max = myVector[0];
    for (int i = 1; i < myVector.size(); i++) {
        if (myVector[i] > max) {
            max = myVector[i];
        }
    }
    return max;
}

void fillBins(int nums[], int size, vector<vector<int>>& histogram) {
    int numOfBins = histogram.size();

    while (numOfBins > 0) {
        for (int i = 0; i < size; i++) {
            if (nums[i] / 10 == numOfBins - 1) {
                histogram[numOfBins - 1].push_back(nums[i]);
            }
        }
        numOfBins--;
    }
}

void returnBins(const vector<vector<int>>& histogram) {
    for (int i = 0; i < histogram.size(); i++) {
        cout << "Bin " << i + 1 << ": ";
        for (int j = 0; j < histogram[i].size(); j++) {
            if (histogram[i][j] != -1) {
                cout << histogram[i][j] << " ";
            }
        }
        cout << endl;
    }
}