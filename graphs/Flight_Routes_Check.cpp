// orz
#include <bits/stdc++.h>

#define ll long long 
#define endl "\n"
#define fr first
#define sc second
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define mp make_pair
#define PI acos(-1) 
#define py cout << "YES" << endl
#define pn cout << "NO" << endl
#define pll pair<ll,ll>

using namespace std;
/*There are n cities and m flight connections. Your task is to check if you can travel from any city to any other city using the available flights.
Input
The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,\dots,n.
After this, there are m lines describing the flights. Each line has two integers a and b: there is a flight from city a to city b. All flights are one-way flights.
Output
Print "YES" if all routes are possible, and "NO" otherwise. In the latter case also print two cities a and b such that you cannot travel from city a to city b. If there are several possible solutions, you can print any of them.
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
4 5
1 2
2 3
3 1
1 4
3 4

Output:
NO
4 2*/

void solve() 
{
    ll n , m ; 
    cin >> n >> m ;
    vector < vector < ll > > g(n+1) , rg(n+1) ; 
    for(ll i = 0 ; i < m ; i++)
    {
        ll a , b ; 
        cin >> a >> b ; 
        g[a].push_back(b) ; 
        rg[b].push_back(a) ; 
    }
    queue <ll> q ;
    vector < bool > vis(n+1 , false) ;
    q.push(1) ;
    vis[1] = true ;
    while(!q.empty())
    {
        ll node = q.front() ; 
        q.pop() ; 
        for(auto child : g[node])
        {
            if(!vis[child])
            {
                vis[child] = true ; 
                q.push(child) ; 
            }
        }
    }
    for(ll i = 1 ; i <= n ; i++)
    {
        if(!vis[i])
        {
            pn ; 
            cout << 1 << " " << i << endl ; 
            return ; 
        }
    }
    vector < ll > rvis(n+1 , false) ; 
    queue <ll> rq ;
    rq.push(1) ;
    rvis[1] = true ;
    while(!rq.empty())
    {
        ll node = rq.front() ; 
        rq.pop() ; 
        for(auto child : rg[node])
        {
            if(!rvis[child])
            {
                rvis[child] = true ; 
                rq.push(child) ; 
            }
        }
    }
    for(ll i = 1 ; i <= n ; i++)
    {
        if(!rvis[i])
        {
            pn ; 
            cout << i << " " << 1 << endl ; 
            return ; 
        }
    }
    py ; 



    
    

   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
   
/*You have 
𝑛
n cities and 
𝑚
m one-way flights. You need to determine: is it possible to fly from any city to any other city, possibly using multiple flights in sequence?

Formally: define 
𝑢
⇝
𝑣
u⇝v ("
𝑢
u can reach 
𝑣
v") to mean there's a directed path from 
𝑢
u to 
𝑣
v (possibly through other cities). The question asks: is it true that 
𝑢
⇝
𝑣
u⇝v for every pair 
(
𝑢
,
𝑣
)
(u,v) with 
𝑢
≠
𝑣
u

=v? This property is called strong connectivity — every node can reach every other node via directed edges.

If it's not strongly connected, you must also exhibit one witness pair 
(
𝑎
,
𝑏
)
(a,b) where 
𝑎
⇝
𝑏
a⇝b fails.

The brute-force way to check this would be running BFS from every single node — 
𝑂
(
𝑛
)
O(n) BFS calls, each 
𝑂
(
𝑛
+
𝑚
)
O(n+m), giving 
𝑂
(
𝑛
(
𝑛
+
𝑚
)
)
O(n(n+m)) total. With 
𝑛
n up to 
10
5
10
5
, that's far too slow. We need something in 
𝑂
(
𝑛
+
𝑚
)
O(n+m) — i.e., just two BFS calls total, no matter how big 
𝑛
n is.

The claim to prove

Claim: The graph is strongly connected if and only if city 1 can reach every other city, and every other city can reach city 1.

In symbols: define 
𝑅
=
{
𝑥
:
1
⇝
𝑥
}
R={x:1⇝x} (reachable from 1) and 
𝐵
=
{
𝑥
:
𝑥
⇝
1
}
B={x:x⇝1} (can reach back to 1). The claim is:

graph is strongly connected
  
⟺
  
𝑅
=
{
1
,
…
,
𝑛
}
 and 
𝐵
=
{
1
,
…
,
𝑛
}
graph is strongly connected⟺R={1,…,n} and B={1,…,n}

This is an "if and only if," so we need to prove both directions.

Direction 1: strongly connected 
  
⟹
  
⟹ both conditions hold

This direction is immediate. If the graph is strongly connected, then by definition every pair of nodes can reach each other — in particular, node 1 can reach every node (so 
𝑅
R is everything), and every node can reach node 1 (so 
𝐵
B is everything). Nothing to prove beyond unpacking the definition.

Direction 2: both conditions hold 
  
⟹
  
⟹ strongly connected (the interesting part)

Assume 
𝑅
=
{
1
,
…
,
𝑛
}
R={1,…,n} and 
𝐵
=
{
1
,
…
,
𝑛
}
B={1,…,n}. We need to show that for any pair of cities 
𝑢
,
𝑣
u,v (with 
𝑢
≠
𝑣
u

=v), we have 
𝑢
⇝
𝑣
u⇝v.

Take arbitrary 
𝑢
,
𝑣
u,v. We know:

Since 
𝑢
∈
𝐵
u∈B, we have 
𝑢
⇝
1
u⇝1 (a path exists from 
𝑢
u to city 1).
Since 
𝑣
∈
𝑅
v∈R, we have 
1
⇝
𝑣
1⇝v (a path exists from city 1 to 
𝑣
v).

Now just concatenate these two paths: walk from 
𝑢
u to 
1
1 using the first path, then continue from 
1
1 to 
𝑣
v using the second path. This gives a valid walk from 
𝑢
u to 
𝑣
v in the directed graph — so 
𝑢
⇝
𝑣
u⇝v.

Since 
𝑢
,
𝑣
u,v were arbitrary, this holds for every pair, which is exactly the definition of strongly connected. 
■
■

Why this collapses 
𝑛
n BFS calls into 2

The naive approach checks reachability for all 
(
𝑛
2
)
(
2
n
	​

) (or 
𝑛
(
𝑛
−
1
)
n(n−1) ordered) pairs directly. The proof above shows you don't need to — reachability through the "hub" node 1 automatically covers every pair simultaneously, as long as 1 itself is universally reachable both ways.

𝑅
R (everything reachable from 1) is computed with one forward BFS/DFS from node 1 on the graph as given.
𝐵
B (everything that can reach node 1) is computed with one BFS/DFS from node 1 on the graph with every edge reversed — because a path from 
𝑥
x to 1 in the original graph is exactly a path from 1 to 
𝑥
x in the reversed graph (reversing turns "can reach 1" into "1 can reach").

So instead of 
𝑛
n traversals, we need exactly 2, regardless of how large 
𝑛
n is. That's what brings the complexity down from 
𝑂
(
𝑛
(
𝑛
+
𝑚
)
)
O(n(n+m)) to 
𝑂
(
𝑛
+
𝑚
)
O(n+m).

Note: node 1 isn't special — any node works

Nothing in the proof used a specific property of node 1; it works as the hub precisely because it's a fixed reference point that every other node's reachability gets checked against. You could equally well pick any city 
𝑘
k and run forward/backward BFS from 
𝑘
k — the proof goes through unchanged with 
𝑘
k in place of 
1
1. Node 1 is just a convenient, arbitrary choice.

Finding a witness pair when it fails

If the graph is not strongly connected, the proof's contrapositive tells us where to look:

If some node 
𝑥
∉
𝑅
x∈
/
R (i.e., 1 cannot reach 
𝑥
x), then 
(
1
,
𝑥
)
(1,x) is a valid witness pair — you genuinely cannot fly from 1 to 
𝑥
x.
If some node 
𝑥
∉
𝐵
x∈
/
B (i.e., 
𝑥
x cannot reach 1), then 
(
𝑥
,
1
)
(x,1) is a valid witness pair.

This is guaranteed to find some failing pair whenever the graph isn't strongly connected — because if both 
𝑅
R and 
𝐵
B were "everything," the claim proves the graph would be strongly connected, contradiction. So at least one of the two BFS passes must miss a node whenever the answer is NO.*/
  