/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

long double dp[2002][2002];

void solve() {
    //World Final when? 
    long long n, t; long double p; cin >> n >> p >> t;
    for (int timer = 1; timer <= t; ++timer) {
        for (int human = 1; human <= n; ++human) {
            dp[human][timer] = p * (dp[human - 1][timer - 1] + 1) + (1.0 - p) * (dp[human][timer - 1]);
        }
    }

    cout << setprecision(6) << fixed << dp[n][t];
}

#define TASK "test"

signed main()
{
   ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   if (fopen("input.txt", "r")) {
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
   }
   int t = 1;
   //cin >> t;
   while (t--)
   solve();
   return 0;
}