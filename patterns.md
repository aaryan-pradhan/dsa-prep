# Patterns

Canonical shape per pattern, built only from problems solved in this repo.
Appended to by dsa-buddy on first establishing/reinforcing a pattern —
a reminder, not a tutorial.

## Linked list — group-bounded in-place reversal

Cut a fixed-size window with a lookahead pointer, reverse it standalone via
a `prev/cur/next` sweep, splice both ends back into the surrounding list,
advance by the window size. Dummy head node avoids special-casing the first
group. See `linked_list/01_reverse_k_group`.

## Linked list — split + reverse half + merge alternately

Singly-linked lists can't walk backward, so to interleave front and back
you reverse the back half instead: find the midpoint with slow/fast
pointers, cut into two halves, reverse the second half, then merge by
alternating nodes with a `while (second)` loop (`tmp1/tmp2` save-before-
overwrite, then `first->next=second; second->next=tmp1; first=tmp1;
second=tmp2`). Looping on `second` alone means it degrades gracefully when
`second` is empty or shorter than `first` — no special-casing for small N
or split asymmetry. See `linked_list/02_reorder_list`.

## Linked list — divide-and-conquer sort (merge sort)

Find the midpoint with slow/fast pointers (`fast = head->next` start, so a
2-node list still makes progress instead of returning the same head),
split, recurse on both halves down to the base case (`!head ||
!head->next`), then merge two independently-sorted halves by repeatedly
taking the smaller front node — not the alternating merge used for
in-place reordering. Once one side is exhausted, splice the other's
remainder on wholesale; it's already ≥ everything merged so far. See
`linked_list/03_merge_sort`.

## Graphs — monotonic-reach BFS collapsed into a sweep

When jumps only move forward, reachable ranges only extend, and every edge
costs 1, BFS-by-queue is unnecessary — visitation order is just index
order. Track two values while scanning left to right: `curEnd` (edge of
everything reachable in the current jump count) and `farthest` (edge being
built for the next jump count, updated via `i + power[i]` as each stone is
passed). When the scan index steps past `curEnd`, that's proof one more
jump was needed: `jumps++; curEnd = farthest`. Init both to the start
index so the start needs no special-casing. Same shape as LeetCode "Jump
Game II". See `graphs/01_min_jumps_frog`.

## Arrays — split-sort-remerge by predicate

When swaps are restricted to elements sharing some predicate (parity here),
positions belonging to each predicate class are fixed but values within a
class are freely permutable — so sort each class independently to kill its
internal inversions (cross-class inversions are unavoidable either way).
Implement as two passes over the same array, not stored index lists: pass 1
buckets values by the predicate and sorts each bucket; pass 2 re-evaluates
the same predicate per position (not stored) to pick which bucket's next
value (via a per-bucket pointer) overwrites that position. Cheap predicate
re-check beats bookkeeping positions. See
`arrays/02_parity_constrained_sort`.

## Math — LCM via GCD, divide before multiply

`lcm(a,b) = a / gcd(a,b) * b`, computed in that order — dividing first
keeps the intermediate value small, whereas `a*b` first can overflow even
when the true LCM wouldn't. Default to `long long` for all inputs/output in
number-theory problems, since these judges size constraints to make `int`
overflow silently. See `math/01_next_common_height`.

## Arrays — merge intervals for union size

When coordinates are too large to mark individually, sort intervals by
`l` and sweep, tracking a single open block `(curL, curR)`. If the next
`l_j <= curR`, it overlaps/touches the open block — extend
`curR = max(curR, r_j)`. Otherwise flush the open block's length
(`curR - curL + 1`) into the total and start a new block at `l_j`. The
last block never gets a triggering "next" segment — flush it once more,
explicitly, after the loop. Use a wide integer type for the running total.
See `arrays/03_union_of_painted_bricks`.

## Math — XOR-cancellation for missing/unpaired value

When every value should appear an even number of times (or a known full
range appears once each) except one outlier, XOR the full expected range
with the actual values in one pass. Matched pairs cancel (`x ^ x = 0`),
leaving only the outlier — no extra storage, no sorting. See
`math/03_missing_number`.

## Gotcha — unordered_set/unordered_map anti-hash TLE on CSES

CSES test data includes an anti-hash test targeting the default
`unordered_set`/`unordered_map` hash on integers (predictable, so an
adversarial input forces every key into the same bucket) — degrades every
op to O(n), O(n^2) total, TLE on the final test case. Default to sorting
(sort + adjacent-run scan, or `set`/`map`, both comparison-based and
immune) for judge-facing code instead of unordered containers, unless a
custom hash is used. See `arrays/07_distinct_values`.

## Arrays — per-value option counting for distinct-subsequence counts

