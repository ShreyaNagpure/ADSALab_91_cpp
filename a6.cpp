#include <iostream>
#include <algorithm>
using namespace std;

// Function to check if we can finish all tasks with given work per day
bool canFinish(int task[], int n, int d, int work) {
    int days = 0;
    for (int i = 0; i < n; i++) {
        // Number of days required for this task
        days += (task[i] + work - 1) / work;
        if (days > d) return false;
    }
    return true;
}

int minWorkPerDay(int task[], int n, int d) {
    int low = 1, high = *max_element(task, task + n);
    int ans = high;

    // Binary search for minimum possible work per day
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canFinish(task, n, d, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, d;
    cout << "Enter number of tasks: ";
    cin >> n;

    int task[100];
    cout << "Enter work units for each task: ";
    for (int i = 0; i < n; i++)
        cin >> task[i];

    cout << "Enter number of days: ";
    cin >> d;

    cout << "Minimum work per day = " << minWorkPerDay(task, n, d) << endl;
    return 0;
}
