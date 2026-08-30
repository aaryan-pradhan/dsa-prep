# Dynamic Range Sum Queries

Link: CSES 1648
Pattern: segment tree, same as templates/segment_tree.cpp — point
update (set, not add) + range sum query
Time: O((n + q) log n)  Space: O(n)

## Statement

Array supports point updates (set position k to u) interleaved with range
sum queries.

## Examples

    3 2 4 5 1 1 5 3, sum(1,4)=14, sum(5,6)=2, set(3,1), sum(1,4)=11

## Recall Trail

- Direct application of `templates/segment_tree.cpp` unmodified (sum
  merge, `update` sets — not adds — a position's value). No adaptation
  needed beyond wiring up the two query types.
- 1-indexed queries (`k`, `a`, `b`) map to 0-indexed tree positions via
  `-1`, same convention as `arrays/23_static_range_minimum_queries`.
