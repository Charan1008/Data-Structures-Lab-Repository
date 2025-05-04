#include <iostream>
#include <vector>
#include <unordered_set> 

using namespace std; 

int solve () {
    int n;  
    cin >> n;

    vector<int> a(n);

    for (int i=0; i<n; i++) {
        cin >> a[i];  
    }
    
    unordered_set<int> seen;
    int left = 0;
    int max_len = 0;

    for (int right=0; right<n; ++right) {
        while (seen.find(a[right]) != seen.end()) {
            seen.erase(a[left]);
            left++;
        }
        seen.insert(a[right]);
        max_len = max(max_len, right-left+1);
    }
    return n - max_len;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }

    return 0;
}