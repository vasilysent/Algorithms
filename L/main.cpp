#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int array[n];
    for (int i = 0; i < n; ++i)
        cin >> array[i];
    if (n == 1) {
        cout << array[0];
        return 0;
    }
    if (k == 1) {
        for (int i = 0; i < n; ++i)
            cout << array[i] << ' ';
        return 0;
    }
    int block_left_min[n];
    int block_right_min[n];
    k--;
    block_left_min[0] = array[0];
    block_right_min[n-1] = array[n-1];
    int j = n - 2;
    for (int i = 1; i < n; ++i) {
        if (i % k == 0) block_left_min[i] = array[i];
        else block_left_min[i] = min(block_left_min[i - 1], array[i]);

        if ((j+1) % k == 0) block_right_min[j] = array[j];
        else block_right_min[j] = min(block_right_min[j+1], array[j]);
        j--;
    }
    k++;
    int r;
    for (int l = 0; l < n - k + 1; ++l) {
        r = l + k - 1;
        cout << min(block_right_min[l], block_left_min[r]) << ' ';
    }
    return 0;
}
