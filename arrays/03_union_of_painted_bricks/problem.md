# Union of Painted Bricks

Link: (pasted, no URL given)
Pattern: sort intervals by L, merge overlapping, sum merged lengths
Time: O(N log N)  Space: O(N)

## Statement

N days, each day Mantesh paints all bricks in [L_i, R_i] (repaint is a
no-op). Brick numbers can be up to ~1e9, so a per-brick boolean array
doesn't fit. Count total distinct bricks painted = size of the union of N
intervals.

## Examples

    (2,5),(10,10),(4,5),(3,7),(12,14) -> 10

## Recall Trail

- Marking every brick is out given the coordinate range — sort segments by
  `l` and merge overlapping ranges into contiguous blocks instead.
- Merge condition: `l_j <= cur_r` means the next segment overlaps (or
  touches) the block being built — extend `cur_r = max(cur_r, r_j)`.
  Otherwise the current block is finished: flush its length
  (`cur_r - cur_l + 1`) into the running total, then start a new block at
  `l_j`.
- Ties on `l` don't need special handling — sorting groups them adjacently,
  and `max` picks up the correct `r` regardless of which same-`l` segment
  is processed first.
- The last block never gets a "next segment" to trigger its flush — must
  flush it explicitly once after the loop ends.
- Use `long long` throughout: with N and coordinates both up to ~1e5/1e9,
  the total can reach ~1e14, well past `int` range.
