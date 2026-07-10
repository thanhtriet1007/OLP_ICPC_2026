#include <bits/stdc++.h>

#define int            long long
#define endl           '\n'

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF    = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n, q;
vector<int>adj[N];

int in[N], en[N], timer = 0;

void dfs(int u, int p) {
    in[u] = ++timer;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    en[u] = timer;
}

int st[N * 4], lz[N * 4];

void push(int id, int l, int r) {
    if (lz[id] == 0) return;
    st[id] = lz[id];
    if (l != r) {
        lz[id * 2] = lz[id];
        lz[id * 2 + 1] = lz[id];
    }
    lz[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    push(id, l, r);
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        lz[id] = (1ll << (val - 1));
        push(id, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    st[id] = st[id * 2] | st[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v) {
    push(id, l, r);
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return st[id];
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) | get(id * 2 + 1, mid + 1, r, u, v);
}

void init() {
    for (int i = 0; i < N * 4; i++) {
        st[i] = 0;
        lz[i] = 0; 
    }
}

int cl[N];

void solve() {
    //Trie's solution here
    cin >> n >> q;

    init();

    for (int i = 1; i <= n; ++i) cin >> cl[i];
    
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    
    for (int i = 1; i <= n; ++i) {
        update(1, 1, n, in[i], in[i], cl[i]);
    }

    while (q--) {
        int op, u, c; 
        cin >> op;
        if (op == 2) {
            cin >> u;
            int ans = get(1, 1, n, in[u], en[u]);
            cout << __builtin_popcountll(ans) << endl;
        } else {
            cin >> u >> c;
            update(1, 1, n, in[u], en[u], c);
        }
    }
}

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