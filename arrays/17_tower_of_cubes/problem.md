# Tower of Cubes

Link: CSES 1073
Pattern: patience-sorting-style greedy — multiset of tower tops, place
each cube on the tightest-fitting tower (smallest top strictly > cube)
Time: O(n log n)  Space: O(n)

## Statement

Process cubes in given order. Each cube either starts a new tower or goes
on top of an existing tower whose current top is strictly larger.
Minimize the number of towers.

## Examples

    3 8 2 1 5 -> 2

## Recall Trail

- Maintain a `multiset` of each tower's current top value (not `set` —
  two towers can legitimately share the same top, e.g. two size-5 cubes
  back to back each start/extend their own tower with top 5).
- For each cube `c`: `upper_bound(c)` finds the smallest top *strictly*
  greater than `c` (must be strict — a top equal to `c` can't accept it,
  rule requires upper < lower). If found, erase it and insert `c` (that
  tower's top shrinks to `c` — placing tightest-fitting first preserves
  taller towers for future smaller cubes). If not found, just insert `c`
  (new tower).
- No manual array-shifting needed — `multiset` keeps itself sorted through
  insert/erase, unlike a plain sorted vector.
- Answer = final `multiset` size.
