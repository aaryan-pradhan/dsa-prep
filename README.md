# dsa-prep

DSA practice for placement interviews. Each solved problem is a self-contained
C++17 file stored directly under its topic. The repository is designed for
fast practice and recall, not as a reusable C++ library.

## Repository layout

```
arrays/                      # array and CSES solutions
backtracking/                # backtracking solutions
dp/                          # dynamic programming solutions
graphs/                      # graph solutions
heaps/, linked_list/, ...    # other topic folders
LEDGER.html                  # master recall reference
ledger/                      # shared ledger CSS and JavaScript
docs/adr/                    # architecture decisions
```

Every solution follows this shape:

```text
topic/Problem_Name.cpp
├── problem metadata and statement
├── solution
└── Recall Trail
```

There are no per-problem folders or separate problem files. New solutions
should use `Title_Case_Name.cpp` and include the problem, pattern, time, and
space information at the top.

## Ledger system

The ledgers are local HTML recall references, not tutorials. Open `LEDGER.html`
in a browser to browse the problems currently indexed. Child ledgers group
problems by topic and pattern; shared styles and data live in `ledger/`.

The pages have no build step and can be opened directly from the repository.
See `CONTEXT.md` for the ledger vocabulary and entry format.

## Compile and run

```bash
g++ -O2 -std=c++17 -o /tmp/a.out topic/Problem_Name.cpp && /tmp/a.out
```

For CSES-style solutions, provide input through standard input:

```bash
g++ -O2 -std=c++17 -o /tmp/a.out topic/Problem_Name.cpp
/tmp/a.out < input.txt
```

## Local files

CPH binaries and metadata, Python cache files, Claude/GSD planning metadata,
editor settings, and macOS `.DS_Store` files are ignored by Git. The local
`CLAUDE.md` file contains assistant-specific repository instructions and is
not part of the tracked project documentation.
