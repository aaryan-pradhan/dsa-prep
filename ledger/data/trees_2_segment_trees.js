/* ledger/data/trees_2_segment_trees.js — index rows for one child ledger.
 * Adding a problem: append one object to the array. Nothing else to update. */
LEDGER.add(
  { slug: 'trees_2_segment_trees',
    topic: 'trees',
    title: "Segment Trees & Flattening",
    file: 'Tree_Ledger_2_Segment_Trees.html',
    part: 2 },
  [
    { name: "Subtree Queries",
      anchor: 'subtree-queries',
      fam: "Euler tour + segment tree",
      inv: "subtree(s) = [tin[s], tout[s]]; point set at tin, range sum",
      time: "O((n+q) log n)" },
    { name: "Hotel Queries",
      anchor: 'hotel-queries',
      fam: "Segment tree descent",
      inv: "max tree; go left if left.mx &ge; r; prune mx &lt; r; leaf &minus;= r",
      time: "O((n+m) log n)" },
    { name: "List Removals",
      anchor: 'list-removals',
      fam: "Segment tree descent",
      inv: "0/1 count tree; left.sum &ge; k ? left : right with k &minus; left.sum",
      time: "O(n log n)" },
    { name: "Range Update Queries",
      anchor: 'range-update-queries',
      fam: "Lazy propagation",
      inv: "push: sum += len&middot;lazy, children.lazy += lazy; push on every visit",
      time: "O((n+q) log n)" },
    { name: "Forest Queries",
      anchor: 'forest-queries',
      fam: "2D prefix sums",
      inv: "ps[y2][x2] &minus; ps[y1&minus;1][x2] &minus; ps[y2][x1&minus;1] + ps[y1&minus;1][x1&minus;1]",
      time: "O(n&sup2; + q)" }
  ],
  [
    { file: 'trees/Path_Queries.cpp', why: "unfinished: 'algodebug.h' not found; stnode used before declaration; query has no body" },
    { file: 'trees/Salary_Queries.cpp', why: "empty template: 'algodebug.h' not found; solve() empty" }
  ]
);
