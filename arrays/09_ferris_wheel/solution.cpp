// Problem: Ferris Wheel
// Pattern: sort, two-pointer from both ends — pair lightest with heaviest
// when they fit together, else heaviest rides alone
// Time: O(n log n)  Space: O(1) extra

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    sort(p.begin(), p.end());

    int i = 0, j = n - 1, count = 0;
    while (i <= j) {
        if (p[i] + p[j] <= x) i++;
        j--;
        count++;
    }

    cout << count << '\n';
    return 0;
}
