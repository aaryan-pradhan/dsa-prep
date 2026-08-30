// Problem: Union of Painted Bricks
// Pattern: sort intervals by L, merge overlapping, sum merged lengths
// Time: O(N log N)  Space: O(N)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<pair<long long, long long>> seg(n);
    for (int i = 0; i < n; i++) cin >> seg[i].first >> seg[i].second;

    sort(seg.begin(), seg.end());

    long long total = 0;
    long long curL = seg[0].first, curR = seg[0].second;
    for (int i = 1; i < n; i++) {
        long long l = seg[i].first, r = seg[i].second;
        if (l <= curR) {
            curR = max(curR, r);
        } else {
            total += curR - curL + 1;
            curL = l;
            curR = r;
        }
    }
    total += curR - curL + 1;

    cout << total << '\n';
    return 0;
}
