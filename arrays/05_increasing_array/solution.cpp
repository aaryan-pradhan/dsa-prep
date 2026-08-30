// Problem: Increasing Array
// Pattern: single-pass greedy — track running previous (post-adjustment), pay the shortfall
// Time: O(n)  Space: O(1)

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    long long prev = 0, cost = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (x < prev) cost += prev - x;
        else prev = x;
    }

    cout << cost << '\n';
    return 0;
}
