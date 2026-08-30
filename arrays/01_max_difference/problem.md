# Maximum Difference

Link: (pasted, no URL given)
Pattern: single pass, running min — max(arr[j] - min_so_far) over i < j
Time: O(N)  Space: O(1)

## Statement

Given N elements in an array, select two indexes i and j such that i < j
and arr[j] - arr[i] is maximum possible. Output that maximum difference.

## Examples

    [1,2,3,4,5] -> 4   (i=0, j=4: 5-1=4)

## Recall Trail

- Not "global max - global min" — that ignores `i < j`. Counterexample:
  `[5,1]`, global max=5 comes before global min=1, so the only valid pair
  gives `1-5=-4`, not `5-1=4`.
- Single pass: track `min_so_far` (min of everything strictly before the
  current index). At each `j`, candidate answer is `arr[j] - min_so_far`;
  keep the max seen. No clamping to 0 — a strictly decreasing array yields
  a negative answer, which is correct (least-bad achievable pair).
- Loop must start at `i=1` with `min_so_far = arr[0]`, `maxDiff` seeded
  from the first real pair (`arr[1]-arr[0]`). Starting the loop at `i=0`
  with `min_so_far` already `arr[0]` lets index 0 pair with itself
  (`arr[0]-arr[0]=0`), which can inflate the answer above what any real
  `i<j` pair achieves on a decreasing array.
