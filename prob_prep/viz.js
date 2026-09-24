// Interactive diagrams for the prob_prep ledgers.
// Usage: <div class="viz" data-viz="walk" data-p='{"lo":-8,"hi":4}'></div>
// Each widget draws with the page's .fig SVG classes, so it follows light/dark mode.
(function () {
const NS = 'http://www.w3.org/2000/svg';
const css = `
.viz{border:1px dashed var(--rule);border-radius:8px;padding:.6rem .8rem;margin:.8rem 0}
.viz .cap{font-size:.92rem;margin:.1rem 0 .4rem}
.viz .ctl{display:flex;flex-wrap:wrap;gap:.45rem .8rem;align-items:center;font-size:.85rem;margin:.35rem 0}
.viz .ctl label{display:inline-flex;gap:.35rem;align-items:center}
.viz input[type=range]{width:7rem;accent-color:var(--accent)}
.viz input[type=text],.viz select{font:inherit;font-size:.85rem;background:var(--card);color:var(--ink);border:1px solid var(--rule);border-radius:6px;padding:.2rem .4rem}
.viz .out{font-size:.85rem;font-variant-numeric:tabular-nums;margin:.3rem 0 0}
.viz .out b{color:var(--accent)}
.viz svg{display:block;width:100%;height:auto;max-width:640px;margin:.3rem auto;font-size:12px}
.viz svg text{fill:var(--ink);font-family:inherit}
.viz .red{fill:#c8423b} .viz .blk{fill:var(--ink)} .viz .down{fill:var(--rule)}
.viz .hit{color:var(--accent);font-weight:700}
`;
const st = document.createElement('style'); st.textContent = css; document.head.appendChild(st);

// ---------- helpers ----------
function el(tag, attrs, parent) {
  const e = document.createElementNS(NS, tag);
  for (const k in attrs) e.setAttribute(k, attrs[k]);
  if (parent) parent.appendChild(e);
  return e;
}
function txt(parent, x, y, s, cls, anchor) {
  const t = el('text', { x, y, 'text-anchor': anchor || 'middle', class: cls || '' }, parent);
  t.textContent = s; return t;
}
function svg(w, h, label) {
  const s = el('svg', { viewBox: `0 0 ${w} ${h}`, class: 'fig', role: 'img', 'aria-label': label });
  return s;
}
function html(s) { const d = document.createElement('div'); d.innerHTML = s.trim(); return d.firstChild; }
function btn(parent, label, fn) {
  const b = document.createElement('button'); b.type = 'button'; b.textContent = label;
  b.addEventListener('click', fn); parent.appendChild(b); return b;
}
function slider(parent, label, min, max, step, val, fn) {
  const l = document.createElement('label');
  l.innerHTML = `${label} <input type="range" min="${min}" max="${max}" step="${step}" value="${val}"><output>${val}</output>`;
  const i = l.querySelector('input'), o = l.querySelector('output');
  i.addEventListener('input', () => { o.textContent = i.value; fn(+i.value); });
  parent.appendChild(l); return i;
}
const f3 = x => (Math.round(x * 1000) / 1000).toFixed(3);
const f2 = x => (Math.round(x * 100) / 100).toFixed(2);
function shuffle(a) { for (let i = a.length - 1; i > 0; i--) { const j = Math.random() * (i + 1) | 0; [a[i], a[j]] = [a[j], a[i]]; } return a; }

// ---------- walk: ±1 walk between lo and hi ----------
// p: {lo (or null), hi, p, seesaw, sliders:["a","b","p"], drift}
function walk(root, P) {
  let lo = P.lo, hi = P.hi, p = P.p ?? 0.5;
  const cap = root.appendChild(html('<p class="cap"></p>'));
  const seesaw = P.seesaw ? root.appendChild(svg(560, 140, 'Seesaw: the two end points balance at the start 0')) : null;
  const plot = root.appendChild(svg(560, 210, 'Sample path of the walk'));
  const ctl = root.appendChild(html('<div class="ctl"></div>'));
  const out = root.appendChild(html('<p class="out"></p>'));
  let runs = 0, tops = 0, sumT = 0, last = null;

  function theory() {
    const q = 1 - p;
    if (lo === null) return { r: 1, ET: hi / (p - q) };
    const a = -lo, b = hi;
    if (Math.abs(p - 0.5) < 1e-9) return { r: a / (a + b), ET: a * b };
    const rho = q / p, r = (1 - Math.pow(rho, -a)) / (Math.pow(rho, b) - Math.pow(rho, -a));
    return { r, ET: (b * r - a * (1 - r)) / (p - q) };
  }
  function simulate() {
    let s = 0; const path = [0];
    while (s < hi && (lo === null || s > lo) && path.length < 20000) { s += Math.random() < p ? 1 : -1; path.push(s); }
    return path;
  }
  function drawSeesaw() {
    if (!seesaw) return;
    seesaw.innerHTML = '';
    const { r } = theory(), x0 = 40, x1 = 520, X = v => x0 + (v - lo) / (hi - lo) * (x1 - x0), y = 60;
    el('line', { x1: x0, y1: y, x2: x1, y2: y, class: 'ln' }, seesaw);
    el('path', { d: `M${X(0) - 12},${y + 26} L${X(0)},${y + 2} L${X(0) + 12},${y + 26} Z`, class: 'nd' }, seesaw);
    txt(seesaw, X(0), y + 42, 'start 0', 'm');
    const R = v => 6 + 26 * Math.sqrt(v);
    el('circle', { cx: X(lo), cy: y - R(1 - r) - 2, r: R(1 - r), class: 'bad' }, seesaw);
    el('circle', { cx: X(hi), cy: y - R(r) - 2, r: R(r), class: 'rg' }, seesaw);
    txt(seesaw, X(lo), y + 22, `${lo}`, 'g'); txt(seesaw, X(hi), y + 22, `+${hi}`, 'a');
    txt(seesaw, X(lo), y + 40, `P = ${f3(1 - r)}`, 'g'); txt(seesaw, X(hi), y + 40, `P = ${f3(r)}`, 'a');
    txt(seesaw, 280, 132, `${hi} × ${f3(r)}  =  ${-lo} × ${f3(1 - r)}   (the beam balances at 0)`, 'm');
  }
  function drawPlot(path) {
    plot.innerHTML = '';
    const L = lo === null ? Math.min(-4, ...(path || [0])) : lo;
    const n = Math.max(40, path ? path.length - 1 : 0);
    const x0 = 40, x1 = 545, y0 = 185, y1 = 15;
    const X = i => x0 + i / n * (x1 - x0), Y = v => y0 - (v - L) / (hi - L) * (y0 - y1);
    el('line', { x1: x0, y1: Y(0), x2: x1, y2: Y(0), class: 'mu' }, plot);
    el('line', { x1: x0, y1: Y(hi), x2: x1, y2: Y(hi), class: 'ac dsh' }, plot);
    txt(plot, x0 - 6, Y(hi) + 4, `+${hi}`, 'a', 'end'); txt(plot, x0 - 6, Y(0) + 4, '0', 'm', 'end');
    if (lo !== null) { el('line', { x1: x0, y1: Y(lo), x2: x1, y2: Y(lo), class: 'gl dsh' }, plot); txt(plot, x0 - 6, Y(lo) + 4, `${lo}`, 'g', 'end'); }
    if (P.drift) {
      const m = 2 * p - 1, iEnd = Math.min(n, hi / m);
      el('line', { x1: X(0), y1: Y(0), x2: X(iEnd), y2: Y(m * iEnd), class: 'gl dsh' }, plot);
      txt(plot, X(iEnd) - 4, Y(m * iEnd) + 16, `average path: +${f2(m)} per step`, 'g', 'end');
    }
    txt(plot, (x0 + x1) / 2, 204, `step →  (0 … ${n})`, 'm');
    if (!path) { txt(plot, (x0 + x1) / 2, 100, 'press "One walk"', 'm'); return; }
    el('polyline', { points: path.map((v, i) => `${X(i)},${Y(v)}`).join(' '), class: 'ac', 'stroke-width': 1.8 }, plot);
    const e = path[path.length - 1];
    el('circle', { cx: X(path.length - 1), cy: Y(e), r: 5, class: e >= hi ? 'rg' : 'bad' }, plot);
  }
  function report() {
    const { r, ET } = theory();
    const lastS = last ? `Last walk: ended at <b>${last[last.length - 1] > 0 ? '+' : ''}${last[last.length - 1]}</b> after <b>${last.length - 1}</b> steps.<br>` : '';
    out.innerHTML = lastS + (runs ? `${runs} walks: ` +
      (lo !== null ? `ended at +${hi} in <b>${f3(tops / runs)}</b> of them (theory ${f3(r)}); ` : '') +
      `average steps <b>${f2(sumT / runs)}</b> (theory ${f2(ET)}).` : 'No walks yet.');
  }
  function run(k) {
    for (let j = 0; j < k; j++) { const pa = simulate(); runs++; sumT += pa.length - 1; if (pa[pa.length - 1] >= hi) tops++; last = pa; }
    drawPlot(last); report();
  }
  function reset() { runs = tops = sumT = 0; last = null; drawSeesaw(); drawPlot(null); report(); setCap(); }
  function setCap() { cap.innerHTML = P.cap ? P.cap.replace('{lo}', lo).replace('{hi}', hi).replace('{p}', p) : ''; }
  btn(ctl, 'One walk', () => run(1)); btn(ctl, '1000 walks', () => run(1000)); btn(ctl, 'Reset', reset);
  const S = P.sliders || [];
  if (S.includes('a')) slider(ctl, 'lower', 1, 12, 1, -lo, v => { lo = -v; reset(); });
  if (S.includes('b')) slider(ctl, 'upper', 1, 12, 1, hi, v => { hi = v; reset(); });
  if (S.includes('p')) slider(ctl, 'P(up)', 0.3, 0.8, 0.05, p, v => { p = v; reset(); });
  reset();
}

// ---------- cards: stop and bet the next card is red ----------
function cards(root, P) {
  root.appendChild(html('<p class="cap">Flip cards. The line is <b>X = reds left ÷ cards left</b> = your chance of winning if you stop now. It wanders, but on average it never moves.</p>'));
  const s = root.appendChild(svg(560, 190, 'Deck, and the path of X = reds left / cards left'));
  const ctl = root.appendChild(html('<div class="ctl"></div>'));
  const ctl2 = root.appendChild(html('<div class="ctl"></div>'));
  const out = root.appendChild(html('<p class="out"></p>'));
  let deck, i, hist, done;
  function newDeck() { deck = shuffle(Array.from({ length: 52 }, (_, k) => k < 26)); i = 0; hist = [0.5]; done = null; draw(); }
  const reds = () => deck.slice(i).filter(Boolean).length;
  function draw() {
    s.innerHTML = '';
    for (let k = 0; k < 52; k++) {
      const x = 20 + k * 10;
      const cls = k < i || (done !== null && k === i) ? (deck[k] ? 'red' : 'blk') : 'down';
      el('rect', { x, y: 10, width: 8, height: 22, rx: 1.5, class: cls }, s);
    }
    if (done !== null) el('rect', { x: 18 + i * 10, y: 7, width: 12, height: 28, rx: 2, fill: 'none', class: 'ac' }, s);
    const x0 = 20, x1 = 540, y0 = 170, y1 = 50, X = k => x0 + k / 51 * (x1 - x0), Y = v => y0 - v * (y0 - y1);
    el('line', { x1: x0, y1: Y(.5), x2: x1, y2: Y(.5), class: 'gl dsh' }, s);
    txt(s, x1, Y(.5) - 6, 'start ½', 'g', 'end');
    el('line', { x1: x0, y1: Y(0), x2: x1, y2: Y(0), class: 'mu' }, s); el('line', { x1: x0, y1: Y(1), x2: x1, y2: Y(1), class: 'mu' }, s);
    txt(s, x0 - 4, Y(1) + 4, '1', 'm', 'end'); txt(s, x0 - 4, Y(0) + 4, '0', 'm', 'end');
    el('polyline', { points: hist.map((v, k) => `${X(k)},${Y(v)}`).join(' '), class: 'ac' }, s);
    txt(s, 280, 186, 'cards flipped →', 'm');
    const r = reds(), m = 52 - i;
    out.innerHTML = done === null
      ? `Flipped ${i}. Left: ${r} red of ${m}. If you stop now you win with probability <b>${r}/${m} = ${f3(r / m)}</b>.`
      : `You stopped with X = ${f3(hist[hist.length - 1])}. Next card is <b>${deck[i] ? 'red: you win' : 'black: you lose'}</b>.`;
  }
  btn(ctl, 'Flip', () => { if (done !== null || i >= 51) return; i++; hist.push(reds() / (52 - i)); draw(); });
  btn(ctl, 'Stop & bet red', () => { if (done !== null) return; done = deck[i]; draw(); });
  btn(ctl, 'New deck', newDeck);
  const strat = document.createElement('select');
  strat.innerHTML = '<option value="0">stop at once</option><option value="1">stop the first time reds left &gt; blacks left</option><option value="2">stop the first time X ≥ 0.6</option><option value="3">never stop (bet on the last card)</option>';
  ctl2.appendChild(document.createTextNode('Strategy: ')); ctl2.appendChild(strat);
  btn(ctl2, 'Play 20 000 decks', () => {
    let win = 0; const N = 20000, k = +strat.value;
    for (let t = 0; t < N; t++) {
      const d = shuffle(Array.from({ length: 52 }, (_, j) => j < 26)); let r = 26, j = 0;
      for (; j < 51; j++) {
        const m = 52 - j;
        if (k === 0 || (k === 1 && 2 * r > m) || (k === 2 && r / m >= 0.6)) break;
        if (d[j]) r--;
      }
      if (d[j]) win++;
    }
    out.innerHTML = `Strategy "${strat.options[k].text}": won <b>${f3(win / N)}</b> of ${N} decks. Every strategy lands at ½.`;
  });
  newDeck();
}

// ---------- disc: 2-D lattice walk until r² ≥ R² ----------
function disc(root, P) {
  const R = P.R || 10;
  root.appendChild(html(`<p class="cap">The walk starts at the centre and stops the first time x² + y² ≥ ${R * R}. <b>Watch the exit point:</b> it usually lands <i>outside</i> the circle, not on it.</p>`));
  const s = root.appendChild(svg(360, 360, 'Grid walk leaving a disc'));
  const ctl = root.appendChild(html('<div class="ctl"></div>'));
  const out = root.appendChild(html('<p class="out"></p>'));
  const C = 180, u = 13.5, X = x => C + x * u, Y = y => C - y * u;
  let anim = 0, runs = 0, sumT = 0, sumR = 0, over = 0;
  function base() {
    s.innerHTML = '';
    for (let x = -R - 2; x <= R + 2; x++) for (let y = -R - 2; y <= R + 2; y++)
      el('circle', { cx: X(x), cy: Y(y), r: x * x + y * y < R * R ? 1.4 : 0.8, class: 'dot', 'fill-opacity': x * x + y * y < R * R ? .45 : .2 }, s);
    el('circle', { cx: C, cy: C, r: R * u, class: 'gl' }, s);
  }
  function one() {
    let x = 0, y = 0; const pts = [[0, 0]];
    while (x * x + y * y < R * R) { const d = Math.random() * 4 | 0; if (d === 0) x++; else if (d === 1) x--; else if (d === 2) y++; else y--; pts.push([x, y]); }
    return pts;
  }
  function stats() {
    return runs ? `${runs} walks: average steps <b>${f2(sumT / runs)}</b>, average exit x² + y² <b>${f2(sumR / runs)}</b> (they match: E[T] = E[x² + y²]); overshoot past ${R * R} in <b>${f3(over / runs)}</b> of walks. Exact: 104.69.` : '';
  }
  btn(ctl, 'Animate one walk', () => {
    cancelAnimationFrame(anim); base();
    const pts = one(); const pl = el('polyline', { points: '', class: 'ac', 'stroke-width': 1.5 }, s);
    let k = 0;
    (function step() {
      k = Math.min(pts.length, k + 3);
      pl.setAttribute('points', pts.slice(0, k).map(([a, b]) => `${X(a)},${Y(b)}`).join(' '));
      if (k < pts.length) { anim = requestAnimationFrame(step); return; }
      const [a, b] = pts[pts.length - 1];
      el('circle', { cx: X(a), cy: Y(b), r: 5, class: a * a + b * b > R * R ? 'bad' : 'rg' }, s);
      out.innerHTML = `Exit at (${a}, ${b}) after <b>${pts.length - 1}</b> steps: x² + y² = <b>${a * a + b * b}</b>${a * a + b * b > R * R ? ' — past the circle' : ' — exactly on the circle'}.<br>` + stats();
    })();
  });
  btn(ctl, '2000 walks', () => {
    for (let t = 0; t < 2000; t++) { const pts = one(), [a, b] = pts[pts.length - 1]; runs++; sumT += pts.length - 1; sumR += a * a + b * b; if (a * a + b * b > R * R) over++; }
    out.innerHTML = stats();
  });
  base();
}

// ---------- repeat: roll a die until the first value comes back ----------
function repeat(root) {
  const face = ['', '⚀', '⚁', '⚂', '⚃', '⚄', '⚅'];
  root.appendChild(html('<p class="cap">The first roll (boxed) sets the target. Keep rolling until it shows again. Each roll averages 3.5, and there are 7 rolls on average, so the sum averages 7 × 3.5.</p>'));
  const seq = root.appendChild(html('<p style="font-size:1.8rem;line-height:1.3;margin:.2rem 0;word-break:break-all"></p>'));
  const ctl = root.appendChild(html('<div class="ctl"></div>'));
  const out = root.appendChild(html('<p class="out"></p>'));
  const roll = () => 1 + (Math.random() * 6 | 0);
  function one() { const a = [roll()]; do a.push(roll()); while (a[a.length - 1] !== a[0]); return a; }
  btn(ctl, 'Roll a game', () => {
    const a = one();
    seq.innerHTML = a.map((v, k) => k === 0 || k === a.length - 1 ? `<span class="hit" style="outline:2px solid var(--accent);border-radius:4px">${face[v]}</span>` : face[v]).join(' ');
    out.innerHTML = `${a.length} rolls, sum <b>${a.reduce((x, y) => x + y)}</b>.`;
  });
  btn(ctl, '10 000 games', () => {
    let T = 0, S = 0; const N = 10000;
    for (let t = 0; t < N; t++) { const a = one(); T += a.length; S += a.reduce((x, y) => x + y); }
    out.innerHTML = `Average rolls <b>${f2(T / N)}</b> (theory 7). Average sum <b>${f2(S / N)}</b> (theory 7 × 3.5 = 24.5).`;
  });
}

// ---------- pattern: expected tosses until a coin pattern ----------
function pattern(root, P) {
  root.appendChild(html('<p class="cap">Type any H/T pattern. When the pattern is finally completed, the gamblers still holding money are exactly those whose bets so far spell a <b>prefix that is also a suffix</b>. Their money adds up to E[T].</p>'));
  const ctl = root.appendChild(html('<div class="ctl"></div>'));
  const inp = document.createElement('input'); inp.type = 'text'; inp.value = P.pat || 'HHTTHTT'; inp.maxLength = 12; inp.size = 14;
  ctl.appendChild(document.createTextNode('Pattern: ')); ctl.appendChild(inp);
  const s = root.appendChild(svg(560, 60, 'Pattern with the surviving gamblers bracketed'));
  const tbl = root.appendChild(html('<div class="tw"></div>'));
  const ctl2 = root.appendChild(html('<div class="ctl"></div>'));
  const out = root.appendChild(html('<p class="out"></p>'));
  function calc() {
    const w = inp.value.toUpperCase().replace(/[^HT]/g, ''), n = w.length; let E = 0; const rows = [], live = [];
    for (let L = 1; L <= n; L++) { const ok = w.slice(0, L) === w.slice(n - L); if (ok) { E += 2 ** L; live.push(L); } rows.push([L, w.slice(0, L), w.slice(n - L), ok]); }
    return { w, n, E, rows, live };
  }
  function draw() {
    const { w, n, E, rows, live } = calc();
    s.setAttribute('viewBox', `0 0 560 ${40 + 14 * live.length}`);
    s.innerHTML = ''; const x0 = 280 - n * 14;
    [...w].forEach((c, k) => txt(s, x0 + 28 * k + 14, 22, c, c === 'H' ? 'a' : 'g'));
    live.forEach((L, j) => {
      const y = 34 + 14 * j, xa = x0 + 28 * (n - L) + 4, xb = x0 + 28 * n - 4;
      el('path', { d: `M${xa},${y - 6} L${xa},${y} L${xb},${y} L${xb},${y - 6}`, class: 'ac' }, s);
      txt(s, xb + 8, y + 4, `$${2 ** L}`, 'a', 'start');
    });
    tbl.innerHTML = '<table><tr><th>L</th><th>first L</th><th>last L</th><th>same?</th><th>money</th></tr>' +
      rows.map(([L, a, b, ok]) => `<tr><td>${L}</td><td>${a}</td><td>${b}</td><td>${ok ? '✓' : '✗'}</td><td>${ok ? '$' + 2 ** L : '—'}</td></tr>`).join('') + '</table>';
    out.innerHTML = n ? `E[T] = ${live.map(L => '2^' + L).join(' + ')} = <b>${E}</b>` : 'Type H and T.';
  }
  inp.addEventListener('input', draw);
  btn(ctl2, 'Simulate 5000 runs', () => {
    const { w, n, E } = calc(); if (!n || n > 10) { out.innerHTML += ' (simulation needs 1–10 letters)'; return; }
    let S = 0; const N = 5000;
    for (let t = 0; t < N; t++) { let str = '', k = 0; do { str = (str + (Math.random() < .5 ? 'H' : 'T')).slice(-n); k++; } while (str !== w); S += k; }
    out.innerHTML = `E[T] = <b>${E}</b>. Simulated average over ${N} runs: <b>${f2(S / N)}</b>.`;
  });
  draw();
}

// ---------- chain: Markov chain with a token, P(X_n = j) bars and Monte Carlo ----------
// p: {S:[[label,x,y],...], P:[[...]], start:i | [dist], bars, stat:'path'|'absorb'|'time'|'hit'|'return',
//     path:[i0,i1,...], target:i, w, h, cap}
function chain(root, P) {
  const S = P.S, M = P.P, n = S.length, W = P.w || 560, H = P.h || 260;
  const absorbing = S.map((_, i) => M[i][i] === 1);
  let start = Array.isArray(P.start) ? null : (P.start ?? 0);
  const dist0 = () => Array.isArray(P.start) ? P.start.slice() : S.map((_, i) => +(i === start));
  if (P.cap) root.appendChild(html(`<p class="cap">${P.cap}</p>`));
  const s = root.appendChild(svg(W, H + (P.bars ? 82 : 0), 'Markov chain diagram'));
  const ctl = root.appendChild(html('<div class="ctl"></div>'));
  const out = root.appendChild(html('<p class="out"></p>'));
  let cur, t, dist, lastEdge, trail;
  const R = 22, pos = i => ({ x: S[i][1], y: S[i][2] });
  function pick(row) { let u = Math.random(), j = 0; for (; j < n - 1; j++) { u -= row[j]; if (u < 0) break; } return j; }
  function sampleStart() { return start !== null ? start : pick(P.start); }
  function edgeGeom(i, j) {
    const a = pos(i), b = pos(j);
    if (i === j) {
      let cx = 0, cy = 0; S.forEach((_, k) => { cx += S[k][1] / n; cy += S[k][2] / n; });
      let dx = a.x - cx, dy = a.y - cy, L = Math.hypot(dx, dy) || 1; dx /= L; dy /= L; if (n === 1) { dx = 0; dy = -1; }
      const px = -dy, py = dx, o = { x: a.x + dx * R, y: a.y + dy * R };
      const c1 = { x: o.x + dx * 46 + px * 26, y: o.y + dy * 46 + py * 26 }, c2 = { x: o.x + dx * 46 - px * 26, y: o.y + dy * 46 - py * 26 };
      return { d: `M${a.x + px * 10 + dx * 18},${a.y + py * 10 + dy * 18} C${c1.x},${c1.y} ${c2.x},${c2.y} ${a.x - px * 10 + dx * 20},${a.y - py * 10 + dy * 20}`, lx: a.x + dx * 58, ly: a.y + dy * 58 + 4 };
    }
    const dx = b.x - a.x, dy = b.y - a.y, L = Math.hypot(dx, dy), ux = dx / L, uy = dy / L;
    const bend = M[j][i] > 0 ? 18 : 0, nx = -uy * bend, ny = ux * bend;
    const x1 = a.x + ux * R, y1 = a.y + uy * R, x2 = b.x - ux * (R + 3), y2 = b.y - uy * (R + 3);
    const mx = (x1 + x2) / 2 + nx, my = (y1 + y2) / 2 + ny;
    const q = 0.72, bx = (1 - q) ** 2 * x1 + 2 * (1 - q) * q * mx + q * q * x2, byy = (1 - q) ** 2 * y1 + 2 * (1 - q) * q * my + q * q * y2;
    const side = bend ? 1 : 0.6;   // label sits beside the arrow, near its head
    return { d: `M${x1},${y1} Q${mx},${my} ${x2},${y2}`, lx: bx - uy * 13 * side, ly: byy + ux * 13 * side + 4 };
  }
  const fmt = v => (Math.round(v * 1000) / 1000).toString().replace(/^0\./, '.');
  function draw() {
    s.innerHTML = '';
    const defs = el('defs', {}, s);
    ['ahv', 'ahva'].forEach((id, k) => {
      const m = el('marker', { id: id + root.dataset.uid, viewBox: '0 0 10 10', refX: 9, refY: 5, markerWidth: 7, markerHeight: 7, orient: 'auto-start-reverse' }, defs);
      el('path', { d: 'M0,0L10,5L0,10z', style: `fill:var(${k ? '--accent' : '--muted'})` }, m);
    });
    for (let i = 0; i < n; i++) for (let j = 0; j < n; j++) {
      if (!(M[i][j] > 0) || (absorbing[i] && i === j && P.hideAbsLoops !== false)) continue;
      const g = edgeGeom(i, j), hot = lastEdge && lastEdge[0] === i && lastEdge[1] === j;
      el('path', { d: g.d, class: hot ? 'ac' : 'mu', 'marker-end': `url(#${hot ? 'ahva' : 'ahv'}${root.dataset.uid})` }, s);
      txt(s, g.lx, g.ly, fmt(M[i][j]), hot ? 'a' : 'm');
    }
    for (let i = 0; i < n; i++) {
      const { x, y } = pos(i), onPath = P.path && trail && trail[P.path.indexOf(i)] !== undefined;
      el('circle', { cx: x, cy: y, r: R, class: absorbing[i] ? 'bad' : 'nd', style: 'cursor:pointer' }, s)
        .addEventListener('click', () => { if (!Array.isArray(P.start)) { start = i; reset(); } });
      txt(s, x, y + 5, S[i][0], '', 'middle').style.pointerEvents = 'none';
      if (i === cur) el('circle', { cx: x, cy: y, r: R + 5, class: 'ac' }, s);
      if (P.bars) {
        const bh = 56 * dist[i], by = H + 60;
        el('rect', { x: x - 12, y: by - bh, width: 24, height: Math.max(bh, .5), class: 'rg' }, s);
        txt(s, x, by + 12, fmt(dist[i]), 'a');
      }
    }
    if (P.bars) txt(s, 8, H + 12, `P(Xₙ = j) for n = ${t}`, 'm', 'start');
  }
  function status() {
    const bits = [];
    bits.push(`Step ${t}: at <b>${S[cur][0]}</b>.`);
    if (P.path) bits.push(`Path so far: ${trail.map(k => S[k][0]).join(' → ')}.`);
    out.innerHTML = bits.join(' ') + (out.dataset.mc ? '<br>' + out.dataset.mc : '');
  }
  function step() {
    if (absorbing[cur]) return false;
    const j = pick(M[cur]); lastEdge = [cur, j]; cur = j; t++; trail.push(j);
    dist = dist.map((_, k) => dist.reduce((acc, v, i) => acc + v * M[i][k], 0));
    return true;
  }
  function reset() { cur = sampleStart(); t = 0; dist = dist0(); lastEdge = null; trail = [cur]; out.dataset.mc = ''; draw(); status(); }
  btn(ctl, 'Step', () => { step(); draw(); status(); });
  btn(ctl, 'Run until stuck', () => { let k = 0; while (step() && k++ < 1000); draw(); status(); });
  btn(ctl, 'Reset', reset);
  if (P.stat) btn(ctl, 'Run 10 000', () => {
    const N = 10000; let msg = '';
    if (P.stat === 'path') {
      let hit = 0; const N = 200000;
      for (let r = 0; r < N; r++) { let c = pick(P.start), ok = c === P.path[0]; for (let k = 1; k < P.path.length && ok; k++) { c = pick(M[c]); ok = c === P.path[k]; } if (ok) hit++; }
      msg = `${N} runs: path ${P.path.map(k => S[k][0]).join(' → ')} happened <b>${(hit / N).toFixed(4)}</b> of the time.`;
    } else if (P.stat === 'absorb') {
      const cnt = new Array(n).fill(0); let T = 0;
      for (let r = 0; r < N; r++) { let c = sampleStart(), k = 0; while (!absorbing[c] && k < 1e5) { c = pick(M[c]); k++; } cnt[c]++; T += k; }
      msg = `${N} runs from ${S[sampleStart()][0]}: ` + S.map((x, i) => absorbing[i] ? `ended in ${x[0]} <b>${f3(cnt[i] / N)}</b>` : '').filter(Boolean).join(', ') + `; average steps <b>${f2(T / N)}</b>.`;
    } else if (P.stat === 'time') {
      const cnt = new Array(n).fill(0); let c = sampleStart();
      for (let r = 0; r < N * 10; r++) { c = pick(M[c]); cnt[c]++; }
      msg = `Fraction of ${N * 10} steps spent in each state: ` + S.map((x, i) => `${x[0]} <b>${f3(cnt[i] / N / 10)}</b>`).join(', ') + '.';
    } else if (P.stat === 'hit' || P.stat === 'return') {
      let T = 0; const tg = P.target;
      for (let r = 0; r < N; r++) { let c = sampleStart(), k = 0; do { c = pick(M[c]); k++; } while (c !== tg && k < 1e5); T += k; }
      msg = `${N} runs: average steps from ${S[sampleStart()][0]} ${sampleStart() === tg ? 'until back at' : 'to reach'} ${S[tg][0]}: <b>${f2(T / N)}</b>.`;
    }
    out.dataset.mc = msg; status();
  });
  if (!Array.isArray(P.start)) ctl.appendChild(html('<span class="m" style="color:var(--muted)">click a state to start there</span>'));
  reset();
}

// ---------- area: geometric probability by throwing points ----------
// p: {xr:[0,1], yr:[0,1], f:"JS boolean expression in x,y", exact, label, xl, yl}
function area(root, P) {
  const [xa, xb] = P.xr || [0, 1], [ya, yb] = P.yr || [0, 1];
  const f = new Function('x', 'y', 'return (' + P.f + ');');
  if (P.cap) root.appendChild(html(`<p class="cap">${P.cap}</p>`));
  const W = 320, H = Math.round(320 * (yb - ya) / (xb - xa)), pad = 34;
  const s = root.appendChild(svg(W + pad + 10, Math.min(H, 420) + pad + 10, 'Region of the sample space'));
  const sc = Math.min(W / (xb - xa), 420 / (yb - ya)), w = (xb - xa) * sc, h = (yb - ya) * sc;
  const X = x => pad + (x - xa) * sc, Y = y => 10 + h - (y - ya) * sc;
  const g = el('g', {}, s), pts = el('g', {}, s);
  const N = 80;
  for (let i = 0; i < N; i++) for (let j = 0; j < N; j++) {
    const x = xa + (i + .5) / N * (xb - xa), y = ya + (j + .5) / N * (yb - ya);
    if (f(x, y)) el('rect', { x: X(xa + i / N * (xb - xa)), y: Y(ya + (j + 1) / N * (yb - ya)), width: w / N + .3, height: h / N + .3, style: 'fill:var(--accent);fill-opacity:.25' }, g);
  }
  el('rect', { x: X(xa), y: Y(yb), width: w, height: h, class: 'ln' }, s);
  txt(s, X(xa), Y(ya) + 16, xa, 'm'); txt(s, X(xb), Y(ya) + 16, xb, 'm'); txt(s, X(xa) - 6, Y(yb) + 4, yb, 'm', 'end');
  txt(s, (X(xa) + X(xb)) / 2, Y(ya) + 28, P.xl || 'x', 'm'); txt(s, X(xa) - 8, (Y(ya) + Y(yb)) / 2, P.yl || 'y', 'm', 'end');
  const ctl = root.appendChild(html('<div class="ctl"></div>')), out = root.appendChild(html('<p class="out"></p>'));
  let tot = 0, hit = 0;
  function throwN(k) {
    for (let i = 0; i < k; i++) {
      const x = xa + Math.random() * (xb - xa), y = ya + Math.random() * (yb - ya), ok = f(x, y); tot++; if (ok) hit++;
      if (pts.childNodes.length < 1500) el('circle', { cx: X(x), cy: Y(y), r: 1.8, class: ok ? 'adot' : 'dot', 'fill-opacity': ok ? 1 : .35 }, pts);
    }
    out.innerHTML = `${tot} random points: <b>${f3(hit / tot)}</b> landed in the shaded region${P.exact !== undefined ? ` (exact ${P.exactLabel || f3(P.exact)})` : ''}.`;
  }
  btn(ctl, 'Throw 100 points', () => throwN(100)); btn(ctl, 'Throw 10 000', () => throwN(10000));
  btn(ctl, 'Clear', () => { pts.innerHTML = ''; tot = hit = 0; out.innerHTML = 'The shaded part is the event. Its share of the box is the probability.'; });
  out.innerHTML = 'The shaded part is the event. Its share of the box is the probability.';
}

// ---------- tree: two-stage probability tree for Bayes ----------
// p: {H:[[label,prior],...], E:"evidence label", like:[P(E|H_i)], sliders:true}
function tree(root, P) {
  const Hs = P.H.map(h => h.slice()), like = P.like.slice();
  if (P.cap) root.appendChild(html(`<p class="cap">${P.cap}</p>`));
  const s = root.appendChild(svg(560, 40 + 70 * Hs.length, 'Probability tree'));
  const ctl = root.appendChild(html('<div class="ctl"></div>')), out = root.appendChild(html('<p class="out"></p>'));
  function draw() {
    s.innerHTML = '';
    const tot = Hs.reduce((a, h, i) => a + h[1] * like[i], 0), rowH = 70;
    txt(s, 30, 30 + rowH * Hs.length / 2, 'start', 'm');
    Hs.forEach((h, i) => {
      const y = 40 + rowH * i + 20, joint = h[1] * like[i];
      el('line', { x1: 60, y1: 26 + rowH * Hs.length / 2, x2: 190, y2: y, class: 'ln', 'stroke-width': 1 + 10 * h[1] }, s);
      txt(s, 125, (26 + rowH * Hs.length / 2 + y) / 2 - 6, f3(h[1]), 'm');
      txt(s, 200, y + 4, h[0], '', 'start');
      el('line', { x1: 290, y1: y, x2: 400, y2: y - 14, class: 'ac', 'stroke-width': 1 + 10 * like[i] }, s);
      el('line', { x1: 290, y1: y, x2: 400, y2: y + 14, class: 'mu', 'stroke-width': 1 + 10 * (1 - like[i]) }, s);
      txt(s, 345, y - 14, f3(like[i]), 'a');
      txt(s, 408, y - 10, `${P.E}: ${f3(joint)}`, 'a', 'start');
      txt(s, 408, y + 18, `not: ${f3(h[1] * (1 - like[i]))}`, 'm', 'start');
    });
    out.innerHTML = `P(${P.E}) = ${Hs.map((h, i) => `${f3(h[1])}·${f3(like[i])}`).join(' + ')} = <b>${f3(tot)}</b>.<br>` +
      Hs.map((h, i) => `P(${h[0]} | ${P.E}) = ${f3(h[1] * like[i])} ÷ ${f3(tot)} = <b>${f3(h[1] * like[i] / tot)}</b>`).join('<br>');
  }
  if (P.sliders) {
    if (Hs.length === 2) slider(ctl, `P(${Hs[0][0]})`, 0, 1, 0.01, Hs[0][1], v => { Hs[0][1] = v; Hs[1][1] = +(1 - v).toFixed(4); draw(); });
    Hs.forEach((h, i) => slider(ctl, `P(${P.E} | ${h[0]})`, 0, 1, 0.01, like[i], v => { like[i] = v; draw(); }));
  }
  draw();
}

// ---------- sim: generic Monte Carlo of a page-defined experiment ----------
// p: {fn:"name in VIZ.fns", exact, exactLabel, what, N}
function sim(root, P) {
  if (P.cap) root.appendChild(html(`<p class="cap">${P.cap}</p>`));
  const ctl = root.appendChild(html('<div class="ctl"></div>')), out = root.appendChild(html('<p class="out"></p>'));
  const fn = VIZ.fns[P.fn], N = P.N || 20000;
  let tot = 0, sum = 0;
  btn(ctl, 'Run once', () => { const r = fn(true); out.innerHTML = (typeof r === 'object' ? r.show : '') ; });
  btn(ctl, `Run ${N.toLocaleString()}`, () => {
    for (let i = 0; i < N; i++) { const r = fn(false); sum += typeof r === 'object' ? r.v : +r; tot++; }
    out.innerHTML = `${tot.toLocaleString()} runs: ${P.what || 'average'} = <b>${f3(sum / tot)}</b>` + (P.exact !== undefined ? ` (exact ${P.exactLabel || f3(P.exact)})` : '') + '.';
  });
}

// ---------- curve: slide x, read one or more curves y(x) ----------
// p: {fn (VIZ.fns name, x -> number or [numbers]), xr:[a,b], step, x0, labels:[...], xl, yl, argmax, info (VIZ.fns name, x -> html)}
function curve(root, P) {
  const fn = VIZ.fns[P.fn], [a, b] = P.xr, step = P.step || (b - a) / 200;
  if (P.cap) root.appendChild(html(`<p class="cap">${P.cap}</p>`));
  const s = root.appendChild(svg(560, 250, 'Curve'));
  const ctl = root.appendChild(html('<div class="ctl"></div>')), out = root.appendChild(html('<p class="out"></p>'));
  const xs = []; for (let x = a; x <= b + 1e-9; x += step) xs.push(+x.toFixed(10));
  const ys = xs.map(x => [].concat(fn(x)));
  const k = ys[0].length, flat = ys.flat().filter(Number.isFinite);
  const lo = Math.min(0, ...flat), hi = Math.max(...flat) * 1.08 || 1;
  const x0 = 56, x1 = 540, y0 = 215, y1 = 12, X = x => x0 + (x - a) / (b - a) * (x1 - x0), Y = y => y0 - (y - lo) / (hi - lo) * (y0 - y1);
  const cls = ['ac', 'gl', 'mu'], tcls = ['a', 'g', 'm'];
  let best = 0; ys.forEach((y, i) => { if (y[0] > ys[best][0]) best = i; });
  function draw(x) {
    s.innerHTML = '';
    el('line', { x1: x0, y1: Y(lo), x2: x1, y2: Y(lo), class: 'ln' }, s); el('line', { x1: x0, y1: y0, x2: x0, y2: y1, class: 'ln' }, s);
    txt(s, x0, y0 + 16, a, 'm'); txt(s, x1, y0 + 16, b, 'm'); txt(s, (x0 + x1) / 2, y0 + 30, P.xl || 'x', 'm');
    txt(s, x0 - 6, Y(hi / 1.08) + 4, f2(hi / 1.08), 'm', 'end'); txt(s, x0 - 6, Y(lo) + 4, f2(lo), 'm', 'end');
    for (let j = 0; j < k; j++) {
      el('polyline', { points: xs.map((xx, i) => Number.isFinite(ys[i][j]) ? `${X(xx)},${Y(ys[i][j])}` : '').join(' '), class: cls[j % 3], 'stroke-width': j ? 2 : 2.5 }, s);
      if (P.labels) txt(s, x1 - 4, 14 + 16 * j, P.labels[j], tcls[j % 3], 'end');
    }
    if (P.argmax) { el('circle', { cx: X(xs[best]), cy: Y(ys[best][0]), r: 5, class: 'bad' }, s); txt(s, X(xs[best]), Y(ys[best][0]) - 10, `best x = ${xs[best]}`, 'g'); }
    const i = Math.round((x - a) / step), yv = ys[Math.max(0, Math.min(xs.length - 1, i))];
    el('line', { x1: X(x), y1: y0, x2: X(x), y2: y1, class: 'mu dsh' }, s);
    yv.forEach((y, j) => Number.isFinite(y) && el('circle', { cx: X(x), cy: Y(y), r: 4, class: j ? 'dot' : 'adot' }, s));
    out.innerHTML = `${P.xl || 'x'} = <b>${x}</b>: ` + yv.map((y, j) => `${P.labels ? P.labels[j] + ' ' : ''}<b>${f3(y)}</b>`).join(', ') + (P.info ? '<br>' + VIZ.fns[P.info](x) : '');
  }
  slider(ctl, P.xl || 'x', a, b, step, P.x0 ?? a, draw);
  draw(P.x0 ?? a);
}

// ---------- dptable: click a cell to see its equation and the cells it uses ----------
// p: {fn (VIZ.fns name) returning {rl, cl, rows:[labels], cols:[labels], val(r,c), deps(r,c), eq(r,c), cls(r,c)}, start:[r,c]}
function dptable(root, P) {
  const T = VIZ.fns[P.fn]();
  if (P.cap) root.appendChild(html(`<p class="cap">${P.cap}</p>`));
  const wrap = root.appendChild(html('<div class="tw"></div>')), out = root.appendChild(html('<p class="out"></p>'));
  function draw(sel) {
    const dep = sel ? T.deps(...sel).map(d => d.join(',')) : [];
    let h = `<table><tr><th>${T.rl} \\ ${T.cl}</th>` + T.cols.map(c => `<th>${c}</th>`).join('') + '</tr>';
    T.rows.forEach((rv, r) => {
      h += `<tr><th>${rv}</th>`;
      T.cols.forEach((cv, c) => {
        const k = r + ',' + c, isSel = sel && sel.join(',') === k, isDep = dep.includes(k), extra = T.cls ? T.cls(r, c) : '';
        const st = isSel ? 'background:var(--accent);color:var(--card)' : isDep ? 'background:var(--idea);outline:2px solid var(--accent)' : extra === 'stop' ? 'background:var(--gapbg);color:var(--gap)' : '';
        h += `<td data-k="${k}" style="cursor:pointer;${st}">${T.val(r, c)}</td>`;
      });
      h += '</tr>';
    });
    wrap.innerHTML = h + '</table>';
    wrap.querySelectorAll('td[data-k]').forEach(td => td.addEventListener('click', () => draw(td.dataset.k.split(',').map(Number))));
    out.innerHTML = sel ? T.eq(...sel) : 'Click any cell.';
  }
  draw(P.start || null);
}

const VIZ = { walk, cards, disc, repeat, pattern, chain, area, tree, sim, curve, dptable };
VIZ.fns = {};
VIZ.h = { el, txt, svg, html, btn, slider, f3, f2, shuffle };
window.VIZ = VIZ;
let uid = 0;
// A page can add its own widgets/experiments: function vizPage(VIZ) { VIZ.fns.x = ...; VIZ.custom = (root, p) => ... }
function init() {
  if (window.vizPage && !VIZ.pageDone) { VIZ.pageDone = 1; window.vizPage(VIZ); }
  document.querySelectorAll('.viz[data-viz]').forEach(r => {
    if (r.dataset.done) return; r.dataset.done = 1; r.dataset.uid = ++uid;
    try { VIZ[r.dataset.viz](r, r.dataset.p ? JSON.parse(r.dataset.p) : {}); }
    catch (e) { r.textContent = 'diagram error: ' + e.message; }
  });
}
if (document.readyState === 'loading') document.addEventListener('DOMContentLoaded', init); else init();
})();
