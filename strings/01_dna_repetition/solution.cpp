// Problem: DNA Repetition (longest run of a single character)
// Pattern: single-pass run-length scan — track current run vs previous char, keep a running max
// Time: O(n)  Space: O(1)

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    int count = 1, maxCount = 1;
    for (size_t i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) count++;
        else count = 1;
        maxCount = max(maxCount, count);
    }

    cout << maxCount << '\n';
    return 0;
}
