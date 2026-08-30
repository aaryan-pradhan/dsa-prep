# Josephus Queries (children in a circle)

Link: CSES 2163
Pattern: segment tree order-statistics query — find the k-th alive
element by rank in O(log n), instead of O(n) list simulation
Time: O(n log n)  Space: O(n)

## Statement

n children in a circle, indices 1..n. Repeatedly skip k, remove the next
child. Print the removal order. n up to 2e5, k up to 1e9.

## Examples

    n=7, k=2 -> 3 6 2 7 5 1 4

## Recall Trail

- Direct circular-list simulation is O(n) per removal worst case (k can
  be far larger than n, forcing a full lap or more), O(n^2) total — too
  slow. Need O(log n) per removal.
- Segment tree over an array of 1s (alive)/0s (removed), node.sum = count
  of alive in that range. `findKth(k)` descends from the root: if the left
  child's sum >= k, the answer is in the left half (recurse left, same
  k); else recurse right with `k -= leftChild.sum` (skip past everything
  already counted on the left). O(log n), one path down, no backtracking.
- Recurrence for which *rank* (not position) gets removed each step:
  track `idx` (the rank, among current survivors, "just after" the last
  removal) and `rem` (survivor count). `nextRank = (idx + k) % rem + 1`;
  removed position = `findKth(nextRank)`. After removing: `idx =
  nextRank - 1`, `rem--` — the removed rank becomes the new "just after"
  pointer for the shrunk survivor set, since everyone past it shifts down
  by one rank.
- See `templates/segment_tree.cpp` for the reusable structure — this repo
  standardizes on segment tree over Fenwick tree/BIT for this family of
  problems (point-update + order-statistics), since a segment tree covers
  everything a BIT does plus range queries, with one structure to
  remember instead of two.
