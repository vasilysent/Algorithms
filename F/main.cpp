#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool num_comp (string a, string b) {
    return a + b > b + a;
}

int main() {
    vector<string> numbers;
    string line;
    while (cin >> line) numbers.push_back(line);
    sort(numbers.begin(), numbers.end(), num_comp);
    for (string i : numbers)
        cout << i;
    return 0;
}
