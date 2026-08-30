# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Purpose

DSA practice repo for placement interviews. Not a library or application — every "feature" is a new problem folder. Optimize for fast, low-friction problem solving over code architecture.

## Layout

Each problem lives in its own folder under its topic: `topic/NN_problem_slug/`, e.g. `arrays/03_two_sum/`.

- `problem.md` — statement/link, pattern, complexity target
- `solution.cpp` — assert-based `main()`, no Python unless explicitly asked for

`<bits/stdc++.h>` is fine to use. macOS's `g++` is clang under the hood and
doesn't ship that header natively, but this machine has a shim at
`~/.local/include/bits/stdc++.h` on `CPATH` (set in `~/.zshrc`), so plain
`g++ ... solution.cpp` resolves it from any directory without extra flags.

Topics: `arrays`, `backtracking`, `dp`, `graphs`, `heaps`, `linked_list`,
`math`, `stacks_queues`, `strings`, `trees`. New topics get created
on-demand as problems don't fit existing ones — no fixed list.

Use `templates/solution_template.py` and `templates/solution_template.cpp` as the starting point for every new solution file — keep the header comment format (`Problem` / `Link` / `Pattern` / `Time` / `Space`) consistent.

## Commands

```bash
# compile + run a C++ solution
g++ -O2 -std=c++17 -o /tmp/a.out topic/problem_slug/solution.cpp && /tmp/a.out

# same, with debug() / debugArr() macros available (templates/algodebug.h)
g++ -O2 -std=c++17 -Itemplates -o /tmp/a.out topic/problem_slug/solution.cpp && /tmp/a.out
```

There is no repo-wide build/lint config — each problem is self-contained.

`templates/algodebug.h` provides `debug(...)` / `debugArr(...)` macros (compiled out under `-DONLINE_JUDGE`). Because solutions live nested under `topic/NN_slug/`, not flat, `#include "algodebug.h"` needs `-Itemplates` on the compile line to resolve — plain quote-include won't find it otherwise.

## Workflow

Governed by the `dsa-buddy` skill (`~/.claude/skills/dsa-buddy/SKILL.md`) — don't reproduce its process here. Repo-specific notes only:

- New problem: create the topic-numbered folder first; dsa-buddy fills in `problem.md`/`solution.*`/`test_solution.py` as its last step, not before.
- Reopening an old folder is spaced recall, not a fresh request — check for an existing solution + Recall Trail before rewriting.
- Style comes only from what's shared in this repo, never outside directories; `patterns.md` at the repo root tracks it.
