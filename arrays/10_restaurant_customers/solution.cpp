// Problem: Restaurant Customers
// Pattern: sweep line — split each interval into +1/-1 events, sort by
// time, track running total and its max
// Time: O(n log n)  Space: O(n)

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
