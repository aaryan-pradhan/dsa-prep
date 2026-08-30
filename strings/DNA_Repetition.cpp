// Problem: DNA Repetition (longest run of a single character)
// Link: CSES 1069
// Pattern: single-pass run-length scan — track current run vs previous char, keep a running max
// Time: O(n)  Space: O(1)
//
// Longest maximal substring of a single repeated character.
//
// Example:
//     ATTCGGGA -> 3   (GGG)

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

// Recall Trail
// - Single pass, compare s[i] to s[i-1]: same -> extend current run
//   (count++), different -> current char starts a fresh run (count = 1,
//   not 0 — the mismatch position itself still belongs to a run of length
//   at least 1). Update maxCount every iteration.
// - Init both count and maxCount to 1 before the loop, not 0 — covers
//   n == 1 for free since the loop body never runs.