For "count subsequences where every element is distinct" (order/
contiguity irrelevant, unlike distinct-*subarray* counting — different
problem despite the similar name, two-pointer doesn't apply), think per
distinct value instead of per position. A value with frequency `f` has
`f+1` mutually exclusive options in any subsequence: exclude it, or
include exactly one of its `f` occurrences (never `2^f` — that treats
occurrences as independent bits and allows more than one "on" at once,
which isn't a valid distinct-subsequence). Options across different
values are independent, so total = `Π (freq[v]+1)` over distinct values,
counting the empty subsequence too — subtract 1 at the end. See
`arrays/20_distinct_subsequences`.

## Data structure — segment tree order-statistics query (find k-th alive)

For "repeatedly remove elements by rank/position and need the next
removal target fast" (Josephus-style circle problems, or any "find the
k-th remaining element" need), a plain array/list simulation costs O(n)
per query in the worst case. A segment tree over a 1/0 alive array gives
O(log n) point-update (mark removed) for free via the standard
build/update/merge; the extra trick is `findKth`, which descends from the
root — go left if the left child's sum already covers k, else subtract
the left child's sum from k and go right — one path down, O(log n), no
backtracking. This repo standardizes on segment tree over Fenwick
tree/BIT for this family of problems: a segment tree subsumes everything
a BIT does (point update, prefix/range sum) plus general range queries,
so there's one structure to remember instead of two. See `arrays/Josephus_Queries.cpp` and `arrays/Array_Ledger_5_Range_Queries.html`.

## Math — modular arithmetic helper template

Standing template for any mod-1e9+7 (or other prime mod) problem:
`madd(a,b) = (a%MOD+b%MOD)%MOD`, `mmul(a,b)`, `msub(a,b)` (can go negative
— never used as the final answer directly), `mpow(a,b)` (fast
exponentiation for modular inverse via Fermat's little theorem, `minv(a)
= mpow(a, MOD-2)`), `mdiv(a,b) = mmul(a, minv(b))`, and `mcorr(a) =
(a%MOD+MOD)%MOD` to fix up a possibly-negative intermediate — apply
`mcorr` once, at the very end, not after every subtraction. See
`arrays/20_distinct_subsequences`, `dp/01_dice_combinations`.

## Arrays — dynamic gap tracking with set + multiset

For "insert points one at a time into a range, report the longest empty
gap after each insertion," use two containers with different jobs: a
`set` of boundary positions (seeded with the range's two endpoints as
sentinels) for O(log n) predecessor/successor lookup of a new point via
`lower_bound` + `prev()`; and a `multiset` of gap *lengths* for O(1) max
via `*rbegin()` (must be `multiset` — lengths can repeat even when
positions can't). Each insertion destroys exactly one gap (found via the
predecessor/successor pair) and creates two new ones. Erase the destroyed
length by iterator (`gaps.erase(gaps.find(len))`), never by value
(`gaps.erase(len)` deletes every gap of that length, not just the one
that broke). See `arrays/18_traffic_lights`.

## Arrays — patience-sorting greedy with a multiset of "pile tops"

For "minimum number of piles/towers/sequences to partition a sequence,
processing in given order, where each pile must stay monotonic" (Dilworth-
type problems), keep a `multiset` of each pile's current top value — not
`set`, since two piles can legitimately share a top value. For each new
element, binary-search (`upper_bound`/`lower_bound`, whichever matches the
strictness of the monotonic rule) for the tightest-fitting existing pile;
if found, erase that top and insert the new value (placing tightest-fit
first preserves the more "open" piles for future elements — this greedy
choice is the crux of correctness); if not found, insert as a brand-new
pile. Answer = final multiset size. No manual shifting needed — the
multiset keeps itself sorted through insert/erase. See
`arrays/17_tower_of_cubes`.

## Arrays — incremental invariant maintenance under localized updates

When a running count depends on a per-index local condition (here: "is
pos[i] < pos[i-1]") and updates only change a *few* underlying values
(here: pos[] for the two swapped values), don't recompute the whole count
per update. Identify exactly which local conditions ("edges") could
possibly flip because of the changed values — usually a small, fixed-size
neighborhood per changed value (here: 2 edges per value, since value `w`
only participates in edges `(w-1,w)` and `(w,w+1)`). Dedupe overlapping
edges with a `std::set` rather than hand-rolled casework. Then:
subtract each affected edge's old contribution, apply the update, add
back each edge's new contribution. Never recompute "after" without first
undoing "before" — that double-counts. See
`arrays/15_collecting_numbers_ii`.

## Arrays — greedy contiguous-range extension for subset sums

For "smallest sum not formable as a subset sum," sort ascending and
maintain the invariant that every sum in `[0, R]` is achievable using
coins processed so far. The next coin `x` extends the range iff `x <=
R+1` (equality included — `x == R+1` still closes the gap), giving new
range `[0, R+x]`; the first coin that fails this (`x > R+1`) proves `R+1`
is unreachable, and every later (larger, sorted) coin only makes the gap
worse, so stop immediately and answer `R+1`. See
`arrays/13_missing_coin_sum`.

## Arrays — sweep line via +1/-1 events for max concurrency

For "max number of intervals simultaneously active" (as opposed to total
covered length — see the union-of-intervals sweep below), don't reason
about the raw `(start,end)` pairs directly. Split each into two separate
timestamped events (`start -> +1`, `end -> -1`), sort all `2n` events by
time, and sweep once: maintain a running total and track its max
separately (`best = max(best, running)`) — the final running total is
always 0, so the answer has to be captured mid-sweep, not read off the
end. See `arrays/10_restaurant_customers`.

## Arrays — sort, converge-from-both-ends greedy pairing

When pairing up elements of a *single* array under a per-pair capacity
constraint, minimizing pair (group) count, sort and use two pointers
starting at opposite ends. The extreme (heaviest/largest) unmatched
element is always resolved this step — try pairing it with the current
lightest/smallest unmatched element; if it fits, consume both, else it
goes alone and only the extreme pointer moves. Always advance the extreme
pointer and always charge one group per step; the crossing/equal-pointer
case resolves the last single element for free without special-casing.
See `arrays/09_ferris_wheel`.

## Arrays — sort-both-sides two-pointer greedy matching

When matching two groups under a per-pair tolerance/range condition, and
each element on both sides can be used at most once, sort both arrays and
sweep with one pointer per side instead of checking each element against
the other side independently (independent checks double-count a shared
element across matches). Three cases per step: current right-side value
too small for current left-side element -> it's too small for every later
(sorted-ascending) left element too, discard it (`j++`); too big -> only
this left element is unmatchable *so far*, a later larger one might still
fit it, advance the left pointer instead (`i++`); fits -> match and consume
both (`count++; i++; j++`). See `arrays/08_apartments`.

## Arrays — discard-while-negative-total greedy

When you're choosing a subset + assigning increasing weights (positions)
to maximize a weighted sum, and any element can be dropped, sort
ascending and start by including everything. Popping the front (smallest)
element changes the answer by exactly `-T`, where `T` is the sum of all
currently-included elements — the popped value's own magnitude cancels
out of that delta entirely. So: keep popping the smallest while `T < 0`
(it strictly helps), stop the instant `T >= 0`. No floor-at-0 clamp
needed — the identity naturally drives the answer to 0 if `T` stays
negative all the way to empty. See `arrays/04_reducing_dishes`.

## DP — 1D bottom-up, sum over fixed-size window of prior states

When order matters (each distinct sequence of choices counts separately,
not just each distinct multiset), `dp[i]` = number of ways to reach state
`i`, defined as the sum of `dp[i-k]` over every valid last-choice `k`
(bounded by `i-k >= 0`). Seed `dp[0] = 1` (the empty/no-op state) rather
than hardcoding early entries — the same recurrence then produces
`dp[1..k]` correctly with no special-casing. See
`dp/01_dice_combinations`.

Variant — unbounded reuse, minimizing count instead of counting ways:
`dp[left]` = min items needed to reach `left`, defined as `min over all
choices c<=left of dp[left-c]+1`. A 2D memoized recursion keyed on
`(choice_index, left)` also works (0/1-knapsack-shaped: stay on the same
index to reuse, advance to permanently drop a choice) but is unnecessary
here — since every choice is legal at every state regardless of history
(true unbounded reuse, order-independent), the index dimension collapses
away into a single loop over all choices per `left`. Watch two gotchas:
seed `dp[0]=0` (not the count-of-ways `1`), and guard `dp[left-c] ==
INF` before adding `+1` so an infeasible sub-result never contaminates a
real candidate. See `dp/02_minimizing_coins`.

Variant — unbounded reuse, order-matters counting (merges the two
variants above): `dp[sum] = sum over all coins c<=sum of dp[sum-c]` via
`madd`, same "no index dimension needed" collapse as the minimizing
variant, but summing (counting all ordered ways) instead of taking a
min. Base case `dp[0] = 1` (count-of-ways identity), not `0` and not the
min-variant's `0`. See `dp/03_coin_combinations_i`.

Variant — unbounded reuse, order-doesn't-matter counting (combinations,
not permutations): unlike every variant above, the coin-index dimension
does NOT collapse away for free — the natural recursion is
`rec(i,left) = rec(i,left-c[i]) [take, stay on i] + rec(i+1,left) [skip,
advance]`, which genuinely needs `i`. The collapse to a single 1D
`dp[sum]` array only works because of loop nesting: **coins outer, sum
inner** (`dp[sum] = madd(dp[sum], dp[sum-c])` per coin, sum ascending
within each coin's pass) — this folds each coin's contribution into the
array once, as an update to whatever baseline already sat there, which is
what makes coin-processing order irrelevant and collapses the "skip"
case into a no-op copy. Contrast with `dp/03`'s nesting (sum outer, coins
inner), which is what makes it count permutations instead. Also: at
`n=100, x=1e6`, the naive 2D table is ~808MB — over typical 512MB limits
— so here the space reduction is load-bearing, not just tidy. See
`dp/04_coin_combinations_ii`.
