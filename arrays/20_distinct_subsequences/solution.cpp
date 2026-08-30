// Problem: Distinct Subsequences
// Pattern: per-value option counting — a value with frequency f has (f+1)
// independent options (exclude, or include one of its f occurrences);
// multiply across distinct values, subtract 1 for the empty subsequence
// Time: O(n log n)  Space: O(n)

#include <iostream>
#include <map>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

ll mmul(ll a, ll b) { return (a % MOD * (b % MOD)) % MOD; }
ll msub(ll a, ll b) { return (a % MOD - b % MOD) % MOD; }
ll mcorr(ll a) { return (a % MOD + MOD) % MOD; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    map<int, ll> freq;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        freq[v]++;
    }

    ll ans = 1;
    for (auto& [val, f] : freq) {
        ans = mmul(ans, f + 1);
    }

    ans = mcorr(msub(ans, 1));
    cout << ans << '\n';
    return 0;
}
