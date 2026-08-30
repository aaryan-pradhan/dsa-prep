# Sort a Linked List (Merge Sort)

Link: (pasted, no URL given)
Pattern: divide and conquer — split at midpoint, recurse, merge two sorted lists
Time: O(N log N)  Space: O(log N) recursion stack

## Statement

Sort a singly linked list in O(N log N) using merge sort. Return the new head.

Constraints: 0 ≤ N ≤ 1e5, 0 ≤ node value ≤ 1e9.

## Examples

    [2]           -> [2]
    [1,3,6,1,7]   -> [1,1,3,6,7]

## Recall Trail

- Array merge sort needs random-access splitting; a linked list doesn't
  have that, so find the midpoint with slow/fast pointers (as in
  `02_reorder_list`), recurse on both halves, then merge.
- `findMid` here starts `fast = head->next` (not `head`, unlike the
  reorder-list variant) — this lands on the *first* middle and, critically,
  guarantees progress: with `fast = head` a 2-node list would return
  `slow = head` unchanged, and calling `mergesort` again on the same head
  recurses forever. Base case (`!head || !head->next`) is what actually
  prevents that for 0/1-node lists, but the `fast = head->next` offset is
  what keeps a 2-node split from degenerating.
- Merge step is a **comparison merge**, not the reorder problem's
  alternating merge: `left->val < right->val` decides which node gets
  appended next, since the two halves are independently sorted, not just
  split halves of one list.
- Once one side runs out, the entire remaining side can be spliced on
  wholesale, unsorted-comparison-free — every node left in the exhausted
  side's sibling is already ≥ everything merged so far, since it survived
  every earlier comparison.
- Base case must handle both `head == nullptr` and `head->next == nullptr`:
  skipping it either null-derefs in `findMid` (`head->next` on null) or
  infinite-recurses on a single node.
