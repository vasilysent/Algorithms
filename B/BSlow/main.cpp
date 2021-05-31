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
bool all_single(string str, int indices[]){ // e.g. AbcbDaBCBd
    int size = str.size();
    int i = 0;
    while(indices[i] == 0 && i < size) i++;
    if (i == size) return false;
    char prev_type = type(str[i]);
    i++;
    while (i < size) {
        while(indices[i] == 0 && i < size) i++;
        if (i == size) return false;
        if (type(str[i]) == prev_type) return false;
        else prev_type = type(str[i]);
        i++;
    }
    return true;
}
bool all_caught(int indices[], int size) {
    for(int i = 0; i < size; i++) if (indices[i] != 0) return false;
    return true;
}
void skip_caught(int indices[], int* i, int size) {
    while(indices[*i] == 0 && *i < size) (*i)++;
}
void set_indices(string str, int indices[]) {
    int animal_counter = 0;
    int trap_counter = 0;
    int size = str.size();
    for (int i = 0; i < size; i++) {
        if (is_upper_case(str[i])) {trap_counter++; indices[i] = -trap_counter; }
        if (is_lower_case(str[i])) {animal_counter++; indices[i] = animal_counter; }
    }
}

int main() {

    string zoo;
    cin>>zoo; // string input

    const int n = zoo.length() / 2; // number of animals (or traps)
    int indices[2 * n]; // array with
    set_indices(zoo, indices);

    int traps[n]; // array of all traps containing animal indices or zeros if no animal in a trap

    char current_type;               // animal type in a current streak

    int prev_animal_at = -1;
    int prev_trap_at = -1;
    int prev_animal_num = -1;
    int prev_trap_num = -1;

    while (!all_single(zoo, indices) && !all_caught(indices, 2 * n)) {
        int i = 0;
        while (i < 2*n) {
            skip_caught(indices, &i, 2*n); // set pointer at the first object in the streak

            current_type = type(zoo[i]);       // set a type for the streak
            if(is_upper_case(zoo[i])) { prev_trap_num = -indices[i]; prev_trap_at = i; }
            if(is_lower_case(zoo[i])) { prev_animal_num = indices[i]; prev_animal_at = i; }
            i++;                               // go next
            skip_caught(indices, &i, 2*n); // skip caught if there are any
            while (type(zoo[i]) == current_type && i < 2*n){ // while streak continues and we haven't reached the end
                if(is_upper_case(zoo[i])) { prev_trap_num = -indices[i]; prev_trap_at = i; }
                if(is_lower_case(zoo[i])) { prev_animal_num = indices[i]; prev_animal_at = i; }
                if (prev_animal_num != -1 && prev_trap_num != -1) {
                    traps[prev_trap_num - 1] = prev_animal_num;
                    indices[prev_trap_at] = 0;
                    indices[prev_animal_at] = 0;
                    prev_animal_at = -1;
                    prev_animal_num = -1;
                    prev_trap_at = -1;
                    prev_trap_num = -1;
                }
                i++;
                skip_caught(indices, &i, 2*n);
            }
            if(prev_animal_num != -1) { prev_animal_at = -1; prev_animal_num = -1; }
            if(prev_trap_num != -1) { prev_trap_at = -1; prev_trap_num = -1; }

        }
    }
    if(all_single(zoo, indices)) {
        cout << "Impossible" << endl;
        return 0; // finish the program
    }

    cout << "Possible" << endl;
    for (int i = 0; i < n; i++) cout << traps[i] << " " << flush;

    return 0;
}