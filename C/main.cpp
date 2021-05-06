#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    unordered_map<int, unordered_map<string, int>> levels;
    vector<int> output;
    int current_level = 0;
    unordered_map<string, int> block_variables;
    levels[current_level] = block_variables;
    string line;
    while (getline(cin, line)) {

        if (line == "{") {
            current_level++;
            unordered_map<string, int> block_variables;
            levels[current_level] = block_variables;
        }

        if (line == "}") {
            levels.erase(current_level);
            current_level--;
           // block_variables = levels[current_level];
        }
        if (line.find('=') != string::npos) {
            int equal_position = line.find('=');
            string var1 = line.substr(0, equal_position);
            line.erase(0, equal_position + 1);

            // input "var=value"
            if (line[0] == '-' || isdigit(line[0])) {
                (levels[current_level])[var1] = stoi(line);
            }
            // input "var1=var2"
            else {
                if ((levels[current_level]).find(line) != (levels[current_level]).end()) {
                    (levels[current_level])[var1] = (levels[current_level])[line];
                    output.push_back((levels[current_level])[line]);
                }
                else {
                    int i = current_level - 1;
                    i = max(i, 0);
                    while (i > 0 && levels[i].find(line) == levels[i].end()) i--;
                    (levels[current_level])[var1] = (levels[i])[line];
                    output.push_back((levels[i])[line]);
                }
            }
        }
    }
    for (auto &value: output) {
        cout << value << endl;
    }

    return 0;
}
