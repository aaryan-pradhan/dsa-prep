# Beautiful Permutation

Link: CSES 1070
Pattern: split by parity — evens ascending then odds ascending, so within
each half consecutive prints differ by 2, and the halves' boundary values
(largest even, 1) are far apart
Time: O(n)  Space: O(n) for output buffer

## Statement

Permutation of 1..n with no adjacent elements differing by exactly 1.
Print any valid one, or "NO SOLUTION" if none exists.

## Examples

    5 -> 4 2 5 3 1   (any valid beautiful permutation accepted)

## Recall Trail

- Impossible only for n == 2 and n == 3 — checked all permutations by hand,
  every arrangement has some adjacent diff of 1. n == 1 is trivially fine
  (no adjacent pair to violate) despite looking like a small-n edge case.
- Construction for everything else: print all even numbers ascending, then
  all odd numbers ascending. Within a half, consecutive values differ by 2.
  At the boundary (largest even -> 1), the gap is always large enough once
  n >= 4.
