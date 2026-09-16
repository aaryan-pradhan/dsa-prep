/* ledger/data/graphs_2_shortest_paths.js — index rows for one child ledger.
 * Adding a problem: append one object to the array. Nothing else to update. */
LEDGER.add(
  { slug: 'graphs_2_shortest_paths',
    topic: 'graphs',
    title: "Shortest Paths",
    file: 'Graph_Ledger_2_Shortest_Paths.html',
    part: 2 },
  [
    { name: "Shortest Routes I",
      anchor: 'shortest-routes-i',
      fam: "Dijkstra and variants",
      inv: "pop min d; skip if done; relax dist[v] &gt; dist[u] + w",
      time: "O((n+m) log m)" },
    { name: "Flight Discount",
      anchor: 'flight-discount',
      fam: "Dijkstra and variants",
      inv: "state (city, used) ; edges: (a,0)→(b,0) c, (a,0)→(b,1) ⌊c/2⌋, (a,1)→(b,1) c",
      time: "O((n+m) log m)" },
    { name: "Flight Routes",
      anchor: 'flight-routes',
      fam: "Dijkstra and variants",
      inv: "each vertex may be popped k times; the first k pops of n are the answers",
      time: "O(k\u00b7(n+m) log(km))" },
    { name: "Investigation",
      anchor: 'investigation',
      fam: "Dijkstra and variants",
      inv: "d+w &lt; dist: overwrite (ways, min, max); d+w == dist: merge",
      time: "O((n+m) log m)" },
    { name: "High Score",
      anchor: 'high-score',
      fam: "Bellman-Ford",
      inv: "weights negated; after n rounds, a still-relaxable edge into a vertex that reaches n &rArr; &minus;1",
      time: "O(n\u00b7m)" },
    { name: "Cycle Finding",
      anchor: 'cycle-finding',
      fam: "Bellman-Ford",
      inv: "dist ≡ 0 (virtual source); x = vertex relaxed in round n; walk par n times, then collect cycle",
      time: "O(n\u00b7m)" },
    { name: "Shortest Routes II",
      anchor: 'shortest-routes-ii',
      fam: "Floyd\u2013Warshall",
      inv: "g[i][j] = min(g[i][j], g[i][k] + g[k][j]), k outermost",
      time: "O(n\u00b3 + q)" }
  ],
  [

  ]
);
