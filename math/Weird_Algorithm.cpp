// Problem: Weird Algorithm (Collatz sequence)
// Link: CSES 1068
// Pattern: simulate with a loop, print each state, exit right after the terminal value
// Time: O(steps) per input, steps bounded by known Collatz behavior for n <= 1e6
// Space: O(1)
//
// n even -> n/2, n odd -> 3n+1, repeat until n == 1. Print every value n
// takes, including the initial n and the final 1.
//
// Example:
//     3 -> 3 10 5 16 8 4 2 1

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n;
    cin >> n;

    while (n != 1) {
        cout << n << ' ';
        if (n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
    }
    cout << 1 << '\n';

    return 0;
}

// Recall Trail
// - No aggregate asked for (count, max, etc.) — just print every value in
//   sequence, and the number of steps is unknown up front. That's a plain
//   simulate-with-a-loop, not a pattern to search for.
// - 1 can't go through the even/odd transform (would loop forever), so it's
//   handled outside the loop: while (n != 1) { print n; transform; } print 1;.
//   This also makes n == 1 on input a correct edge case for free — loop body
//   never runs, 1 prints immediately.
// - n <= 1e6 so 3n+1 never overflows int, but used long long anyway —
//   cheap and removes the need to think about it.
