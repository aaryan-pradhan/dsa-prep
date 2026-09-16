/* ledger/data/linked_list_1_pointers.js — index rows for one child ledger.
 * Adding a problem: append one object to the array. Nothing else to update. */
LEDGER.add(
  { slug: 'linked_list_1_pointers',
    topic: 'linked_list',
    title: "Pointer Surgery",
    file: 'Linked_List_Ledger_1_Pointer_Surgery.html',
    part: 1 },
  [
    { name: "Merge Sort Linked List",
      anchor: 'merge-sort-linked-list',
      fam: "Split & merge",
      inv: "fast = head-&gt;next &rArr; first middle; cut; recurse; dummy merge",
      time: "O(N log N)" },
    { name: "Reorder List I",
      anchor: 'reorder-list-i',
      fam: "Split & merge",
      inv: "second middle; cut; reverse second half; interleave while second",
      time: "O(N)" },
    { name: "Reverse Nodes in k-Group",
      anchor: 'reverse-nodes-in-k-group',
      fam: "Group reversal",
      inv: "tail = K&minus;1 steps; cut; reverse; prev-&gt;next = newHead; head-&gt;next = nextGroup; prev = head",
      time: "O(N)" }
  ],
  [

  ]
);
