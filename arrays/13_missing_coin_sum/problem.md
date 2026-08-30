# Missing Coin Sum

Link: CSES 1745
Pattern: sort ascending, greedily extend the contiguous achievable-sum
range [0, R]; a coin x extends it iff x <= R+1, else R+1 is the answer
Time: O(n log n)  Space: O(n)

## Statement

Smallest positive sum not formable as a subset sum of the given coins.

## Examples

    2 9 1 2 7 -> 6

## Recall Trail

- Sort coins ascending. Invariant: after processing some prefix, every sum
  in `[0, R]` is achievable.
- Next coin `x` extends the range iff `x <= R+1` (equality included — `x ==
  R+1` still closes the gap, since `[0,R] ∪ {R+1..R+1+x}` stays
  contiguous). If `x > R+1`, `R+1` is unreachable and nothing after it
  (all sorted larger) can fix that — answer is `R+1`, stop immediately.
- If the loop finishes without a gap, all coins summed and `R+1` is still
  the answer (the range covers everything the coins can build).
