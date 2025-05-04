#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<vector<string>> words(3, vector<string>(n));
    unordered_map<string, int> wordCount;
    
    // Read input and count occurrences of each word
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> words[i][j];
            wordCount[words[i][j]]++;
        }
    }
    
    vector<int> scores(3, 0);
    
    // Calculate scores
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            string word = words[i][j];
            if (wordCount[word] == 1) {
                scores[i] += 3;
            } else if (wordCount[word] == 2) {
                scores[i] += 1;
            }
        }
    }
    
    // Print results
    cout << scores[0] << " " << scores[1] << " " << scores[2] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
