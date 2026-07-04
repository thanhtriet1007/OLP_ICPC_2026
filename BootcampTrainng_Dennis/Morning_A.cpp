/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n;
vector<int>adj[N];

int dist[N];
long double prob[N];

void dfs(int u, int p) {
    for (int &v : adj[u]) {
        if (v == p) continue;
        dist[v] = dist[u] + 1;
        prob[v] = prob[u] / (adj[u].size() - (u != 1));
        dfs(v, u);
    }
}

void solve() {
    cin >> n;
    prob[1] = 1;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);

    //for (int i = 1; i <= n; ++i) cout << dist[i] << ' ' << prob[i] << ' ';
    long double ans = 0;
    for (int i = 2; i <= n; ++i) {
        if ((int)adj[i].size() == 1) {
            ans += (prob[i] * dist[i]);
        }
    }

    cout << setprecision(6) << fixed << ans;
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