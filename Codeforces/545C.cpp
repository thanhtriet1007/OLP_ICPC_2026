/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n;
int x[N], h[N];
int l[N], r[N];

int cnt = 0;

int compress[N];

int st[N * 4];

void update(int id, int l, int r, int pos, int val) {
    if (l > pos || r < pos) return;
    if (l == r) {
        st[id] = val;
        return;
    }

    int mid = (l + r) / 2;

    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) {
        return st[id];
    }

    int mid = (l + r) / 2;

    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int dp[N];

void solve() {
    //World Final when?
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> h[i];
        l[i] = x[i] - h[i];
        r[i] = x[i] + h[i];

        compress[++cnt] = x[i];
        compress[++cnt] = l[i];
        compress[++cnt] = r[i];
    }

    sort(compress + 1, compress + 1 + cnt);

    for (int i = 1; i <= n; ++i) {
        x[i] = lower_bound(compress + 1, compress + 1 + cnt, x[i]) - compress;
        l[i] = lower_bound(compress + 1, compress + 1 + cnt, l[i]) - compress;
        r[i] = lower_bound(compress + 1, compress + 1 + cnt, r[i]) - compress;
    }
    x[0] = -INF;
    x[n + 1] = INF;

    for (int i = 1; i <= n; ++i) {
        //to left 
        if (l[i] > x[i - 1]) {
            dp[x[i]] = max(dp[x[i]], get(1,1,cnt,1,l[i] - 1) + 1);
            update(1,1,cnt,x[i],dp[x[i]]);
        }

        //to right
        if (r[i] < x[i + 1]) {
            dp[r[i]] = max(dp[r[i]], get(1,1,cnt,1,x[i] - 1) + 1);
            update(1,1,cnt,r[i],dp[r[i]]);
        }
    }

    cout << dp[r[n]];
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