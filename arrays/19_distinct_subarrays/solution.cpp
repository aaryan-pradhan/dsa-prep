// Problem: Distinct Subarrays (count)
// Pattern: same duplicate-free window as Playlist, but accumulate
// head-tail+1 (subarrays starting at tail) every outer step instead of
// tracking the max
// Time: O(n log n)  Space: O(n)

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
    for (auto& v : a) cin >> v;

    map<int, int> freq;
    int tail = 0, head = -1;
    long long ans = 0;

    while (tail < n) {
        while (head + 1 < n && freq[a[head + 1]] == 0) {
            head++;
            freq[a[head]]++;
        }
        ans += head - tail + 1;

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


