/*program to solve the Game Problem using STL*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Function to determine the number of winners
int find_winners(int n, const vector<int>& a) {
    set<int> players; // Set to store active players
    for (int i = 1; i <= n; i++) {
        players.insert(i);
    }
    
    while (true) {
        vector<int> to_remove; // List of players to be removed in this round
        for (int idx : a) {
            if (idx <= players.size()) {
                auto it = players.begin(); // Get iterator to the start of set
                advance(it, idx - 1); // Move iterator to the required index
                to_remove.push_back(*it);
            }
        }
        
        if (to_remove.empty()) break; // If no players to remove, stop the game
        
        for (int p : to_remove) {
            players.erase(p); // Remove players who were eliminated in this round
        }
    }
    
    return players.size(); // Return the number of remaining players (winners)
}

int main() {
    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        int k, q;
        cin >> k >> q; // Read k (length of sequence) and q (number of queries)
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i]; // Read the sequence a
        }
        vector<int> queries(q);
        for (int i = 0; i < q; i++) {
            cin >> queries[i]; // Read the different values of n for queries
        }
        
        for (int n : queries) {
            cout << find_winners(n, a) << " "; // Compute and print result for each query
        }
        cout << endl;
    }
    return 0;
}