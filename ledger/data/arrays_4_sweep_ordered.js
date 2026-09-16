/* ledger/data/arrays_4_sweep_ordered.js — index rows for one child ledger.
 * Adding a problem: append one object to the array. Nothing else to update. */
LEDGER.add(
  { slug: 'arrays_4_sweep_ordered',     // must match <body data-slug>
    topic: 'arrays',                    // key in LEDGER.TOPICS
    title: 'Sweep &amp; Ordered Set',   // shown on the master page card
    file: 'Array_Ledger_4_Sweep_Ordered.html',
    part: 4 },
  [
    { name: 'Restaurant Customers',
      anchor: 'restaurant-customers',
      fam: 'interval sweep',
      inv: 'a&#7522;&rarr;+1, b&#7522;&rarr;&minus;1; running += &delta;; best = max(best, running)',
      time: 'O(n log n)' },

    { name: 'Union of Painted Bricks',
      anchor: 'union-of-painted-bricks',
      fam: 'interval sweep',
      inv: 'sort by L; l &le; curR ? curR = max(curR, r) : flush curR&minus;curL+1',
      time: 'O(N log N)' },

    { name: 'Nested Ranges Check',
      anchor: 'nested-ranges-check',
      fam: 'interval sweep',
      inv: 'sort l&uarr;, r&darr;; fwd: r &le; maxr &rArr; contained; bwd: r &ge; minr &rArr; contains',
      time: 'O(n log n)' },

    { name: 'Room Allocation',
      anchor: 'room-allocation',
      fam: 'interval assignment',
      inv: 'ties: +1 before &minus;1; k = max concurrency; pool.pop_back() / push_back(room)',
      time: 'O(n log n)' },

    { name: 'Tower of Cubes',
      anchor: 'tower-of-cubes',
      fam: 'ordered-set greedy',
      inv: 'it = tops.upper_bound(c); if (it != end) erase(it); insert(c); ans = |tops|',
      time: 'O(n log n)' },

    { name: 'Traffic Lights',
      anchor: 'traffic-lights',
      fam: 'ordered-set greedy',
      inv: 'erase(find(hi&minus;lo)); insert(p&minus;lo), insert(hi&minus;p); ans = *gaps.rbegin()',
      time: 'O(n log n)' },
    { name: 'Concert Tickets',
      anchor: 'concert-tickets',
      fam: 'ordered-set greedy',
      inv: "it = prev(prices.upper_bound(maxᵢ)); sell *it, erase that one copy",
      time: 'O((n+m) log n)' }
  ],
  [
    { file: 'arrays/Nested_Ranges_Count.cpp',
      why: 'compiles clean but wrong on its own sample — expected "2 0 0 0", produces ' +
           '"1 0 0 0". It is the Check sweep with ans1[idx]=1 swapped for ans1[idx]++, ' +
           'and each index is visited once per pass, so the counter can never exceed 1. ' +
           'The counting variant needs a Fenwick/segment tree over compressed endpoints.' }
  ]
);
