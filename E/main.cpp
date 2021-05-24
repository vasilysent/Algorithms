#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool can_distribute(int min_distance, vector<int> *stalls, int cows_number) {
    cows_number--; // first cow in the firth stall
    int prev_cow_at = (*stalls)[0];
    for (int i : *stalls) {
        if (i - prev_cow_at >= min_distance) { cows_number--; prev_cow_at = i; }
        if (cows_number == 0) return true;
    }
    return false;
}

int main() {
    int stalls_number;
    cin >> stalls_number;
    int cows_number;
    cin >> cows_number;
    vector<int> stalls;
    for (int i = 0; i < stalls_number; i++) {
        stalls.push_back(0);
        cin >> stalls[i];
    }

    int bin_left = 0;
    int bin_right = stalls[stalls_number - 1] - stalls[0] + 1;

    while (bin_left < bin_right - 1) {
        int mid = (bin_left + bin_right) / 2;
        if ( can_distribute(mid , &stalls, cows_number) )
            bin_left = mid;
        else bin_right = mid;
    }

    cout << bin_left;

    return 0;
}
