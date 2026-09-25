# QuantFest 2026 — Mock Paper: Full Solutions

The questions are in `QuantFest_2026_Mock_Paper.md`. Every answer was checked by exact computation or simulation. All six C++ solutions pass the samples and matched brute force on random tests.

| Paper | Answers |
|---|---|
| 2 (Relay) | 20, 41, 720, 30, 7, 42, 14, 429, 7129, 10, 55, 147 |
| 3 (Written) | 1: 20, 15 · 2: 11/16, 25/48 · 3: 30 min, 7.5 · 4: 3/4, 3/(2√π) · 5: 49/4, 617/36 · 6: H₁₀₀ − 1/100 ≈ 5.1774 · 7: 100, 0.2857 · 8: 55/3 |

---

## Paper 1 — Coding

### C1. Minimise the Rank

**Setup.** Suppose candidate i has relative rank r among the first i candidates. Their absolute rank then has expectation r(n+1)/(i+1).
- Why: given relative rank r, the r-th smallest of i uniformly random positions among {1..n} has mean r(n+1)/(i+1).

**Recursion.**
- V_i is the best expected rank achievable when you are about to see candidate i and have not yet hired anyone.
- At the last candidate you are forced to hire: r is uniform on 1..n, so V_n = (n+1)/2.
- Otherwise V_i = (1/i) · Σ_{r=1}^{i} min(r(n+1)/(i+1), V_{i+1}), because r is uniform on 1..i and you either hire now or continue.

**Speed.** r(n+1)/(i+1) increases with r, so you hire exactly when r ≤ t = ⌊V_{i+1}(i+1)/(n+1)⌋ (capped at i). That makes each step an arithmetic series plus (i − t)·V_{i+1}: O(1) per step, O(n) in total.

**Check.** n = 3 gives 5/3 and n = 10 gives 3223/1260 ≈ 2.557937 (exact fractions). As n → ∞ the value tends to ≈ 3.8695; n = 10⁵ gives 3.868966.

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n; cin >> n;
    double V = (n + 1) / 2.0;                       // forced to take the last candidate
    for (long long i = n - 1; i >= 1; i--) {
        double c = (n + 1.0) / (i + 1);             // expected rank per unit of relative rank
        long long t = min<long long>(i, (long long)floor(V / c));   // take r <= t
        V = (c * t * (t + 1) / 2 + (i - t) * V) / i;
    }
    printf("%.6f\n", V);
}
```

### C2. Random Walk on a Tree

**Key fact.** Root the tree. Let e(x) = E[steps from x to its parent], and let sub(x) be the size of x's subtree. Claim: e(x) = 2·sub(x) − 1.

Proof by induction from the leaves up:
- A leaf has one neighbour (its parent), so e(x) = 1 = 2·1 − 1.
- Otherwise x has d = c + 1 neighbours: c children and 1 parent.
  - With probability 1/d the walk steps straight to the parent: cost 1.
  - With probability 1/d it steps into child y. It then needs e(y) steps to come back to x, and e(x) more from there: cost 1 + e(y) + e(x).
- So e(x) = 1 + (1/d)·Σ_y (e(y) + e(x)). Multiply by d and move the c·e(x) terms to the left:
  e(x) = d + Σ_y e(y) = 1 + c + Σ_y (2·sub(y) − 1) = 1 + 2·Σ_y sub(y) = 1 + 2(sub(x) − 1) = 2·sub(x) − 1.

Re-rooting at the child gives the downward cost: E[steps from the parent into child x] = 2(n − sub(x)) − 1.

**Queries.**
- Let U[x] be the sum of the "up" costs from x to the root, and D[x] the sum of the "down" costs from the root to x.
- The path u → v goes up to l = lca(u, v) and then down to v, so E = (U[u] − U[l]) + (D[v] − D[l]).
- Hitting times add along the path because in a tree the walk must pass through every vertex on it.

**Complexity.** O((n + q) log n) with binary lifting. Values reach about 4·10¹⁰, so use `long long`.

**Check.** The path 1–2–3 gives 1 + 3 = 4 = (n − 1)². Random small trees were checked against an exact linear solve.

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q; scanf("%d %d", &n, &q);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) { int a, b; scanf("%d %d", &a, &b); g[a].push_back(b); g[b].push_back(a); }
    const int LG = 18;
    vector<array<int, LG>> up(n + 1);
    vector<int> dep(n + 1, 0), order, par(n + 1, 0);
    vector<long long> sub(n + 1, 1), U(n + 1, 0), D(n + 1, 0);
    order.reserve(n); vector<int> st = {1}; par[1] = 1;
    while (!st.empty()) { int x = st.back(); st.pop_back(); order.push_back(x);
        for (int y : g[x]) if (y != par[x]) { par[y] = x; dep[y] = dep[x] + 1; st.push_back(y); } }
    for (int i = n - 1; i > 0; i--) sub[par[order[i]]] += sub[order[i]];
    for (int x : order) {
        if (x != 1) { U[x] = U[par[x]] + 2 * sub[x] - 1; D[x] = D[par[x]] + 2 * (n - sub[x]) - 1; }
        up[x][0] = par[x]; for (int k = 1; k < LG; k++) up[x][k] = up[up[x][k - 1]][k - 1];
    }
    auto lca = [&](int a, int b) {
        if (dep[a] < dep[b]) swap(a, b);
        for (int k = LG - 1; k >= 0; k--) if (dep[a] - (1 << k) >= dep[b]) a = up[a][k];
        if (a == b) return a;
        for (int k = LG - 1; k >= 0; k--) if (up[a][k] != up[b][k]) a = up[a][k], b = up[b][k];
        return up[a][0];
    };
    while (q--) { int u, v; scanf("%d %d", &u, &v); int l = lca(u, v);
        printf("%lld\n", (U[u] - U[l]) + (D[v] - D[l])); }
}
```

