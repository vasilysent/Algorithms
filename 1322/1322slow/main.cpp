#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int string_number;
    string last_column;
    string first_column;
    cin >> string_number >> first_column;
    // const int symbols_number = 'z' - 'A' + 1;
    // int letter_occurrences[symbols_number] = {0};
    /*int letter_occurrences[58] = {0};
    for (int i = 0; i < last_column.length(); ++i) {
        letter_occurrences[last_column[i] - 'A']++;
    }*/
    last_column = first_column;
    sort(first_column.begin(), first_column.end());
    string s = last_column;
    //int next[last_column.length()];
    int next[100000];
    for (int i = 0; i < first_column.length(); ++i) {
        size_t pos = s.find(first_column[i]);
        next[i] = pos;
        s[pos] = '[';
    }
    string_number--;
    for (int i = 0; i < last_column.length(); i++) {
        cout << last_column[next[string_number]];
        string_number = next[string_number];
    }
    return 0;
}
