# Static Range Minimum Queries

Link: CSES 1647
Pattern: segment tree, same template as templates/segment_tree.cpp,
merge swapped to min (identity = +infinity instead of 0)
Time: O((n + q) log n)  Space: O(n)

## Statement

Array never changes; answer q range-minimum queries.

## Examples

    3 2 4 5 1 1 5 3, query (2,4) -> 2, (5,6) -> 1, (1,8) -> 1, (3,3) -> 4

## Recall Trail

- Same segment tree shape as `templates/segment_tree.cpp` — only `merge`
  changes (`min` instead of `+`), and the node's default/identity value
  changes correspondingly (`+infinity`, not `0` — a "no overlap" query
  node must not affect a `min` merge the way `0` doesn't affect a sum).
- Array is static (no updates), so `update`/`findKth` are dropped
  entirely — only `build` + `query` are needed here.
- Queries are 1-indexed (`a,b` from input); tree is built 0-indexed
  (`[0, n-1]`), so pass `a-1, b-1` into `query`.
