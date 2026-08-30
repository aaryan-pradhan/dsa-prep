# Increasing Array

Link: CSES 1094
Pattern: single-pass greedy — track running previous (post-adjustment), pay the shortfall
Time: O(n)  Space: O(1)

## Statement

Only allowed move: increase any element by 1. Minimum total moves to make
the array non-decreasing.

## Examples

    3 2 5 1 7 -> 5

## Recall Trail

- Compare each element to the *running* previous value (after any bumps
  already applied), not the original array's previous value — a bumped
  element raises the floor for everything after it.
- If `x[i] < prev`, pay `prev - x[i]` and leave `prev` unchanged (x[i] is
  now conceptually `prev`). Else `prev = x[i]` (no cost, new floor).
- Cost accumulates in `long long` — n up to 2e5 and per-step diffs up to
  ~1e9 means the total can exceed int range.
