// Problem: Apartments
// Pattern: sort both sides, two-pointer greedy sweep
// Time: O(n log n + m log m)  Space: O(1) extra

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, count = 0;
    while (i < n && j < m) {
        if (b[j] < a[i] - k) j++;
        else if (b[j] > a[i] + k) i++;
        else { count++; i++; j++; }
    }

    cout << count << '\n';
    return 0;
}
