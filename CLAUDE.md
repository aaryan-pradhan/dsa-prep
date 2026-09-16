# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Purpose

DSA practice repo for placement interviews. Not a library or application — every "feature" is a new problem folder. Optimize for fast, low-friction problem solving over code architecture.

## Layout

Every problem is ONE flat file directly under its topic: `topic/Title_Case_Name.cpp`,
e.g. `arrays/Distinct_Values.cpp`, `dp/Book_Shop.cpp`. No per-problem folder,
no separate `problem.md` — assert-based (or CSES-stdin-based) `main()`, no
Python unless explicitly asked for.

Each file is self-contained, top to bottom:

- Header comment: `// Problem:` / `// Link:` (when a real URL/ID exists) /
  `// Pattern:` / `// Time:` / `// Space:`.
- Problem statement folded in as a comment block right under the header —
  the full pasted statement for CSES/CPH-sourced problems, a condensed
  paraphrase for problems written directly through dsa-buddy.
- The code.
- `// Recall Trail` comment block at the very bottom — pattern name, key
  decision points condensed, one-line core approach. Scannable in ~10
  seconds; this is what spaced revision reads, in place of the old
  `problem.md`'s `## Recall Trail` section.

CSES-sourced files (solved via the CPH VS Code extension, dropped in
directly) additionally keep `#include <bits/stdc++.h>` plus the full
13-line macro block (`ll`/`endl`/`fr`/`sc`/`MOD`/`MOD1`/`INF`/`mp`/`PI`/
`py`/`pn`/`pll`) verbatim even where unused — that's the standing shape
for that source, not something to trim per file.

`<bits/stdc++.h>` is fine to use. macOS's `g++` is clang under the hood and
doesn't ship that header natively, but this machine has a shim at
`~/.local/include/bits/stdc++.h` on `CPATH` (set in `~/.zshrc`), so plain
`g++ ... solution.cpp` resolves it from any directory without extra flags.
(Non-interactive shells that don't load `~/.zshrc` need `-I ~/.local/include`
explicitly.)

Topics: `arrays`, `backtracking`, `dp`, `graphs`, `heaps`, `linked_list`,
`math`, `stacks_queues`, `strings`, `trees`. New topics get created
on-demand as problems don't fit existing ones — no fixed list.

Keep the header comment format (`Problem` / `Link` / `Pattern` / `Time` /
`Space`) and the statement/Recall-Trail comment placement consistent across
new solution files.

The CSES progress tracker no longer lives here — it moved on 15 Sep 2026 to
`../timetable/CSES_TRACKER.md` (next to the daily plans). It's a
section-by-section checklist in priority order; a solved problem is ticked
and linked back to its flat file here
(`- [x] [Name](../dsa-prep/topic/File.cpp)`).
`*.bin` (CPH-compiled binaries) and `.cph/` (CPH metadata) are
gitignored — CPH-extension artifacts, not source.

## Commands

```bash
# compile + run a C++ solution
g++ -O2 -std=c++17 -o /tmp/a.out topic/Problem_Name.cpp && /tmp/a.out
```

There is no repo-wide build/lint config — each problem is self-contained.

## Workflow

Governed by the `dsa-buddy` skill (`~/.claude/skills/dsa-buddy/SKILL.md`) — don't reproduce its process here. Repo-specific notes only:

- New problem: dsa-buddy writes the single `topic/Title_Case_Name.cpp` file as its last step, not before — no folder to create up front.
- Reopening an existing file is spaced recall, not a fresh request — check for an existing solution + Recall Trail (bottom-of-file comment) before rewriting.
- Style comes only from what's shared in this repo, never outside directories; `patterns.md` at the repo root tracks it.
