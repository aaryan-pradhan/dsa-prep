# Child ledger build spec

Read `ledger/TEMPLATE.html` first — it is a complete, working child ledger with
one fully worked entry (Increasing Array). Copy its structure exactly. Read
`CONTEXT.md` for the terminology. Read `ledger/data/_template.js` for the data file.

## Hard rules

1. **Never edit any `.cpp` file.** Read-only pass over the repo.
2. **Do not write CSS.** `ledger/ledger.css` is the only stylesheet; link it as
   `../ledger/ledger.css`. If you need a style that isn't there, reuse an
   existing class rather than inventing one.
3. **Verify before including — compiling is not enough.** First
   `g++ -O2 -std=c++17 -I$HOME/.local/include -o /tmp/x <file>`.
   Then, whenever the `/* */` statement block carries a sample input and expected
   output, **run the binary on that sample and diff the result**. A file that fails
   to compile, or compiles but disagrees with its own sample, goes in the footer
   `.excluded` list with the exact evidence (the command, the got, the expected) —
   never silently dropped and never "fixed" by inventing a working version.
   This is not hypothetical: `arrays/Nested_Ranges_Count.cpp` compiles with zero
   diagnostics and prints `1 0 0 0` where its own sample expects `2 0 0 0`.
4. **Golden Rules** govern the prose: *Solutions are simple. Proofs are simple.
   Implementations are simple.* One-line observations, symbols over sentences.
   If an observation needs a paragraph, it hasn't been reduced far enough.

## The five-part entry

Every `<article class="entry">` has all five `.sec` blocks in order:

1. **The ask** — the statement reduced to its mathematical baseline. What is
   asked, stated simply, plus a `.formal` line in symbols where it helps.
   Never the pasted CSES prose.
2. **Key observations** — `<ol class="obs">`, one line each, the facts that make
   the solution possible. Typically 3–5.
3. **Brute force → why it dies** — a `.brute` table with four rows in this order:
   `naive` (what the obvious approach is), `cost` (its complexity), `dies at`
   (row class `dies` — the *specific constraint* from the problem and the
   resulting operation count), `therefore` (row class `therefore` — the data
   structure or idea this motivates, and the new complexity).
4. **Diagram** — inline SVG in `<figure class="diagram">`, of a small concrete
   test case, ideally the problem's own sample. Use only the `s-*` classes from
   ledger.css (`s-box`, `s-fill`, `s-hi`, `s-edge`, `s-warn`, `s-good`, `s-t`,
   `s-tm`, `s-td`, `s-ta`) so it themes correctly in light and dark — never
   hardcode a colour. Always set `viewBox` and a `role="img"` + `aria-label`.
   Always write a `<figcaption>` saying what the picture shows.
   Skip this section only when the structure is genuinely obvious from prose.
5. **Implementation** — a `.impl-note` paragraph (2–4 sentences on how the code
   realises the idea; mention the one line a reader would misread), then
   `.src-meta` with the repo path, then `<pre class="source"><code>` holding the
   file **verbatim**.

Then the two callouts, unchanged from the existing ledgers: `.callout.gotcha`
(a real trap in *this* code) and `.callout.trigger` (the one-line recognition
phrase for a differently-worded problem).

## What "verbatim" means

The `.cpp` exactly as written — macro block included, `//` comments included,
sparse commenting left sparse. Remove exactly two things:

- the `/* ... */` pasted-statement block (section 1 replaces it)
- the trailing `// Recall Trail` block (the entry as a whole replaces it)

Add nothing. Do not insert explanatory comments into the user's code. Escape
`<`, `>`, `&` for HTML. Preserve indentation and blank lines.

The `// Recall Trail` is your best source for sections 2 and the Gotcha — it
records what the solver actually found hard.

## Files you write

- `<topic>/<File>.html` — the child ledger, from TEMPLATE.html
- `ledger/data/<slug>.js` — one `LEDGER.add(...)` call, one row per problem

`<body data-base=".." data-slug="<slug>">`. Each `row.anchor` must match an
`<article id>` on the page. Scripts at the end of body, in this order:
`<script src="../ledger/data.js"></script>` then `<script src="../ledger/data/<slug>.js"></script>`.

## Page furniture

Masthead (kicker links back to `../LEDGER.html`), `#master` table section,
`#recognition` section, then one `<section class="family">` per family, then the
footer with the `.excluded` box. Recognition rules: 4–7 numbered judgment calls,
each one demonstrated by at least two problems **on this page** — never a generic
rule you didn't see in the code.

## Report back

One short paragraph: file path, problem count, family names, anything excluded
and why. Do not paste the HTML.
