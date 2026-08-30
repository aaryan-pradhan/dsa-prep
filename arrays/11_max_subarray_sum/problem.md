# Maximum Subarray Sum

Link: CSES 1643
Pattern: Kadane's — running best-ending-here, extend or restart at each element
Time: O(n)  Space: O(1)

## Statement

Max sum of a contiguous nonempty subarray.

## Examples

    -1 3 -2 5 3 -5 2 2 -> 9   (subarray [3, -2, 5, 3])

## Recall Trail

- At each element decide: extend the running sum, or abandon it and start
  fresh here — `cur = max(x[i], cur + x[i])`.
- Track `best` separately from `cur` (`best = max(best, cur)`) since the
  optimal subarray doesn't have to end at the last index scanned.
- Init both `cur` and `best` to `x[0]`, not `0` — subarray must be
  nonempty, so an all-negative array must still return its least-negative
  single element, not `0`.
