// Problem: Reducing Dishes
// Pattern: sort ascending, then pop the smallest from the front while the
//          running total of included elements is negative
// Time: O(N log N)  Space: O(N)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        long long ans = 0, total = 0;
        for (int i = 0; i < n; i++) {
            ans += (long long)(i + 1) * a[i];
            total += a[i];
        }

        int start = 0;
        while (start < n && total < 0) {
            ans -= total;
            total -= a[start];
            start++;
        }

        cout << ans << '\n';
    }
    return 0;
}
