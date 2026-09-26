# QuantFest 2026 — Mock Regionals: Answers

The questions are in `QuantFest_2026_Mock_Regionals.md`. Every answer was checked by exact computation, plus simulation for the probability ones. All six C++ solutions pass the samples and run in under 0.1 s at the maximum limits.

| Test | Answers |
|---|---|
| 2 (Relay) | 6, 12, 54, 8, 8, 12, 13, 20 |
| 3 (Written) | 1: 13/27 · 2: 224/255, 1027/85 · 3: 10, 1/3 · 4: 71/18 · 5: 1/4, 11/18 · 6: L ⇔ n mod 7 ∈ {0, 2}, Alice (take 1 or 3) · 7: 48/5 · 8: 1/2, 1/3 |

---

## Test 1 — Coding

### C1. Up to k Rolls — Form 1
rec(j) = expected payout when you are about to make roll j. Base case: rec(k) = (m + 1)/2, because the last roll must be kept. For j < k, rec(j) = E[max(X, rec(j+1))]: keep x exactly when x > rec(j+1). With t = ⌊rec(j+1)⌋, that expectation is (t·rec(j+1) + (t+1) + … + m)/m, an arithmetic series, so each step is O(1) and the whole thing is O(k). This is the same threshold trick as C1 "Minimise the Rank" in the first mock.

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long m, k; cin >> m >> k;
    double V = (m + 1) / 2.0;                              // rec(k): last roll, must keep
    for (long long j = k - 1; j >= 1; j--) {               // rec(j) = E[max(X, rec(j+1))]
        long long t = min<long long>(m, (long long)floor(V)); // keep x > V, i.e. x >= t+1
        V = (t * V + (double)(m + t + 1) * (m - t) / 2) / m;
    }
    printf("%.6f\n", V);
}
```

### C2. Square Stones — Form 5
win(n) = true if the player about to move with n stones can force a win. win(0) = false (no move). win(n) = true if some square s² ≤ n has win(n − s²) = false. There are 10⁵ states with √n moves each, about 3·10⁷ operations. The losing sizes start 0, 2, 5, 7, 10, 12, 15, 17, 20, 22, 34, 39, …, with no simple pattern, so the DP is the whole solution.

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    const int N = 100000; vector<char> win(N + 1, 0);           // win[n]: player to move wins
    for (int n = 1; n <= N; n++)
        for (int s = 1; s * s <= n && !win[n]; s++) if (!win[n - s * s]) win[n] = 1;
    int t; cin >> t; while (t--) { int n; cin >> n; puts(win[n] ? "Alice" : "Bob"); }
}
```

### C3. Ruin, Modulo — Form 1 with the "P(x) = a + b·P(1)" trick
P(i) = p·P(i+1) + q·P(i−1), with P(0) = 0 and P(N) = 1. Solving this gives P(s) = (1 − rˢ)/(1 − rᴺ), where r = q/p. In the fair case r = 1 and P(s) = s/N. Compute r = (b − a)·a⁻¹ mod 998244353, then use fast powers, since N goes up to 10¹⁸. (This is the prelims "Our Random Jump" idea: write every value in terms of one unknown.)

```cpp
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long pw(long long b, long long e) { long long r = 1; b %= MOD; while (e) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; } return r; }
int main() {
    long long a, b, s, N; cin >> a >> b >> s >> N;
    if (2 * a == b) { cout << s % MOD * pw(N, MOD - 2) % MOD << "\n"; return 0; }   // fair: s/N
    long long r = (b - a) % MOD * pw(a, MOD - 2) % MOD;                               // r = q/p
    long long num = (1 - pw(r, s) + MOD) % MOD, den = (1 - pw(r, N) + MOD) % MOD;
    cout << num * pw(den, MOD - 2) % MOD << "\n";
}
```

### C4. Never Below Zero — reflection
Of all C(n+m, m) orderings, the bad ones touch −1. Reflect each bad path after its first touch of −1: this is a bijection onto paths with n+1 downs, of which there are C(n+m, m−1). Answer: C(n+m, m) − C(n+m, m−1) when m ≤ n, else 0. Precompute factorials up to 2·10⁶. (This is the prelims "Stat Expo" ballot count with ratio 1.)

