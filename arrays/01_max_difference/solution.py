"""
Problem: Maximum Difference
Pattern: single pass, running min -- max(arr[j] - min_so_far) over i < j
Time: O(N)  Space: O(1)
"""

from typing import List


def max_difference(arr: List[int]) -> int:
    min_so_far = arr[0]
    max_diff = arr[1] - arr[0]

    for i in range(1, len(arr)):
        max_diff = max(max_diff, arr[i] - min_so_far)
        min_so_far = min(min_so_far, arr[i])

    return max_diff
