# 1. Shared ledger assets over standalone HTML

Date: 2026-09-16

## Status

Accepted.

## Context

The ledgers started as three self-contained HTML files — `arrays/Array_Ledger.html`,
`dp/DP_Ledger.html`, `graphs/Graph_Ledger.html`. Each carried its own full copy
of the visual system (~368 lines of CSS) and its own hardcoded master table.
The `recall-ledger` skill explicitly calls for "a complete standalone document".

Three things broke that:

1. The ledgers went stale. 13 of 40 `arrays/` problems and 8 of 31 `graphs/`
   problems were never added, and `trees/`, `math/`, `linked_list/` and
   `strings/` had no ledger at all.
2. The per-entry format got much heavier — the statement reduced to a
   mathematical baseline, key observations, a brute-force-and-why-it-dies
   section, a hand-authored inline SVG, and the full verbatim solution. At that
   density a topic no longer fits one page; `arrays/` alone splits into four.
3. The repo owner is actively adding problems. Maintainability, not
   self-containment, is the binding constraint: "the idea is to make it
   maintainable — I am going to add more problems, so it should be easy to
   update the new ledgers into the master."

Fifteen standalone files would mean fifteen copies of the CSS and a master
table that silently drifts out of date the first time a problem is added and
the master isn't hand-edited.

## Decision

Ledger pages share two assets:

- `ledger/ledger.css` — the entire visual system. The only stylesheet.
- `ledger/data.js` — one row per problem (name, topic, family, invariant,
  time, href). The only index.

`LEDGER.html` and every child ledger load both and render their tables from
`data.js` at page load. `data.js` is loaded with `<script src>` rather than
`fetch()`, because Chrome blocks `fetch()` against `file://` — the pages must
work by double-clicking them, with no server.

Adding a problem is then two local edits: append one row to `data.js`, paste
one `<article>` into the right child ledger. Counts, topic cards, the global
table and every child's master table follow automatically.

This supersedes the `recall-ledger` skill's standalone-document rule for this
repo.

## Consequences

Good:

- A theme change is one edit to `ledger.css`, not fifteen.
- The master cannot drift from the children — both read the same `data.js`.
- Adding a problem no longer requires regenerating anything.
- No build step, which the repo does not have and does not want (CLAUDE.md:
  "There is no repo-wide build/lint config").

Bad:

- A ledger file is no longer portable on its own. Moving or emailing a single
  child ledger gives an unstyled page with an empty table. They live in the
  git repo; this is accepted.
- The pages now depend on JavaScript. With JS disabled, the hand-written
  entries still render — only the generated tables are lost.
- `data.js` is duplicated state: a problem's row there and its `<article>` in a
  child ledger can disagree. Mitigated by the anchor in `href` being checkable,
  not by any enforcement.

Rejected alternative: a `tools/build_ledger.sh` that scrapes child anchors and
regenerates the master. Keeps the pages pure HTML, but introduces a build step
to a repo that has none, and silently rots whenever the script isn't run.
