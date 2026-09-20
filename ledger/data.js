/* ledger/data.js — shared runtime for LEDGER.html and every child ledger.
 *
 * Loaded with <script src>, never fetch(): Chrome blocks fetch() over file://
 * and these pages must work by double-clicking them, with no server.
 *
 * Each child ledger owns exactly one data file in ledger/data/<slug>.js which
 * calls LEDGER.add(...) at load. A child ledger loads only its own; LEDGER.html
 * loads all of them. See docs/adr/0001-shared-ledger-assets-over-standalone-html.md
 */
window.LEDGER = (function () {
  var children = [];   // {slug, topic, title, file, part, problems:[...]}

  /* Topic metadata. Order here is the order on the master page. */
  var TOPICS = {
    arrays:      { label: 'Arrays',      dir: 'arrays' },
    graphs:      { label: 'Graphs',      dir: 'graphs' },
    dp:          { label: 'DP',          dir: 'dp' },
    trees:       { label: 'Trees',       dir: 'trees' },
    mathematics: { label: 'Mathematics', dir: 'mathematics' },
    linked_list: { label: 'Linked List', dir: 'linked_list' },
    strings:     { label: 'Strings',     dir: 'strings' }
  };

  /* meta: {slug, topic, title, file, part}
   * problems: [{name, anchor, fam, inv, time}]  — inv/time may contain HTML entities
   * excluded: [{file, why}]                     — optional
   */
  function add(meta, problems, excluded) {
    meta.problems = problems || [];
    meta.excluded = excluded || [];
    children.push(meta);
  }

  function esc(s) {
    return String(s).replace(/&(?![a-zA-Z#0-9]+;)/g, '&amp;')
                    .replace(/</g, '&lt;').replace(/>/g, '&gt;');
  }

  /* href from page at `depth` dirs below repo root ('' for root, '..' for a child) */
  function link(base, child, anchor) {
    var p = TOPICS[child.topic].dir + '/' + child.file + '#' + anchor;
    return base ? base + '/' + p : p;
  }

  function allRows() {
    var rows = [];
    children.forEach(function (c) {
      c.problems.forEach(function (p) { rows.push({ c: c, p: p }); });
    });
    return rows;
  }

  /* ---- master page: topic cards ---- */
  function renderCards(el, base) {
    var byTopic = {};
    children.forEach(function (c) { (byTopic[c.topic] = byTopic[c.topic] || []).push(c); });
    var html = '';
    Object.keys(TOPICS).forEach(function (t) {
      var cs = byTopic[t]; if (!cs) return;
      var n = cs.reduce(function (a, c) { return a + c.problems.length; }, 0);
      html += '<div class="topic-card"><h3>' + esc(TOPICS[t].label) +
              '<span class="n">' + n + '</span></h3><ul>';
      cs.forEach(function (c) {
        var href = (base ? base + '/' : '') + TOPICS[t].dir + '/' + c.file;
        html += '<li><a href="' + href + '">' + esc(c.title) + '</a>' +
                '<span class="n">' + c.problems.length + '</span></li>';
      });
      html += '</ul></div>';
    });
    el.innerHTML = html;
  }

  /* ---- global / per-page problem table ---- */
  function renderTable(tbody, base, opts) {
    opts = opts || {};
    var rows = allRows();
    if (opts.slug) rows = rows.filter(function (r) { return r.c.slug === opts.slug; });
    var html = '';
    rows.forEach(function (r) {
      html += '<tr><td><a href="' + link(base, r.c, r.p.anchor) + '">' +
              esc(r.p.name) + '</a></td>' +
              (opts.slug ? '' : '<td class="mono">' + esc(TOPICS[r.c.topic].label) + '</td>') +
              '<td class="mono">' + esc(r.p.fam) + '</td>' +
              '<td class="mono">' + r.p.inv + '</td>' +
              '<td class="mono num">' + r.p.time + '</td></tr>';
    });
    tbody.innerHTML = html;
    return rows.length;
  }

  /* ---- live filter over a rendered table ---- */
  function wireFilter(input, tbody, countEl) {
    var total = tbody.rows.length;
    input.addEventListener('input', function () {
      var q = input.value.trim().toLowerCase(), shown = 0;
      Array.prototype.forEach.call(tbody.rows, function (tr) {
        var hit = !q || tr.textContent.toLowerCase().indexOf(q) !== -1;
        tr.hidden = !hit; if (hit) shown++;
      });
      if (countEl) countEl.textContent = shown + ' of ' + total + ' problems';
    });
  }

  function mount(base) {
    base = base || '';
    var cards = document.getElementById('cards');
    if (cards) renderCards(cards, base);
    var tbody = document.getElementById('master-body');
    if (tbody) {
      var n = renderTable(tbody, base, { slug: document.body.dataset.slug || null });
      var countEl = document.getElementById('count');
      if (countEl) countEl.textContent = n + ' problems';
      var f = document.getElementById('filter');
      if (f) wireFilter(f, tbody, countEl);
    }
  }

  document.addEventListener('DOMContentLoaded', function () {
    mount(document.body.dataset.base || '');
  });

  return { add: add, TOPICS: TOPICS, children: children, mount: mount };
})();
