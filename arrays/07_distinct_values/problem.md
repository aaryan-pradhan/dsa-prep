# Distinct Values

Link: CSES 1621
Pattern: dump into a set, count size
Time: O(n log n)  Space: O(n)

## Statement

Count distinct values in a list of n integers.

## Examples

    2 3 2 2 3 -> 2

## Recall Trail

- First pass used `unordered_set` — TLE'd on CSES's final test case.
  CSES includes an anti-hash test targeting the default `unordered_set`/
  `unordered_map` hash on integers, forcing collisions and O(n) per op.
  Fixed by sorting instead: count runs of equal adjacent values after
  `sort()`. Immune to adversarial input, same O(n log n).
