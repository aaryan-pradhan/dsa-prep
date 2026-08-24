# dsa-prep

DSA practice for placement interviews. Fast-lane / deep-lane recall system — see workflow below.

## Layout

Each problem is a folder under its topic: `topic/NN_problem_slug/`

- `problem.md` — statement/link, pattern, complexity target
- `solution.py` + `test_solution.py` (pytest)
- `solution.cpp` (optional — assert-based `main()`, compile with `g++ -O2 -o a.out solution.cpp && ./a.out`)

## Workflow

**Fast lane** (most problems, breadth): paste problem + old C++ solution → state approach in 1-2 lines before writing code → code only the core function, no boilerplate, ~8-10 min timebox → verify immediately (pytest or compiled asserts).

**Deep lane** (new problems, or fast-lane misses): full untimed solve, no reference shown.

Old problems get resurfaced later, unannounced, for spaced recall.

## Run tests

```bash
# python
pytest topic/problem_slug/

# c++
g++ -O2 -std=c++17 -o /tmp/a.out topic/problem_slug/solution.cpp && /tmp/a.out
```
