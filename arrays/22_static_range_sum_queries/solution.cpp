// Problem: Static Range Sum Queries
// Pattern: prefix sums — prefix[i] = sum of first i elements (1-indexed),
// answer for [a,b] is prefix[b] - prefix[a-1]
// Time: O(n + q)  Space: O(n)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << '\n';
    }

    return 0;
}
