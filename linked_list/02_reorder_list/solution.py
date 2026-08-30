"""
Problem: Reorder List I
Pattern: split + reverse second half + merge alternately
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


def _middle_node(head: ListNode) -> ListNode:
    slow = fast = head
    while fast:
        fast = fast.next
        if fast:
            slow = slow.next
            fast = fast.next
    return slow


def reorder_list(head: Optional[ListNode]) -> None:
    if head is None or head.next is None:
        return

    mid = _middle_node(head)
    second = mid.next
    mid.next = None
    second = _reverse(second)

    first = head
    while second:
        tmp1 = first.next
        tmp2 = second.next
        first.next = second
        second.next = tmp1
        first = tmp1
        second = tmp2
