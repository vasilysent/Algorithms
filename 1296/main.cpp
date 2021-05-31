#include <iostream>
using namespace std;

// Kadane’s Algorithm
int main() {
    int n;
    cin >> n;
    int current_max = 0;
    int current_sum = 0;
    int num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        current_sum += num;
        if (current_max < current_sum) current_max = current_sum;
        if (current_sum < 0) current_sum = 0;
    }
    if (current_max < 0) current_max = 0;
    cout << current_max;

    return 0;
}
