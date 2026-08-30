// Problem: Weird Algorithm (Collatz sequence)
// Pattern: simulate with a loop, print each state, exit right after the terminal value
// Time: O(steps) per input, steps bounded by known Collatz behavior for n <= 1e6
// Space: O(1)

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
