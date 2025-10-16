#include <iostream>
using namespace std;

int calculateProfit(int price[], int days) {
    int totalProfit = 0;

    for (int i = 1; i < days; i++) {
        if (price[i] > price[i - 1]) {
            totalProfit += price[i] - price[i - 1];
        }
    }

    return totalProfit;
}

int main() {
    int days;
    cout << "Enter number of days: ";
    cin >> days;

    int price[100];
    cout << "Enter stock prices: ";
    for (int i = 0; i < days; i++) {
        cin >> price[i];
    }

    int result = calculateProfit(price, days);
    cout << "Maximum Profit = " << result << endl;

    return 0;
}
