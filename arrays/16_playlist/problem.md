# Playlist

Link: CSES 1141
Pattern: two-pointer window (tail/head), freq map keeps window duplicate-free
Time: O(n log n)  Space: O(n)

## Statement

Longest contiguous subsequence with no repeated song id.

## Examples

    1 2 1 3 2 7 4 2 -> 5   (window: 1 3 2 7 4)

## Recall Trail

- Two-pointer window: `tail`/`head`. Inner loop extends `head` while the
  next song isn't already in the window (`freq[a[head+1]] == 0`),
  incrementing its freq as it's absorbed.
- Answer is `max(ans, head-tail+1)` every outer iteration, **not** `ans +=
  ...` — that `+=` form belongs to "count all valid subarrays" problems;
  this one wants the single longest window.
- Shrink step: decrement `freq[a[tail]]`, `tail++` — this is what makes
  room for the next repeat once the window is maximal.
- Used `map` instead of `unordered_map` for the frequency table — CSES's
  anti-hash test targets `unordered_map` on plain int keys (see
  `arrays/07_distinct_values`), and `map`'s O(log n) is cheap enough at
  n <= 2e5.
