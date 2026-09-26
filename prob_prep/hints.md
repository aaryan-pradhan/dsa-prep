# QuantFest 2026 Regionals: Hints

Contest: **Sun 27 Sep 2026**.

## Organizer hints

- **Main 3 distributions: normal, Poisson, uniform.**
- **Distribution questions will be non-standard and tricky to read**, with unusual setups and surprising answers. Don't expect textbook plug-ins.
- **No covariance or bivariate questions.**
- **Relay is an MCQ paper: 12 questions, 10 of them expected value or combinatorics.** The other 2 are something else, most likely distributions.
- **Relay: 45 minutes.**
- **Calculator allowed only in Paper 3.**
- **Relay questions are independent**: random order, not one after the other.
- **Cutoff for finals: 100 marks.**

## Coding paper: official score distribution

| Problem | Marks |
|---|---|
| A | 8 |
| B1 | 6 |
| B2 | 12 |
| C | 16 |
| D1 | 14 |
| D2 | 16 |
| E | 24 |
| **Total** | **96** |

- **About 83% is mathematics (probability).** That's 80 of 96 marks. It matches everything except one 16-mark problem (C or D2) being mathematics, so expect one problem that is mostly implementation.
- **Sub-parts:** B1 → B2 and D1 → D2 are probably an easy version then a hard one. Solve B1 and D1 first, then look for the insight that scales them up.
- **Order of attack:** A (8) → B1 (6) → D1 (14) → C (16) → B2 (12) → D2 (16) → E (24). E is a quarter of the paper, so read it early even if you solve it last.
- **Prep:** the coding problems are probability derivations turned into code: expectation DP, modular inverses mod 998244353, and doubles to 1e-6. See [quantfest_mock.html#code](quantfest_mock.html#code).

## Format (shape from [quantfest_mock.html](quantfest_mock.html); organizer hints above override it)

| Test | Format | Time | Calculator |
|---|---|---|---|
| 1 | Coding | 1 h 30 min | — |
| 2 | Relay (MCQ, 12 Q) | 45 min | no |
| 3 | Written (probability) | 1 h 30 min | **yes** |

- **Relay questions are independent (random order, not chained).** No "T = previous answer". A wrong answer doesn't carry into the next question.
- 2025 prelims topics: ballot-type counting, expectation DP, "P(x) = a + b·P(1)" self-loops, run-length strings, uniforms.

## What this changes

- **Cutoff 100:** if the total is 240, as in the mock (96 coding + 48 relay + 96 written), 100 is about 42%. Only the coding marks are official. The coding sure-wins A + B1 + D1 give 28, so the rest has to come from partial credit on the written paper and correct relay answers. Bank safe marks before chasing E.
- **Skip:** covariance, joint distributions, and bivariate problems in the ledgers.
- **Distributions to know cold** for normal, Poisson and uniform:
  - PDF/PMF, mean, variance and CDF.
  - Normal: standardising (z-scores) and the 68/95/99.7 rule.
  - Poisson: sums of independent Poissons, thinning, and the link to exponential waiting times.
  - Uniform: order statistics (E[k-th smallest of n] = k/(n+1)) and geometric probability.
- **Tricky distribution questions:**
  - **Read slowly.** Name the random variable and its distribution in one line before any maths, e.g. "X = arrivals in [0, t] ~ Poisson(λt)".
  - **Look for the disguise:**
    - Poisson hiding behind thinning or splitting, or "given N = n arrivals, the arrival times are sorted uniforms".
    - A uniform hiding in a symmetry argument or a stick-breaking problem.
    - A normal hiding behind symmetry, e.g. P(X > Y) for iid X and Y is 1/2, or behind a CLT approximation.
  - **Surprising answers are expected.** If the answer looks too clean or too odd, check it on a small case. Don't second-guess it just because it's surprising.
- **Relay drill:** expected value ([probability.html](probability.html), [markov.html](markov.html)) and counting ([combinatorics.html](combinatorics.html)).
- **Relay pace:** 45 min for 12 questions is about 3.75 min each, with no calculator. Keep answers exact.
- **MCQ:** questions are independent, so skip freely and come back. Only correct answers score. Small cases and eliminating options are fair tools.
- **Paper 3 has a calculator:** numeric normal and Poisson answers, such as Φ values and e^(−λ) sums, are fair game there.
