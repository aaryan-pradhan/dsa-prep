// Problem: Traffic Lights
// Pattern: set of boundary positions (with 0, x sentinels) for
// predecessor/successor lookup, multiset of gap lengths for O(1) max
// Time: O(n log n)  Space: O(n)

#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long x;
    int n;
    cin >> x >> n;

    set<long long> positions = {0, x};
    multiset<long long> gaps = {x};

    for (int i = 0; i < n; i++) {
        long long p;
        cin >> p;

        auto it = positions.upper_bound(p);
        // this is the first element > p, so the previous element is the largest <= p

        long long hi = *it ; 
        
        if (it != positions.begin()) {
            it--;
        }

        long long lo = *it;

        gaps.erase(gaps.find(hi - lo));
        // all in O of log n time, since multiset is implemented as a balanced BST
        gaps.insert(p - lo);
        gaps.insert(hi - p);
        positions.insert(p);

        cout << *gaps.rbegin() << ' ';
    }
    cout << '\n';

    return 0;
}
