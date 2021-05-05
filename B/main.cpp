#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// if it's an animal
bool is_lower_case(char letter) {
    if (letter >= 'a' && letter <= 'z') return true;
    return false;
}
// if it's a trap
bool is_upper_case(char letter) {
    if (letter >= 'A' && letter <= 'Z') return true;
    return false;
}

struct zoo_object {
    bool type;  // true for an animal and false for a trap
    char kind;  // lowercase letter of kind
    int number; // number in order of appearing
};

int main() {
    struct zoo_object current_object;
    char current_letter;
    int animal_counter = 0;
    int trap_counter = 0;
    stack<struct zoo_object> zoo;
    zoo.push({false, ' ', 0}); // adding an dummy object to the stack
    vector<int> traps; // vector of traps with animals' numbers

    while (cin >> current_letter) {
        // if animal
        if (is_lower_case(current_letter)) {
            current_object.kind = current_letter;
            current_object.type = true; // animal
            animal_counter++;
            current_object.number = animal_counter;
        }
        // if trap
        if (is_upper_case(current_letter)) {
            current_object.kind = current_letter + ('a' - 'A');
            current_object.type = false; // trap
            trap_counter++;
            current_object.number = trap_counter;
            traps.push_back(0);
        }
        // if current object has same kind and different type, e.g. 'A' and 'a'
        if (current_object.kind == zoo.top().kind && current_object.type != zoo.top().type) {
            // remember animal number to the trap in the vector
            // if current is a trap
            if (!current_object.type) traps[trap_counter - 1] = zoo.top().number;
            else traps[zoo.top().number - 1] = current_object.number;
            zoo.pop(); // erase the pair
        }
        else zoo.push(current_object);
    }
    if (zoo.size() == 1) { // if only the dummy object left
        cout << "Possible" << endl;
        for (auto &trap: traps) {
            cout << trap << " " << flush;
        }
    }
    else cout << "Impossible" << endl;

    return 0;
}
