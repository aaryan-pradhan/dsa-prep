"""
Problem: Sort a Linked List (Merge Sort)
Pattern: divide and conquer -- split at midpoint, recurse, merge two sorted lists
Time: O(N log N)  Space: O(log N) recursion stack
"""

from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def _find_mid(head: ListNode) -> ListNode:
    slow = head
    fast = head.next
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    return slow


def _merge(left: Optional[ListNode], right: Optional[ListNode]) -> Optional[ListNode]:
    if left is None:
        return right
    if right is None:
        return left

    dummy = ListNode(-1)
    temp = dummy
    while left and right:
        if left.val < right.val:
            temp.next = left
            temp = left
            left = left.next
        else:
            temp.next = right
            temp = right
            right = right.next

    temp.next = left if left else right
    return dummy.next


def mergesort(head: Optional[ListNode]) -> Optional[ListNode]:
    if head is None or head.next is None:
        return head

    mid = _find_mid(head)
    left = head
    right = mid.next
    mid.next = None

    left = mergesort(left)
    right = mergesort(right)

    return _merge(left, right)