```cpp
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353; const int M = 2000001;
long long f[M], inv[M];
long long pw(long long b, long long e) { long long r = 1; while (e) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; } return r; }
long long C(int n, int k) { return k < 0 || k > n ? 0 : f[n] * inv[k] % MOD * inv[n - k] % MOD; }
int main() {
    f[0] = 1; for (int i = 1; i < M; i++) f[i] = f[i - 1] * i % MOD;
    inv[M - 1] = pw(f[M - 1], MOD - 2); for (int i = M - 1; i > 0; i--) inv[i - 1] = inv[i] * i % MOD;
    int q; scanf("%d", &q);
    while (q--) { int n, m; scanf("%d %d", &n, &m);
        printf("%lld\n", m > n ? 0 : (C(n + m, m) - C(n + m, m - 1) + MOD) % MOD); }   // reflection
}
```

### C5. Divisor Walk — Form 1 with a self-loop
E(1) = 0. For x > 1 with d(x) divisors, E(x) = 1 + (1/d(x))·Σ_(d | x) E(d). The term d = x is E(x) itself: a self-loop. Move it to the left side:
E(x)·(1 − 1/d(x)) = 1 + (1/d(x))·Σ_(d | x, d < x) E(d).
Fill x = 1, 2, … in increasing order. Add each E(x) to all of its multiples, which is a harmonic sieve, O(n log n) in total. Check: E(2) = 1 + (0 + E(2))/2, so E(2) = 2. Also E(12) = 91/30.

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    const int N = 1000000; vector<double> E(N + 1, 0), S(N + 1, 0); vector<int> d(N + 1, 0);
    for (int x = 1; x <= N; x++) {
        if (x > 1) E[x] = (1 + S[x] / (d[x] + 1)) / (1 - 1.0 / (d[x] + 1));   // self-loop solved: d(x) = d[x] + 1
        for (int y = 2 * x; y <= N; y += x) { S[y] += E[x]; d[y]++; }         // proper divisors of y
    }
    int q; scanf("%d", &q); while (q--) { int n; scanf("%d", &n); printf("%.6f\n", E[n]); }
}
```

### C6. Ends of the Row — Form 4 + Form 5
best(l, r) = the total that the player about to move collects from a[l..r] under best play. The two totals add up to sum(l..r), so best(l, r) = sum(l..r) − min(best(l+1, r), best(l, r−1)). Base case: best(l, l) = a[l]. Answer best(1, n): O(n²) time with one rolling row.

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; scanf("%d", &n); vector<long long> a(n), pre(n + 1, 0);
    for (int i = 0; i < n; i++) { scanf("%lld", &a[i]); pre[i + 1] = pre[i] + a[i]; }
    vector<long long> dp(n, 0);                        // dp[l] = best(l, r) for the current length
    for (int i = 0; i < n; i++) dp[i] = a[i];
    for (int len = 2; len <= n; len++)
        for (int l = 0; l + len - 1 < n; l++) { int r = l + len - 1;
            dp[l] = (pre[r + 1] - pre[l]) - min(dp[l + 1], dp[l]); }   // dp[l+1]=best(l+1,r), dp[l]=best(l,r-1)
    printf("%lld\n", dp[0]);
}
```

---

## Test 2 — Relay

1. **6.** The number of rolls is geometric with success probability 1/6, so its mean is 6.
2. **12.** Each head takes 2 tosses on average, so T = 6 heads take 2·6 = 12.
3. **54.** A convex n-gon has n(n − 3)/2 diagonals: 12·9/2 = 54.
4. **8.** 54 = 2·3³ has (1 + 1)(3 + 1) = 8 divisors.
5. **8.** The stationary distribution is uniform, 1/8 on each vertex, so the expected return time is 1/(1/8) = 8.
6. **12.** Starting from s with target N, a fair gambler's expected duration is s(N − s) = 2·(8 − 2) = 12.
7. **13.** The 2 × n domino tilings follow Fibonacci, 1, 2, 3, 5, 8, 13 for n = 1…6, and here n = 6.
8. **20.** Inclusion–exclusion: ⌊100/13⌋ + ⌊100/7⌋ − ⌊100/91⌋ = 7 + 14 − 1 = 20.

