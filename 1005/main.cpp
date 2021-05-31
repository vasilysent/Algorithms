#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n; // number of stones (max 20)
    int stones[20]; // stone weights
    cin >> n;
    int sum = 0; // overall sum of weights
    for (int i = 0; i < n; ++i) {
        cin >> stones[i];
        sum += stones[i];
    }

    int heap_sum; // sum of weights in one heap
    int min_difference = INT_MAX;
    for (unsigned long i = 0; i < (1 << (n - 1)); ++i) { // 2^n / 2 - number of all combinations as a binary number
        heap_sum = 0;
        for (unsigned long j = 0; j < n; ++j) { // for in bit masks, checking if each stone is in the heap
            if (i & (1 << j)) heap_sum += stones[j]; // if one is there, count its weight
        }
        min_difference = min(abs(sum - 2 * heap_sum), min_difference);
    }
    cout << min_difference;
    return 0;
}
