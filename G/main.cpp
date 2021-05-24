#include <iostream>
#include <algorithm>
using namespace std;

unsigned int weights[26]; // a to z

bool letter_weight_comp (char letter1, char letter2) {
    return weights[letter1 - 'a'] > weights[letter2 - 'a'];
}

int main() {
    string line;
    cin >> line;
    string weighted_letters;
    string single_letters;
    for (int i = 0; i < 26; ++i) {
        cin >> weights[i];
        int letter_occurrences = count(line.begin(), line.end(), 'a' + i);
        if (letter_occurrences == 1) single_letters.push_back('a' + i);
        else if (letter_occurrences >= 2) {
            weighted_letters.push_back('a' + i);
            for (int j = 0; j < letter_occurrences - 2; ++j) {
                single_letters.push_back('a' + i);
            }
        }
    }
    sort(weighted_letters.begin(), weighted_letters.end(), letter_weight_comp);

    cout << weighted_letters << single_letters;
    reverse(weighted_letters.begin(), weighted_letters.end());
    cout << weighted_letters;

    return 0;
}

