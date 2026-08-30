# Weird Algorithm (Collatz sequence)

Link: CSES 1068
Pattern: simulate with a loop, print each state, exit right after the terminal value
Time: O(steps)  Space: O(1)

## Statement

n even -> n/2, n odd -> 3n+1, repeat until n == 1. Print every value n
takes, including the initial n and the final 1.

## Examples

    3 -> 3 10 5 16 8 4 2 1

## Recall Trail

- No aggregate asked for (count, max, etc.) — just print every value in
  sequence, and the number of steps is unknown up front. That's a plain
  simulate-with-a-loop, not a pattern to search for.
- `1` can't go through the even/odd transform (would loop forever), so it's
  handled outside the loop: `while (n != 1) { print n; transform; } print 1;`.
  This also makes `n == 1` on input a correct edge case for free — loop body
  never runs, `1` prints immediately.
- `n <= 1e6` so `3n+1` never overflows `int`, but used `long long` anyway —
  cheap and removes the need to think about it.
