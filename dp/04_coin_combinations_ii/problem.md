# Coin Combinations II

Link: https://cses.fi/problemset/task/1636
Pattern: 1D bottom-up DP, order-doesn't-matter counting, unbounded reuse
Time target: O(n*x)  Space target: O(x)

Count the distinct *combinations* (order doesn't matter) that produce sum
`x` from `n` reusable coin values — `2+2+5` and `2+5+2` are the same
combination, counted once. Answer modulo 10^9+7.

Constraints: 1 <= n <= 100, 1 <= x <= 10^6, 1 <= c_i <= 10^6

## Recall Trail

**Approach:** contrast with `dp/03_coin_combinations_i` (permutations —
loop `sum` outer, `coins` inner, `dp[sum] = Σ_c dp[sum-c]`). Here, loop
**coins outer, sum inner**: `dp[sum] += dp[sum-c]` per coin, sweeping sum
ascending within each coin's pass. This fixes a canonical order over coin
*types* (all uses of coin 1 folded in before coin 2 is ever considered),
which is exactly what collapses every permutation of a multiset into one
count.

**Decision points:**
- Natural formulation is 2D: `rec(i, left) = rec(i, left-c[i])` (take,
  stay on `i` — unbounded reuse) `+ rec(i+1, left)` (skip, advance).
  Needs the coin-index dimension `i`, unlike the minimizing/permutation
  variants where that dimension collapses away trivially.
- Iterative 2D (`dp[i][sum]`) is not just inelegant here — at
  `n=100, x=1e6` a `(n+1)x(x+1)` `ll` table is ~808MB, over the 512MB
  limit. Space reduction is required, not optional.
- Rolling 2-row version needs an explicit baseline copy
  (`dp[cur] = dp[prev]`) before folding in each coin — that copy *is* the
  "skip this coin" case, made explicit.
- The copy is a no-op with a single array: `dp[sum]` already holds the
  "before this coin" baseline in place. That's why full 1D collapse works
  and coin *processing order* is irrelevant — each coin just folds into
  the same running array once, regardless of which coin is folded in
  first.
- Loop direction within a coin's pass: `sum` ascending (`c` to `x`), same
  direction as unbounded knapsack — lets `dp[sum-c]` already reflect this
  same coin reused earlier in this pass.
- Base case `dp[0] = 1`, same identity as the permutations variant.