### C3. Max of Different Uniforms

**Formula.** For M ≥ 0, E[M] = ∫₀^∞ P(M > t) dt = ∫₀^{max b} (1 − Π_i F_i(t)) dt, where F_i(t) = clamp((t − a_i)/(b_i − a_i), 0, 1).

**Segments.**
- Sort all endpoints. On each segment [L, R] between consecutive endpoints, every F_i is either 0, 1 or linear.
- If some F_i = 0 on the whole segment, the integrand is 1 and the segment contributes R − L.
- Otherwise Π F_i is a polynomial of degree d = the number of active (linear) factors.

**Exact numerical integration.** Gauss–Legendre with ⌊d/2⌋ + 1 nodes integrates a polynomial of degree d exactly.
- Evaluate the product directly at each node, so no polynomial coefficients are ever stored.
- There are O(n) segments, each needing O(n) nodes × O(n) factors: O(n³), about 2.7·10⁷ operations for n = 300.

**Trap.** Expanding the product into coefficients loses all precision.

**Check.** [0,1],[0,1] gives 2/3, and [0,1],[0,2] gives 13/12. Monte Carlo agreed on random inputs.

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n; vector<double> a(n), b(n); vector<double> pts;
    for (int i = 0; i < n; i++) { cin >> a[i] >> b[i]; pts.push_back(a[i]); pts.push_back(b[i]); }
    pts.push_back(0); sort(pts.begin(), pts.end()); pts.erase(unique(pts.begin(), pts.end()), pts.end());
    // Gauss-Legendre nodes, m points exact for degree 2m-1
    auto gl = [](int m) { vector<double> x(m), w(m);
        for (int i = 0; i < m; i++) { double z = cos(M_PI * (i + 0.75) / (m + 0.5)), pp;
            for (int it = 0; it < 100; it++) { double p1 = 1, p2 = 0; for (int j = 1; j <= m; j++) { double p3 = p2; p2 = p1; p1 = ((2 * j - 1) * z * p2 - (j - 1) * p3) / j; }
                pp = m * (z * p1 - p2) / (z * z - 1); double z1 = z; z = z1 - p1 / pp; if (fabs(z - z1) < 1e-15) break; }
            x[i] = z; w[i] = 2 / ((1 - z * z) * pp * pp); } return make_pair(x, w); };
    double E = 0;                                     // E[max] = integral over t >= 0 of (1 - prod F_i(t))
    for (size_t s = 0; s + 1 < pts.size(); s++) {
        double L = pts[s], R = pts[s + 1]; int deg = 0; bool zero = false;
        for (int i = 0; i < n; i++) { if (b[i] <= L) continue; if (a[i] >= R) { zero = true; break; } deg++; }
        if (zero) { E += R - L; continue; }           // some F_i = 0 on the whole segment
        auto [x, w] = gl(deg / 2 + 1);
        double I = 0;
        for (size_t k = 0; k < x.size(); k++) { double t = (L + R) / 2 + (R - L) / 2 * x[k], pr = 1;
            for (int i = 0; i < n; i++) if (b[i] > L) pr *= (t - a[i]) / (b[i] - a[i]);
            I += w[k] * (1 - pr); }
        E += I * (R - L) / 2;
    }
    printf("%.6f\n", E);
}
```

### C4. Bold Play

**Recursion.** With stake min(x, 1 − x):
- For x < ½: win → 2x, lose → 0. So Q(x) = p·Q(2x).
- For x ≥ ½: win → 1, lose → 2x − 1. So Q(x) = p + (1 − p)·Q(2x − 1).
- Boundaries: Q(0) = 0 and Q(1) = 1.

**Unrolling.** Each step maps x to 2x mod 1, i.e. it reads x's next binary digit, and adds p times a running multiplier when that digit is 1. So Q(x) = Σ_k p·Π(multipliers so far) over the 1-bits of x.

**Implementation.**
- Keep x = a/b exactly with integers: a ← 2a or 2a − b, which stays below 2·10⁹, so `long long` is enough.
- Stop when a = 0 (x hit 0 exactly) or when the multiplier drops below 1e-15.
- The multiplier shrinks by at least max(p, 1 − p) ≤ 0.99 per step, so about 3500 steps are enough. A fixed 60 iterations is wrong for p near 0.99.

**Check.** p = ½ gives Q(x) = x (a fair game). p = 0.4 with x = ¾ gives 0.4 + 0.6·0.4 = 0.64.

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    double p; long long a, b; char sl; cin >> p >> a >> sl >> b;
    // Q(x) = p Q(2x) (x < 1/2);  p + (1-p) Q(2x-1) (x >= 1/2).  Accumulate the linear chain.
    double ans = 0, mult = 1;
    for (int it = 0; it < 6000 && mult > 1e-15; it++) {
        if (a == 0) break;                            // Q(0) = 0
        if (2 * a < b) { mult *= p; a = 2 * a; }
        else { ans += mult * p; mult *= (1 - p); a = 2 * a - b; }
    }
    printf("%.6f\n", ans);
}
```

