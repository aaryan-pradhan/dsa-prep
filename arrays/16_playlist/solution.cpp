// Problem: Playlist
// Pattern: two-pointer window (tail/head), freq map keeps window duplicate-free
// Time: O(n log n)  Space: O(n)
//
// map (not unordered_map) to sidestep CSES's anti-hash test on plain int keys.

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    map<int, int> freq;
    int tail = 0, head = -1;
    long long ans = 0;

    while (tail < n) {
        while (head + 1 < n && freq[a[head + 1]] == 0) {
            head++;
            freq[a[head]]++;
        }
        ans = max(ans, (long long)(head - tail + 1));

        if (tail > head) {
            tail++;
            head = tail - 1;
        } else {
            freq[a[tail]]--;
            tail++;
        }
    }

    cout << ans << '\n';
    return 0;
}
