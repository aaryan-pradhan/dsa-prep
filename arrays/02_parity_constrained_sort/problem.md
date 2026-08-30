# Parity-Constrained Sort (Boys/Girls Line)

Link: (pasted, no URL given)
Pattern: split by parity, sort each group, re-merge on a second pass keyed
on the same parity check
Time: O(N log N) per test case  Space: O(N)

## Statement

T test cases. Each has N integers. Only same-parity elements may be
swapped with each other (evens with evens, odds with odds). Output the
permutation closest to fully non-decreasing achievable under that
constraint. Multiple answers accepted if tied.

## Examples

    [2,3,9,1,2,7] -> [2,1,3,7,2,9]
    [4,2,8]       -> [2,4,8]

## Recall Trail

- Same-parity swaps mean any permutation *within* a parity class is
  reachable, but nothing crosses classes — a position that started even
  can never end up odd. So the fixed structure is "which positions belong
  to which class," not the values themselves.
- Within each class, full freedom → sort that class ascending eliminates
  all inversions inside it; cross-class inversions are unavoidable
  regardless of internal order, so sorting each class is optimal.
- Don't store index/position arrays. Two passes over the same array:
  pass 1 buckets values into `evens`/`odds` by `a[i]%2`; sort both; pass 2
  re-checks `a[i]%2` (same test, not stored) to decide which sorted
  bucket's next value to overwrite `a[i]` with, via two pointers
  (`ei`, `oi`). No map, no stored positions — the parity check itself is
  cheap enough to just redo.
- Naturally handles all-even / all-odd arrays with no special-casing — one
  bucket just stays empty and its pointer is never advanced.
