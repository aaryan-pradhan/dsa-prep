# Apartments

Link: CSES 1084
Pattern: sort both sides, two-pointer greedy sweep
Time: O(n log n + m log m)  Space: O(1) extra

## Statement

n applicants each want a size in `[a_i - k, a_i + k]`, m apartments each of
fixed size. Maximize the number of applicants matched to a distinct
apartment.

## Examples

    a = 60 45 80 60, b = 30 60 75, k=5 -> 2

## Recall Trail

- A binary-search-per-applicant check (does *some* apartment fit) isn't
  enough — apartments can't be reused across matches. Need to consume a
  matched apartment.
- Sort both arrays, sweep with one pointer each (`i` applicants, `j`
  apartments):
  - `b[j] < a[i]-k`: apartment too small for even the current cheapest
    applicant — it's too small for every applicant after too (sorted), so
    discard it: `j++`.
  - `b[j] > a[i]+k`: current apartment too big for this applicant, but
    might fit a later (larger) one — move on: `i++`.
  - else: match, consume both: `count++; i++; j++`.
