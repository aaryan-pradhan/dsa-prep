// Problem: Restaurant Customers
// Link: CSES 1619
// Pattern: sweep line — split each interval into +1/-1 events, sort by
// time, track running total and its max
// Time: O(n log n)  Space: O(n)
//
// Given n (arrival, leaving) intervals, find the max number simultaneously
// present.
//
// Example:
//     (5,8) (2,4) (3,9) -> 2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<pair<long long, int>> events;
    events.reserve(2 * n);
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        events.push_back({a, 1});
        events.push_back({b, -1});
    }

    sort(events.begin(), events.end());

    int running = 0, best = 0;
    for (auto& [time, delta] : events) {
        running += delta;
        best = max(best, running);
    }

    cout << best << '\n';
    return 0;
}

// Recall Trail
// - Don't reason about the raw intervals directly — split each into two
//   separate timestamped events: arrival = +1, leaving = -1. Sort all
//   2n events by time.
// - Sweep once: maintain a running total (add the event's delta), and update
//   a separate best = max(best, running) at every step — the max has to be
//   tracked continuously, not read off the final total (which is always 0).
// - Arrival/leaving times are guaranteed distinct, so no tie-break needed
//   between an arrival and departure at the same instant.
