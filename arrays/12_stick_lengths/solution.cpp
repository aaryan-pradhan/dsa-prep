// Problem: Stick Lengths
// Pattern: sort, target = median, sum absolute deviations
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

    vector<long long> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    sort(p.begin(), p.end());
    long long median = p[n / 2];

    long long cost = 0;
    for (int i = 0; i < n; i++) cost += abs(p[i] - median);

    cout << cost << '\n';
    return 0;
}
