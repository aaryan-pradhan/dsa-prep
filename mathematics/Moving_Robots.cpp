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
#define ld long double
using namespace std;
/*Each square of an 8 \times 8 chessboard has a robot. Each robot independently moves k steps, and there can be many robots on the same square.
On each turn, a robot moves one step left, right, up or down, but not outside the board. It randomly chooses a direction among those where it can move.
Your task is to calculate the expected number of empty squares after k turns.
Input
The only input line has an integer k.
Output
Print the expected number of empty squares rounded to six decimal places (rounding half to even).
Constraints

1 \le k \le 100

Example
Input:
10

Output:
23.120740*/
// ll rec ( ll sx , ll sy , ll ex , ll ey)
// {
//     // let this return the probability that the robot who started at sx , sy ends up at ex , ey after k moves
//     // if we are at sx , sy and we have to go to ex , ey in k moves, then we can go to any of the 4 directions and then we have to go to ex , ey in k-1 moves
//     if (k == 0) return (sx == ex && sy == ey);
//     if (dp[sx][sy][ex][ey][k] != -1)
//     {
//         return dp[sx][sy][ex][ey][k];
//     }
//     ll ans = 0 ; 
//     if(sx > 0) ans += rec(sx-1 , sy , ex , ey , k-1);
//     if(sx < 7) ans += rec(sx+1 , sy , ex , ey , k-1);
//     if(sy > 0) ans += rec(sx , sy-1 , ex , ey , k-1);
//     if(sy < 7) ans += rec(sx , sy+1 , ex , ey , k-1);
//     return dp[sx][sy][ex][ey][k] = ans/4.0;
    
// }

void solve() 
{
    ll k ; 
    cin >> k ;

    ld dp[8][8][8][8][k+1];
    memset(dp , 0 , sizeof(dp));
    for(ll ex = 0 ; ex < 8 ; ex++)
    {
        for(ll ey = 0 ; ey < 8 ; ey++)
        {
            for(ll l = 0 ; l <= k ; l++)
            { 
                for(ll sx = 0 ; sx < 8 ; sx++)
                {
                    for(ll sy = 0 ; sy < 8 ; sy++)
                    {
                        if(l == 0)
                        {
                            dp[sx][sy][ex][ey][l] = (sx == ex && sy == ey);
                            continue ; 
                        }
                        ld ans = 0 ; 
                        ll cnt = 0 ; 
                        if(sx > 0) 
                        {
                            ans += dp[sx-1][sy][ex][ey][l-1];
                            cnt++;
                        }
                        if(sx < 7)
                        {
                            ans += dp[sx+1][sy][ex][ey][l-1];
                            cnt++;
                        }
                        if(sy > 0)
                        {
                            ans += dp[sx][sy-1][ex][ey][l-1];
                            cnt++;
                        }
                        if(sy < 7)
                        {
                            ans += dp[sx][sy+1][ex][ey][l-1];
                            cnt++;
                        }
                        dp[sx][sy][ex][ey][l] = ans / (cnt * 1.0) ;
                    }
                }
            }
            
        }
        
    }
    ld dp2[8][8][k+1];
    for(ll ex = 0 ; ex < 8 ; ex++)
    {
        for(ll ey = 0 ; ey < 8 ; ey++)
        {
            ld res= 1.0 ; 
            for(ll sx = 0 ; sx < 8 ; sx++)
            {
                for(ll sy = 0 ; sy < 8 ; sy++)
                {
                    res *= (1.0 - dp[sx][sy][ex][ey][k]);
                }
            }
            dp2[ex][ey][k] = res ;
        }
        
    }
    ld res = 0 ; 
    for(ll ex = 0 ; ex < 8 ; ex++)
    {
        for(ll ey = 0 ; ey < 8 ; ey++)
        {
            res += dp2[ex][ey][k];
        }
    }
    cout << fixed << setprecision(6) << res << endl;

    


   






}

signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  