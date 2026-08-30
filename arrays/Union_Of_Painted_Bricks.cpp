// Problem: Union of Painted Bricks
// Pattern: sort intervals by L, merge overlapping, sum merged lengths
// Time: O(N log N)  Space: O(N)
//
// N days, each day Mantesh paints all bricks in [L_i, R_i] (repaint is a
// no-op). Brick numbers can be up to ~1e9, so a per-brick boolean array
// doesn't fit. Count total distinct bricks painted = size of the union of N
// intervals.
//
// Example:
//     (2,5),(10,10),(4,5),(3,7),(12,14) -> 10

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

// Recall Trail
// - Marking every brick is out given the coordinate range — sort segments by
//   l and merge overlapping ranges into contiguous blocks instead.
// - Merge condition: l_j <= cur_r means the next segment overlaps (or
//   touches) the block being built — extend cur_r = max(cur_r, r_j).
//   Otherwise the current block is finished: flush its length
//   (cur_r - cur_l + 1) into the running total, then start a new block at
//   l_j.
// - Ties on l don't need special handling — sorting groups them adjacently,
//   and max picks up the correct r regardless of which same-l segment
//   is processed first.
// - The last block never gets a "next segment" to trigger its flush — must
//   flush it explicitly once after the loop ends.
// - Use long long throughout: with N and coordinates both up to ~1e5/1e9,
//   the total can reach ~1e14, well past int range.
