#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <string.h>
#include <stdio.h>


using namespace std;

int main() {
    // cin.sync_with_stdio(false);
    vector<map<string, int>> levels;
    levels.reserve(50000);
    int current_level = 0;
    map<string, int> block_variables;
    levels.push_back(block_variables);

    // int MAX_LINE = 22;
    string line;
    // char *result;
    while(true) {
        cin>>line;
        if (line.compare("tmp") == 0)
            break;
     // while (getline(cin, line)) {
    //while((result = fgets(line, MAX_LINE, stdin )) != NULL) {


            if (strcmp(line.c_str(), "{") == 0) {
            current_level++;
            map<string, int> block_variables;
            levels.push_back(block_variables);
        }

        else if (strcmp(line.c_str(), "}") == 0) {
            levels.pop_back();
            current_level--;
        }

        else {
            int equal_position = line.find('=');
            string var1 = line.substr(0, equal_position);
            string after_equal = line.substr(equal_position + 1, line.length() - 1);

            // input "var=value"
            if (after_equal[0] == '-' || isdigit(after_equal[0])) {
                (levels[current_level])[var1] = stoi(after_equal);
            }

            // input "var1=var2"
            else {
                if ((levels[current_level]).find(after_equal) != (levels[current_level]).end()) {
                    int var2 = (levels[current_level])[after_equal];
                    (levels[current_level])[var1] = var2;
                    cout << var2 << endl;

                }
                else {
                    int i = current_level - 1;
                    i = max(i, 0);
                    while (i > 0 && levels[i].find(after_equal) == levels[i].end()) i--;
                    int var2 = (levels[i])[after_equal];
                    (levels[current_level])[var1] = var2;
                    (levels[current_level])[after_equal] = var2;
                    cout << var2 << endl;
                }
            }
        }
        line = "tmp";
    }

    return 0;
}
