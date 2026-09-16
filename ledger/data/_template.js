/* ledger/data/<slug>.js — index rows for one child ledger.
 * Adding a problem: append one object to the array. Nothing else to update. */
LEDGER.add(
  { slug: 'arrays_1_linear_scan',        // must match <body data-slug>
    topic: 'arrays',                     // key in LEDGER.TOPICS
    title: 'Linear Scan',                // shown on the master page card
    file: 'Array_Ledger_1_Linear_Scan.html',
    part: 1 },
  [
    { name: 'Increasing Array',
      anchor: 'increasing-array',        // must match the <article id>
      fam: 'running floor',
      inv: 'prev = max(prev, a&#7522;); cost += max(0, prev &minus; a&#7522;)',
      time: 'O(n)' }
  ],
  [ /* excluded: { file: 'arrays/Sum_of_Divisors.cpp', why: 'file is 1 byte' } */ ]
);
