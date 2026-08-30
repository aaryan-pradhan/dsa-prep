# Dynamic Range Minimum Queries

Link: CSES 1649
Pattern: segment tree, same as templates/segment_tree.cpp — point
update (set) + range min query, merge/identity swapped for min
Time: O((n + q) log n)  Space: O(n)

## Statement

Array supports point updates (set position k to u) interleaved with range
minimum queries.

## Examples

    3 2 4 5 1 1 5 3, min(1,4)=2, min(5,6)=1, set(2,3), min(1,4)=3

## Recall Trail

- Straight combination of `arrays/23_static_range_minimum_queries`'s
  min-merge/infinity-identity and `arrays/24_dynamic_range_sum_queries`'s
  update support — no new decision points.
