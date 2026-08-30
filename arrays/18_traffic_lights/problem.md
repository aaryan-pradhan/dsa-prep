# Traffic Lights

Link: CSES 1163
Pattern: set of boundary positions (with 0, x sentinels) for
predecessor/successor lookup, multiset of gap lengths for O(1) max
Time: O(n log n)  Space: O(n)

## Statement

Street `0..x`, lights added one at a time at distinct positions. After
each addition, print the longest gap with no light.

## Examples

    x=8, lights 3 6 2 -> 5 3 3

## Recall Trail

- Two containers, different jobs: `set<long long> positions` (seeded with
  sentinels `0, x`) for O(log n) predecessor/successor of a new light —
  `set` because positions are distinct; `multiset<long long> gaps` for
  O(1) max via `*gaps.rbegin()` — `multiset` because gap *lengths* can
  repeat.
- Inserting `p`: `lower_bound(p)` in `positions` gives the boundary just
  above (`hi`); `prev()` of that iterator gives the boundary just below
  (`lo`). The destroyed gap is `hi - lo`; the two new ones are `p - lo`
  and `hi - p`.
- Must erase the destroyed gap by iterator (`gaps.erase(gaps.find(hi -
  lo))`), not by value (`gaps.erase(hi - lo)`) — the value form deletes
  every gap of that length, not just the one that broke.
- Variable named `prev` collided with `std::prev` — renamed to `lo`/`hi`.
