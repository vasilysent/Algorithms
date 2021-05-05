#include <iostream>
using namespace std;

int main() {

    int n; // number of plants on the bed
    cin>>n;

    if (n == 1) {
        cout<< 1 << " " << 1 <<endl;
        return 0;
    }

    int bed [n]; // bed array
    for(int i = 0; i < n; i++) {
        cin>>bed[i];
    }

    int photo_first = 0;      // index of the first plant in the photo
    int max_photo_first = 0;  // index of the first plant in the maximal photo
    int max_photo_last = 1;   // index of the last  plant in the maximal photo
    int max_photo_length = 1; // initializing maximal bed length

    bool couple = false;      // "previous to plants are same" flag

    for(int i = 1; i < n; i++) {
        if (bed[i] == bed[i - 1]) {     // if current plant is the same with the previous
            if (!couple) {              // if it is not a triple
                if (i == n - 1) {       // in case this is the last plant in the bed
                    if (i - photo_first + 1 > max_photo_length) { // then comparing bed length with the maximal
                        max_photo_first = photo_first;
                        max_photo_last = i;
                    }
                }
                couple = true;
            }
            else {  // if it is a triple
                if (i - photo_first > max_photo_length) {
                    max_photo_first = photo_first;
                    max_photo_last = i - 1;
                    max_photo_length = max_photo_last - max_photo_first + 1;
                }
                photo_first = i - 1;
                // photo_last = i;
            }
        }
        else { // if current plant is different from the previous
            couple = false;
            if (i == n - 1) {
                if (i - photo_first + 1 > max_photo_length) {
                    max_photo_first = photo_first;
                    max_photo_last = i;
                }
            }
        }
    }

    cout<< max_photo_first + 1 << " " << max_photo_last + 1 <<endl;

    return 0;
}
