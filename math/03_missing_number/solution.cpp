// Problem: Missing Number
// Pattern: XOR 1..n with the given values — duplicates cancel, only the missing one survives
// Time: O(n)  Space: O(1)

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    long long x = 0;
    for (int i = 1; i <= n; i++) x ^= i;

    int v;
    for (int i = 0; i < n - 1; i++) {
        cin >> v;
        x ^= v;
    }

    cout << x << '\n';
    return 0;
}
