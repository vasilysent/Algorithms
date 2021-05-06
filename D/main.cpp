#include <iostream>
using namespace std;

int main() {
    int initial_number;     // a
    int multiplier;         // b
    int for_experiments;    // c
    int container_capacity; // d
    int days;               // k
    cin >> initial_number >> multiplier >> for_experiments >> container_capacity >> days;
    int current_number = initial_number;
    int previous_day_number;

    for (int i = 0; i < days; i++) {
        previous_day_number = current_number;
        current_number = min(max(current_number * multiplier - for_experiments, 0), container_capacity);
        if (current_number == 0 || current_number == previous_day_number) break;
    }
    cout << current_number << endl;

    return 0;
}
