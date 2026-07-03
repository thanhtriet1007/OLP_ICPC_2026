/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const int       maxA   = 1e5 + 2000;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n;
int a[N];

int dp[N], st[N * 4];

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

void solve() {
    //World Final when?
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        //dp[a[i]] += a[i];
    }

    sort(a + 1, a + 1 + n, greater<int>());
    vector<bool>mark(maxA + 1, 0);

    for (int i = 1; i <= n; ++i) {
        if (!mark[a[i]]) {
            dp[a[i]] += get(1,1,maxA,a[i] + 2, maxA) + a[i];
        } else {
            dp[a[i]] += a[i];
        }
        mark[a[i]] = 1;
        update(1,1,maxA,a[i],dp[a[i]]);
    }

    cout << *max_element(dp + 1, dp + 1 + maxA);
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