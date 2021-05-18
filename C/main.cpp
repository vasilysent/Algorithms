#include <iostream>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

void block_parser(unordered_map<string, int> *all_variables) {
    unordered_map<string, int> changed_variables;
    string line;
    while (getline(cin, line)) {
        if (strcmp(line.c_str(), "{") == 0) block_parser(all_variables);
        else if (strcmp(line.c_str(), "}") == 0) {
            for (auto &variable: changed_variables)
                (*all_variables)[variable.first] = variable.second;
            break;
        }
        else
        {
            int equal_position = line.find('=');
            string var1 = line.substr(0, equal_position);
            string after_equal = line.substr(equal_position + 1, line.length() - 1);

            if (changed_variables.find(var1) == changed_variables.end())
                changed_variables[var1] = (*all_variables)[var1];  // if there is no such name it will return 0 by default

            // input "var=value"
            if (after_equal[0] == '-' || isdigit(after_equal[0]))
                (*all_variables)[var1] = stoi(after_equal);

            // input "var1=var2"
            else {
                int var2 = (*all_variables)[after_equal]; // if there is no such name it will return 0 by default
                (*all_variables)[var1] = var2;
                cout << var2 << endl;
            }
        }
    }
}

int main() {
    // cin.sync_with_stdio(false);

    unordered_map<string, int> all_variables;
    block_parser(&all_variables);

    return 0;
}
