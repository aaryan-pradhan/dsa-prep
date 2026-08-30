# dsa-prep

DSA practice for placement interviews, driven by the `dsa-buddy` Claude Code skill — see workflow below.

## Layout

Each problem is a folder under its topic: `topic/NN_problem_slug/`

- `problem.md` — statement/link, pattern, complexity target
- `solution.py` + `test_solution.py` (pytest)
- `solution.cpp` (optional — assert-based `main()`, compile with `g++ -O2 -o a.out solution.cpp && ./a.out`)

## Workflow

Paste a problem + a correct solution → short one-at-a-time chat questions converge to the full approach → code written and verified once, at the end → a `## Recall Trail` appended to `problem.md` for revision.

Old problems resurface later, unannounced, for spaced recall. `patterns.md` at the repo root accumulates per-pattern style notes as they come up.

## Run tests

```bash
# python
pytest topic/problem_slug/

# c++
g++ -O2 -std=c++17 -o /tmp/a.out topic/problem_slug/solution.cpp && /tmp/a.out
```
