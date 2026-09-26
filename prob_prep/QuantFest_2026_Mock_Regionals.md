# QuantFest 2026 — Mock Regionals

**Total: 240 marks · 3 h 30 min · Answers in `QuantFest_2026_Mock_Regionals_Answers.md`**

Same shape as the official Regionals: three tests on one day, 1.5 h + 0.5 h + 1.5 h. The questions are predictions, not leaks. They are built from the 2025 prelims topics (ballot-type counting, expectation DP, "P(x) = a + b·P(1)" self-loops, run-length strings, uniforms), plus every family in these ledgers.

| Test | Format | Questions | Marks | Time |
|---|---|---|---|---|
| 1 | Coding | 6 × 16 | 96 | 1 h 30 min |
| 2 | Relay | 8 × 6 | 48 | 30 min |
| 3 | Written (probability) | 8 × 12 | 96 | 1 h 30 min |

**Instructions**
- No calculators in Tests 2 and 3. Give exact answers.
- Test 1: real outputs are accepted within an absolute or relative error of 1e-6. Modular outputs are taken mod 998244353.
- Test 2: T is the answer to the previous question. Only correct answers score.
- Test 3: show your working; partial credit is available.

---

## Test 1 — Coding (96 marks, 1 h 30 min)

### C1. Up to k Rolls (16 marks)
You roll a fair m-sided die (faces 1..m). After each roll you may keep the number (you are paid that many dollars and the game ends) or throw it away and roll again. You may roll at most k times; the k-th roll must be kept.

Output the expected payout under optimal play.

Input: m k (1 ≤ m, k ≤ 10⁶). Output: one real number.

| Input | Output |
|---|---|
| 6 1 | 3.500000 |
| 6 2 | 4.250000 |
| 6 3 | 4.666667 |
| 10 3 | 7.450000 |

### C2. Square Stones (16 marks)
A pile has n stones. Alice and Bob alternate, Alice first. A move removes a positive perfect square number of stones (1, 4, 9, …), no more than the pile holds. The player who cannot move loses.

Input: t, then t lines each with n (1 ≤ t ≤ 10⁵, 1 ≤ n ≤ 10⁵). Output: the winner for each n.

| Input | Output |
|---|---|
| 5 / 1 / 2 / 3 / 4 / 5 | Alice Bob Alice Alice Bob |

### C3. Ruin, Modulo (16 marks)
A gambler holds s dollars. Each round they win $1 with probability p = a/b and lose $1 otherwise, and play stops at $0 or $N. Output the probability of reaching $N, as P·Q⁻¹ mod 998244353.

Input: a b s N (1 ≤ a < b ≤ 10⁹, 0 ≤ s ≤ N ≤ 10¹⁸). It is guaranteed the answer's denominator is not divisible by 998244353.

| Input | Output |
|---|---|
| 1 2 1 2 | 499122177 |
| 2 3 1 2 | 665496236 |
| 2 3 2 5 | 96604293 |

### C4. Never Below Zero (16 marks)
Count the orderings of n up-steps (+1) and m down-steps (−1) whose running sum never goes below 0. Output mod 998244353.

Input: q, then q lines each with n m (1 ≤ q ≤ 10⁵, 0 ≤ n, m ≤ 10⁶).

| Input | Output |
|---|---|
| 4 / 2 1 / 3 3 / 5 2 / 3 4 | 2 5 14 0 |

### C5. Divisor Walk (16 marks)
Start at n. Each step, replace the current number x by a uniformly random divisor of x (1 and x itself included). Output the expected number of steps until the number is 1.

Input: q, then q lines each with n (1 ≤ q ≤ 10⁵, 1 ≤ n ≤ 10⁶). Output: one real number per query.

| Input | Output |
|---|---|
| 5 / 1 / 2 / 4 / 6 / 12 | 0.000000 2.000000 2.500000 2.666667 3.033333 |

### C6. Ends of the Row (16 marks)
n coins with values a₁ … aₙ lie in a row. Alice and Bob alternate, Alice first; each turn a player takes the coin at either end of the row. Both play to maximise their own total. Output Alice's total.

Input: n, then a₁ … aₙ (1 ≤ n ≤ 5000, 1 ≤ aᵢ ≤ 10⁹).

| Input | Output |
|---|---|
| 4 / 3 9 1 2 | 11 |
| 3 / 1 2 3 | 4 |
| 4 / 4 4 4 4 | 8 |

---

## Test 2 — Relay (48 marks, 30 min)

T is the answer to the previous question.

1. A fair die is rolled until the first 6. What is the expected number of rolls?
2. A fair coin is tossed until T heads have appeared in total. What is the expected number of tosses?
3. How many diagonals does a convex T-gon have?
4. How many positive divisors does T have?
5. A token walks on the T vertices of a cycle, moving to each of its two neighbours with probability ½. Starting at vertex 0, what is the expected number of steps until it first returns to 0?
6. A gambler has $2 and bets $1 on fair coin flips until reaching $0 or $T. What is the expected number of bets?
7. In how many ways can a 2 × (T/2) board be tiled with 1 × 2 dominoes?
8. How many integers from 1 to 100 are divisible by T or by 7?

---

## Test 3 — Written (96 marks, 1 h 30 min)

**W1. Tuesday (12).** A family has two children. Each child is a boy or a girl with probability ½, born on each weekday with probability 1/7, independently. You learn that at least one child is a boy born on a Tuesday. Find P(both are boys).

**W2. Biased walk (5 + 7).** A walk starts at 0. Each step is +1 with probability 2/3 and −1 with probability 1/3, and it stops on first reaching −3 or +5.
(a) Find P(it stops at +5).
(b) Find the expected number of steps.

**W3. Patterns (5 + 7).** A fair coin is tossed repeatedly.
(a) Find the expected number of tosses until HTH first appears.
(b) Find P(HTH appears before HHT).

**W4. Paid rerolls (12).** You roll a fair die. You may reroll up to 2 more times, paying $1 per reroll; you are paid the last number rolled, minus what you paid. Find the value of the game under optimal play, and the optimal strategy.

**W5. Broken stick (5 + 7).** A stick of length 1 is broken at two independent uniform points.
(a) Find P(the three pieces form a triangle).
(b) Find the expected length of the longest piece.

**W6. Take 1, 3 or 4 (12).** A pile has 2026 stones. Alice and Bob alternate, Alice first; a move removes 1, 3 or 4 stones. The player who cannot move loses. Find every losing pile size, prove your answer, and state who wins from 2026 with a winning first move.

**W7. First ace (12).** A standard 52-card deck is shuffled. Find the expected number of cards that appear before the first ace.

**W8. Two uniforms (5 + 7).** X, Y are independent and uniform on [0, 1].
(a) Find P(max(X, Y) ≤ 2·min(X, Y)).
(b) Find E|X − Y|.