### C5. Many-way Penney

**Gambler argument.**
- Before each letter, a new gambler arrives for every pattern P_j. They bet $1 at fair odds (payout k) that the next letter is P_j's next letter, and keep doubling up.
- The casino's net gain is a martingale.
- When pattern P_i finishes the game, the P_j-gamblers still alive are exactly those whose bets so far spell a prefix of P_j that equals a suffix of P_i. The one who started L letters ago holds k^L.

**Linear system.**
- Define C(P_i, P_j) = Σ k^L over all L where the length-L suffix of P_i equals the length-L prefix of P_j.
- Optional stopping for the P_j-gamblers: Σ_i q_i · C(P_i, P_j) = E[T] for every j. Here q_i = P(P_i wins) and E[T] is the expected number of letters.
- Together with Σ q_i = 1 this gives n + 1 linear equations in n + 1 unknowns.

**Overlaps.** Compute the prefix function of `P_j + sep + P_i`. The border chain from the end lists every such L. Cost: O(|P_i| + |P_j|) per pair.

**Solve.** Gaussian elimination mod 998244353. O(n²·|P| + n³) in total.

**Check.** For HH vs TTT: C(HH,HH) = 2 + 4 = 6, C(TTT,TTT) = 2 + 4 + 8 = 14, and the cross terms are 0. So 6q₁ = 14q₂ = E and q₁ + q₂ = 1, which gives q₁ = 7/10 and E = 21/5. Random pattern sets were checked against an exact Markov-chain solve.

