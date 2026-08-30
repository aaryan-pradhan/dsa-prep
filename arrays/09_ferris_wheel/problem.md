# Ferris Wheel

Link: CSES 1090
Pattern: sort, two-pointer from both ends — pair lightest with heaviest
when they fit together, else heaviest rides alone
Time: O(n log n)  Space: O(1) extra

## Statement

n children, gondola holds 1 or 2, total weight per gondola <= x. Minimum
gondolas needed.

## Examples

    7 2 3 9, x=10 -> 3

## Recall Trail

- Sort, `i` at lightest unmatched, `j` at heaviest unmatched.
- If `p[i] + p[j] <= x`: pair them, both consumed (`i++`). Either way `j`
  always decrements (the current heaviest is always resolved this step —
  either paired or sent alone) and `count++` always fires once per step.
- `i == j` (one child left) still works correctly: the self-pair check
  trivially succeeds or the child just goes alone either way, exactly one
  gondola charged, loop then ends (`i > j`).
