#include<iostream>
using namespace std;

int main() {
    int arr[20], size;
    int left = 0, right, middle;

    cout << "Enter the number of elements: ";
    cin >> size;

    cout << "Enter sorted array elements (only 0s and 1s):\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    right = size - 1;
    int zeroCount = 0;

    while (left <= right) {
        middle = (left + right) / 2;

        if (arr[middle] == 1) {
            // All 0s are on the left side
            right = middle - 1;
        } else {
            // arr[middle] == 0
            // Check if it's the last 0 or next is 1
            if (middle == size - 1 || arr[middle + 1] == 1) {
                zeroCount = middle + 1;
                break;
            } else {
                left = middle + 1;
            }
        }
    }

    cout << "\nNumber of 0s in the array: " << zeroCount << endl;

    return 0;
}