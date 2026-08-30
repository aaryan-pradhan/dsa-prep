// Problem: Collecting Numbers
// Pattern: position array, count rounds by adjacency breaks
// Time: O(n)  Space: O(n)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
    }

    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i - 1]) rounds++;
    }

    cout << rounds << '\n';
    return 0;
}
