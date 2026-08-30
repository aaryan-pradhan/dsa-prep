# Next Common Height (Nandu and Chandu)

Link: (pasted, no URL given)
Pattern: LCM of two step sizes — divide-before-multiply to avoid overflow
Time: O(log(min(a,b))) per test case  Space: O(1)

## Statement

Both start at height x. One jumps up by a each move, the other by b each
move. T test cases, each (x, a, b). Output the next height (strictly above
x) both will visit.

## Examples

    (1, 1, 2)  -> 3
    (1, 19, 19) -> 20
    (17, 2, 3) -> 23

## Recall Trail

- A shared height above x needs `k*a = m*b` for some positive integers
  k, m — the smallest such value is `lcm(a, b)`. Answer: `x + lcm(a, b)`.
- `lcm(a,b) = a / gcd(a,b) * b` — divide by gcd *before* multiplying by b,
  not after, to avoid `a*b` overflowing when a and b are both large.
- All of x, a, b, and the result cast to `long long` — safe default for
  number-theory problems where inputs can be large enough that `int`
  overflows silently.