```cpp
#include <bits/stdc++.h>
using namespace std;
const long long M = 998244353;
long long pw(long long b, long long e) { long long r = 1; b %= M; while (e) { if (e & 1) r = r * b % M; b = b * b % M; e >>= 1; } return r; }
// sum of k^L over all L where the length-L suffix of s equals the length-L prefix of t
long long corr(const string& s, const string& t, long long k) {
    string z = t + '\x01' + s; int m = z.size(); vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) { int j = pi[i - 1]; while (j && z[i] != z[j]) j = pi[j - 1]; if (z[i] == z[j]) j++; pi[i] = j; }
    long long r = 0; for (int L = pi[m - 1]; L > 0; L = pi[L - 1]) r = (r + pw(k, L)) % M;
    return r;
}
int main() {
    int n; long long k; cin >> n >> k; vector<string> P(n); for (auto& s : P) cin >> s;
    // unknowns q_1..q_n, E :  sum_i q_i C(P_i,P_j) - E = 0 for each j;  sum_i q_i = 1
    int N = n + 1; vector<vector<long long>> A(N, vector<long long>(N + 1, 0));
    for (int j = 0; j < n; j++) { for (int i = 0; i < n; i++) A[j][i] = corr(P[i], P[j], k); A[j][n] = M - 1; }
    for (int i = 0; i < n; i++) A[n][i] = 1; A[n][N] = 1;
    for (int c = 0; c < N; c++) { int piv = c; while (!A[piv][c]) piv++; swap(A[piv], A[c]);
        long long inv = pw(A[c][c], M - 2); for (auto& v : A[c]) v = v * inv % M;
        for (int r = 0; r < N; r++) if (r != c && A[r][c]) { long long f = A[r][c]; for (int x = 0; x <= N; x++) A[r][x] = ((A[r][x] - f * A[c][x]) % M + M) % M; } }
    for (int i = 0; i < n; i++) printf("%lld\n", A[i][N]);
}
```

### C6. Longest Run

**Tail sum.** E[L] = Σ_{k=1}^{n} P(L ≥ k) = Σ_k (1 − g_k(n)), where g_k(i) = P(every run of H among the first i tosses is shorter than k).

**Recurrence.** Classify by the length j of the final run of H:
- If j < i: the last j tosses are H (probability pʲ), preceded by a T (1 − p), preceded by a valid string of length i − j − 1.
- If j = i: all i tosses are H. This is allowed only if i < k.
- So g_k(i) = (1 − p)·Σ_{j=0}^{k−1} pʲ·g_k(i − 1 − j) + [i < k]·pⁱ.

**Speed.** Keep a sliding window S = Σ_{j<k} pʲ·g(i − 1 − j). Update it as S ← p·S + g(i − 1) − pᵏ·g(i − 1 − k), which is O(1) per step. That is O(n) per k and O(n²) = 2.5·10⁷ in total.

