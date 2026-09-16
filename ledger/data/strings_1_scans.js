/* ledger/data/strings_1_scans.js — index rows for one child ledger.
 * Adding a problem: append one object to the array. Nothing else to update. */
LEDGER.add(
  { slug: 'strings_1_scans',
    topic: 'strings',
    title: "String Scans",
    file: 'String_Ledger_1_Scans.html',
    part: 1 },
  [
    { name: "DNA Repetition",
      anchor: 'dna-repetition',
      fam: "Run-length scan",
      inv: "s[i] == s[i&minus;1] ? count++ : count = 1; max after each",
      time: "O(n)" }
  ],
  [

  ]
);
