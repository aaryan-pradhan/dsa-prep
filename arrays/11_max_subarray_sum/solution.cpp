// Problem: Maximum Subarray Sum
// Pattern: Kadane's — running best-ending-here, extend or restart at each element
// Time: O(n)  Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<long long> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    long long cur = x[0], best = x[0];
    for (int i = 1; i < n; i++) {
        cur = max(x[i], cur + x[i]);
        best = max(best, cur);
    }

    cout << best << '\n';
    return 0;
}
