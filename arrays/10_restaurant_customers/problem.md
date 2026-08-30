# Restaurant Customers

Link: CSES 1619
Pattern: sweep line — split each interval into +1/-1 events, sort by time,
track running total and its max
Time: O(n log n)  Space: O(n)

## Statement

Given n (arrival, leaving) intervals, find the max number simultaneously
present.

## Examples

    (5,8) (2,4) (3,9) -> 2

## Recall Trail

- Don't reason about the raw intervals directly — split each into two
  separate timestamped events: arrival = `+1`, leaving = `-1`. Sort all
  `2n` events by time.
- Sweep once: maintain a running total (add the event's delta), and update
  a separate `best = max(best, running)` at every step — the max has to be
  tracked continuously, not read off the final total (which is always 0).
- Arrival/leaving times are guaranteed distinct, so no tie-break needed
  between an arrival and departure at the same instant.
