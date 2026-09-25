# QuantFest 2026 — Mock Paper

**Total: 240 marks · Solutions in `QuantFest_2026_Mock_Solutions.md`**

| Paper | Format | Questions | Marks | Time |
|---|---|---|---|---|
| 1 | Coding | 6 × 16 | 96 | 1 h 30 min |
| 2 | Relay | 12 × 4 | 48 | 45 min |
| 3 | Written | 5 × (5 + 7) + 3 × 12 | 96 | 2 h |

**Instructions**
- Calculators are not allowed in Papers 2 and 3. Give exact answers unless a question asks for decimals.
- In Paper 1, real outputs are accepted within an absolute or relative error of 1e-6. Modular outputs are taken mod 998244353.
- In Paper 2, T is the answer to the previous question. Marks are awarded only for correct answers.
- Show your working in Paper 3; partial credit is available.

---

## Paper 1 — Coding (96 marks, 1 h 30 min)

### C1. Minimise the Rank (16 marks)
`n` candidates, ranked 1 (best) to n, are interviewed in uniformly random order. After each interview you learn only that candidate's rank **among those seen so far**, and you must immediately hire them or reject them for good. You must hire exactly one candidate; if you reach the last one, you must hire them.

Output the minimum possible expected rank of the person hired.

**Input:** one integer `n` (1 ≤ n ≤ 10⁶).
**Output:** one real number.

| Input | Output |
|---|---|
| `3` | `1.666667` |
| `10` | `2.557937` |

### C2. Random Walk on a Tree (16 marks)
A tree has `n` vertices. A walker at a vertex moves to a uniformly random neighbour at each step. For each query `(u, v)` with u ≠ v, output the expected number of steps to first reach `v` when starting from `u`. Every answer is an integer.

**Input:** `n q` on the first line. Then n − 1 edges `a b`. Then q queries `u v`.
**Constraints:** 2 ≤ n ≤ 2·10⁵, 1 ≤ q ≤ 2·10⁵.

Example: the input is
```
3 1
1 2
2 3
1 3
```
and the output is `4`.

### C3. Max of Different Uniforms (16 marks)
The `X_i` are independent, with `X_i` uniform on `[a_i, b_i]`. Output E[max(X₁, …, Xₙ)].

**Input:** `n`, then n lines `a_i b_i`.
**Constraints:** 1 ≤ n ≤ 300, and the endpoints are integers with 0 ≤ a_i < b_i ≤ 10⁶.

| Input | Output |
|---|---|
| `2` / `0 1` / `0 1` | `0.666667` |
| `2` / `0 1` / `0 2` | `1.083333` |

### C4. Bold Play (16 marks)
You have fortune `x` with 0 < x < 1 and want to reach 1. Each bet wins its stake with probability `p` and loses it otherwise. You always stake min(x, 1 − x). Output the probability that you ever reach 1.

**Input:** a real `p` (0.01 ≤ p ≤ 0.99) and a fraction `a/b` (1 ≤ a < b ≤ 10⁹).

| Input | Output |
|---|---|
| `0.5 3/10` | `0.300000` |
| `0.4 3/4` | `0.640000` |

### C5. Many-way Penney (16 marks)
Letters are drawn independently and uniformly from an alphabet of `k` letters until one of the `n` given patterns appears as a block of consecutive letters. No pattern is a substring of another.

For each pattern, output the probability that it appears first, as p·q⁻¹ mod 998244353.

**Input:** `n k`, then n patterns, one per line.
**Constraints:** 2 ≤ n ≤ 10, 2 ≤ k ≤ 26, each pattern has length between 1 and 10⁵, and the patterns are written with the first k uppercase letters.

Example: the input is
```
2 2
HH
TTT
```
and the output is
```
99824436
898419918
```

### C6. Longest Run (16 marks)
A coin with P(H) = p is tossed n times. Output the expected length of the longest run of consecutive heads.

**Input:** `n p`.
**Constraints:** 1 ≤ n ≤ 5000.

| Input | Output |
|---|---|
| `3 0.5` | `1.375000` |

---

## Paper 2 — Relay (48 marks, 45 min)

Each question is worth 4 marks.

1. A fair coin is tossed until HTHT appears. What is the expected number of tosses?
2. Let n = T/4. The probability that a uniformly random permutation of {1, …, n} has no fixed point is p/q in lowest terms. Find p + q.
3. Let n = T − 36. Roll n fair six-sided dice. In how many of the 6ⁿ outcomes are all n faces different?
4. How many positive divisors does T have?
5. Let k = T/10. A fair coin is tossed until k consecutive tosses show the same face (all H or all T). What is the expected number of tosses?
6. A pair of fair dice is rolled repeatedly. What is the expected number of rolls until a total of T comes up on two consecutive rolls?
7. Let n = T/6. How many triangles whose vertices are vertices of a regular n-gon contain the centre of the n-gon in their interior?
8. Find the Catalan number C_{T/2}.
9. Let n = T mod 10. The expected number of records (values larger than every earlier value; the first value always counts) in a uniformly random permutation of n distinct numbers is p/2520. Find p.
10. Let m = T mod 100. How many primes are ≤ m?
11. Let a = T − 7 and b = T/2. A fair ±1 random walk starts at 0 and stops on first reaching −a or +b. Find 3 × E[number of steps | the walk stops at +b].
12. Let k = T mod 7. Find 10 × (expected number of rolls of a fair k-sided die until every face has appeared at least once).

---

## Paper 3 — Written (96 marks, 2 h)

**Q1. Overlapping patterns** (5 + 7)
A fair coin is tossed repeatedly.
(a) Find the expected number of tosses until HTHT first appears.
(b) Find the expected number of tosses until HTHT **or** THTH first appears.

**Q2. Shattered stick** (5 + 7)
(a) A unit stick is broken at 4 points chosen independently and uniformly. Find the probability that the 5 pieces can form a pentagon.
(b) A unit stick is broken at 3 independent uniform points. Find the expected length of the longest of the 4 pieces.

**Q3. Buses and callers** (5 + 7)
(a) Buses arrive at a stop as a Poisson process with rate 4 per hour. You arrive at a random time. Find the expected length of the gap between the bus before you and the bus after you.
(b) Calls arrive as a Poisson process with rate 5 per hour. Each call is from a VIP independently with probability 0.3. Given that exactly 4 VIP calls arrived in a particular hour, find the expected total number of calls in that hour.

**Q4. Gaussian geometry** (5 + 7)
X, Y, Z are independent standard normal random variables.
(a) Find P(X > Y | X > 0).
(b) Find E[max(X, Y, Z)].

**Q5. Make me a market** (5 + 7)
(a) Two fair dice are rolled and you are paid the product of the faces. What is the fair price?
(b) After seeing both dice you may reroll one of them (once), or keep both, and you are paid the final product. What is the fair price under optimal play?

**Q6. Lost boarding pass** (12)
100 passengers with assigned seats board a 100-seat plane in order 1, 2, …, 100. Passenger 1 has lost their boarding pass and sits in a uniformly random seat. Every later passenger sits in their own seat if it is free, and otherwise in a uniformly random free seat. Find the expected number of passengers who do not sit in their own seat.

**Q7. Landing on 100** (12)
A fair die is rolled repeatedly and the running total is kept, stopping as soon as the total is at least 100. Which final total is most likely? Give its probability to 4 decimal places, with justification.

**Q8. The conditioned walk** (12)
A fair ±1 random walk starts at 0 and stops on first reaching −3 or +5. Given that it stops at +5, find the expected number of steps.
