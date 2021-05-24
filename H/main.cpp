#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int products_num;
    int each_free;
    cin >> products_num >> each_free;
    vector<int> prices;
    int price;
    while (cin >> price) prices.push_back(price);
    sort(prices.rbegin(), prices.rend());
    int sum = 0;
    for (int i = 0; i < products_num; ++i) {
        if ((i+1) % each_free != 0) sum += prices[i];
    }
    cout << sum;

    return 0;
}
