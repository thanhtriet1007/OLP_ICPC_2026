/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n;
int mi[N], ma[N];

int x[N], y[N];

void solve() {
    //World Final when?
    for (int i = 1; i <= 6; ++i) {
        cin >> x[i] >> y[i];
    }

    for (int i = y[3]; i <= y[4]; ++i) {
        mi[i] = x[3], ma[i] = x[4];
    }

    for (int i = y[5]; i <= y[6]; ++i) {
        mi[i] = min(mi[i], x[5]);
        mi[i] = max()
    }
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