# Reorder List I

Link: (pasted, no URL given)
Pattern: split + reverse second half + merge alternately
Time: O(N)  Space: O(1)

## Statement

Given the head of a singly linked list, reorder it in place from
`L1 -> L2 -> ... -> Ln` to `L1 -> Ln -> L2 -> Ln-1 -> L3 -> Ln-2 -> ...`.
Node values may not be changed — only links may be rewired.

Constraints: 0 ≤ length ≤ 1e6, 0 ≤ node value ≤ 1e9.

## Examples

    [3]           -> [3]
    [1,2,3,4]     -> [1,4,2,3]
    [1,2,3,4,5]   -> [1,5,2,4,3]

## Recall Trail

- Core idea: singly-linked means no `prev` pointer, so you can't walk
  backward from the tail repeatedly. Reversing a portion turns "walk
  backward" into "walk forward" — so split the list in half, reverse the
  second half, then merge the two halves by alternating nodes.
- Middle-finder variant used here (`slow=fast=head`; each iteration
  `fast=fast->next`, and only if `fast` is still non-null does
  `slow=slow->next; fast=fast->next` run): lands on the *second* middle for
  even-length lists, so the first half ends up longer by 2 for even N (and
  by 1 for odd N, same as the standard `fast->next && fast->next->next`
  variant). This is fine here — see next point.
- Merge loop: `while (second)` — `tmp1=first->next`, `tmp2=second->next`,
  `first->next=second`, `second->next=tmp1`, `first=tmp1`, `second=tmp2`.
  Because the loop condition is only on `second`, it degrades gracefully:
  `second` empty from the start (N≤2) → loop body never runs, list
  untouched; `second` shorter than `first` → last write is
  `second->next=tmp1`, which reattaches the untouched remainder of `first`
  automatically. No special-casing needed for either the split asymmetry or
  small N.
