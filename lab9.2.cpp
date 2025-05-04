/*program to solve the Strength Difference Problem using STL*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t; // Read number of test cases
    while (t--) {
        int n;
        cin >> n; // Read number of participants
        vector<int> strengths(n);
        
        for (int i = 0; i < n; i++) {
            cin >> strengths[i]; // Read strengths of participants
        }
        
        // Find the two largest strengths
        int max1 = *max_element(strengths.begin(), strengths.end());
        int max2 = -1;
        for (int s : strengths) {
            if (s != max1) {
                max2 = max(max2, s);
            }
        }
        
        // Output results
        for (int i = 0; i < n; i++) {
            if (strengths[i] == max1) {
                cout << strengths[i] - max2 << " "; // If it's the strongest, compare with second strongest
            } else {
                cout << strengths[i] - max1 << " "; // Otherwise, compare with the strongest
            }
        }
        cout << endl;
    }
    return 0;
}