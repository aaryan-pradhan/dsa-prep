# Collecting Numbers

Link: CSES 2216
Pattern: position array, count rounds by adjacency breaks
Time: O(n)  Space: O(n)

## Statement

Repeatedly sweep left-to-right, each round collecting numbers in
increasing order as far as the sweep gets them contiguously. Count rounds
needed to collect 1..n.

## Examples

    4 2 1 5 3 -> 3

## Recall Trail

- Build `pos[]`: index of each value in the array. Values `i-1` and `i`
  are collectible in the same round iff `pos[i-1] < pos[i]` (i appears
  later in the array, reachable in the same left-to-right sweep after
  i-1). If `pos[i] < pos[i-1]`, a new round is forced.
- Answer = `1 + (count of i in 2..n where pos[i] < pos[i-1])` — start at 1
  round for the first value, add one for each break.
