# dsa-prep

DSA practice for placement interviews. Every problem is one flat `.cpp` file under its topic — no per-problem folders.

## Layout

```
topic/Problem_Name.cpp       # the solution (self-contained)
LEDGER.html                  # master recall reference — every solved problem
arrays/Array_Ledger_*.html   # child ledgers by pattern family
ledger/                      # shared CSS + JS for the ledger pages
```

See `CLAUDE.md` for the full file conventions and `CONTEXT.md` for the domain language.

## Compile & run

```bash
g++ -O2 -std=c++17 -o /tmp/a.out topic/Problem_Name.cpp && /tmp/a.out
```
