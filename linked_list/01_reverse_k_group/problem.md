# Reverse List - hard version (Reverse Nodes in k-Group)

Link: (pasted, no URL given)
Pattern: group-bounded in-place reversal (cut fixed-size window, reverse standalone, splice back)
Time: O(N)  Space: O(1)

## Statement

Given a singly linked list of length N and an integer K, reverse the nodes
in groups of size K and return the head. K divides N exactly (no partial
final group to worry about).

Constraints: 1 ≤ N ≤ 1e6, 1 ≤ K ≤ N, 0 ≤ node values ≤ 1e9, N % K == 0.

## Examples

    [1,2,3,4,5,6], K=3 -> [3,2,1,6,5,4]
    [1,3,2],       K=3 -> [2,3,1]

## Recall Trail

- State: `head` = start of current unprocessed group, `prev` = last node of
  the previous (already-reversed) group, dummy node ahead of `head` avoids
  special-casing the first group.
- Reverse helper: `p, c = None, h`; loop while `c`: save `n = c.next` before
  overwriting `c.next = p` (must save first — you lose the rest of the list
  otherwise), then `p, c = c, n`; return `p`.
- Group loop: walk `t` forward `k-1` steps to find the group's tail, save
  `nxtg = t.next`, cut with `t.next = None`, reverse the group, then splice:
  `prev.next = new_head`, `old_head.next = nxtg`, advance
  `prev, head = old_head, nxtg`.
- `k == 1` needs no special case — the loop degenerates to a 1-node
  "reversal" and relinks correctly on its own.
