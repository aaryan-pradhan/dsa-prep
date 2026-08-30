# Coin Combinations I

Link: https://cses.fi/problemset/task/1635
Pattern: 1D bottom-up DP, order-matters counting, unbounded reuse
Time target: O(n*x)  Space target: O(x)

Count the distinct ordered ways to produce sum `x` from `n` reusable coin
values (order matters — 2+2+5, 2+5+2, 5+2+2 count separately). Answer
modulo 10^9+7.

Constraints: 1 <= n <= 100, 1 <= x <= 10^6, 1 <= c_i <= 10^6

## Recall Trail

**Approach:** merge of `dp/01_dice_combinations` (order matters -> sum
over choices) and `dp/02_minimizing_coins` (arbitrary reusable coin set,
no index dimension needed). `dp[sum] = sum over coins c of dp[sum-c]`.

**Decision points:**
- Base case `dp[0] = 1` (not `0`) — same gotcha as dice combinations:
  with `dp[0]=0`, `dp[c]` for a lone coin value `c` would wrongly compute
  to 0 instead of 1.
- Guard `sum - c >= 0` before accumulating.
- `dp[sum] = madd(dp[sum], dp[sum-c])` per coin, accumulated across all
  coins in the inner loop — reuses `madd` from `dp/01_dice_combinations`.

Contrast with `dp/02_minimizing_coins`: same "loop over all coins per
sum" shape, but that one takes `min(...)+1` (unbounded reuse, order
doesn't matter, minimizing), this one takes `sum via madd` (order
matters, counting all ways). See patterns.md for both variants side by
side.
