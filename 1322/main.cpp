#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int string_number;
    string last_column;
    cin >> string_number >> last_column;
    
    const int symbols_number = 'z' - 'A' + 1;
    // int letter_count[symbols_number] = {0};
    int letter_count[58] = {0};
    for (int i = 0; i < last_column.length(); ++i) {
        letter_count[last_column[i] - 'A']++;
    }
    int sum = 0;
    // int letter_first_pos[symbols_number] = {0};
    int letter_first_pos[58] = {0};
    for (int i = 0; i < symbols_number; ++i) {
        sum += letter_count[i];
        letter_first_pos[i] = sum - letter_count[i];
    }

    //int next[last_column.length()];
    int next[100000];

    for (int i = 0; i < last_column.length(); ++i) {
        next[letter_first_pos[last_column[i] - 'A']] = i;
        letter_first_pos[last_column[i] - 'A']++;
    }
    string_number--;
    for (int i = 0; i < last_column.length(); i++) {
        cout << last_column[next[string_number]];
        string_number = next[string_number];
    }
    return 0;
}
