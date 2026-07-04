/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n;
char a[502][502];

vector<int>adj[N];
bool vis[N];

void dfs(int u) {
    vis[u] = 1;
    for (int &v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

vector<ii>listEdge;
int dist[502][502];

void solve() {
    //World Final when?
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        vis[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            dist[i][j] = dist[j][i] = INF;
        }
    }
    listEdge.clear();

    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
        for (int j = i + 1; j <= n; ++j) {
            if (a[i][j] == '1') {
                adj[i].push_back(j);
                adj[j].push_back(i);
                dist[i][j] = dist[j][i] = 1;
               
                listEdge.push_back({i, j});
            }
        }
    }


    dfs(1);

    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) {
            cout << "NO\n";
            return;
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    //for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (dist[i][j] % 2 != (a[i][j] - '0')) {
                    //cout << i << ' ' << j << ' ' <<dist[i][j] << endl;
                    cout << "NO\n";
                    return;
                }
            
        }
    }

    cout << "YES\n";
    cout << listEdge.size() << endl;
    for (auto [u, v] : listEdge) {
        cout << u << ' ' << v << endl;
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
   cin >> t;
   while (t--)
   solve();
   return 0;
}