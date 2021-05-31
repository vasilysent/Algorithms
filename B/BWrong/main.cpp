#include <iostream>
#include <string>
using namespace std;

const int uppercase_begin = 65; // 'A'
const int uppercase_end = 90;   // 'Z'
const int lowercase_begin = 97; // 'a'
const int lowercase_end = 122;  // 'z'
const int letter_case_shift = lowercase_begin - uppercase_begin; // e.g. difference between 'g' and 'G'

// if it's an animal
bool is_lower_case(char letter) {
    if (letter >= lowercase_begin && letter <= lowercase_end) { return true; }
    else return false;
}
// if it's a trap
bool is_upper_case(char letter) {
    if (letter >= uppercase_begin && letter <= uppercase_end) { return true; }
    else return false;
}

// returns lowercase letter (type of animal)
char type(char letter){
    if (is_lower_case(letter)) return letter;
    if (is_upper_case(letter)) return letter + letter_case_shift;
    return ' ';
}
// returns lowercase letter (type of animal) and +1 to difference variable if it's an animal and -1 if it's a trap
char type_and_count(char letter, int* difference){
    if (is_lower_case(letter)) {
        (*difference)++;
        return letter;
    }
    if (is_upper_case(letter)) {
        (*difference)--;
        return letter + letter_case_shift;
    }
    return ' ';
}

int main() {

    string zoo;
    cin>>zoo; // string input

    int n = zoo.length() / 2; // number of animals (or traps)

    int animal_traps_difference = 0; // difference between number of animals and traps in a streak
    char current_type;               // animal type in a current streak

    int first_skipped_animals = 0;   // number of animals in the first streak

    current_type = type_and_count(zoo[0], &animal_traps_difference); // current type is the first
    if (is_lower_case(zoo[0])) first_skipped_animals = 1;            // +1 to animal count if it is

    int i = 1; // main counter variable (now pointing at second object)

    // to set pointer at the second streak (because the first can make a loop)
    while (i < 2 * n && type(zoo[i]) == current_type) {
        current_type = type_and_count(zoo[i], &animal_traps_difference); // counting difference
        if (is_lower_case(zoo[i])) first_skipped_animals++;              // +1 to animal count if it is
        i++;
    }

    // if all objects belong to one kind (we reached the end with the first streak)
    if (i == 2 * n){
        // if we can distribute all animals
        if (animal_traps_difference == 0) {
            cout << "Possible" << endl;
            for (int j = 0; j < n; j++) cout << j + 1 << " " << flush;
            return 0;
        }
        // if we cannot distribute all animals
        else {
            cout << "Impossible" << endl;
            return 0; // finish the program
        }
    }
    int first_skipped_difference = animal_traps_difference; // difference in the first streak
    animal_traps_difference = 0;  // set difference to zero for the next streak

    // other streaks
    while(i < 2 * n) {
        current_type = type_and_count(zoo[i], &animal_traps_difference);     // first object in a streak defines its type
        i++;
        while (i < 2 * n && type(zoo[i]) == current_type) {                  // while objects are same type
            current_type = type_and_count(zoo[i], &animal_traps_difference); // count difference
            i++;                                                             // go next
        }
        // if we haven't reached the end or reached it, but last type isn't same with the first
        if (i < 2 * n || ( i == 2 * n && current_type != type(zoo[0]))) {
            if (animal_traps_difference != 0) { // and if we cannot distribute animals in the streak
                cout << "Impossible" << endl;
                return 0; // finish the program
            }
            animal_traps_difference = 0; // set difference to zero for the next streak
        }
    }
    // now we have reached the end

    // if last streak type is same with the first (loop)
    if (current_type == type(zoo[0])) {
        animal_traps_difference += first_skipped_difference; // sum differences of two parts
        if (animal_traps_difference != 0) { // if we cannot distribute animals in the streak
            cout << "Impossible" << endl;
            return 0; // finish the program
        }
    }

    // Then we can distribute animals
    cout << "Possible" << endl;
    if (first_skipped_difference <= 0) {
        for (int j = n + first_skipped_difference + 1; j <= n; j++) cout << j << " " << flush;
        for (int j = 1; (j <= n + first_skipped_difference); j++) cout << j << " " << flush;
    }
    else {
        for (int j = first_skipped_difference + 1; (j <= n); j++) cout << j << " " << flush;
        for (int j = 1; j <= first_skipped_difference; j++) cout << j << " " << flush;
    }

    return 0;
}