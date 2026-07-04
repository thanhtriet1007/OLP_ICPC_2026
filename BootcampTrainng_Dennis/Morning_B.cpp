/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n, k;

long double probLOE[N];

void solve() {
    //World Final when?
    cin >> n >> k; 
    probLOE[1] = pow(1.0 / (n * 1.0), (k * 1.0));
    
    for (int i = 1; i <= n; ++i) {
        probLOE[i] = pow((long double)i / (n * 1.0), k * 1.0);
    }
    long double ans = 0;
    for (int i = 1; i <= n; ++i) {
        long double prob = probLOE[i] - probLOE[i - 1];
        ans += i * prob;
    }

    cout << setprecision(10) << fixed << ans;
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