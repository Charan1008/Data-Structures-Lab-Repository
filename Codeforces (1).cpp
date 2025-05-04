#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve() {
    int n;
    printf("Enter the number of block towers: ");
    scanf("%d", &n);

    vector<int> a(n);
    int max_blocks = a[0];

    for (int i=0; i<n; i++) {
        printf("Enter the values to store in the blocktowers: ");
        scanf("%d", &a[i]);
    }

    if (n>1) {
        vector<int> b(a.begin(), a.end());
        sort(b.begin(),b.end());
        for (int blocks :b) {
            if (blocks > max_blocks) {
                max_blocks += (blocks - max_blocks + 1)/2;
            }
        }
    }
    printf("The output is : %d\n", max_blocks);
    return 0;
}

int main() {
    int t;
    printf("Enter the number of testcases: ");
    scanf("%d", &t);

    while(t--) {
        solve();
    }
    return 0;
}