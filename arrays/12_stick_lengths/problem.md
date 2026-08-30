# Stick Lengths

Link: CSES 1074
Pattern: sort, target = median, sum absolute deviations
Time: O(n log n)  Space: O(n)

## Statement

Minimum total cost to make all sticks equal length, cost per stick =
|new - old|.

## Examples

    2 3 1 5 2 -> 5

## Recall Trail

- Minimizing `Σ|p_i - m|` over `m` is minimized at the median — proved via
  pairing smallest with largest after sorting: each pair `(p_i,
  p_{n+1-i})` forces `m` into `[p_i, p_{n+1-i}]` to hit that pair's lower
  bound `p_{n+1-i}-p_i`, these intervals nest, and their intersection is
  exactly the median (a point if n odd, a range if n even — either
  endpoint of that range works since sticks are integers, no averaging
  needed).
- Implementation: sort, take `p[n/2]` as the target (works for both parities
  since any median value in the tie range gives the same minimal cost), sum
  `abs(p[i] - median)`.
