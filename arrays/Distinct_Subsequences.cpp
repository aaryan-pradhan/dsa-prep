// Problem: Distinct Subsequences
// Link: CSES 2429
// Pattern: per-value option counting — a value with frequency f has (f+1)
// independent options (exclude, or include one of its f occurrences);
// multiply across distinct values, subtract 1 for the empty subsequence
// Time: O(n log n)  Space: O(n)
//
// Count subsequences (not necessarily contiguous) where every element is
// distinct, modulo 1e9+7.
//
// Example:
//     1 2 1 3 -> 11

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

// Recall Trail
// - Contiguity doesn't matter here (unlike arrays/19_distinct_subarrays),
//   so the two-pointer window approach doesn't apply at all — different
//   problem shape despite the similar name.
// - A value can appear at most once in any valid subsequence. For a value
//   with frequency f, the real option set is: exclude it, or include
//   exactly one of its f occurrences — f+1 mutually exclusive options
//   (not 2^f, which would treat occurrence choices as independent bits
//   and overcount by allowing multiple occurrences "on" at once).
// - Options for different distinct values are independent, so total
//   combinations = Π (freq[v] + 1) over distinct values v. This counts
//   every subsequence exactly once, including the empty one (every value
//   excluded) — subtract 1 for the final answer.
// - Modular arithmetic helpers (mmul, msub, mcorr — apply mcorr once
//   at the very end to fix up a possibly-negative result from msub) are
//   the standing template for any mod-1e9+7 problem in this repo.
