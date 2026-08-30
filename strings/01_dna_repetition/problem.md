# DNA Repetition

Link: CSES 1069
Pattern: single-pass run-length scan — track current run vs previous char, keep a running max
Time: O(n)  Space: O(1)

## Statement

Longest maximal substring of a single repeated character.

## Examples

    ATTCGGGA -> 3   (GGG)

## Recall Trail

- Single pass, compare `s[i]` to `s[i-1]`: same -> extend current run
  (`count++`), different -> current char starts a fresh run (`count = 1`,
  not `0` — the mismatch position itself still belongs to a run of length
  at least 1). Update `maxCount` every iteration.
- Init both `count` and `maxCount` to `1` before the loop, not `0` — covers
  `n == 1` for free since the loop body never runs.
