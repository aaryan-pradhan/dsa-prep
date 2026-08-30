# Dice Combinations

Link: https://cses.fi/problemset/task/1633
Pattern: 1D bottom-up DP
Time target: O(n)  Space target: O(n)

Count the number of ways to construct sum `n` by throwing a dice one or
more times, each throw producing an outcome between 1 and 6. Order
matters (1+2 and 2+1 are distinct). Answer modulo 10^9+7.

Constraints: 1 <= n <= 10^6

## Recall Trail

**Approach:** `dp[i]` = number of ways to make sum `i`. Since order
matters, the last throw is some `k` in `1..6`, so `dp[i] = sum(dp[i-k])`
for all valid `k`.

**Decision points:**
- Base case: `dp[0] = 1` (empty throw sequence makes sum 0) — not
  `dp[0] = 0`. Seeding it this way lets the *same* recurrence produce
  `dp[1]=1, dp[2]=2, dp[3]=4` with no hardcoded exceptions for small `i`.
- Bound check: `i - k >= 0` guards each term before adding, since `k` can
  exceed `i` for small `i`.
- Mod arithmetic: `madd(a,b) = (a%MOD + b%MOD) % MOD` — repo's modular
  helper set didn't have an addition helper yet (only `mmul`/`msub`/
  `mpow`/`minv`/`mdiv`/`mcorr`), added here.