---

## Test 3 — Written

**W1. 13/27.** Count ordered (child 1, child 2) pairs; each child is one of 14 equally likely (sex, day) types. The pairs containing a Tuesday boy number 14 + 14 − 1 = 27. Of these, the pairs where both are boys number 7 + 7 − 1 = 13.

**W2. (a) 224/255. (b) 1027/85.** (a) Let r = q/p = 1/2. From start distance 3 to a total span of 8, P = (1 − r³)/(1 − r⁸) = (7/8)/(255/256) = 224/255. (b) By Wald's identity, E[S_τ] = (p − q)·E[τ], so E[τ] = 3·(5P − 3(1 − P)) = 3(8P − 3) = 3·(1792 − 765)/255 = 1027/85.

**W3. (a) 10. (b) 1/3.** (a) HTH matches itself with overlaps of length 1 and 3, so E = 2¹ + 2³ = 10. (b) Once H has appeared, the next toss decides it: H → HH, and HHT is then certain before HTH, because an HH run ends in HHT as soon as a T comes; T → HT, and from HT the next toss H finishes HTH, while T sends you back to the start. From the start: x = P(HTH first) = P(from H), and from H: x = ½·0 + ½·(½·1 + ½·x). So x = ¼ + x/4, and x = 1/3.

**W4. 71/18, reroll on 1 or 2 every time.** With no rerolls left the value is 7/2. With one reroll left, keep x if x ≥ 7/2 − 1 = 5/2, so reroll 1 and 2: value (2·5/2 + 3 + 4 + 5 + 6)/6 = 23/6. With two rerolls left, keep x if x ≥ 23/6 − 1 = 17/6, so again reroll 1 and 2: value (2·17/6 + 18)/6 = 71/18 ≈ 3.944.

**W5. (a) 1/4. (b) 11/18.** (a) The pieces form a triangle exactly when every piece is shorter than ½. Each "piece ≥ ½" event has probability 1/4, and at most one can happen, so the answer is 1 − 3/4 = 1/4. (b) For the n uniform spacings of [0, 1], E[longest] = (1/n)(1 + 1/2 + … + 1/n). With n = 3: (1/3)(11/6) = 11/18.

**W6. L ⇔ n mod 7 ∈ {0, 2}. Alice wins by taking 1 or 3.** Form 5: win(n) = some move m ∈ {1, 3, 4} with m ≤ n gives win(n − m) = false. Small cases give L = 0, 2, 7, 9, 14, 16, …, which has period 7. Proof, with residues mod 7: (i) from an L-position every move goes to a W-position, since 0 − {1, 3, 4} = {6, 4, 3} and 2 − {1, 3, 4} = {1, 6, 5}, and none of these is 0 or 2. (ii) From every W-position some move reaches an L-position: 1 → 0 (take 1), 3 → 0 (take 3), 4 → 0 (take 4), 5 → 2 (take 3), 6 → 2 (take 4). 2026 ≡ 3 (mod 7), which is W. Take 1 (to 2025 ≡ 2) or take 3 (to 2023 ≡ 0).

**W7. 48/5.** Linearity of expectation: each of the 48 non-aces comes before all 4 aces with probability 1/5, since it is equally likely to be anywhere among those 5 cards. So 48/5 = 9.6.

**W8. (a) 1/2. (b) 1/3.** (a) The event is the region between the lines y = x/2 and y = 2x in the unit square. The two cut-off triangles each have area ½·1·½ = 1/4, so the answer is 1 − 1/2 = 1/2. (b) E|X − Y| = 2∫₀¹∫₀ˣ (x − y) dy dx = 2∫₀¹ x²/2 dx = 1/3.
