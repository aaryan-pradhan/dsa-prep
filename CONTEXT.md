# CONTEXT

Domain language for this repo. Terms here are the ones that carry meaning
across conversations — not implementation details.

## Golden Rules

The standing constraint on every ledger's prose. Stated by the repo owner:

```
    Solutions are simple.
    Proofs are simple.
    Implementations are simple.
```

If an explanation in a ledger is not simple, it is wrong — not the reader.
A key observation that needs a paragraph is a sign the observation hasn't
been reduced far enough yet.

## Terms

### Ledger
A pre-interview recall reference for solved problems. Not a tutorial and not
a solution archive — its job is to let a pattern be *re-derived and coded
live*, from a differently-worded problem, in an interview. Every ledger is
HTML, opened locally from the repo.

### Master ledger
`LEDGER.html` at the repo root. The single entry point. Renders topic cards
and one global table of every problem from `ledger/data.js`. Contains no
problem content of its own.

### Child ledger
A single HTML page covering one *pattern-family group* within a topic, e.g.
`arrays/Array_Ledger_2_Sort_Greedy.html`. Held to roughly 7–12 problems so a
page stays scannable. A topic has as many child ledgers as it needs; adding
problems eventually means adding a child ledger, not growing one without
bound.

### Entry
One problem inside a child ledger. Fixed five-part shape, in this order:

1. **The Ask** — the statement reduced to its mathematical baseline. What is
   being asked, stated simply and in symbols. Not the pasted CSES prose.
2. **Key observations** — the numbered facts that make the solution possible.
3. **Brute force → why it dies** — the naive approach, its complexity, and
   the specific constraint that kills it. This is what motivates the next
   line: *therefore, introduce <data structure>*.
4. **Diagram** — inline SVG of a small concrete test case, where the
   structure is not obvious from prose.
5. **Implementation** — the solution file verbatim, minus its `/* */`
   statement block, plus a brief prose note on the implementation.

### Verbatim
In an Implementation block: the `.cpp` exactly as written, including the
macro block and whatever inline comments exist. Two things are removed and
nothing else — the `/* */` pasted-statement comment (part 1 replaces it) and
the `// Recall Trail` block (the entry as a whole replaces it). Comments are
never *added* to someone's code in a ledger. A sparsely-commented solution
ships sparsely commented; the five-part breakdown carries the explanation.

### Excluded
A solution file the ledger deliberately does not cover, because it does not
compile or never produces an answer. Excluded files are named in the child
ledger's footer with their exact error. They are never silently dropped, and
a working version is never invented to fill the gap.

### Recall Trail
The `// Recall Trail` comment block at the bottom of each `.cpp` (see
CLAUDE.md). Primary source material when building an entry — it records what
the solver actually found hard, which is what part 2 and the Gotcha callout
should be built from.

## Ledger system

### Architecture
All ledger pages share two assets — `ledger/ledger.css` (the visual system)
and `ledger/data.js` (the problem index). No build step. Pages work by
double-clicking them over `file://`. See
`docs/adr/0001-shared-ledger-assets-over-standalone-html.md` for the full
trade-off.

Adding a problem: append one row to `ledger/data/<slug>.js`, paste one
`<article class="entry">` into the matching child ledger. The master page,
topic cards, and every table update themselves.

### Migration state (as of 16 Sep 2026)
- **Arrays**: 100% MIGRATED. All 5 child ledgers (`Array_Ledger_1_Linear_Scan.html` through `Array_Ledger_5_Range_Queries.html`) and all 5 data JS files (`arrays_1` through `arrays_5`) are complete. The old monolithic `arrays/Array_Ledger.html` has been deleted.
- **DP**: MIGRATED. `dp/DP_Ledger_1_Sums_Knapsack.html` (10) and `dp/DP_Ledger_2_Tables_Intervals.html` (9), data files `dp_1`/`dp_2`. `dp/Counting_Towers.cpp` excluded (does not compile). Old `dp/DP_Ledger.html` deleted.
- **Graphs**: MIGRATED. `Graph_Ledger_1_Traversal.html` (9), `Graph_Ledger_2_Shortest_Paths.html` (7), `Graph_Ledger_3_Structure.html` (9), data files `graphs_1`–`graphs_3`. Excluded: `Planets_Queries_II` and `Planets_Cycles` (don't compile) and `Nested_Ranges_Count` (no output on sample). Misfiled `Concert_Tickets`, `Movie_Festival`, `Sum_of_Two_Values` moved to `arrays/` and added to `Array_Ledger_2`/`_4`. Old `graphs/Graph_Ledger.html` deleted.
- **Other topics** (trees, math, linked_list, strings): No ledgers yet.
- **LEDGER.html**: Loads the array (`arrays_1`–`arrays_5`), DP (`dp_1`, `dp_2`) and graph (`graphs_1`–`graphs_3`) data files. Remaining topics get script tags as their child ledgers are built.
