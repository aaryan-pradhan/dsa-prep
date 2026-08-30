// Problem: Playlist
// Link: CSES 1141
// Pattern: two-pointer window (tail/head), freq map keeps window duplicate-free
// Time: O(n log n)  Space: O(n)
//
// map (not unordered_map) to sidestep CSES's anti-hash test on plain int keys.
//
// Longest contiguous subsequence with no repeated song id.
//
// Example:
//     1 2 1 3 2 7 4 2 -> 5   (window: 1 3 2 7 4)

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

// Recall Trail
// - Two-pointer window: tail/head. Inner loop extends head while the
//   next song isn't already in the window (freq[a[head+1]] == 0),
//   incrementing its freq as it's absorbed.
// - Answer is max(ans, head-tail+1) every outer iteration, not ans +=
//   ... — that += form belongs to "count all valid subarrays" problems;
//   this one wants the single longest window.
// - Shrink step: decrement freq[a[tail]], tail++ — this is what makes
//   room for the next repeat once the window is maximal.
// - Used map instead of unordered_map for the frequency table — CSES's
//   anti-hash test targets unordered_map on plain int keys (see
//   arrays/07_distinct_values), and map's O(log n) is cheap enough at
//   n <= 2e5.
