/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n, k;
vector<int>adj[N];

int isMeow[N];
int ans = 0;

void dfs(int u, int p, int cntMeow) {
    if ((int)adj[u].size() == 1 && u != 1) ++ans;
    for (int &v : adj[u]) {
        if (v == p) continue;
        if (isMeow[v] == 0) {
            dfs(v, u, 0);
        } else {
            if (cntMeow + 1 <= k) dfs(v, u, cntMeow + 1);
        }
    }
}


void solve() {
    //World Final when?
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> isMeow[i];

    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, isMeow[1]);

    cout << ans;
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