**Check.** n = 3, p = ½ gives 11/8. Brute force over all 2ⁿ strings (n ≤ 10) agreed.

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; double p; cin >> n >> p;
    double E = 0;
    for (int k = 1; k <= n; k++) {                    // E = sum_k P(longest >= k) = sum_k (1 - P(all runs < k))
        vector<double> g(n + 1); g[0] = 1;
        double S = 0;                                 // S = sum_{j=0}^{k-1} p^j g[i-1-j]
        double pk = pow(p, k);
        for (int i = 1; i <= n; i++) {
            S = S * p + g[i - 1];                     // shift window: add j = 0 term
            if (i - 1 - k >= 0) S -= pk * g[i - 1 - k];
            g[i] = (1 - p) * S + (i < k ? pow(p, i) : 0);   // last run of H has length j; or all H
        }
        E += 1 - g[n];
    }
    printf("%.6f\n", E);
}
```

---

## Paper 2 — Relay

**R1 = 20.**
- Casino argument: before each toss a new gambler bets $1 on HTHT, doubling on every correct letter.
- Every bet is fair, so E[money paid out] = E[money taken in] = E[T].
- When HTHT completes, the gamblers still alive are those whose letters so far form a prefix of HTHT that is also a suffix of HTHT: HT (holding 2² = 4) and HTHT (holding 2⁴ = 16).
- E[T] = 4 + 16 = **20**.

**R2 = 41.**
- n = 20/4 = 5.
- Derangements: D₅ = 5!(1 − 1 + 1/2! − 1/3! + 1/4! − 1/5!) = 120 − 120 + 60 − 20 + 5 − 1 = 44.
- P = 44/120 = 11/30 (gcd 4), so p + q = **41**.

**R3 = 720.**
- n = 41 − 36 = 5.
- All different: 6 choices for the first die, 5 for the second, …, 2 for the fifth: 6·5·4·3·2 = **720**.

**R4 = 30.**
- 720 = 2⁴·3²·5, so the number of divisors is (4+1)(2+1)(1+1) = **30**.

**R5 = 7.**
- k = 30/10 = 3.
- After the first toss, track r = the length of the current run of equal faces.
- Each toss either extends the run (probability ½) or starts a new run of length 1 (probability ½).
- Let E_r = the expected number of further tosses from run length r, with E₃ = 0:
  - E₂ = 1 + ½·E₃ + ½·E₁ = 1 + ½E₁
  - E₁ = 1 + ½E₂ + ½E₁
- So ½E₁ = 1 + ½(1 + ½E₁) = 3/2 + ¼E₁, which gives ¼E₁ = 3/2 and E₁ = 6.
- Adding the first toss: 1 + 6 = **7**.
- (The general answer is 2ᵏ − 1. The trap is "k heads in a row", which gives 2^(k+1) − 2 = 14.)

**R6 = 42.**
- A total of 7 has probability p = 6/36 = 1/6 per roll.
- States: 0 = the last roll was not a 7 (or no roll yet); 1 = the last roll was a 7.
  - e₀ = 1 + p·e₁ + (1 − p)·e₀
  - e₁ = 1 + p·0 + (1 − p)·e₀
- Substitute the second into the first: p·e₀ = 1 + p(1 + (1 − p)·e₀). So p·e₀ − p(1 − p)·e₀ = 1 + p, i.e. p²·e₀ = 1 + p.
- e₀ = (1 + p)/p² = (7/6)·36 = **42**.

**R7 = 14.**
- n = 42/6 = 7. There are C(7,3) = 35 triangles.
- A triangle misses the centre exactly when its three vertices lie within a half-circle. For odd n no two vertices are diametrically opposite, so this is unambiguous.
- Count the bad triangles by their first vertex v, going clockwise: the other two must lie among the next (n − 1)/2 = 3 vertices, so C(3,2) = 3 choices. Each bad triangle has exactly one such first vertex.
- Bad = 7·3 = 21, so good = 35 − 21 = **14**.

**R8 = 429.**
- T/2 = 7, and C₇ = C(14,7)/8 = 3432/8 = **429**.

**R9 = 7129.**
- n = 429 mod 10 = 9.
- The i-th value is a record exactly when it is the largest of the first i values; by symmetry that has probability 1/i.
- By linearity, E = H₉ = 1 + 1/2 + … + 1/9 = 7129/2520, so p = **7129**.

**R10 = 10.**
- m = 7129 mod 100 = 29. The primes ≤ 29 are 2, 3, 5, 7, 11, 13, 17, 19, 23, 29: **10**.

**R11 = 55.**
- a = 10 − 7 = 3 and b = 10/2 = 5. By Paper 3 Q8 below, E[T | stop at +5] = 55/3.
- 3 × 55/3 = **55**.

**R12 = 147.**
- k = 55 mod 7 = 6.
- With j faces already seen, each roll shows a new face with probability (6 − j)/6, so that stage lasts 6/(6 − j) rolls on average.
- Total = 6/6 + 6/5 + 6/4 + 6/3 + 6/2 + 6/1 = 6·H₆ = 14.7, and 10 × 14.7 = **147**.

---

## Paper 3 — Written

### Q1 (a) = 20
- Casino argument, as in R1. The gamblers alive at the end are those whose played letters are both a prefix and a suffix of HTHT: L = 2 (HT) and L = 4.
- E = 2² + 2⁴ = **20**.

### Q1 (b) = 15
- **States** are the longest ending of the tosses so far that is still the start of one of the patterns: ∅, H, T, HT, TH, HTH, THT.
- **Transitions:**

  | State | Toss H | Toss T |
  |---|---|---|
  | H | H | HT |
  | HT | HTH | T |
  | HTH | H | done (HTHT) |
  | T | TH | T |
  | TH | H | THT |
  | THT | done (THTH) | T |

  - Why HT + T → T: HTT has no ending that starts HTHT except "T", which starts THTH.
  - Why HTH + H → H: the only useful ending of HTHH is H.
- **Symmetry.** Swapping H and T swaps the two patterns, so e_H = e_T = a, e_HT = e_TH = b, and e_HTH = e_THT = c.
- **Equations** (each toss costs 1):
  - a = 1 + ½a + ½b
  - b = 1 + ½c + ½a
  - c = 1 + ½·0 + ½a
- **Solve:**
  - From the first: ½a = 1 + ½b, so a = 2 + b.
  - Substitute c into the second: b = 1 + ½(1 + ½a) + ½a = 3/2 + ¾a.
  - Then a = 2 + 3/2 + ¾a, so ¼a = 7/2 and a = 14.
- e_∅ = 1 + a = **15**. (Not 20/2: the two patterns share their "middle".)

### Q2 (a) = 11/16
- n pieces form a polygon exactly when every piece is shorter than ½ (the polygon inequality).
- A particular piece is ≥ ½ with probability (1/2)^(n−1): all n − 1 cut points must avoid a half-length region.
- At most one piece can be ≥ ½, so these events are disjoint and P(fail) = n·(1/2)^(n−1).
- n = 5: P = 1 − 5/16 = **11/16**.

### Q2 (b) = 25/48
- **Representation.** Let E₁, …, E_n be iid Exp(1) and S = their sum. The n pieces have the same joint law as (E₁/S, …, E_n/S), and this vector is independent of S.
- **Sorting.** Write the sorted exponentials in decreasing order: E_(1) ≥ … ≥ E_(n). By memorylessness, the gaps between consecutive order statistics are independent exponentials, and E[E_(1)] = 1/1 + 1/2 + … + 1/n = H_n.
- **Longest piece.** It equals E_(1)/S. By independence, E[E_(1)] = E[E_(1)/S]·E[S], so E[longest] = H_n/n.
- n = 4: (1/4)(1 + 1/2 + 1/3 + 1/4) = (1/4)(25/12) = **25/48**.

### Q3 (a) = 30 minutes
- By memorylessness, the time back to the previous bus and the time forward to the next bus are independent Exp(λ), each with mean 1/λ.
- The gap containing you has mean 2/λ = 2/4 h = **30 min**.
- This is the inspection paradox: long gaps are more likely to contain you, so the gap you see is length-biased. Its density is λ²x·e^(−λx).

### Q3 (b) = 7.5
- Thinning: VIP calls form a Poisson(1.5/h) process and non-VIP calls a Poisson(3.5/h) process, and the two are **independent**.
- So given 4 VIP calls, the non-VIP count is still Poisson(3.5), and E[total] = 4 + 3.5 = **7.5**.

### Q4 (a) = 3/4
- (X, Y) is rotationally symmetric, so the probability of a wedge is its angle divided by 360°.
- {X > 0} is the angles (−90°, 90°). {X > Y} is the angles (−135°, 45°). Their intersection is (−90°, 45°): 135°.
- P(X > Y, X > 0) = 135/360 = 3/8, and P(X > 0) = 1/2.
- Conditional: (3/8)/(1/2) = **3/4**.

### Q4 (b) = 3/(2√π) ≈ 0.846
- By symmetry E[max] = 3·E[X·1{X > Y, X > Z}] = 3∫ x·φ(x)·Φ(x)² dx.
- Integrate by parts using x·φ(x) = −φ′(x): ∫ x·φ·Φ² dx = ∫ φ(x)·2Φ(x)φ(x) dx = 2∫ φ(x)²Φ(x) dx.
- φ(x)² = e^(−x²)/(2π) = (1/(2√π))·g(x), where g is the N(0, ½) density.
- ∫ g(x)Φ(x) dx = P(Z ≤ W) for independent Z ~ N(0,1) and W ~ N(0,½). Z − W is symmetric about 0, so this is ½.
- So E[max] = 3·2·(1/(2√π))·½ = **3/(2√π)**. A simulation gives 0.8456.

### Q5 (a) = 49/4
- The dice are independent, so E[ab] = E[a]·E[b] = 3.5² = **12.25**.

### Q5 (b) = 617/36 ≈ 17.14
- Let m ≤ M be the two faces.
  - Keep both: payoff mM.
  - Reroll the smaller die: expected payoff 3.5·M. (Rerolling the larger die is never better.)
- Reroll exactly when m < 3.5, i.e. m ≤ 3.
- The 27 ordered pairs with min ≤ 3 have Σ max = 112, contributing 3.5 × 112 = 392.
- The 9 pairs with both faces in {4, 5, 6} contribute (4 + 5 + 6)² = 225.
- E = (392 + 225)/36 = **617/36**.

### Q6 = H₁₀₀ − 1/100 ≈ 5.1774
- **Passenger 1** is misplaced unless they happen to pick seat 1: probability 99/100.
- **Passenger j ≥ 2** (n = 100):
  - When j boards, seats 2, …, j − 1 are all taken. Every earlier passenger either sat in their own seat or found it taken.
  - So exactly j − 1 seats are taken, all of seats 2..j − 1 among them. That leaves exactly one taken seat among the n − j + 2 seats {1, j, j+1, …, n}.
  - Every random choice so far treated those seats symmetrically, so that taken seat is equally likely to be any of them.
  - P(seat j is taken) = 1/(n − j + 2).
- **Linearity:**
  - E = (n − 1)/n + Σ_{j=2}^{n} 1/(n − j + 2)
  - The sum is 1/n + 1/(n−1) + … + 1/2 = H_n − 1, so E = 1 − 1/n + H_n − 1 = H_n − 1/n.
- n = 100: H₁₀₀ ≈ 5.18738, so E ≈ **5.1774**. A simulation agrees.

### Q7: final total 100, with P ≈ 0.2857
- The final total is s + d, where s ∈ {94, …, 99} is the last total below 100 and d is the final roll.
- A final total of 100 + j (j = 0, …, 5) needs s ≥ 94 + j followed by the exact roll: 6 − j possible values of s, each finished by probability 1/6.
- Far from the start, the chance that the running total ever equals a given s is ≈ 1/(mean roll) = 1/3.5 = 2/7 (the renewal theorem).
- So P(100 + j) ≈ (6 − j)·(2/7)·(1/6) = (6 − j)/21: 6/21, 5/21, …, 1/21. **100 is most likely**, with P ≈ 2/7 ≈ **0.2857**.
- The exact dynamic program over totals gives 0.28571 to 5 decimals. The error from the "far from the start" approximation is below 10⁻¹⁰ by 100.

### Q8 = 55/3
- **Setup.** Let y = distance above −3, so y runs from 0 to N = 8 and the walk starts at y = 3.
- P(stop at the top | at y) = h(y) = y/N (fair gambler's ruin).
- **Conditioned walk.** Given that it stops at the top, the walk moves y → y ± 1 with probabilities h(y ± 1)/(2h(y)). This is Doob's h-transform: Bayes applied to one step.
- **Equation.** Let m(y) = E[steps | stop at the top]:
  - m(y) = 1 + [(y − 1)·m(y − 1) + (y + 1)·m(y + 1)]/(2y), with m(N) = 0.
- **Guess** m(y) = (N² − y²)/3. Checking the right-hand side:
  - (y − 1)(N² − (y − 1)²) + (y + 1)(N² − (y + 1)²) = 2yN² − 2y³ − 6y
  - Dividing by 6y gives (N² − y² − 3)/3.
  - Adding 1 gives (N² − y²)/3 ✓. Also m(N) = 0 ✓.
- **Answer.** m(3) = (64 − 9)/3 = **55/3** ≈ 18.33.
- The trap: the unconditional E[T] = 3·5 = 15.
