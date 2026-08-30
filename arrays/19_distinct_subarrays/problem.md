# Distinct Subarrays

Link: CSES 2428
Pattern: same duplicate-free window as Playlist, but accumulate
head-tail+1 (subarrays starting at tail) every outer step instead of
tracking the max
Time: O(n log n)  Space: O(n)

## Statement

Count subarrays where every element is distinct.

## Examples

    1 2 1 3 -> 8

## Recall Trail

- Identical window mechanics to `arrays/16_playlist` (freq map, tail/head,
  extend head while next element isn't already in the window).
- The only change: instead of `ans = max(ans, head-tail+1)`, accumulate
  `ans += head-tail+1` every outer iteration. For the current `tail`, this
  counts every valid subarray *starting* at `tail` (right endpoint
  anywhere from `tail` to the current maximal `head`) — summing across all
  `tail` values (each visited exactly once, `head` only ever moving
  forward) covers every valid subarray exactly once, no double-counting.
- Don't reach for a `nC2`-style combinatorial formula here — it's a
  fixed-one-endpoint counting problem, not a "choose k from n" one.
