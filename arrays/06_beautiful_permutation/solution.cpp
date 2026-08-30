// Problem: Beautiful Permutation
// Pattern: split by parity — evens ascending then odds ascending, so within
// each half consecutive prints differ by 2, and the halves' boundary values
// (largest even, 1) are far apart
// Time: O(n)  Space: O(n) for output buffer

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    for (int i = 2; i <= n; i += 2) cout << i << ' ';
    for (int i = 1; i <= n; i += 2) cout << i << ' ';
    cout << '\n';

    return 0;
}
