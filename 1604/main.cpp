#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    struct sign{
        int frequency;
        int index;
    };
    vector<struct sign> signs;
    int types_number;
    cin >> types_number;
    signs.reserve(types_number);
    int signs_number = 0;
    int freq;
    for (int i = 1; i <= types_number; ++i) {
        cin >> freq;
        signs.push_back({freq, i});
        signs_number += freq;
    }

    int min_idx = 0;
    int max_idx = 0;
    int min_freq = INT_MAX;
    int max_freq = 0;
    for (int i = 0; i < types_number; ++i) {
        if (signs[i].frequency > 0) {
            if (signs[i].frequency < min_freq) {
                min_idx = signs[i].index;
                min_freq = signs[i].frequency;
            }
            if (signs[i].frequency >= max_freq) {
                max_idx = signs[i].index;
                max_freq = signs[i].frequency;
            }
        }
    }

    while (signs_number > 1) {
        signs[min_idx - 1].frequency--;
        signs[max_idx - 1].frequency--;
        signs_number -= 2;
        cout << max_idx << ' ' << min_idx << ' ';

        min_freq = INT_MAX;
        max_freq = 0;
        for (int i = 0; i < types_number; ++i) {
            if (signs[i].frequency > 0) {
                if (signs[i].frequency < min_freq) {
                    min_idx = signs[i].index;
                    min_freq = signs[i].frequency;
                }
                if (signs[i].frequency >= max_freq) {
                    max_idx = signs[i].index;
                    max_freq = signs[i].frequency;
                }
            }
        }
    }
    if (signs_number == 1) cout << max_idx;

    return 0;
}
