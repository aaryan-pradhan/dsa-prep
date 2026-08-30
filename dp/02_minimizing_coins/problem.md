# Minimizing Coins

Link: https://cses.fi/problemset/task/1634
Pattern: 1D bottom-up DP, unbounded reuse
Time target: O(n*x)  Space target: O(x)

Produce sum `x` from `n` coins (positive integer values, each reusable any
number of times) using the minimum number of coins. Print -1 if
impossible.

Constraints: 1 <= n <= 100, 1 <= x <= 10^6, 1 <= c_i <= 10^6

## Recall Trail

**Approach:** started from a 2D memoized recursion `rec(i, left)`
(min coins to make `left` using only coins from index `i` onward, `i`
staying fixed on take = reuse, advancing on skip). Converged that this
works but wastes memory/time (~10^8 states) and, if implemented as actual
recursion, would blow the stack at `x` up to 10^6.

**Decision points:**
- The `i` index tracks "is this coin still allowed" — meaningful in 0/1
  knapsack (finite supply) but redundant here since *every* coin is legal
  at *every* state regardless of history. Collapsed the 2D
  `rec(i,left)` into 1D `dp[left]` by replacing "skip coin i / take coin
  i" branches with one loop over *all* coin values per state:
  `dp[left] = min over coins c<=left of dp[left-c]+1`.
- Base case `dp[0] = 0` (zero coins for sum zero) — the identity that
  makes `+1` count correctly when `left-c` lands exactly on it.
- Sentinel: init `dp[1..x] = INF` (1e9), skip a candidate if
  `dp[left-c] == INF` (infeasible sub-result) so `INF+1` never gets
  mistaken for a real answer. Output `-1` if `dp[x]` stays `INF`.
- Bottom-up loop (not top-down recursion) to avoid stack depth ~`x` =
  10^6.

See also `dp/01_dice_combinations` — same "1D bottom-up, sum/min over
prior states" family, but that one sums over a *fixed* window (dice faces
1-6, order matters) while this one takes a *min* over an arbitrary coin
set (order doesn't matter, unbounded reuse).
