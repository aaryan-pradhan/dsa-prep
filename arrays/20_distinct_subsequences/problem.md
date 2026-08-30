# Distinct Subsequences

Link: CSES 2429
Pattern: per-value option counting — a value with frequency f has (f+1)
independent options (exclude, or include one of its f occurrences);
multiply across distinct values, subtract 1 for the empty subsequence
Time: O(n log n)  Space: O(n)

## Statement

Count subsequences (not necessarily contiguous) where every element is
distinct, modulo 1e9+7.

## Examples

    1 2 1 3 -> 11

## Recall Trail

- Contiguity doesn't matter here (unlike `arrays/19_distinct_subarrays`),
  so the two-pointer window approach doesn't apply at all — different
  problem shape despite the similar name.
- A value can appear at most once in any valid subsequence. For a value
  with frequency `f`, the real option set is: exclude it, or include
  exactly one of its `f` occurrences — `f+1` mutually exclusive options
  (not `2^f`, which would treat occurrence choices as independent bits
  and overcount by allowing multiple occurrences "on" at once).
- Options for different distinct values are independent, so total
  combinations = `Π (freq[v] + 1)` over distinct values `v`. This counts
  every subsequence exactly once, including the empty one (every value
  excluded) — subtract 1 for the final answer.
- Modular arithmetic helpers (`mmul`, `msub`, `mcorr` — apply `mcorr` once
  at the very end to fix up a possibly-negative result from `msub`) are
  the standing template for any mod-1e9+7 problem in this repo.
