// String Processing using Stack ADT...
#include <iostream>
#include <stack> // Operations in the stack are used...

using namespace std;
// String processing...
string processString(string str) {
    stack<char> s;
    for (char ch : str) {
        if (ch == '+') {
            if (!s.empty()) s.pop(); // Remove immediate left character
        } else {
            s.push(ch);
        }
    }

    string result = "";
    while (!s.empty()) {
        result = s.top() + result;
        s.pop();
    }
    return result;
}
// Main function
int main() {
    string input;
    cout << "Enter a string with '+' symbol: ";
    cin >> input;

    string result = processString(input);
    cout << "Processed string: " << result << endl;

    return 0;
}