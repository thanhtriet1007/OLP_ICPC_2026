/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n, m;
vector<int>adj[N];
vector<int>revAdj[N];

stack<int>st;

bool vis[N];

void dfs1(int u) {
    vis[u] = 1;
    for (int &v : adj[u]) {
        if (!vis[v]) {
            dfs1(v);
        }
    }
    st.push(u);
}

void dfs2(int u) {
    vis[u] = 1;
    for (int &v : revAdj[u]) {
        if (!vis[v]) {
            dfs2(v);
        }
    }
}

void solve() {
    //World Final when?
    cin >> n >> m;
    while (!st.empty()) st.pop();
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        vis[i] = 0;
        revAdj[i].clear();
    }

    for (int i = 1; i <= m; ++i) { 
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    dfs1(1);
    if (st.size() != n) {
        cout << "NO\n";
        return;
    }

    for (int i = 1; i <= n; ++i) vis[i] = 0;

    int node = st.top();
    dfs2(node);
    
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
   cin >> t;
   while (t--)
   solve();
   return 0;
}