"""
Problem: Reverse List - hard version (Reverse Nodes in k-Group)
Pattern: group-bounded in-place reversal
Time: O(N)  Space: O(1)
"""

from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def _reverse(h: Optional[ListNode]) -> Optional[ListNode]:
    p, c = None, h
    while c is not None:
        n = c.next
        c.next = p
        p = c
        c = n
    return p


def reverse_k_group(head: Optional[ListNode], k: int) -> Optional[ListNode]:
    if head is None or k == 1:
        return head

    d = ListNode(0, head)
    p = d
    h = head

    while h is not None:
        t = h
        for _ in range(k - 1):
            t = t.next

        nxtg = t.next
        t.next = None
        nh = _reverse(h)

        p.next = nh
        h.next = nxtg

        p = h
        h = nxtg

    return d.next
