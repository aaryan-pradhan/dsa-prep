// Problem: Missing Coin Sum
// Pattern: sort ascending, greedily extend the contiguous achievable-sum
// range [0, R]; a coin x extends it iff x <= R+1, else R+1 is the answer
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

    vector<long long> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    sort(x.begin(), x.end());

    long long r = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] > r + 1) break;
        r += x[i];
    }

    cout << r + 1 << '\n';
    return 0;
}
